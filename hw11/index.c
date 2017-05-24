#include "index.h"

Index create_index() {
	Index empty = {.root = NULL, .allfilenames = NULL};
	return empty;
}

void _free_allfilenames(StringListNode* allfilenames) {
	if (allfilenames != NULL) {
		if (allfilenames->next != NULL) {
			_free_allfilenames(allfilenames->next);
		}
		free(allfilenames->filename);
		StringListNode* hold = allfilenames;
		allfilenames = NULL;
		free(hold);
	}
	return;
}

void _free_filenames(StringListNode* filenames) {
	if (filenames != NULL) {
		if (filenames->next != NULL) {
			_free_filenames(filenames->next);
		}
		StringListNode* hold = filenames;
		filenames = NULL;
		free(hold);
	}
	return;
}

void _free_root(IndexBSTNode* root) {
	if (root != NULL) {
		if (root->left != NULL) {
			_free_root(root->left);
		}
		if (root->right != NULL) {
			_free_root(root->right);
		}
		free(root->word);
		_free_filenames(root->filenames);
		IndexBSTNode* hold = root;
		root = NULL;
		free(hold);
	}
	return;
}

char* _search_allfilenames(StringListNode* allfilenames, char* filename) {
	if (allfilenames->filename == NULL) {
		allfilenames->next = NULL;
		allfilenames->filename = _strdup(filename);
		return allfilenames->filename;
	}
	else if (strcmp(filename, allfilenames->filename) == 0) {
		return allfilenames->filename;
	}
	else {
		if (allfilenames->next == NULL) {
			allfilenames->next = malloc(sizeof(StringListNode));
			allfilenames->next->filename = NULL;
		}
		return _search_allfilenames(allfilenames->next, filename);
	}
}

void _add_filename(StringListNode* allfilenames, StringListNode* filenames, char* filename) {
	if (filenames->filename == NULL) {
		filenames->next = NULL;
		filenames->filename = _search_allfilenames(allfilenames, filename);
		return;
	}
	else if (strcmp(filename, filenames->filename) == 0) {
		return;
	}
	else {
		if (filenames->next == NULL) {
			filenames->next = malloc(sizeof(StringListNode));
			filenames->next->filename = NULL;
		}
		_add_filename(allfilenames, filenames->next, filename);
	}
	return;
}

void _add_word(StringListNode* allfilenames, IndexBSTNode* Node, char* word, char* filename) {
	if (Node->word == NULL) {
		Node->word = _strdup(word);
		Node->filenames = malloc(sizeof(StringListNode));
		Node->filenames->next = NULL;
		Node->filenames->filename = NULL;
		_add_filename(allfilenames, Node->filenames, filename);
		Node->left = NULL;
		Node->right = NULL;
	}
	else if (strcmp(word, Node->word) == 0) {
		_add_filename(allfilenames, Node->filenames, filename);
	}
	else if (strcmp(word, Node->word) < 0) {
		if (Node->left == NULL) {
			Node->left = malloc(sizeof(IndexBSTNode));
			Node->left->word = NULL;
		}
		_add_word(allfilenames, Node->left, word, filename);
	}
	else if (strcmp(word, Node->word) > 0) {
		if (Node->right == NULL) {
			Node->right = malloc(sizeof(IndexBSTNode));
			Node->right->word = NULL;
		}
		_add_word(allfilenames, Node->right, word, filename);
	}
	return;
}
/*
void _build_work(StringListNode* filenames, StringListNode* original) {
	char* dummy = NULL;
	if (original->next != NULL) {
		_build_work(filenames, original->next);
	}
	if (filenames == NULL) {
		filenames = malloc(sizeof(StringListNode));
		filenames->filename = NULL;
	}
	dummy = _search_allfilenames(filenames, original->filename);
	if (dummy != NULL) {
		dummy = NULL;
	}
	return;
}

void _build_filenames(IndexBSTNode* Node, char* word, StringListNode* filenames) {
	//int cnt = 0;
	//int cnt_temp = 0;
	if (Node == NULL) {
		filenames = NULL;
		return;
	}
	else if (strcmp(word, Node->word) == 0) {
		_build_work(filenames, Node->filenames);
	}
	else if (strcmp(word, Node->word) < 0) {
		if (Node->left == NULL) {
			return;
		}
		_build_filenames(Node->left, word, filenames);
	}
	else if (strcmp(word, Node->word) > 0) {
		if (Node->right == NULL) {
			return;
		}
		_build_filenames(Node->right, word, filenames);
	}
	return ;
}
*/

