#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct Stack {
	int top[MAX_SIZE];//Stack�� top�� �����ϴ� Linked List	
	int size;//Stack�� ũ��
	int maxSize;//Stack�� �ִ� ũ��
}typedef Stack;

void init(Stack** stack, int maxSize) { //1. Stack�� �ʱ�ȭ(���� �Ҵ�, ���� ���� �ʱ�ȭ)�ϴ� �Լ�(init)

	(*stack) = (Stack*)malloc(sizeof(Stack));
	for (int i = 0; i < (*stack)->size; i++) {
		(*stack)->top[i] = NULL;
	}
	(*stack)->size = 0;
	(*stack)->maxSize = maxSize;

}

int size(Stack* stack) {  //2. Stack�� ũ�⸦ ��ȯ�ϴ� �Լ�(size)
	return stack->size;
}

int isFull(Stack* stack) { //3. Stack�� �� á���� Ȯ���ϴ� �Լ�(isFull)
	if (stack->size == stack->maxSize) {
		return 1;
	}
	return 0;
}

void push(Stack* stack, int data) { //4. Stack�� �����͸� �ִ� �Լ�(push)
	if (isFull(stack) == 1) {
		printf("stack�� �� á���ϴٶ���");
	}
	else {
		stack->top[stack->size+1] = data;
		(stack->size)++;
	}

}

int pop(Stack* stack) { //5. Stack���� �����͸� ���� �Լ�(pop)
	int temp=0;
	if (stack->size == 0) {
		return 0;
	}
	else {
		temp = stack->top[stack->size];
		stack->top[stack->size] = NULL;
		(stack->size)--;
		return temp;
	}
}

int peek(Stack* stack) { //6. Stack�� top�� �ִ� �����͸� ��ȯ�ϴ� �Լ�(peek)
	if (stack->size == 0) {
		return 0;
	}
	else {
		return stack->top[stack->size];
	}
}

void printStack(Stack* stack) { //6. Stack�� ��� �����͸� ����ϴ� �Լ�(printStack)v
	if (stack->size == 0) {
		printf("stack�� �ƹ��͵� �����ϴ�");
	}
	else {
		for (int i = 1; i <= stack->size; i++) {
			printf("%d, ", stack->top[i]);
		}
		printf("\n");
	}
}

void deleteStack(Stack* stack) {  //7. Stack�� �����ϴ� �Լ�(deleteStack)

}

int isEmpty(Stack* stack) {  //8. Stack�� ����ִ��� Ȯ���ϴ� �Լ�(isEmpty)
	if (stack->size == 0) {
		return 1;
	}
	return 0;
}


void test();
int main() {
	//�迭�� ����Ͽ� Stack�� �����غ���
	//Stack ����ü ���Ǹ� �ڼ��ϰ� ���캻 �� �����ϴ� ���� ��õ
	//test �Լ�ó�� �Լ� ���� ���Ǹ� ���� �ϰ� main �Ʒ����� �����ؾ� �Լ��� ã�� ���ϴ� ��Ȳ�� ������ �� ����
	// 
	//�����ؾ� �� �Լ� ���
	//1. Stack�� �ʱ�ȭ(���� �Ҵ�, ���� ���� �ʱ�ȭ)�ϴ� �Լ�(init)v
	//2. Stack�� ũ�⸦ ��ȯ�ϴ� �Լ�(size)
	//3. Stack�� �� á���� Ȯ���ϴ� �Լ�(isFull)
	//4. Stack�� �����͸� �ִ� �Լ�(push)
	//5. Stack���� �����͸� ���� �Լ�(pop)
	//6. Stack�� top�� �ִ� �����͸� ��ȯ�ϴ� �Լ�(peek)
	//6. Stack�� ��� �����͸� ����ϴ� �Լ�(printStack)v
	//7. Stack�� �����ϴ� �Լ�(deleteStack)v
	//8. Stack�� ����ִ��� Ȯ���ϴ� �Լ�(isEmpty)

	//�ش� �׽�Ʈ �ڵ带 ���� ���������� ����ؾ� �Ѵ�
	//��� �Լ� �׽�Ʈ
	Stack* stack;
	init(&stack, 10);
	printf("Stack�� ũ��: %d\n", size(stack)); // ���⼭ size�� 0�� ���;���.
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