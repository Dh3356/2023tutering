#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct Stack {
	int top[MAX_SIZE];//Stack�� top�� �����ϴ� Linked List	
	int size;//Stack�� ũ��
	int maxSize;//Stack�� �ִ� ũ��
}typedef Stack;


void init(Stack** stack, int num);
int size(Stack* stack);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, int data);
int pop(Stack* stack);
int peek(Stack* stack);
void printStack(Stack* stack);
void deleteStack(Stack* stack);
int main() {
	//�迭�� ����Ͽ� Stack�� �����غ���
	//Stack ����ü ���Ǹ� �ڼ��ϰ� ���캻 �� �����ϴ� ���� ��õ
	//test �Լ�ó�� �Լ� ���� ���Ǹ� ���� �ϰ� main �Ʒ����� �����ؾ� �Լ��� ã�� ���ϴ� ��Ȳ�� ������ �� ����
	// 
	//�����ؾ� �� �Լ� ���
	//1. Stack�� �ʱ�ȭ(���� �Ҵ�, ���� ���� �ʱ�ȭ)�ϴ� �Լ�(init)
	//2. Stack�� ũ�⸦ ��ȯ�ϴ� �Լ�(size)
	//3. Stack�� �� á���� Ȯ���ϴ� �Լ�(isFull)
	//4. Stack�� �����͸� �ִ� �Լ�(push)
	//5. Stack���� �����͸� ���� �Լ�(pop)
	//6. Stack�� top�� �ִ� �����͸� ��ȯ�ϴ� �Լ�(peek)
	//6. Stack�� ��� �����͸� ����ϴ� �Լ�(printStack)
	//7. Stack�� �����ϴ� �Լ�(deleteStack)
	//8. Stack�� ����ִ��� Ȯ���ϴ� �Լ�(isEmpty)

	//�ش� �׽�Ʈ �ڵ带 ���� ���������� ����ؾ� �Ѵ�
	//��� �Լ� �׽�Ʈ
	Stack* stack;
	init(&stack, 10);
	printf("Stack�� ũ��: %d\n", size(stack));
	printf("Stack�� ����ִ��� Ȯ��: %d\n", isEmpty(stack));
	printf("Stack�� �� á���� Ȯ��: %d\n", isFull(stack));
	printf("Stack�� 1, 2, 3, 4, 5�� �߰�\n");
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);
	printf("Stack�� ũ��: %d\n", size(stack));
	printf("Stack�� top: %d\n", peek(stack));
	printf("Stack���� pop: %d\n", pop(stack));
	printf("Stack���� pop: %d\n", pop(stack));
	printf("Stack���� pop: %d\n", pop(stack));
	printf("Stack���� pop: %d\n", pop(stack));
	printf("Stack���� pop: %d\n", pop(stack));
	printf("Stack�� ũ��: %d\n", size(stack));
	printf("Stack�� ����ִ��� Ȯ��: %d\n", isEmpty(stack));
	printf("Stack�� �� á���� Ȯ��: %d\n", isFull(stack));
	printf("Stack�� 1, 2, 3�� �߰�\n");
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	printf("Stack�� ��� ������ ���\n");
	printStack(stack);
	printf("Stack ����\n");
	deleteStack(stack);
	return 0;
}


void init(Stack** stack, int num) {
	(*stack) = (struct Stack*)malloc(sizeof(struct Stack));
	for (int i = 0; i < num; i++) {
		(*stack)->top[i] = NULL;
	}
	(*stack)->size = 0;
	(*stack)->maxSize = num;


}
int size(Stack* stack) {
	return stack->size;
}
int isEmpty(Stack* stack) {
	if (stack->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int isFull(Stack* stack) {
	if (stack->size == stack->maxSize) {
		return 1;
	}
	else {
		return 0;
	}
}
void push(Stack* stack, int data) {
	if (isFull(stack) != 1) {
		stack->top[stack->size++] = data;
	}
	else {
		printf("X\n");
	}
}
int pop(Stack* stack) {
	if (isEmpty(stack)) {
		return -1;
	}
	else {
		return stack->top[--stack->size];
	}
}
int peek(Stack* stack) {
	if (isEmpty(stack) == 1) {
		return -1;
	}
	else {
		return stack->top[stack->size - 1];
	}
}

void printStack(Stack* stack) {
	for (int i = 0; i < stack->size; i++) {
		printf("%d \n", stack->top[i]);
	}
}
void deleteStack(Stack* stack) {
	free(stack);
}