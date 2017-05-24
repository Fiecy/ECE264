#include "index.h"

int main(int argc, char* argv[]) {
	Index index = create_index();
	put(index, "YL", "ECE264");
	put(index, "Momo", "ECE362");
	put(index, "YL", "ECE362");
	put(index, "HYF", "ECE264");
	put(index, "HYF", "ECE362");
	put(index, "YL", "ECE264");
	put(index, "Liangts", "ECE362");
	put(index, "YL", "ECE337");
	put(index, "Hex", "ECE362");
	put(index, "Hex", "ECE337");

	int count = 0;
	char** get1 = get(index, count, "YL");
	printf("YL's course list:\n");
	while (count > 0) {
		printf("        %s\n", get1[count]);
		count--;
	}


	free_index(index);
	return EXIT_SUCCESS;
}
