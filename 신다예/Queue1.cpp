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
		//printf("삭제성공\n");
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
	printf("학생의 이름, 학번을 입력해주세요.\n");
	scanf("%s %d", &nameTemp, &stuTemp);

	Student newStudent;
	strcpy(newStudent.name, nameTemp);
	newStudent.stuNum = stuTemp;
	enqueue(queue, newStudent);

}

void menu(Queue** queue) {
	int choice;

	while (1) {
		printf("1.학생추가, 2.모든 학생 출력 후 종료\n");
		scanf("%d", &choice);

		if (choice == 1) {
			stuEnqueue(*queue);
			//printf("%d번\n",  (*queue)->size);

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
	//학생 데이터를 저장하는 Queue를 만들고, 학생 데이터를 추가한 후, 출력하는 프로그램을 만들자
	//추가할 수 있는 학생은 최대 20명이다.
	// 
	//메뉴는 다음과 같다. 
	//1. 학생 추가
	//2. 모든 학생 순서대로 출력 후 종료
	//
	//Queue, LinkedList, Student를 전부 구현해야 한다.
	//모든 것을 함수로 구현해야 한다.
	// 
	//main 함수는 다음과 같다.
	Queue* studentQueue;
	init(&studentQueue, 20);
	menu(&studentQueue);
	return 0;
}