#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct LinkedList {
	int data;
	LinkedList* next;
} typedef LinkedList;

int main() {
	//LinkedList를 이용하여 사용자가 EOF(Windows에서는 Ctrl + Z를 3번 입력하면 됨)를 입력할 때까지 
	//입력받은 정수 데이터를 Linked List에 역순으로 저장하고(a->b 에서 c 입력 시 c->a->b)
	//저장된 데이터를 순서대로 전부 출력하는 프로그램을 작성.
	//데이터를 넣는 함수 작성, 데이터를 전부 출력하는 함수 작성
	return 0;
}