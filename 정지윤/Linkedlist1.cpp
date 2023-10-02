#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkedList {
	int data;
	struct LinkedList* next;
} typedef LinkedList;

 LinkedList* addData(LinkedList* LinkedList1, int data){
	//제일 처음 LinkedList에 LinkedList의 주소를 넣음
	 LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));

	if (newLinkedList == NULL) {
		printf("실패\n");
	}

	newLinkedList->data = data;
	newLinkedList->next =LinkedList1;
	return newLinkedList;

 }

void printData( LinkedList* LinkedList1){
 LinkedList* first = LinkedList1;
	while (first!=NULL){
		printf("%d\n", first->data);
		first = first->next;
	}
}

int main(){
	LinkedList* LinkedList1 = NULL;
	int data;
	//LinkedList를 이용하여 사용자가 EOF(Windows에서는 Ctrl + Z를 3번 입력하면 됨)를 입력할 때까지 
	//입력받은 정수 데이터를 Linked List에 역순으로 저장하고(a->b 에서 c 입력 시 c->a->b)
	//저장된 데이터를 순서대로 전부 출력하는 프로그램을 작성.
	//데이터를 넣는 함수 작성, 데이터를 전부 출력하는 함수 작성
	while (scanf("%d", &data) != EOF) {
		LinkedList1 = addData(LinkedList1, data);
	}
	printData(LinkedList1);

	while (LinkedList1 != NULL) {
		LinkedList* temp = LinkedList1;
		LinkedList1 = LinkedList1->next;
		free(temp);
	}

	return 0;
}