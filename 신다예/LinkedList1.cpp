#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct LinkedList {
	int data;
	LinkedList* next;
} typedef LinkedList;


void getData(LinkedList** linkedList) {
	int data=0;
	
	while (scanf("%d", &data) != EOF) {
		if (*linkedList == NULL) {
			*linkedList = (LinkedList*)malloc(sizeof(LinkedList));
			(*linkedList)->data = data;
			(*linkedList)->next = NULL;
		}
		else {
			LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));
			newLinkedList->data = data;
			newLinkedList->next = (*linkedList);
			(*linkedList) = newLinkedList;
		}

	}
	

}

void printData(LinkedList* linkedList) {
	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
	head = linkedList;
	while (head != NULL) { 
		printf("%d -> ", head->data);
		head = head->next;
		
	}
	
}

int main() {
	//LinkedList�� �̿��Ͽ� ����ڰ� EOF(Windows������ Ctrl + Z�� 3�� �Է��ϸ� ��)�� �Է��� ������ 
	//�Է¹��� ���� �����͸� Linked List�� �������� �����ϰ�(a->b ���� c �Է� �� c->a->b)
	//����� �����͸� ������� ���� ����ϴ� ���α׷��� �ۼ�.
	//�����͸� �ִ� �Լ� �ۼ�, �����͸� ���� ����ϴ� �Լ� �ۼ�

	LinkedList* linkedList;
	
	getData(&linkedList);
	printData(linkedList);





	return 0;
}