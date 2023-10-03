#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
	char* name;
	int age;
	int id;
} typedef Student;;

struct LinkedList {
	Student* data;
	LinkedList* next;
} typedef LinkedList;


void addData(LinkedList** linkedList) {
	char name[100];
	int id;
	int age;

	scanf("%s", name);
	scanf("%d", &age);
	scanf("%d", &id);

	LinkedList* newLinkedList = (LinkedList*)malloc(sizeof(LinkedList));
	Student* newStudent = (Student*)malloc(sizeof(Student));
	newStudent->name = (char*)malloc(strlen(name) + 1);
	strcpy(newStudent->name, name);

	newStudent->age = age;
	newStudent->id = id;
	newLinkedList->data = newStudent;
	newLinkedList->next = NULL;

	if (*linkedList == NULL) {
		*linkedList = newLinkedList;
	}
	else {
		struct LinkedList* head = *linkedList;
		while (head->next != NULL) {
			head = head->next;
		}
		head->next = newLinkedList;
	}


}

void printData(LinkedList* linkedList) {

	LinkedList* head = (LinkedList*)malloc(sizeof(LinkedList));
	head = linkedList;
	while (head != NULL) {
		printf("�̸�:%s ����:%d ID:%d \n", head->data->name, head->data->age, head->data->id);
		head = head->next;

	}

}

int main() {
	//LinkedList�� �̿��Ͽ� �޴��� ���� ����ڿ��� �л� ������ �Է¹޴� ���α׷� �ۼ� 
	//�Է¹��� �л� ���� �����͸� Linked List�� ������� �����ϰ�
	//����� �л� ���� �����͸� ������� ���� ����ϴ� ���α׷��� �ۼ�.
	//�л� ���� �����͸� �ִ� �Լ� �ۼ�, �л� ���� �����͸� ���� ����ϴ� �Լ� �ۼ�
	//�޴��� ������ ���� �� ��. (1. ���� 2. ��ü ��ȸ 3. ����)
	LinkedList* linkedList = NULL;

	int num = 0;
	while (1) {
		int choice = 0;
		printf("�޴� ��ȣ�� �Է����ּ���. / 1.���� 2.��ü��ȸ 3.����\n");
		scanf("%d", &choice);
		if (choice == 1) {
			printf("%d��° �л��� �̸�, ����, ID�� �Է����ּ���.\n", num);
			addData(&linkedList);
			num++;
		}
		else if (choice == 2) {
			if (num == 0) {
				printf("��ȸ�� �л��� �����ϴٶ���.\n");
				continue;
			}
			else {
				printData(linkedList);
			}
		}
		else if (choice == 3) {
			break;
		}
		else {
			printf("�߸��� ��ȸ �޴� �Դϴٶ���.\n");
		}

	}

	return 0;
}