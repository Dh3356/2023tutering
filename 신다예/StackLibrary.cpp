#include <iostream>
#include <stack>
using namespace std;

int main() {
	//C++에서는 Stack 라이브러리를 지원한다.
	//검색을 통해 사용법을 익히고, Stack 라이브러리에 있는 함수들을 사용하는 간단한 프로그램을 직접 구현하자.
	//다음 기능은 반드시 들어가야 한다.
	// 
	//1.push()
	//2.size()
	//3.top()
	//4.pop()
	//5.empty()
	//
	//stdio.h는 사용하지 않는다.
	stack<int> Stack;

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		Stack.push(i);
	}
	cout << "stack의 size:" << Stack.size() << endl;
	if (Stack.empty()) {
		cout << "stack이 비었습니다." << endl;
	}
	else {
		cout << "stack의 top:" << Stack.top() << endl;
	}
	

	for (int i = 0; i < num; i++) {
		cout << "pop stack: " << Stack.top() << endl;
		Stack.pop();
	}

	cout << "stack이 비었습니까? : ";

	if (Stack.empty()) {
		cout << "네" << endl;
	}
	else {
		cout << "아니요" << endl;
	}

	
	
	return 0;
}