#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct Stack {
	int top[MAX_SIZE];//Stack�� top�� �����ϴ� Linked List	
	int size;//Stack�� ũ��
	int maxSize;//Stack�� �ִ� ũ��
}typedef Stack;

int main() {
	//�迭�� ����Ͽ� Stack�� �����غ���
	//Stack ����ü ���Ǹ� �ڼ��ϰ� ���캻 �� �����ϴ� ���� ��õ
	// 
	//�����ؾ� �� �Լ� ���
	//1. Stack�� �ʱ�ȭ�ϴ� �Լ�(initStack)
	//2. Stack�� ũ�⸦ ��ȯ�ϴ� �Լ�(sizeOfStack)
	//3. Stack�� �� á���� Ȯ���ϴ� �Լ�(isFull)
	//4. Stack�� �����͸� �ִ� �Լ�(push)
	//5. Stack���� �����͸� ���� �Լ�(pop)
	//6. Stack�� top�� �ִ� �����͸� ��ȯ�ϴ� �Լ�(peek)
	//6. Stack�� ��� �����͸� ����ϴ� �Լ�(printStack)
	//7. Stack�� �����ϴ� �Լ�(deleteStack)
    //8. Stack�� ����ִ��� Ȯ���ϴ� �Լ�(isEmpty)
	return 0;
}