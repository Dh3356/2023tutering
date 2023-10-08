#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkedList {
	LinkedList* next;
	char data;
} typedef LinkedList;

struct Stack {
	LinkedList* top;
	int size;
} typedef Stack;

int push(Stack* stack, char data) {
	LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));

	newLinkedList->data = data;
	newLinkedList->next = stack->top;
	stack->top = newLinkedList;
	(stack->size)++;
	return 1;  
}

char pop(Stack* stack) {
	if (stack->top == NULL) {
		return -1;
	}

	LinkedList* temp = stack->top;
	char dataInTop = temp->data;
	stack->top = temp->next;
	free(temp);
	return dataInTop;
}

char peek(Stack* stack) {
	return stack->top->data;
}

int main() {
	//Stack을 사용하여 문자열의 중복을 제거하는 프로그램을 작성해보자
	//입출력 예시를 참고하여 구현
	//입력: helloow
	//출력: helow
	//입력: abccddx
	//출력: abcdx
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	Stack* tempStack = (Stack*)malloc(sizeof(Stack));
	
	tempStack->top = NULL;
	tempStack->size = 0;
	stack->top = NULL;
	stack->size = 0;

	char data[100];
	printf("입력: ");
	scanf("%s", data);

	for (int i = 0; data[i] != '\0'; i++) {
		char temp = data[i];
		if (data[i] == data[i + 1]) {
			push(tempStack, temp);
		}
		else {
			push(stack, temp);
		}
	}
	
	printf("출력: ");

	int numSize = stack->size;
	char outputData[100];
	for (int i = numSize-1; i >= 0; i--) {
		 outputData[i] = pop(stack);
	}
	for (int i = 0; i < numSize; i++) {
		printf("%c", outputData[i]);
	}

	return 0;
}