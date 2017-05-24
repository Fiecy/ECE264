#include "sorts.h"

int main(int argc, char* argv[]) {
	// case 1: normal test

	int array[5] = {5,2,6,1,7};
	tree_sort_array(array, sizeof(array)/sizeof(array[0]));
	printf("BST_array:\n");
	for (int i = 0; i < (sizeof(array)/ sizeof(array[0])); i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}

	int array2[5] = {5,2,6,1,7};
	merge_sort_array(array2, sizeof(array2)/sizeof(array2[0]));
	printf("merge_sort_array:\n");
	for (int i = 0; i < (sizeof(array2)/sizeof(array2[0])); i++) {
		printf("array2[%d] = %d\n", i, array2[i]);
	}

	int array3[5] = {5,2,6,1,7};
	quick_sort_array(array3, sizeof(array3)/sizeof(array3[0]));
	printf("quick sort:\n");
	for (int i = 0; i < (sizeof(array3)/sizeof(array3[0])); i++) {
		printf("array3[%d] = %d\n", i, array3[i]);
	}

	// case 2: array with 1 number
	int array4[1] = {5};
	tree_sort_array(array4, sizeof(array4)/sizeof(array4[0]));
	printf("BST_array:\n");
	for (int i = 0; i < (sizeof(array4)/ sizeof(array4[0])); i++) {
		printf("array4[%d] = %d\n", i, array4[i]);
	}

	int array5[1] = {5};
	merge_sort_array(array5, sizeof(array5)/sizeof(array5[0]));
	printf("merge_sort_array:\n");
	for (int i = 0; i < (sizeof(array5)/sizeof(array5[0])); i++) {
		printf("array5[%d] = %d\n", i, array5[i]);
	}

	int array6[1] = {5};
	quick_sort_array(array6, sizeof(array6)/sizeof(array6[0]));
	printf("quick sort:\n");
	for (int i = 0; i < (sizeof(array6)/sizeof(array6[0])); i++) {
		printf("array6[%d] = %d\n", i, array6[i]);
	}

	// case 3: array with 2 number
	int array7[2] = {5,2};
	tree_sort_array(array7, sizeof(array7)/sizeof(array7[0]));
	printf("BST_array:\n");
	for (int i = 0; i < (sizeof(array7)/ sizeof(array7[0])); i++) {
		printf("array7[%d] = %d\n", i, array7[i]);
	}

	int array8[2] = {5,2};
	merge_sort_array(array8, sizeof(array8)/sizeof(array8[0]));
	printf("merge_sort_array:\n");
	for (int i = 0; i < (sizeof(array8)/sizeof(array8[0])); i++) {
		printf("array8[%d] = %d\n", i, array8[i]);
	}

	int array9[2] = {5,2};
	quick_sort_array(array9, sizeof(array9)/sizeof(array9[0]));
	printf("quick sort:\n");
	for (int i = 0; i < (sizeof(array9)/sizeof(array9[0])); i++) {
		printf("array9[%d] = %d\n", i, array9[i]);
	}

	return EXIT_SUCCESS;
}
