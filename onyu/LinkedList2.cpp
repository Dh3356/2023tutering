#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Student {
	char* name;
	int age;
	int id;
} typedef Student;

struct LinkedList {
	Student* data;
	LinkedList* next;
} typedef LinkedList;
void PRINTALL(LinkedList* list) {

	LinkedList* now = list->next;

	while (now != NULL) {
		Student* stu = now->data;
		printf("%s %d %d\n", stu->name, stu->age, stu->id);
		now = now->next;

	}

}
void INPUTDATA(LinkedList* list, Student* stu) {
	stu->name = (char*)malloc(sizeof(char) * 100);
	printf("�л� �̸��� ����, �й��� �Է��ϼ���\n");
	scanf("%s", stu->name);
	scanf("%d", &(stu->age));
	scanf("%d", &(stu->id));

	LinkedList* newLink = (LinkedList*)malloc(sizeof(LinkedList));
	newLink->data = stu;
	newLink->next = list->next;
	list->next = newLink;



}
int main() {
	//LinkedList�� �̿��Ͽ� �޴��� ���� ����ڿ��� �л� ������ �Է¹޴� ���α׷� �ۼ� 
	//�Է¹��� �л� ���� �����͸� Linked List�� ������� �����ϰ�
	//����� �л� ���� �����͸� ������� ���� ����ϴ� ���α׷��� �ۼ�.
	//�л� ���� �����͸� �ִ� �Լ� �ۼ�, �л� ���� �����͸� ���� ����ϴ� �Լ� �ۼ�
	//�޴��� ������ ���� �� ��. (1. ���� 2. ��ü ��ȸ 3. ����)
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	int input = 0;
	list->next = NULL;

	while (input != 3) {
		printf("1.���� 2.��ȸ 3.����\n");

		scanf("%d", &input);

		if (input == 1) {
			Student* stu = (Student*)malloc(sizeof(Student));
			INPUTDATA(list, stu);
		}
		else if (input == 2) {
			PRINTALL(list);
		}
		else {
			break;
		}

	}
	return 0;
}