int _count_word(IndexBSTNode* Node, char* word) {
	int cnt = 0;
	if (Node == NULL || Node->word == NULL) {
		return 0;
	}
	else if(strcmp(word, Node->word) == 0) {
		StringListNode* hold = Node->filenames;
		while (hold != NULL) {
			cnt++;
			hold = hold->next;
		}
		return cnt;
	}
	else if (strcmp(word, Node->word) < 0) {
		if (Node->left == NULL) {
			return 0;
		}
		return _count_word(Node->left, word);
	}
	else if (strcmp(word, Node->word) > 0) {
		if (Node->right == NULL) {
			return 0;
		}
		return _count_word(Node->right, word);
	}
	return cnt;
}

char* _return_the_filename(StringListNode* filenames, int count) {
	if (count > 0) {
		return _return_the_filename(filenames->next, count-1);
	}
	else {
		return filenames->filename;
	}
}

char* _return_filename(IndexBSTNode* Node, char* word, int count) {
	if (strcmp(word, Node->word) == 0) {
		return _return_the_filename(Node->filenames, count);
	}
	else if (strcmp(word, Node->word) < 0) {
		if (Node->left == NULL) {
			return 0;
		}
		return _return_filename(Node->left, word, count);
	}
//	else if (strcmp(word, Node->word) > 0) {
	else {
		if (Node->right == NULL) {
			return 0;
		}
		return _return_filename(Node->right, word, count);
	}
	return NULL;
}
void put(Index* index, char* word, char* filename) {
	if (index->root == NULL) {
		index->root = malloc(sizeof(IndexBSTNode)); 				// malloc
		index->root->word = NULL;
		index->allfilenames = malloc(sizeof(StringListNode));       // malloc
		index->allfilenames->filename = NULL;
		_add_word(index->allfilenames, index->root, word, filename);
	}
	else if (strcmp (word, index->root->word) == 0) {  // string equal
		_add_filename(index->allfilenames, index->root->filenames, filename);
	}
	else if (strcmp(word, index->root->word) < 0) {  // string less
		if (index->root->left == NULL) {
			index->root->left = malloc(sizeof(IndexBSTNode));
			index->root->left->word = NULL;
		}
		_add_word(index->allfilenames, index->root->left, word, filename);
	}
	else {
		if (index->root->right == NULL) {  // string larger
			index->root->right = malloc(sizeof(IndexBSTNode));
			index->root->right->word = NULL;
		}
		_add_word(index->allfilenames, index->root->right, word, filename);
	}
	return;
}

char** get(Index* index, int* count, char* word) {
	if (index->root == NULL) {
		return NULL;
	}
	int cnt = 0;
	char** filenames = NULL;
	cnt = _count_word(index->root, word);
	*count = cnt;
	if (cnt != 0) {
		filenames = malloc(sizeof(char*) * cnt + 1);
		for (int i = 0; i < cnt; i++) {
			filenames[i] = _return_filename(index->root, word, i);
		}
	return filenames;
	}
	return NULL;
}

void free_index(Index* index) {
	if (index->root != NULL) {
		_free_root(index->root);
	}
	if (index->allfilenames != NULL) {
		_free_allfilenames(index->allfilenames);
	}
	return;
}









char* _strdup(const char* s) {
	return strcpy(malloc(sizeof(*s) * strlen(s) +1), s);
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
