#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Student {
	char* name;
	int age;
	int id;
} typedef Student;;

struct LinkedList {
	Student* data;
	LinkedList* next;
} typedef LinkedList;

int main() {
	//LinkedList�� �̿��Ͽ� �޴��� ���� ����ڿ��� �л� ������ �Է¹޴� ���α׷� �ۼ� 
	//�Է¹��� �л� ���� �����͸� Linked List�� ������� �����ϰ�
	//����� �л� ���� �����͸� ������� ���� ����ϴ� ���α׷��� �ۼ�.
	//�л� ���� �����͸� �ִ� �Լ� �ۼ�, �л� ���� �����͸� ���� ����ϴ� �Լ� �ۼ�
	//�޴��� ������ ���� �� ��. (1. ���� 2. ��ü ��ȸ 3. ����)
	return 0;
}