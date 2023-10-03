#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct LinkedList {
	int data;
	LinkedList* next;
} typedef LinkedList;
void PRINTALL(LinkedList* list) {
	LinkedList* now = list;

	while (now != NULL) {

		printf("%d \n", now->data);

		now = now->next;
	}
}
void INPUT(LinkedList** list, int input) {
	LinkedList* newLink = (LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* head = *list;

	newLink->data = input;
	newLink->next = NULL;

	if (head == NULL) {
		*list = newLink;
	}
	else {
		newLink->next = *list;
		*list = newLink;
	}




}
int main() {

	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	list->next = NULL;

	int input = 0;

	while (scanf("%d", &input) != EOF) {
		INPUT(&list, input);
	}

	PRINTALL(list);

	return 0;
}