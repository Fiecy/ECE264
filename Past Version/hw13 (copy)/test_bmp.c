#include "bmp.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	// Stage 00: read_bmp normal case
	FILE* fp = fopen("6x6_24bit.bmp", "r");
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
	free_bmp(image);
	fclose(fp);
	// State 01: free_bmp works 
	FILE* fp1 = fopen("car.bmp", "r");
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
	free_bmp(image1);
	fclose(fp1);
	// State 02: check error return false
	FILE* fp2 = fopen("gray_earth.bmp", "r");
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
	free_bmp(image2);
	fclose(fp2);
	// State 03: header is correct
	FILE* fp3 = fopen("6x6_24bit.bmp", "r");
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
	bool check_header3 = check_bmp_header(&image3->header, fp3);
	if (!check_header3) {
		printf("check_header failed\n");
	}
	else {
		printf("check_header succeed\n");
	}
	free_bmp(image3);
	fclose(fp3);
	// State 04: write_bmp fp == NULL
	FILE* fp4 = fopen("6x6_24bit.bmp", "r");
	char* error4 = NULL;
	BMPImage* image4 = NULL;
	if (fp4 == NULL) {
		printf("fopen error\n");
	}
	image4 = read_bmp(fp4, &error4);
	write_bmp(NULL, image4, &error4);
	if (error4 != NULL) {
		printf("have the following issue\n");
		printf("%s\n", error4);
		free(error4);
	}
	free_bmp(image4);
	fclose(fp4);
	// State 05: write_bmp
	FILE* fp5 = fopen("car.bmp", "r");
	char* error5 = NULL;
	BMPImage* image5 = NULL;
	if (fp5 == NULL) {
		printf("fopen error\n");
	}
	image5 = read_bmp(fp5, &error5);
	FILE* fp5_w = fopen("car_new.bmp", "w");
	int check_write = 0;
	check_write = write_bmp(fp5_w, image5, &error5);
	if (check_write) {
		printf("write car.bmp succeed\n");
	}
	if (error5 != NULL) {
		printf("%s\n", error5);
		free(error5);
	}
	free_bmp(image5);
	fclose(fp5);
	fclose(fp5_w);
	// State 06: crop_bmp run-time error
	FILE* fp6 = fopen("6x6_24bit.bmp", "r");
	char* error6 = NULL;
	BMPImage* image6 = NULL;
	if (fp6 == NULL) {
		printf("fopen error\n");
	}
	image6 = read_bmp(fp6, &error6);
	BMPImage* crop_image6 = crop_bmp(image6, 10,10,2,2, &error6);
	if (error6 != NULL) {
		printf("%s\n", error6);
		free(error6);
	}
	if (crop_image6 != NULL) {
		free_bmp(crop_image6);
	}
	free_bmp(image6);
	fclose(fp6);
	// State 07: crop_bmp succeed
	FILE* fp7 = fopen("6x6_24bit.bmp", "r");
	char* error7 = NULL;
	char* error7_1 = NULL;
	BMPImage* image7 = NULL;
	if (fp7 == NULL) {
		printf("fopen error\n");
	}
	image7 = read_bmp(fp7, &error7);
	BMPImage* crop_image7 = crop_bmp(image7, 0,0,4,4,&error7_1);
	if (error7 != NULL) {
		printf("%s\n", error7);
		free(error7);
	}
	if (error7_1 != NULL) {
		printf("%s\n", error7_1);
		free(error7_1);
	}
	free_bmp(crop_image7);
	free_bmp(image7);
	fclose(fp7);
	// State 08: try different picture
	FILE* fp8 = fopen("airplane.bmp", "r");
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
	free_bmp(image8);
	fclose(fp8);
	// State 09: try different picture
	FILE* fp9 = fopen("purduetrain.bmp", "r");
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
	free_bmp(image9);
	fclose(fp9);
	// State 10: write a different picture
	FILE* fp10 = fopen("purduetrain.bmp", "r");
	FILE* fp10_w = fopen("purduetrain_new.bmp", "w");
	char* error10 = NULL;
	BMPImage* image10 = NULL;
	if (fp10 == NULL) {
		printf("fopen error\n");
	}
	image10 = read_bmp(fp10, &error10);
	int check_write10 = 0;
	check_write10 = write_bmp(fp10_w, image10, &error10);
	if (check_write10) {
		printf("write car.bmp succeed\n");
	}
	if (error10 != NULL) {
		printf("%s\n", error10);
		free(error10);
	}
	free_bmp(image10);
	fclose(fp10);
	fclose(fp10_w);
	// State 11: write_bmp with runtime error
	FILE* fp11 = fopen("purduetrain.bmp", "r");
	char* error11 = NULL;
	BMPImage* image11 = NULL;
	if (fp11 == NULL) {
		printf("fopen error\n");
	}
	image11 = read_bmp(fp11, &error11);
	int check_write11 = 0;
	check_write11 = write_bmp(NULL, image11, &error11);
	if (check_write11) {
		printf("write car.bmp succeed\n");
	}
	if (error11 != NULL) {
		printf("%s\n", error11);
		free(error11);
	}
	free_bmp(image11);
	fclose(fp11);
	// State 12: crop_bmp and write_bmp
	FILE* fp12 = fopen("purduetrain.bmp", "r");
	FILE* fp12_w = fopen("purduetrain_crop.bmp", "w");
	char* error12 = NULL;
	BMPImage* image12 = NULL;
	if (fp12 == NULL) {
		printf("fopen error\n");
	}
	image12 = read_bmp(fp12, &error12);
	if (error12 != NULL) {
		printf("%s\n", error12);
		free(error12);
	}
	BMPImage* crop_image12 = crop_bmp(image12, 1,1,300,300, &error12);
	if (error12 != NULL) {
		printf("%s\n", error12);
		free(error12);
	}
	int check_write12 = write_bmp(fp12_w, crop_image12, &error12);
	if (check_write12) {
		printf("write car.bmp succeed\n");
	}
	if (error12 != NULL) {
		printf("%s\n", error12);
		free(error12);
	}
	free_bmp(image12);
	free_bmp(crop_image12);
	fclose(fp12);
	fclose(fp12_w);
	return EXIT_SUCCESS;
}
