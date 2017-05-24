#include "bmp.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

BMPImage* read_bmp(FILE* fp, char** error) {
	int read_header = 0;
	int read_data = 0;
	int image_size = 0;
	FILE* fp_copy = fp;
	if (fp == NULL) {
		if (*error != NULL) {
			free(*error);
		}
			char* message = "read_bmp failed because fp == NULL";
			*error = malloc((strlen(message) + 1) * sizeof(**error));
			strcpy(*error, message);
		return NULL;
	}	
	BMPImage* image = malloc(sizeof(BMPImage));
	image->data = NULL;
	BMPHeader temp_header;
	read_header = fread(&temp_header, 1, BMP_HEADER_SIZE, fp_copy);

	if (read_header != BMP_HEADER_SIZE) {
		if (*error == NULL) {
			char* message = "read_header failed";
			*error = malloc((strlen(message) + 1) * sizeof(**error));
			strcpy(*error, message);
		}
		free_bmp(image);
		return NULL;
	}
	image->header = temp_header;
	image_size = (temp_header.width_px) * (temp_header.height_px) * (temp_header.bits_per_pixel) / 8 + ((temp_header.width_px) % 4) * (temp_header.height_px);
	image->data = malloc(image_size);
	read_data = fread(image->data, 1, image_size, fp_copy);
	if (read_data != image_size) {
		if (*error != NULL) {
			free(*error);
		}
			char* message = "read_data failed";
			*error = malloc((strlen(message) + 1) * sizeof(**error));
			strcpy(*error, message);
		free_bmp(image);
		return NULL;
	}
	bool check_header = check_bmp_header(&(image->header), fp);
	if (!check_header) {
		if (*error != NULL) {
			free(*error);
		}
			char* message = "check_bmp_header failed";
			*error = malloc((strlen(message) + 1) * sizeof(**error));
			strcpy(*error, message);
		free_bmp(image);
		return NULL;
	}	
	return image;
}

bool check_bmp_header(BMPHeader* bmp_header, FILE* fp) {
	if (bmp_header == NULL) {
		return false;
	}
	if (bmp_header->type != 0x4d42) {
		return false;
	}
	if (bmp_header->offset != BMP_HEADER_SIZE) {
		return false;
	}
	if (bmp_header->dib_header_size != DIB_HEADER_SIZE) {
		return false;
	}
	if (bmp_header->num_planes != 1) {
		return false;
	}
	if (bmp_header->compression != 0) {
		return false;
	}
	if (bmp_header->num_colors != 0 || bmp_header->important_colors != 0) {
		return false;
	}
	if (bmp_header->bits_per_pixel != 16 && bmp_header->bits_per_pixel != 24) {
		return false;
	}
	int image_size = (bmp_header->width_px) * (bmp_header->height_px) * (bmp_header->bits_per_pixel) / 8 + ((bmp_header->width_px) % 4) * (bmp_header->height_px);
	if (bmp_header->image_size_bytes != image_size) {
		return false;
	}
	if (bmp_header->size != (image_size + BMP_HEADER_SIZE)) {
		return false;
	}
	return true;
}

bool write_bmp(FILE* fp, BMPImage* image, char** error) {
	int check_header = 0;
	int check_data = 0;
	if (fp == NULL) {
		if (*error != NULL) {
			free(*error);
		}
			char* message = "write_bmp failed because fp == NULL";
			*error = malloc((strlen(message) + 1) * sizeof(**error));
			strcpy(*error, message);
		return false;
	}	
	if (image == NULL) {
		if (*error != NULL) {
			free(*error);
		}
			char* message = "write_bmp failed because image == NULL";
			*error = malloc((strlen(message) + 1) * sizeof(**error));
			strcpy(*error, message);
		return false;
	}	
	check_header = fwrite(&(image->header), image->header.offset, 1, fp);
	if (check_header != 1) {
		return false;
	}
	check_data = fwrite(image->data, (image->header.size - image->header.offset), 1, fp);
	if (check_data != 1) {
		return false;
	}
	return true;
}

void free_bmp(BMPImage* image) {
	if (image != NULL) {
		if (image->data != NULL) {
			free(image->data);
		}
		free(image);
	}
}

BMPImage* crop_bmp(BMPImage* image, int x, int y, int w, int h, char** error) {
	BMPImage* crop_image = NULL;
	if (((x+w) > (image->header.width_px)) || ((y+h) > (image->header.height_px))) {
		if (*error != NULL) {
			free(*error);
		}
			char* message = "crop_image failed because crop size is larger than the original size";
			*error = malloc((strlen(message) + 1) * sizeof(**error));
			strcpy(*error, message);
		return NULL;
	}
	int byte_per_px = image->header.bits_per_pixel / 8;
	long int image_size = h * w * byte_per_px + ((4 - ((w * byte_per_px) % 4))%4) * h;
	long int total_size = image_size + BMP_HEADER_SIZE;
	// update crop_image
	crop_image = malloc(sizeof(BMPImage));
	crop_image->data = malloc(image_size);
	crop_image->header = image->header;
	crop_image->header.size = total_size;
	crop_image->header.width_px = w;
	crop_image->header.height_px = h;
	crop_image->header.image_size_bytes = image_size;

	// update data
	unsigned char* new_data = crop_image->data;
	unsigned char* old_data = image->data;
	long int starting_point_calc = ((y * image->header.width_px) + x) * byte_per_px + y * ((4 - ((image->header.width_px * byte_per_px) % 4))%4); // calculate the location of first pixel
	unsigned char* starting_point = &(old_data[starting_point_calc]); // jump to the first pixel we need
	long int jump_calc = (((4 - ((image->header.width_px * byte_per_px) % 4))%4) + (image->header.width_px) * byte_per_px);
	for (int i = 0; i < h; i++) {
		if (i != 0) {
			starting_point = &(starting_point[jump_calc]); // jump to the next line
		}
		for (int j = 0; j < (w*byte_per_px); j++) {
			new_data[0] = starting_point[j];
			new_data++;
		}

		for (int k = 0; k < ((4 - ((w * byte_per_px) % 4))%4); k++) { 
			*new_data = 0x00;
			new_data++;
		}

	}
	return crop_image;
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
