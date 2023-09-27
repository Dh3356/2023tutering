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
	//LinkedList를 이용하여 메뉴를 통해 사용자에게 학생 정보를 입력받는 프로그램 작성 
	//입력받은 학생 정보 데이터를 Linked List에 순서대로 저장하고
	//저장된 학생 정보 데이터를 순서대로 전부 출력하는 프로그램을 작성.
	//학생 정보 데이터를 넣는 함수 작성, 학생 정보 데이터를 전부 출력하는 함수 작성
	//메뉴는 다음과 같이 할 것. (1. 삽입 2. 전체 조회 3. 종료)
	return 0;
}