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
		printf("이름:%s 나이:%d ID:%d \n", head->data->name, head->data->age, head->data->id);
		head = head->next;

	}

}

int main() {
	//LinkedList를 이용하여 메뉴를 통해 사용자에게 학생 정보를 입력받는 프로그램 작성 
	//입력받은 학생 정보 데이터를 Linked List에 순서대로 저장하고
	//저장된 학생 정보 데이터를 순서대로 전부 출력하는 프로그램을 작성.
	//학생 정보 데이터를 넣는 함수 작성, 학생 정보 데이터를 전부 출력하는 함수 작성
	//메뉴는 다음과 같이 할 것. (1. 삽입 2. 전체 조회 3. 종료)
	LinkedList* linkedList = NULL;

	int num = 0;
	while (1) {
		int choice = 0;
		printf("메뉴 번호를 입력해주세요. / 1.삽입 2.전체조회 3.종료\n");
		scanf("%d", &choice);
		if (choice == 1) {
			printf("%d번째 학생의 이름, 나이, ID를 입력해주세요.\n", num);
			addData(&linkedList);
			num++;
		}
		else if (choice == 2) {
			if (num == 0) {
				printf("조회할 학생이 없습니다람쥐.\n");
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
			printf("잘못된 조회 메뉴 입니다람쥐.\n");
		}

	}

	return 0;
}