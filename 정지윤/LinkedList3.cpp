#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct LinkedList {
	int data;
	LinkedList* next;
} typedef LinkedList;

LinkedList* addData(LinkedList* LinkedList1, int data) {
	LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));

	if (newLinkedList == NULL) {
		printf("����\n");
	}

	newLinkedList->data = data;
	newLinkedList->next = LinkedList1;

	return newLinkedList;
}

void sortData(LinkedList* LinkedList1, int *num) {
	int temp = 0;
	
	if (LinkedList1 == NULL) {
		return;
	}
		for (int i = 0; i < (*num) - 1; i++) {
			LinkedList* first = LinkedList1;
			for (int j = 0; j < (*num)-i-1; j++) {
				if (first->data > first->next->data) {
					temp = first->data;
					first->data = first->next->data;
					first->next->data = temp;
				}
				first = first->next;
			}
		}
	
}

void printData(LinkedList* LinkedList1) {
	LinkedList* first = LinkedList1;
	while (first != NULL) {
		printf("%d\n", first->data);
		first = first->next;
	}
}

int main() {
	LinkedList* LinkedList1 = NULL;
	int data;
	int num = 0;
	
	//����� �����͸� ������ ��, ���� ����ϴ� ���α׷� �ۼ�.
	//�����͸� �ִ� �Լ� �ۼ�, �����ϴ� �Լ�, �����͸� ���� ����ϴ� �Լ� �ۼ�
	while (scanf("%d", &data) != EOF) {
		LinkedList1 = addData(LinkedList1, data);
		num++;
	}
	sortData(LinkedList1, &num);
	printData(LinkedList1);

	while (LinkedList1 != NULL) {
		LinkedList* temp = LinkedList1;
		LinkedList1 = LinkedList1->next;
		free(temp);
	}
	return 0;
}