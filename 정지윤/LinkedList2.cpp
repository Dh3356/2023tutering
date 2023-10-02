#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
	char* name;
	int age;
	int id;
} typedef Student;

struct LinkedList {
	Student* data;
	LinkedList* next;
} typedef LinkedList;

LinkedList* addData(LinkedList* LinkedList1, Student* students) {
	LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));

	if (newLinkedList == NULL) {
		printf("����\n");
	}
	newLinkedList->data = students;
	newLinkedList->next = LinkedList1;
	return newLinkedList;

}

void printData(LinkedList* LinkedList1) {
	LinkedList* first = LinkedList1;
	while (first != NULL) {
		Student* students = first->data;
		printf("�̸�: %s, ����: %d, �й�: %d\n", students->name, students->age, students->id);
		first = first->next;
	}
}
int main() {
	int menu = 0;
	LinkedList* LinkedList1 = NULL;
	int data;
	struct Student students;

	while (menu!= 3) {

		printf("�޴�: 1.���� 2.��ü ��ȸ 3.����\n");
		printf("�޴��� ����.\n");
		scanf("%d", &menu);

		if (menu == 1) {
			Student* students = (Student*)malloc(sizeof(Student));

			printf("�л��� �̸��� ����, �й��� �Է��ϼ���.\n");
			scanf("%s %d %d", students->name, &students->age, &students->id);

			LinkedList1=addData(LinkedList1, students);
		}
		else if (menu == 2) {
			printData(LinkedList1);
		}
	}
	if (menu == 3) {
		printf("�����.\n");
	}
	
	while (LinkedList1 != NULL) {
		LinkedList* temp = LinkedList1;
		LinkedList1 = LinkedList1->next;
		free(temp);
	}

	return 0;
}