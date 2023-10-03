#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct LinkedList {
	int data;
	LinkedList* next;
} typedef LinkedList;
void PRINTALL(LinkedList* head) {
	LinkedList* now = head;
	while (now != NULL) {
		printf("%d \n", now->data);
		now = now->next;
	}
}

void BubbleSort(LinkedList* head, int size) {
	LinkedList* move;

	move = head;
	move->data = 0;
	move = move->next;

	for (int i = 0; i < size; i++) {
		if (move == NULL) {
			break;
		}
		for (int j = 0; j < size - 1 - i; j++) {
			if (move->data > move->next->data) {
				int temp;
				temp = move->data;
				move->data = move->next->data;
				move->next->data = temp;
			}
			move = move->next;
		}
		move = head->next;
	}
}
void INPUTWORD(LinkedList** list, int input) {

	LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
	LinkedList* head = *list;

	newList->data = input;
	newList->next = NULL;

	if (*list == NULL) {
		*list = newList;
	}
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = newList;
}
int main() {
	//LinkedList를 이용하여 사용자가 EOF(Windows에서는 Ctrl + Z를 3번 입력하면 됨)를 입력할 때까지 
	//입력받은 정수 데이터를 Linked List에 순서대로 저장하고
	//저장된 데이터를 정렬한 후, 전부 출력하는 프로그램 작성.
	//데이터를 넣는 함수 작성, 정렬하는 함수, 데이터를 전부 출력하는 함수 작성
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	int data = 0;
	list->next = NULL;
	int size = 0;
	while (scanf("%d", &data) != EOF) {
		INPUTWORD(&list, data);
		size++;
	}

	BubbleSort(list, size);
	PRINTALL(list);

	return 0;
}