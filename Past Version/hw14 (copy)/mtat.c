#include "mtat.h"
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	int x;
	int y;
	int32_t w;
	int32_t h;
	int radius;
	int padding;
	BMPImage* image;
	BMPImage* binarize_image;
} NEWImage;

long int _sum_all(int x, int y, int w, int h, int radius, BMPImage* image) {
	long int total = 0;
	for (int i = -radius; i < radius+1; i++) {
		for (int j = 0; j < ((radius * 2 + 1) * 3); j++) {
			long long int op_point = (x + i) * (w * 3 + w%4) + (y - radius) * 3 + j;
			if ((x + i) < 0 || (x + i + 1) > h ||  ((y - radius) * 3 + j + 1) > (w*3) || ((y - radius) * 3 + j) < 0) {
				total = total;
			}
			else {
			//printf("op_point = %ld, i = %d, j = %d, x = %d, y = %d\n", op_point, i ,j,x,y); 
				total = total + image->data[op_point];
			}
		}
	}
	//printf("x = %d, y = %d, total = %ld\n", x, y, total);
	return total;
}

void* _operation(void* args) {
	NEWImage* _data = (NEWImage*)args;
	int radius = _data->radius;
	long int op_point = (_data->w * 3 + _data->padding) * _data->x + _data->y * 3;
	int op_data = _data->image->data[op_point] + _data->image->data[op_point+1] + _data->image->data[op_point+2]; 
	int lostx = 0;
	int losty = 0;
	if ((_data->x - _data->radius) < 0) {
		lostx = lostx + _data->radius - _data->x;
	}
	if ((_data->x + _data->radius + 1) > _data->h) {
		lostx = lostx + _data->x + _data->radius + 1 - _data->h;
	}
	if ((_data->y - _data->radius) < 0) {
		losty = losty + _data->radius - _data->y;
	}
	if ((_data->y + _data->radius + 1) > _data->w) {
		losty = losty + _data->y + _data->radius + 1 - _data->w;
	}
	long int total = _sum_all(_data->x, _data->y, _data->w, _data->h, _data->radius, _data->image);
	long int calc_total = ((radius*2+1-lostx)*(radius*2+1-losty) * op_data);
	//printf("x = %d, y = %d, lostx = %d, losty = %d, calc = %ld, total = %ld, op_point = %lld\n", _data->x, _data->y, lostx, losty, calc_total, total, op_point);
	if (calc_total > total) {
		_data->binarize_image->data[op_point] = 0xFF;
		_data->binarize_image->data[op_point+1] = 0xFF;
		_data->binarize_image->data[op_point+2] = 0xFF;
	}
	else {
		_data->binarize_image->data[op_point] = 0x00;
		_data->binarize_image->data[op_point+1] = 0x00;
		_data->binarize_image->data[op_point+2] = 0x00;		
	}
	//printf("x = %d, y = %d, op_point = %ld\n", _data->x, _data->y, op_point);
	return NULL;
}

BMPImage* binarize(BMPImage* image, int radius, int num_threads, char** a_error) {
	if (image == NULL) {
		if (*a_error == NULL) {
			char* message = "image is NULL";
			*a_error = malloc((strlen(message) + 1) * sizeof(**a_error));
			strcpy(*a_error, message);
		}
		return NULL;
	}
	if (image->header.offset != BMP_HEADER_SIZE) {
		if (*a_error == NULL) {
			char* message = "header size != 54";
			*a_error = malloc((strlen(message) + 1) * sizeof(**a_error));
			strcpy(*a_error, message);
		}
		return NULL;
	}
	if (image->header.bits_per_pixel != 24) {
		if (*a_error == NULL) {
			char* message = "bits_per_pixel != 24";
			*a_error = malloc((strlen(message) + 1) * sizeof(**a_error));
			strcpy(*a_error, message);
		}
		return NULL;
	}	

	BMPImage* binarize_image = malloc(sizeof(BMPImage));
	binarize_image->header = image->header;
	binarize_image->data = malloc(image->header.image_size_bytes);

	int numof_threads = 0;
	int w = image->header.width_px;
	int h = image->header.height_px;
	if (num_threads > (w*h)){
		numof_threads = w*h;
	}
	else {
		numof_threads = num_threads;
	}
	//pthread_t threads[numof_threads];
	pthread_t* threads = malloc(numof_threads * sizeof(pthread_t));

	//NEWImage op_image[numof_threads];
	NEWImage* op_image = malloc(numof_threads * sizeof(NEWImage));
	int cnt_threads = 0;
	for (int i = 0; i < h; i++) {
		printf("h = %d\n", i);
		for (int j = 0; j < w; j++) {
			op_image[cnt_threads].x = i;
			op_image[cnt_threads].y = j;
			op_image[cnt_threads].w = w;
			op_image[cnt_threads].h = h;
			op_image[cnt_threads].radius = radius;
			op_image[cnt_threads].padding = w%4;
			op_image[cnt_threads].image = image;
			op_image[cnt_threads].binarize_image = binarize_image;
			pthread_create(&threads[cnt_threads], NULL, _operation, &op_image[cnt_threads]);

			//printf("cnt = %d, numof = %d, h = %d\n", cnt_threads, numof_threads, i);
			cnt_threads = (cnt_threads + 1) % numof_threads;
			if (cnt_threads == 0) {
				for (int t = 0; t < numof_threads; t++) {
					//printf("t = %d\n", t);
					pthread_join(threads[t], NULL);
				}
			}
			//printf("cnt_threads = %d\n", cnt_threads);
		}
		if (i == (h - 1)) {
			for (int t = 0; t < cnt_threads; t++) {
				pthread_join(threads[t], NULL);
			}
		}
		long int op_point = (w * 3 + w%4) * (i+1); 
		for (int k = 0; k < w%4; k++) {
			//printf("paddint_point = %ld\n", op_point-k-1);
			binarize_image->data[op_point-k-1] = 0x00;
		}
	}

	bool check_header = check_bmp_header(&(binarize_image->header), NULL);
	if (!check_header) {
		if (*a_error != NULL) {
			free(*a_error);
		}
			char* message = "check_bmp_header failed";
			*a_error = malloc((strlen(message) + 1) * sizeof(**a_error));
			strcpy(*a_error, message);
		free_bmp(binarize_image);
		return NULL;
	}	

	free(threads);
	free(op_image);
	return binarize_image;
}

