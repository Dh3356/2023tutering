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
	//LinkedList�� �̿��Ͽ� ����ڰ� EOF(Windows������ Ctrl + Z�� 3�� �Է��ϸ� ��)�� �Է��� ������ 
	//�Է¹��� ���� �����͸� Linked List�� ������� �����ϰ�
	//����� �����͸� ������ ��, ���� ����ϴ� ���α׷� �ۼ�.
	//�����͸� �ִ� �Լ� �ۼ�, �����ϴ� �Լ�, �����͸� ���� ����ϴ� �Լ� �ۼ�
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