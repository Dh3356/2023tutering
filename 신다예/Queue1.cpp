#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
	char name[100];
	int stuNum;
}typedef Student;

struct LinkedList {
	LinkedList* temp;
	LinkedList* next;
	Student data;
} typedef LinkedList;

struct Queue {
	LinkedList* front;
	LinkedList* rear;
	int size;
	int maxSize;
} typedef Queue;

int init(Queue** queue, int maxSize) {
	*queue = (Queue*)malloc(sizeof(Queue));
	if (*queue == NULL) {
		return 0;
	}
	(*queue)->front = NULL;
	(*queue)->rear = NULL;
	(*queue)->maxSize = maxSize;
	(*queue)->size = 0;
	return 1;
}

int isEmpty(Queue* queue) {
	return queue->size == 0;
}

int isFull(Queue* queue) {
	return queue->size == queue->maxSize;
}

void enqueue(Queue* queue, Student data) {
	if (isFull(queue)) {
		return;
	}
	else {
		LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));

		newLinkedList->next = NULL;
		newLinkedList->data = data;

		if (isEmpty(queue)) {
			queue->front = newLinkedList;
			queue->rear = newLinkedList;
		}
		else {
			queue->rear->next = newLinkedList;
			queue->rear = newLinkedList;
		}
		(queue->size)++;
	}
}

void dequeue(Queue* queue) {
	if (isEmpty(queue)) {
		return;
	}
	else {
		LinkedList* temp = queue->front;
		Student student = temp->data;

		printf("%s %d\n", student.name, student.stuNum);

		queue->front = temp->next;
		free(temp);

		(queue->size)--;
		//printf("��������\n");
	}
}


int freeQueue(Queue** queue) {
	if (*queue == NULL) {
		return 0;
	}
	else {
		while (!isEmpty(*queue)) {
			dequeue(*queue);
		}
		free(*queue);
		return 1;
	}
}

void stuEnqueue(Queue* queue) {
	char nameTemp[100];
	int stuTemp;
	printf("�л��� �̸�, �й��� �Է����ּ���.\n");
	scanf("%s %d", &nameTemp, &stuTemp);

	Student newStudent;
	strcpy(newStudent.name, nameTemp);
	newStudent.stuNum = stuTemp;
	enqueue(queue, newStudent);

}

void menu(Queue** queue) {
	int choice;

	while (1) {
		printf("1.�л��߰�, 2.��� �л� ��� �� ����\n");
		scanf("%d", &choice);

		if (choice == 1) {
			stuEnqueue(*queue);
			//printf("%d��\n",  (*queue)->size);

			continue;
		}
		else if (choice == 2) {
			while (isEmpty(*queue) == 0) {
				dequeue(*queue);
			}
			break;
		}
	}

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
	menu(&studentQueue);
	return 0;
}