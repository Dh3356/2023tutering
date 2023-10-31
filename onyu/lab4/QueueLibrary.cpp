#include <queue>
#include <iostream>
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

	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	cout << "사이즈는 " << q.size() << endl;

	cout << "맨 앞 원소는 : " << q.front() << endl;
	cout << "맨 뒤 원소는 : " << q.back() << endl;

	cout << "사이즈는 " << q.size() << endl;

	while (!q.empty()) {
		cout << q.front() << "를 지웠습니다" << endl;
		q.pop();
	}

	return 0;
}