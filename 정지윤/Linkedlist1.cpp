#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkedList {
	int data;
	struct LinkedList* next;
} typedef LinkedList;

 LinkedList* addData(LinkedList* LinkedList1, int data){
	//���� ó�� LinkedList�� LinkedList�� �ּҸ� ����
	 LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));

	if (newLinkedList == NULL) {
		printf("����\n");
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
	//LinkedList�� �̿��Ͽ� ����ڰ� EOF(Windows������ Ctrl + Z�� 3�� �Է��ϸ� ��)�� �Է��� ������ 
	//�Է¹��� ���� �����͸� Linked List�� �������� �����ϰ�(a->b ���� c �Է� �� c->a->b)
	//����� �����͸� ������� ���� ����ϴ� ���α׷��� �ۼ�.
	//�����͸� �ִ� �Լ� �ۼ�, �����͸� ���� ����ϴ� �Լ� �ۼ�
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