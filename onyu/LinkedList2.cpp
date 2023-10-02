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
	printf("학생 이름과 나이, 학번을 입력하세요\n");
	scanf("%s", stu->name);
	scanf("%d", &(stu->age));
	scanf("%d", &(stu->id));

	LinkedList* newLink = (LinkedList*)malloc(sizeof(LinkedList));
	newLink->data = stu;
	newLink->next = list->next;
	list->next = newLink;



}
int main() {
	//LinkedList를 이용하여 메뉴를 통해 사용자에게 학생 정보를 입력받는 프로그램 작성 
	//입력받은 학생 정보 데이터를 Linked List에 순서대로 저장하고
	//저장된 학생 정보 데이터를 순서대로 전부 출력하는 프로그램을 작성.
	//학생 정보 데이터를 넣는 함수 작성, 학생 정보 데이터를 전부 출력하는 함수 작성
	//메뉴는 다음과 같이 할 것. (1. 삽입 2. 전체 조회 3. 종료)
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	int input = 0;
	list->next = NULL;

	while (input != 3) {
		printf("1.삽입 2.조회 3.종료\n");

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