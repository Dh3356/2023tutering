#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	//학생 데이터를 저장하는 Queue를 만들고, 학생 데이터를 추가한 후, 출력하는 프로그램을 만들자
	//추가할 수 있는 학생은 최대 20명이다.
	// 
	//메뉴는 다음과 같다. 
	//1. 학생 추가
	//2. 모든 학생 순서대로 출력 후 종료
	//
	//Queue, LinkedList, Student를 전부 구현해야 한다.
	//모든 것을 함수로 구현해야 한다.
	// 
	//main 함수는 다음과 같다.
	Queue* studentQueue;
	init(&studentQueue, 20);
	menu(&studentQueue);
	return 0;
}