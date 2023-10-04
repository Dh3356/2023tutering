#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct Stack {
	int top[MAX_SIZE];//Stack의 top를 저장하는 Linked List	
	int size;//Stack의 크기
	int maxSize;//Stack의 최대 크기
}typedef Stack;

int main() {
	//배열을 사용하여 Stack을 구현해보자
	//Stack 구조체 정의를 자세하게 살펴본 후 진행하는 것을 추천
	// 
	//구현해야 할 함수 목록
	//1. Stack을 초기화하는 함수(initStack)
	//2. Stack의 크기를 반환하는 함수(sizeOfStack)
	//3. Stack이 다 찼는지 확인하는 함수(isFull)
	//4. Stack에 데이터를 넣는 함수(push)
	//5. Stack에서 데이터를 빼는 함수(pop)
	//6. Stack의 top에 있는 데이터를 반환하는 함수(peek)
	//6. Stack의 모든 데이터를 출력하는 함수(printStack)
	//7. Stack을 삭제하는 함수(deleteStack)
    //8. Stack이 비어있는지 확인하는 함수(isEmpty)
	return 0;
}