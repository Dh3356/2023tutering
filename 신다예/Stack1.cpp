#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct Stack {
	int top[MAX_SIZE];//Stack의 top를 저장하는 Linked List	
	int size;//Stack의 크기
	int maxSize;//Stack의 최대 크기
}typedef Stack;

void init(Stack** stack, int maxSize) { //1. Stack을 초기화(동적 할당, 내부 변수 초기화)하는 함수(init)

	(*stack) = (Stack*)malloc(sizeof(Stack));
	for (int i = 0; i < (*stack)->size; i++) {
		(*stack)->top[i] = NULL;
	}
	(*stack)->size = 0;
	(*stack)->maxSize = maxSize;

}

int size(Stack* stack) {  //2. Stack의 크기를 반환하는 함수(size)
	return stack->size;
}

int isFull(Stack* stack) { //3. Stack이 다 찼는지 확인하는 함수(isFull)
	if (stack->size == stack->maxSize) {
		return 1;
	}
	return 0;
}

void push(Stack* stack, int data) { //4. Stack에 데이터를 넣는 함수(push)
	if (isFull(stack) == 1) {
		printf("stack이 다 찼습니다람쥐");
	}
	else {
		stack->top[stack->size+1] = data;
		(stack->size)++;
	}

}

int pop(Stack* stack) { //5. Stack에서 데이터를 빼는 함수(pop)
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

int peek(Stack* stack) { //6. Stack의 top에 있는 데이터를 반환하는 함수(peek)
	if (stack->size == 0) {
		return 0;
	}
	else {
		return stack->top[stack->size];
	}
}

void printStack(Stack* stack) { //6. Stack의 모든 데이터를 출력하는 함수(printStack)v
	if (stack->size == 0) {
		printf("stack에 아무것도 없습니다");
	}
	else {
		for (int i = 1; i <= stack->size; i++) {
			printf("%d, ", stack->top[i]);
		}
		printf("\n");
	}
}

void deleteStack(Stack* stack) {  //7. Stack을 삭제하는 함수(deleteStack)

}

int isEmpty(Stack* stack) {  //8. Stack이 비어있는지 확인하는 함수(isEmpty)
	if (stack->size == 0) {
		return 1;
	}
	return 0;
}


void test();
int main() {
	//배열을 사용하여 Stack을 구현해보자
	//Stack 구조체 정의를 자세하게 살펴본 후 진행하는 것을 추천
	//test 함수처럼 함수 원형 정의를 먼저 하고 main 아래에서 구현해야 함수를 찾지 못하는 상황을 방지할 수 있음
	// 
	//구현해야 할 함수 목록
	//1. Stack을 초기화(동적 할당, 내부 변수 초기화)하는 함수(init)v
	//2. Stack의 크기를 반환하는 함수(size)
	//3. Stack이 다 찼는지 확인하는 함수(isFull)
	//4. Stack에 데이터를 넣는 함수(push)
	//5. Stack에서 데이터를 빼는 함수(pop)
	//6. Stack의 top에 있는 데이터를 반환하는 함수(peek)
	//6. Stack의 모든 데이터를 출력하는 함수(printStack)v
	//7. Stack을 삭제하는 함수(deleteStack)v
	//8. Stack이 비어있는지 확인하는 함수(isEmpty)

	//해당 테스트 코드를 전부 정상적으로 통과해야 한다
	//모든 함수 테스트
	Stack* stack;
	init(&stack, 10);
	printf("Stack의 크기: %d\n", size(stack)); // 여기서 size가 0이 나와야함.
	printf("Stack이 비어있는지 확인: %d\n", isEmpty(stack)); 
	printf("Stack이 다 찼는지 확인: %d\n", isFull(stack));
	printf("Stack에 1, 2, 3, 4, 5를 추가\n");
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);
	printf("Stack의 크기: %d\n", size(stack));
	printf("Stack의 top: %d\n", peek(stack));
	printf("Stack에서 pop: %d\n", pop(stack));
	printf("Stack에서 pop: %d\n", pop(stack));
	printf("Stack에서 pop: %d\n", pop(stack));
	printf("Stack에서 pop: %d\n", pop(stack));
	printf("Stack에서 pop: %d\n", pop(stack));
	printf("Stack의 크기: %d\n", size(stack));
	printf("Stack이 비어있는지 확인: %d\n", isEmpty(stack));
	printf("Stack이 다 찼는지 확인: %d\n", isFull(stack));
	printf("Stack에 1, 2, 3을 추가\n");
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	printf("Stack의 모든 데이터 출력\n");
	printStack(stack);
	printf("Stack 삭제\n");
	deleteStack(stack);
	return 0;
}

void test() {
	return;
}