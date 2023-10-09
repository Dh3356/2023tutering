#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct LinkedList {
	char data;
	LinkedList* next;
}typedef LinkedList;

struct Stack {
	LinkedList* top;
	int size;
}typedef Stack;

int pushStack(struct Stack* stack, char buffer) {
	struct LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));

	newLinkedList->data = buffer;
	newLinkedList->next = stack->top;
	stack->top = newLinkedList;
	stack->size++;

	return 1;
}

int popStack(struct Stack* stack) {
	if (stack->top == NULL) {
		return 0;
	}

	LinkedList* temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	(stack->size)--;

	return 1;
}

int duplicate(struct Stack* stack, char buffer) {
	LinkedList* newLinkedList = stack->top;
	while (newLinkedList!=NULL) {
		if (newLinkedList->data == buffer) {
			return 1;
		}
		newLinkedList = newLinkedList->next;
	}
	return 0;
}

int main() {
	struct Stack* stack = (Stack*)malloc(sizeof(Stack));
	struct Stack* newStack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;
	char temp[MAX_SIZE];

	scanf("%s", temp);

	for (int i = 0; temp[i] != NULL; i++){
		char buffer = temp[i];

		if (!duplicate(stack, buffer)) {
			pushStack(stack, buffer);
		}
	}

	while (stack->top != NULL) {
		pushStack(newStack, stack->top->data);
		popStack(stack);
	}

	while (newStack->top != NULL) {
		printf("%c", newStack->top->data);
		popStack(newStack);
	}
	

	printf("\n");

	free(stack);

	return 0;
}