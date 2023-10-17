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
			printf("이름 : %s 학번: %d\n", current->data.name, current->data.id);
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
	printf("이름이랑 학번을 입력하세요\n");
	scanf("%s", name);
	scanf("%d", &id);

	if (isFull(queue)) {
		printf("가득참\n");
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
	printf("1. 학생추가\n2.모든학생 순서대로 출력후 종료\n");
	scanf("%d", &choice);
	while (1) {
		if (choice == 1) {
			enqueue(queue);
		}
		else if (choice == 2) {
			PRINTALL(queue);
			break;
		}
		printf("1. 학생추가\n2.모든학생 순서대로 출력후 종료\n");
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
	menu(studentQueue);
	return 0;
}