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
void INPUT(LinkedList* list, int input) {
	LinkedList* now = (LinkedList*)malloc(sizeof(LinkedList));

	now->data = input;
	now->next = list->next;
	list->next = now;
}
int main() {

	//LinkedList를 이용하여 사용자가 EOF(Windows에서는 Ctrl + Z를 3번 입력하면 됨)를 입력할 때까지 
	//입력받은 정수 데이터를 Linked List에 순서대로 저장하고
	//저장된 데이터를 정렬한 후, 전부 출력하는 프로그램 작성.
	//데이터를 넣는 함수 작성, 정렬하는 함수, 데이터를 전부 출력하는 함수 작성

	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

	int input = 0;
	while (scanf("%d", &input) != EOF) {
		INPUT(list, input);
	}

	PRINTALL(list);
	return 0;
}