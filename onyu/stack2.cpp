#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct LinkedList {
	char data;
	LinkedList* next;
}typedef LinkedList;
struct Stack {
	LinkedList* top;
	int size;
}typedef Stack;

void push(Stack* stack, char data) {
	LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
	stack->size++;
}
int peek(Stack* stack) {
	if (stack->top == NULL) {
		return 0;
	}
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
	stack->top = NULL;
	stack->size = 0;

	char data[100];
	scanf("%s", data);
	int len = strlen(data);


	int i = 0;
	while (data[i] != '\0') {
		char temp = data[i];
		if (temp != peek(stack)) {
			push(stack, temp);
			printf("%c", temp);
		}
		i++;
	}
	printf("\n");


	return 0;
}