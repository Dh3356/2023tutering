#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Student {
	char name[20];
	int id;
}typedef Student;

struct LinkedList {
	Student data;
	LinkedList* next;
} typedef LinkedList;

struct Queue {
	LinkedList* front;
	LinkedList* rear;
	int size;
	int maxSize;
}typedef Queue;

int init(Queue** queue, int maxSize) {
	*queue = (Queue*)malloc(sizeof(Queue));
	if (*queue == NULL) {
		return 0;
	}
	(*queue)->maxSize = maxSize;
	(*queue)->front = NULL;
	(*queue)->rear = NULL;
	(*queue)->size = 0;

	return 1;
}

int isEmpty(Queue* queue) {
	return queue->size == 0;
}

int isFull(Queue* queue) {
	return queue->size == queue->maxSize;
}

int enQueue(Queue* queue, Student student) {
	if (isFull(queue)) {
		printf("ť ����\n");
		return 0;
	}
	LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));
	newLinkedList->data = student;
	newLinkedList->next = NULL;

	if (isEmpty(queue)) {
		queue->front = queue->rear = newLinkedList;
	}
	else {
		queue->rear->next = newLinkedList;
		queue->rear = newLinkedList;
	}
	queue->size++;
	return 1;
}

Student deQueue(Queue* queue) {
	if (isEmpty(queue)) {
		printf("ť�� ��� �ֽ��ϴ�.\n");
	}
	LinkedList* temp = queue->front;
	Student student = temp->data;

	if (queue->front == queue->rear) {
		queue->front = queue->rear = NULL;
	}
	else {
		queue->front = queue->front->next;
	}
	
	free(temp);
	queue->size--;

	return student;
}

void printAllStu(Student student) {
	printf("�̸�: %s, �й�: %d\n", student.name, student.id);
}

void menu(Queue* studentQueue) {
	int menu = 0;

	while (menu != 2) {
		
		printf("1. �л� �߰�\n");
		printf("2. ��� �л� ������� ��� �� ����\n");

		scanf("%d", &menu);

		if (menu == 1) {
			if (!isFull(studentQueue)) {
				Student newStudent;
				printf("�л��� �̸��� �й��� �Է��ϼ���: \n");
				scanf("%s %d", newStudent.name, &newStudent.id);
				enQueue(studentQueue, newStudent);
				printf("�����\n");
			}
			else {
				printf("����\n");
			}
		}

		else if (menu == 2) {
			if (!isEmpty(studentQueue)) {
				Student student = deQueue(studentQueue);
				printAllStu(student);
			}
			printf("�����մϴ� \n");
		}
		else {
			printf("�ٽ� �Է�\n");
		}
	}
}


int main(){

	Queue* studentQueue;
	init(&studentQueue, 20);
	menu(studentQueue);
	return 0;
}