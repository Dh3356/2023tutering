#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct LinkedList {
	int data;
	LinkedList* next;
} typedef LinkedList;

int main() {
	//LinkedList�� �̿��Ͽ� ����ڰ� EOF(Windows������ Ctrl + Z�� 3�� �Է��ϸ� ��)�� �Է��� ������ 
	//�Է¹��� ���� �����͸� Linked List�� �������� �����ϰ�(a->b ���� c �Է� �� c->a->b)
	//����� �����͸� ������� ���� ����ϴ� ���α׷��� �ۼ�.
	//�����͸� �ִ� �Լ� �ۼ�, �����͸� ���� ����ϴ� �Լ� �ۼ�
	return 0;
}