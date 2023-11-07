#include <iostream>
#include <queue>
using namespace std;

int main() {
	//C++에서는 Queue 라이브러리를 지원한다.
	//검색을 통해 사용법을 익히고, Queue 라이브러리에 있는 함수들을 사용하는 간단한 프로그램을 직접 구현하자.
	//다음 기능은 반드시 들어가야 한다.
	// 
	//1.push
	//2.pop
	//3.front
	//4.back
	//5.size
	//6.empty
	//
	//stdio.h는 사용하지 않는다.

	queue<int> Queue;

	int num;
	cout << "숫자를 입력하세요." << endl;
	cin >> num;

	for (int i = 0; i < num; i++) {
		Queue.push(i);
	}
	cout << "queue의 size:" << Queue.size() << endl;
	if (Queue.empty()) {
		cout << "queue가 비어있습니다." << endl;
	}
	else {
		cout << "queue의 front:" << Queue.front() << endl;
		cout << "queue의 back:" << Queue.back() << endl;
	}


	for (int i = 0; i < num; i++) {
		cout << "pop queue: " << Queue.front() << endl;
		Queue.pop();
	}

	cout << "queue가 비었습니까? : ";

	if (Queue.empty()) {
		cout << "네" << endl;
	}
	else {
		cout << "아니요" << endl;
	}

	return 0;
}