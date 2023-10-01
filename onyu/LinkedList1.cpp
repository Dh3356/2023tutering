#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct LinkedList {
	int data;
	LinkedList* next;
} typedef LinkedList;
void PRINTALL(LinkedList* arr) {
	LinkedList* now = arr;
	while (now != NULL) {
		printf("%d \n", now->data);
		now = now->next;
	}

}
void INPUT(LinkedList** list, int data) {
	LinkedList* arr = (LinkedList*)malloc(sizeof(LinkedList));

	arr->data = data;
	arr->next = *list;
	*list = arr;
}
int main() {

	//LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
	int input = 0;

	LinkedList* list = NULL;
	while (scanf("%d", &input) != EOF) {

		INPUT(&list, input);
	}

	PRINTALL(list);



	//LinkedList�� �̿��Ͽ� ����ڰ� EOF(Windows������ Ctrl + Z�� 3�� �Է��ϸ� ��)�� �Է��� ������ 
	//�Է¹��� ���� �����͸� Linked List�� �������� �����ϰ�(a->b ���� c �Է� �� c->a->b)
	//����� �����͸� ������� ���� ����ϴ� ���α׷��� �ۼ�.
	//�����͸� �ִ� �Լ� �ۼ�, �����͸� ���� ����ϴ� �Լ� �ۼ�
	return 0;
}