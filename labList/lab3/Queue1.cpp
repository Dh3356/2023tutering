#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	//�л� �����͸� �����ϴ� Queue�� �����, �л� �����͸� �߰��� ��, ����ϴ� ���α׷��� ������
	//�߰��� �� �ִ� �л��� �ִ� 20���̴�.
	// 
	//�޴��� ������ ����. 
	//1. �л� �߰�
	//2. ��� �л� ������� ��� �� ����
	//
	//Queue, LinkedList, Student�� ���� �����ؾ� �Ѵ�.
	//��� ���� �Լ��� �����ؾ� �Ѵ�.
	// 
	//main �Լ��� ������ ����.
	Queue* studentQueue;
	init(&studentQueue, 20);
	menu(&studentQueue);
	return 0;
}