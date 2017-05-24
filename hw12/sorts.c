#include "sorts.h"

// helper functions
// BST helper func
void _create_BSTNode(BSTNode** Node, int value) {
	if (*Node == NULL) {
		*Node = malloc(sizeof(**Node));
		(*Node)->left = NULL;
		(*Node)->right = NULL;
		(*Node)->value = value;
	}
	else if (value > (*Node)->value) {
		_create_BSTNode(&((*Node)->right), value);
	}
	else {
		_create_BSTNode(&((*Node)->left), value);
	}
}

void _return_BSTarray(BSTNode* Node, int* array, int* count) {
	if (Node->left != NULL) {
		_return_BSTarray(Node->left, array, count);
	}
	array[*count] = Node->value;
	*count = *count + 1;
	if (Node->right != NULL) {
		_return_BSTarray(Node->right, array, count);
	}
}

void _free_bst(BSTNode* Node) {
	if (Node != NULL) {
		if (Node->left != NULL) {
			_free_bst(Node->left);
		}
		if (Node->right != NULL) {
			_free_bst(Node->right);
		}
		free(Node);
	}
	return;
}
// merge sort helper func
void _build_list(ListNode** head, ListNode** tail, int value) {
	if (*head == NULL) {
		*head = malloc(sizeof(**head));
		(*head)->next = NULL;
		(*head)->value = value;
		(*tail) = (*head);
	}
	else {
		_build_list(&((*head)->next), tail, value);
	}
}

ListNode* _merge_sort(ListNode* Node1, ListNode* Node2) {
	if (Node1 == NULL) {
		return Node2;
	}
	if (Node2 == NULL) {
		return Node1;
	}
	ListNode* hold = NULL;
	if (Node1->value < Node2->value) {
		hold = Node1;
		hold->next = _merge_sort(Node1->next, Node2);
	}
	else {
		hold = Node2;
		hold->next = _merge_sort(Node2->next, Node1);
	}
	return hold;
}

void _return_list(ListNode* Node, int* array, int* count) {
	array[*count] = Node->value;
	*count = *count + 1;
	if (Node->next != NULL) {
		_return_list(Node->next, array, count);
	}
}

void _free_list(ListNode* Node) {
	if (Node != NULL) {
		_free_list(Node->next);
	}
	free(Node);
	return;
}
// begining of functions
// BST
void empty_bst(BST* bst) {
	if (bst->root != NULL) {
		_free_bst(bst->root);
	}
	return;
}

BST create_bst(const int* array, int size) {
	BST bst = {.root = NULL, .size = size};
	if (size == 0 || array[0] == '\0') {
		return bst;
	}
	for (int i = 0; i < size; i++) {
		_create_BSTNode(&bst.root, array[i]);
	}
	return bst;
}

void tree_sort_array(int* array, size_t size) {
	if (size == 0) {
		return;
	}
	BST bst = create_bst(array, size);
	int count = 0;
	_return_BSTarray(bst.root, array, &count);
	empty_bst(&bst);
}
// merge sort
List create_list(const int* array, int size) {
	List list = {.head = NULL, .tail = NULL, .size = size};
	if (size == 0 || array[0] == '\0') {
		list.size = 0;
		return list;
	}
	for (int i = 0; i < size; i++) {
		_build_list(&list.head, &list.tail, array[i]);
	}
	return list;
}

void merge_sort_list(List* list) {
	if (list->size < 2) {
		return;
	}
	// break list
	List list1 = {.head = list->head, .tail = NULL, .size = list->size/2};
	ListNode* hold = list1.head;
	for (int i = 0; i < list1.size-1; i++) {
		hold = hold->next;
	}
	list1.tail = hold;
	List list2 = {.head = hold->next, .tail = list->tail, .size = list->size-list1.size};
	list1.tail->next = NULL;
	merge_sort_list(&list1);
	merge_sort_list(&list2);
	// merge
	list->head = _merge_sort(list1.head, list2.head);
	hold = list->head;
	while (hold->next != NULL) {
		hold = hold->next;
	}
	list->tail = hold;
}

void empty_list(List* list) {
	_free_list(list->head);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void merge_sort_array(int* array, size_t size) {
	if (size == 0) {
		return;
	}
	List list = create_list(array, size);
	merge_sort_list(&list);
	int count = 0;
	_return_list(list.head, array, &count);
	empty_list(&list);
}
// quick sort
int _compare(const void* a1, const void* a2) {
	int* num1 = (int*)a1;
	int* num2 = (int*)a2;
	return (*num1-*num2);
}

void quick_sort_array(int* array, size_t size) {
	if (size == 0) {
		return;
	}
	qsort(array, size, sizeof(array[0]), _compare);
	return;
}
