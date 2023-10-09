#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct Stack {
	int top[MAX_SIZE];//Stack�� top�� �����ϴ� Linked List	
	int size;//Stack�� ũ��
	int maxSize;//Stack�� �ִ� ũ��
}typedef Stack;

void init(struct Stack** stack, int maxSize) {
	*stack = (struct Stack*)malloc(sizeof(struct Stack));
	(*stack)->size = 0;
	(*stack)->maxSize = maxSize;
	for (int i = 0; i < (*stack)->size; i++) {
		(*stack)->top[i] == NULL;
	}
}

int size(struct Stack* stack) {
	return stack->size;
}

int isFull(struct Stack* stack) {
	if (stack->size != stack->maxSize) {
		return 0;
	}
	else {
		return 1;
	}
}

int isEmpty(struct Stack* stack) {
	if (stack->size == 0) {
		return 1;
	}
	return 0;
}

void push(struct Stack* stack, int n) {
	if (isFull(stack) == 1) {
		printf("����\n");
	}
	else {
		stack->top[stack->size + 1] = n;
		(stack->size)++;
	}
}

int pop(struct Stack* stack) {
	if (stack->size == 0) {
		return 0;
	}
	else {
		int temp = 0;
		temp = stack->top[stack->size];
		stack->top[stack->size] == NULL;
		(stack->size)--;

		return temp;
	}
}

int peek(struct Stack* stack) {
	if (stack->top[stack->size] == NULL) {
		return 0;
	}
	return stack->top[stack->size];
}

void printStack(struct Stack* stack) {
	
	for (int i = 1; i <= stack->size; i++) {
		printf("%d ", stack->top[i]);
	}
	printf("\n");
}

void deleteStack(struct Stack* stack) {
	free(stack);
}

void test();

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

void test() {
	return;
}