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

	Queue reQueue;//��迭�� ť
	init(&reQueue);

	int num;

	init(&queueA);
	init(&queueB);

	//�ϴ� ������ �Է�
	int numSize = 0;
	scanf("%d", &numSize);

	//A�� B�� ���ڸ� �Է�
	for (int i = 0; i < numSize; i++) {
		scanf("%d", &num);
		enQueue(&queueA, num);
	}

	for (int i = 0; i < numSize; i++) {
		scanf("%d", &num);
		enQueue(&queueB, num);
	}

	//A�� ���ڸ� B�� ���ؼ� ��迭
	while (queueB.front!=NULL) {
		int B = deQueue(&queueB);
		//�ϴ� �ϳ��� ������

		while (queueA.front->data!=B) {
			int A = deQueue(&queueA);
			//A�� �ִ°� ����
			enQueue(&reQueue, A);
			//���ο� ť�� ��迭
		}
		int A = deQueue(&queueA);
		enQueue(&reQueue, A);
	}
	while (queueA.front!=NULL) {
		int A = deQueue(&queueA);
		enQueue(&reQueue, A);
	}

	//��迭�� ����� ���
	while (reQueue.front != NULL) {
		int numPrint = deQueue(&reQueue);
		printf("%d ", numPrint);
	}
	return 0;
}