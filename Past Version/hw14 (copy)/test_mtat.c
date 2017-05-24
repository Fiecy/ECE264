#include "mtat.h"
#include <stdlib.h>
#include <stdio.h>

void compare_img(BMPImage* image1, BMPImage* image2) {
	if (image1 == NULL) {
		printf("image1 is NULL\n");
		return;
	}
	if (image2 == NULL) {
		printf("image2 is NULL\n");
		return;
	}
	if (image1->header.type != image2->header.type) {
		printf("type is not equal\n");
		return;
	}
	if (image1->header.size != image2->header.size) {
		printf("size is not equal\n");
		return;
	}
	if (image1->header.offset != image2->header.offset) {
		printf("offset is not equal\n");
		return;
	}

	if (image1->header.image_size_bytes != image2->header.image_size_bytes) {
		printf("image_size_bytes is not equal\n");
		return;
	}
	BMPImage* hold1 = image1;
	BMPImage* hold2 = image2;
	for (long int i = 0; i < image1->header.image_size_bytes; i++) {
		if (hold1->data[i] != hold2->data[i]) {
			printf("data not equal, i = %ld\n", i);
			return;
		}
		printf("i = %ld\n", i);
	}
	printf("this two pictures are the same\n");
	return;
}

int main(int argc, char* argv[]) {
	// State 00: normal test, radius = 1
	FILE* fp = fopen("img1_6x6_color.bmp", "r");
	char* error = NULL;
	BMPImage* image = NULL;
	if (fp == NULL) {
		printf("fopen error\n");
	}
	image = read_bmp(fp, &error);
	if (error != NULL) {
		printf("%s\n", error);
		free(error);
	}
	BMPImage* binarize_image = binarize(image, 1, 10, &error);
	if (error != NULL) {
		printf("%s\n", error);
		free(error);
	}

	int check_write = 0;
	FILE* fp_w = fopen("img1_6x6_color_new_bw_r=01.bmp", "w");
	check_write = write_bmp(fp_w, binarize_image, &error);
	if (check_write) {
		printf("6x6 r=01.bmp succeed\n");
	}
	free_bmp(image);
	fclose(fp);
	fclose(fp_w);
	free_bmp(binarize_image);

	FILE* fp0 = fopen("img1_6x6_color_new_bw_r=01.bmp", "r");
	char* error0 = NULL;
	BMPImage* image0 = NULL;
	if (fp0 == NULL) {
		printf("fopen error\n");
	}
	image0 = read_bmp(fp0, &error0);
	if (error0 != NULL) {
		printf("%s\n", error0);
		free(error0);
	}
	free_bmp(image0);
	fclose(fp0);

	// State 01: normal test radius = 2
	FILE* fp1 = fopen("img1_6x6_color.bmp", "r");
	char* error1 = NULL;
	BMPImage* image1 = NULL;
	if (fp1 == NULL) {
		printf("fopen error\n");
	}
	image1 = read_bmp(fp1, &error1);
	if (error1 != NULL) {
		printf("%s\n", error1);
		free(error1);
	}
	BMPImage* binarize_image1 = binarize(image1, 2, 10, &error1);
	if (error1 != NULL) {
		printf("%s\n", error1);
		free(error1);
	}

	int check_write1 = 0;
	FILE* fp_w1 = fopen("img1_6x6_color_new_bw_r=02.bmp", "w");
	check_write1 = write_bmp(fp_w1, binarize_image1, &error1);
	if (check_write1) {
		printf("6x6 r=02.bmp succeed\n");
	}
	free_bmp(image1);
	fclose(fp1);
	fclose(fp_w1);
	free_bmp(binarize_image1);

	// State 02: normal test radius = 3
	FILE* fp2 = fopen("img1_6x6_color.bmp", "r");
	char* error2 = NULL;
	BMPImage* image2 = NULL;
	if (fp2 == NULL) {
		printf("fopen error\n");
	}
	image2 = read_bmp(fp2, &error2);
	if (error2 != NULL) {
		printf("%s\n", error2);
		free(error2);
	}
	BMPImage* binarize_image2 = binarize(image2, 3, 10, &error2);
	if (error2 != NULL) {
		printf("%s\n", error2);
		free(error2);
	}

	int check_write2 = 0;
	FILE* fp_w2 = fopen("img1_6x6_color_new_bw_r=03.bmp", "w");
	check_write2 = write_bmp(fp_w2, binarize_image2, &error2);
	if (check_write2) {
		printf("6x6 r=03.bmp succeed\n");
	}
	free_bmp(image2);
	fclose(fp2);
	fclose(fp_w2);
	free_bmp(binarize_image2);

	// State 03: normal test, radius = 4
	FILE* fp3 = fopen("img1_6x6_color.bmp", "r");
	char* error3 = NULL;
	BMPImage* image3 = NULL;
	if (fp3 == NULL) {
		printf("fopen error\n");
	}
	image3 = read_bmp(fp3, &error3);
	if (error3 != NULL) {
		printf("%s\n", error3);
		free(error3);
	}
	BMPImage* binarize_image3 = binarize(image3, 4, 10, &error3);
	if (error3 != NULL) {
		printf("%s\n", error3);
		free(error3);
	}

	int check_write3 = 0;
	FILE* fp_w3 = fopen("img1_6x6_color_new_bw_r=04.bmp", "w");
	check_write3 = write_bmp(fp_w3, binarize_image3, &error3);
	if (check_write3) {
		printf("6x6 r=04.bmp succeed\n");
	}
	free_bmp(image3);
	fclose(fp3);
	fclose(fp_w3);
	free_bmp(binarize_image3);

	// State 04: normal test, radius = 5
	FILE* fp4 = fopen("img1_6x6_color.bmp", "r");
	char* error4 = NULL;
	BMPImage* image4 = NULL;
	if (fp4 == NULL) {
		printf("fopen error\n");
	}
	image4 = read_bmp(fp4, &error4);
	if (error4 != NULL) {
		printf("%s\n", error4);
		free(error4);
	}
	BMPImage* binarize_image4 = binarize(image4, 5, 35, &error4);
	if (error4 != NULL) {
		printf("%s\n", error4);
		free(error4);
	}

	int check_write4 = 0;
	FILE* fp_w4 = fopen("img1_6x6_color_new_bw_r=05.bmp", "w");
	check_write4 = write_bmp(fp_w4, binarize_image4, &error4);
	if (check_write4) {
		printf("6x6 r=05.bmp succeed\n");
	}
	free_bmp(image4);
	fclose(fp4);
	fclose(fp_w4);
	free_bmp(binarize_image4);

	// State 05: big picture, radius = 2
	FILE* fp5 = fopen("img2_384x510_gray.bmp", "r");
	char* error5 = NULL;
	BMPImage* image5 = NULL;
	if (fp5 == NULL) {
		printf("fopen error\n");
	}
	image5 = read_bmp(fp5, &error5);
	if (error5 != NULL) {
		printf("%s\n", error5);
		free(error5);
	}
	BMPImage* binarize_image5 = binarize(image5, 2, 4, &error5);
	if (error5 != NULL) {
		printf("%s\n", error5);
		free(error5);
	}

	int check_write5 = 0;
	FILE* fp_w5 = fopen("img2_384x510_gray_new_bw_r=02.bmp", "w");
	check_write5 = write_bmp(fp_w5, binarize_image5, &error5);
	if (check_write5) {
		printf("bit picture r=02 succeed\n");
	}
	free_bmp(image5);
	fclose(fp5);
	fclose(fp_w5);
	free_bmp(binarize_image5);

	// State 06: big picture, radius = 5
	FILE* fp6 = fopen("img2_384x510_gray.bmp", "r");
	char* error6 = NULL;
	BMPImage* image6 = NULL;
	if (fp6 == NULL) {
		printf("fopen error\n");
	}
	image6 = read_bmp(fp6, &error6);
	if (error6 != NULL) {
		printf("%s\n", error6);
		free(error6);
	}
	BMPImage* binarize_image6 = binarize(image6, 5, 8, &error5);
	if (error6 != NULL) {
		printf("%s\n", error6);
		free(error6);
	}

	int check_write6 = 0;
	FILE* fp_w6 = fopen("img2_384x510_gray_new_bw_r=05.bmp", "w");
	check_write6 = write_bmp(fp_w6, binarize_image6, &error6);
	if (check_write6) {
		printf("bit picture r=05 succeed\n");
	}
	free_bmp(image6);
	fclose(fp6);
	fclose(fp_w6);
	free_bmp(binarize_image6);

	// State 07: big picture, radius = 10
	FILE* fp7 = fopen("img2_384x510_gray.bmp", "r");
	char* error7 = NULL;
	BMPImage* image7 = NULL;
	if (fp7 == NULL) {
		printf("fopen error\n");
	}
	image7 = read_bmp(fp7, &error7);
	if (error7 != NULL) {
		printf("%s\n", error7);
		free(error7);
	}
	BMPImage* binarize_image7 = binarize(image7,10, 16, &error7);
	if (error7 != NULL) {
		printf("%s\n", error7);
		free(error7);
	}

	int check_write7 = 0;
	FILE* fp_w7 = fopen("img2_384x510_gray_new_bw_r=10.bmp", "w");
	check_write7 = write_bmp(fp_w7, binarize_image7, &error7);
	if (check_write7) {
		printf("bit picture r=10 succeed\n");
	}
	free_bmp(image7);
	fclose(fp7);
	fclose(fp_w7);
	free_bmp(binarize_image7);

	// State 08: big picture, radius = 20
	FILE* fp8 = fopen("img2_384x510_gray.bmp", "r");
	char* error8 = NULL;
	BMPImage* image8 = NULL;
	if (fp8 == NULL) {
		printf("fopen error\n");
	}
	image8 = read_bmp(fp8, &error8);
	if (error8 != NULL) {
		printf("%s\n", error8);
		free(error8);
	}
	BMPImage* binarize_image8 = binarize(image8,20, 32, &error8);
	if (error8 != NULL) {
		printf("%s\n", error8);
		free(error8);
	}

	int check_write8 = 0;
	FILE* fp_w8 = fopen("img2_384x510_gray_new_bw_r=20.bmp", "w");
	check_write8 = write_bmp(fp_w8, binarize_image8, &error8);
	if (check_write8) {
		printf("bit picture r=20 succeed\n");
	}
	free_bmp(image8);
	fclose(fp8);
	fclose(fp_w8);
	free_bmp(binarize_image8);

	// State 09: big picture, radius = 40
	FILE* fp9 = fopen("img2_384x510_gray.bmp", "r");
	char* error9 = NULL;
	BMPImage* image9 = NULL;
	if (fp9 == NULL) {
		printf("fopen error\n");
	}
	image9 = read_bmp(fp9, &error9);
	if (error9 != NULL) {
		printf("%s\n", error9);
		free(error9);
	}
	BMPImage* binarize_image9 = binarize(image9,40, 64, &error9);
	if (error9 != NULL) {
		printf("%s\n", error9);
		free(error9);
	}

	int check_write9 = 0;
	FILE* fp_w9 = fopen("img2_384x510_gray_new_bw_r=40.bmp", "w");
	check_write9 = write_bmp(fp_w9, binarize_image9, &error9);
	if (check_write9) {
		printf("bit picture r=40 succeed\n");
	}
	free_bmp(image9);
	fclose(fp9);
	fclose(fp_w9);
	free_bmp(binarize_image9);

	// State 10: compare data 382x510 r=40
	FILE* fp10_1 = fopen("img2_384x510_gray_new_bw_r=40.bmp", "r");
	char* error10_1 = NULL;
	BMPImage* image10_1 = NULL;
	if (fp10_1 == NULL) {
		printf("fopen error\n");
	}
	image10_1 = read_bmp(fp10_1, &error10_1);
	if (error10_1 != NULL) {
		printf("%s\n", error10_1);
		free(error10_1);
	}
	FILE* fp10_2 = fopen("img2_384x510_bw_r=40.bmp", "r");
	char* error10_2 = NULL;
	BMPImage* image10_2 = NULL;
	if (fp10_2 == NULL) {
		printf("fopen error\n");
	}
	image10_2 = read_bmp(fp10_2, &error10_2);
	if (error10_2 != NULL) {
		printf("%s\n", error10_2);
		free(error10_2);
	}

	printf("compare data 382x510 r=40\n");
	compare_img(image10_1, image10_2);

	free_bmp(image10_1);
	free_bmp(image10_2);
	fclose(fp10_1);
	fclose(fp10_2);

	// State 11: compare data 6x6 r=3
	FILE* fp11_1 = fopen("img1_6x6_color_new_bw_r=03.bmp", "r");
	char* error11_1 = NULL;
	BMPImage* image11_1 = NULL;
	if (fp11_1 == NULL) {
		printf("fopen error\n");
	}
	image11_1 = read_bmp(fp11_1, &error11_1);
	if (error11_1 != NULL) {
		printf("%s\n", error11_1);
		free(error11_1);
	}
	FILE* fp11_2 = fopen("img1_6x6_bw_r=03.bmp", "r");
	char* error11_2 = NULL;
	BMPImage* image11_2 = NULL;
	if (fp11_2 == NULL) {
		printf("fopen error\n");
	}
	image11_2 = read_bmp(fp11_2, &error11_2);
	if (error11_2 != NULL) {
		printf("%s\n", error11_2);
		free(error11_2);
	}

	printf("compare data 6x6 r=3\n");
	compare_img(image11_1, image11_2);

	free_bmp(image11_1);
	free_bmp(image11_2);
	fclose(fp11_1);
	fclose(fp11_2);
	return EXIT_SUCCESS;
}
