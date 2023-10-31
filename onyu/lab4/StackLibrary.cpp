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

	stack<int> s;

	for (int i = 1; i <= 5; i++) {
		s.push(i);
		cout << s.top() << " 을 추가했습니다" << endl;
	}
	cout << "사이즈는: " << s.size() << endl;

	cout << "가장 상단의 값은 :" << s.top() << endl;

	s.pop();

	cout << "가장 상단의 값은 :" << s.top() << endl;

	if (!s.empty()) {
		cout << "차있음 " << endl;
	}


	return 0;
}