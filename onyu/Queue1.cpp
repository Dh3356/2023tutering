#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student {
	char name[20];
	int id;
};
struct LinkedList {
	struct Student data;
	LinkedList* next;
}typedef LinkedList;
struct Queue {
	LinkedList* front;
	LinkedList* rear;
	int size;
	int maxSize;
}typedef Queue;

void PRINTALL(Queue* queue) {
	LinkedList* current = queue->front;

	if (current == NULL) {
		printf("NULL\n");
	}
	else {
		while (current != NULL) {
			printf("�̸� : %s �й�: %d\n", current->data.name, current->data.id);
			current = current->next;
		}
	}
}
int isFull(Queue* queue) {
	return queue->size == queue->maxSize;
}
void enqueue(Queue* queue) {
	int id;
	char name[20];
	printf("�̸��̶� �й��� �Է��ϼ���\n");
	scanf("%s", name);
	scanf("%d", &id);

	if (isFull(queue)) {
		printf("������\n");
		return;
	}
	else {
		LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));
		newLinkedList->data.id = id;
		//		newLinkedList->data.name = name;
		strcpy(newLinkedList->data.name, name);
		newLinkedList->next = NULL;

		if (queue->rear == NULL) {
			queue->front = newLinkedList;
			queue->rear = newLinkedList;
		}
		else {
			queue->rear->next = newLinkedList;
			queue->rear = newLinkedList;
		}
		queue->size++;
	}
}
void menu(Queue* queue) {
	int choice = 0;
	printf("1. �л��߰�\n2.����л� ������� ����� ����\n");
	scanf("%d", &choice);
	while (1) {
		if (choice == 1) {
			enqueue(queue);
		}
		else if (choice == 2) {
			PRINTALL(queue);
			break;
		}
		printf("1. �л��߰�\n2.����л� ������� ����� ����\n");
		scanf("%d", &choice);

	}
}
int init(Queue** queue, int maxSize) {
	*queue = (Queue*)malloc(sizeof(Queue));
	if (*queue == NULL) {
		return 0;
	}
	(*queue)->front = NULL;
	(*queue)->rear = NULL;
	(*queue)->size = 0;
	(*queue)->maxSize = maxSize;
	return 1;
}
int main() {
	//�л� �����͸� �����ϴ� Queue�� �����, �л� �����͸� �߰��� ��, ����ϴ� ���α׷��� ������
	//�߰��� �� �ִ� �л��� �ִ� 20���̴�.
	// 
	//�޴��� ������ ����. 
	//1. �л� �߰�
	//2. ��� �л� ������� ��� �� ����
	//
	//Queue, LinkedList, Student�� ���� �����ؾ� �Ѵ�.
	//��� ���� �Լ��� �����ؾ� �Ѵ�.
	// 
	//main �Լ��� ������ ����.
	Queue* studentQueue;
	init(&studentQueue, 20);
	menu(studentQueue);
	return 0;
}