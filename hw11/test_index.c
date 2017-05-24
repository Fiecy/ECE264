#include "index.h"

int main(int argc, char* argv[]) {

//  case 1 normal test
	Index index = create_index();
	put(&index, "Momo", "ECE301");
	put(&index, "YL", "ECE264");
	put(&index, "Momo", "ECE362");
	put(&index, "YL", "ECE362");
	put(&index, "HYF", "VIP");
	put(&index, "HYF", "ECE362");
	put(&index, "YL", "ECE264");
	put(&index, "Liangts", "ECE362");
	put(&index, "YL", "ECE337");
	put(&index, "Hex", "ECE362");
	put(&index, "Hex", "ECE337");
	put(&index, "HYF", "ECE264");
	if (index.root != NULL) {

		printf("root is %s\n", index.root->word);
		int count = 0;
		char** get1 = NULL;
		IndexBSTNode* hold = index.root;
		get1 = get(&index, &count, hold->word);
		printf("%s's course list:%d\n", hold->word, count);
		for (int i = 0; i < count; i++) {
			printf("        %s\n", get1[i]);
		}
		free(get1);
		
	
		hold = index.root;
		count = 0;
		while (hold->left != NULL) {
		hold = hold->left;
		char** get2 = get(&index, &count, hold->word);
		printf("Left: %s's course list:%d\n", hold->word, count);
		for (int i = 0; i < count; i++) {
			printf("        %s\n", get2[i]);
		}
		free(get2);	

			while (hold->right != NULL) {
			hold = hold->right;
			get2 = get(&index, &count, hold->word);
			printf("Right: %s's course list:%d\n", hold->word, count);
			for (int i = 0; i < count; i++) {
				printf("        %s\n", get2[i]);
			}
			free(get2);
			}
		}

		hold = index.root;
		count = 0;
		while (hold->right != NULL) {
		hold = hold->right;
		char** get2 = get(&index, &count, hold->word);
		printf("Right: %s's course list:%d\n", hold->word, count);
		for (int i = 0; i < count; i++) {
			printf("        %s\n", get2[i]);
		}
		free(get2);
			while (hold->left != NULL) {
			hold = hold->left;
			get2 = get(&index, &count, hold->word);
			printf("Left: %s's course list:%d\n", hold->word, count);
			for (int i = 0; i < count; i++) {
				printf("        %s\n", get2[i]);
			}
			free(get2);	
			}
		}
	}
	else {
		printf("index is empyt\n");
	}
	int count = 5;
	char** get3 = get(&index, &count, "NOT FOUND");
	if (get3 == NULL) {
		printf("WORD NOT FOUND, count = %d\n", count);
	}
	else {
		printf("ERROR, SHOULD RETURN NULL");
	}

	free_index(&index);
	return EXIT_SUCCESS;
}
