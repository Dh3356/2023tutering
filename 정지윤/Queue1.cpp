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
		printf("큐 다참\n");
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
		printf("큐가 비어 있습니다.\n");
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
	printf("이름: %s, 학번: %d\n", student.name, student.id);
}

void menu(Queue* studentQueue) {
	int menu = 0;

	while (menu != 2) {
		
		printf("1. 학생 추가\n");
		printf("2. 모든 학생 순서대로 출력 후 종료\n");

		scanf("%d", &menu);

		if (menu == 1) {
			if (!isFull(studentQueue)) {
				Student newStudent;
				printf("학생의 이름과 학번을 입력하세요: \n");
				scanf("%s %d", newStudent.name, &newStudent.id);
				enQueue(studentQueue, newStudent);
				printf("저장됨\n");
			}
			else {
				printf("다참\n");
			}
		}

		else if (menu == 2) {
			if (!isEmpty(studentQueue)) {
				Student student = deQueue(studentQueue);
				printAllStu(student);
			}
			printf("종료합니다 \n");
		}
		else {
			printf("다시 입력\n");
		}
	}
}


int main(){

	Queue* studentQueue;
	init(&studentQueue, 20);
	menu(studentQueue);
	return 0;
}