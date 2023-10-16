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
	//Stack�� ����Ͽ� ���ڿ��� �ߺ��� �����ϴ� ���α׷��� �ۼ��غ���
	//����� ���ø� �����Ͽ� ����
	//�Է�: helloow
	//���: helow
	//�Է�: abccddx
	//���: abcdx
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