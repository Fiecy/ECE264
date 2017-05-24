#include <sorts.h>

int main(int argc, char* argv[]) {
	// case 1 normal test
	int* array = {5,2,6,8,0}
	tree_sort_array(array, sizeof(array));

	return EXIT_SUCCESS;
}
