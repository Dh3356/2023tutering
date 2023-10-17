#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct LinkedList {
	int data;
	LinkedList* next;
} typedef LinkedList;

struct Queue {
	LinkedList* front;
	LinkedList* rear;
}typedef Queue;

int init(Queue* queue) {
	queue = (Queue*)malloc(sizeof(Queue));
	if (queue == NULL) {
		return 0;
	}
	(queue)->front = NULL;
	(queue)->rear = NULL;
	return 1;
}

void enQueue(Queue* queue, int data) {
	
		LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));
		newLinkedList->data = data;
		newLinkedList->next = NULL;
		if (queue->rear==NULL) {
			queue->front = newLinkedList;
			queue->rear = newLinkedList;
		}
		else {
			queue->rear->next = newLinkedList;
			queue->rear = newLinkedList;
		}

}

int deQueue(Queue* queue) {
	if (queue->front==NULL) {
		return -1;
	}
	else {
		LinkedList* temp = queue->front;
		int data = temp->data;
		queue->front = queue->front->next;

		if (queue->front == NULL) {
			queue->rear = NULL;
		}

		free(temp);
		return data;
	}
}

int main() {
	Queue queueA;
	Queue queueB;

	Queue reQueue;//재배열한 큐
	init(&reQueue);

	int num;

	init(&queueA);
	init(&queueB);

	//일단 사이즈 입력
	int numSize = 0;
	scanf("%d", &numSize);

	//A와 B에 숫자를 입력
	for (int i = 0; i < numSize; i++) {
		scanf("%d", &num);
		enQueue(&queueA, num);
	}

	for (int i = 0; i < numSize; i++) {
		scanf("%d", &num);
		enQueue(&queueB, num);
	}

	//A의 숫자를 B에 의해서 재배열
	while (queueB.front!=NULL) {
		int B = deQueue(&queueB);
		//일단 하나를 빼내고

		while (queueA.front->data!=B) {
			int A = deQueue(&queueA);
			//A에 있는걸 빼서
			enQueue(&reQueue, A);
			//새로운 큐에 재배열
		}
		int A = deQueue(&queueA);
		enQueue(&reQueue, A);
	}
	while (queueA.front!=NULL) {
		int A = deQueue(&queueA);
		enQueue(&reQueue, A);
	}

	//재배열된 결과를 출력
	while (reQueue.front != NULL) {
		int numPrint = deQueue(&reQueue);
		printf("%d ", numPrint);
	}
	return 0;
}