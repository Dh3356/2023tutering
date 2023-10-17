#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkedList {
	LinkedList* temp;
	LinkedList* next;
	int data;
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

int enqueue(Queue* queue, int data) {
	if (isFull(queue)) {
		return 0;
	}
	else {
		LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));
		newLinkedList->data = data;
		newLinkedList->next = NULL;
		if (isEmpty(queue)) {
			queue->front = newLinkedList;
			queue->rear = newLinkedList;
		}
		else {
			queue->rear->next = newLinkedList;
			queue->rear = newLinkedList;
		}
		(queue->size)++;
		return data;

	}
}

int dequeue(Queue* queue) {
	if (isEmpty(queue)) {
		return -1;
	}
	else {
		LinkedList* temp = queue->front;
		int data = temp->data;
		queue->front = temp->next;
		free(temp);
		(queue->size)--;
		return data;
	}
}

int peek(Queue* queue) {
	if (isEmpty(queue)) {
		return -1;
	}
	else {
		return queue->front->data;
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

int main() {
	//두 개의 Queue A와 B가 주어졌을 때, Queue A에는 입력받은 N개의 정수가 순서대로 들어 있고, Queue B에도 입력받은 N개의 정수가 순서대로 들어 있다.
	//Queue B의 순서를 기반으로 Queue A를 재배열하는 프로그램을 작성해보자.
	//Queue A가 [2, 5, 1, 8, 7]이고 Queue B가 [3, 1, 4, 5, 2]일 경우, Queue A를 Queue B의 순서대로 재배열하면 [1, 2, 8, 7, 5]가 된다.
	//입출력 예시
	//입력
	//5
	//2 5 1 8 7
	//3 1 4 5 2
	//출력
	//1 2 8 7 5

	int N;
	printf("개수 입력:");
	scanf("%d", &N);

	Queue* queueA;
	Queue* queueB;
	Queue* tempA;
	Queue* Num;
	init(&Num, N);
	init(&queueA, N);
	init(&queueB, N);
	init(&tempA, N);

	printf("\nA입력:");
	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d", &num);
		enqueue(queueA, num);
		enqueue(Num, i);
	}
	printf("\nB입력:");
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		enqueue(queueB, num);
	}

	while (isEmpty(queueA) == 0) {
		if (peek(Num) == peek(queueB)) {
			enqueue(tempA, queueA->front->data);
			dequeue(queueA);
			dequeue(Num);
			dequeue(queueB);
		}
		else {
			enqueue(queueA, dequeue(queueA));
			enqueue(Num, dequeue(Num));
		}
	}

	while (isEmpty(tempA) == 0) {
		printf("%d ", dequeue(tempA));
	}

	return 0;
}