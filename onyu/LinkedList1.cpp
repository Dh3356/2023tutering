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

	//LinkedList�� �̿��Ͽ� ����ڰ� EOF(Windows������ Ctrl + Z�� 3�� �Է��ϸ� ��)�� �Է��� ������ 
	//�Է¹��� ���� �����͸� Linked List�� ������� �����ϰ�
	//����� �����͸� ������ ��, ���� ����ϴ� ���α׷� �ۼ�.
	//�����͸� �ִ� �Լ� �ۼ�, �����ϴ� �Լ�, �����͸� ���� ����ϴ� �Լ� �ۼ�

	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

	int input = 0;
	while (scanf("%d", &input) != EOF) {
		INPUT(list, input);
	}

	PRINTALL(list);
	return 0;
}