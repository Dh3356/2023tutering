#include<iostream>
#include<deque>
#include<stack>
#include<string>
using namespace std;


bool CHECK(const string str) {
	deque<char> data;
	int len = str.length();

	for (int i = 0; i < len; i++) {
		data.push_back(str[i]);
	}


	while (data.size() > 1) {
		if (data.front() != data.back()) {
			return false;
		}
		data.pop_front();
		data.pop_back();
	}

	return true;

}
int main() {
	// 한 문자열을 입력받아 해당 문자열이 앞으로 읽어도 뒤로 읽어도 같은 문자열인지 판별,
	// true 또는 false를 출력하는 프로그램을 작성.
	// dequq, stack 등을 사용할 때는 라이브러리를 include 하여 사용해라.
	// 입력 예시: helleh
	// 출력 예시: true
	// 입력 예시: hello
	// 출력 예시: false

	// 한 단어씩  deque에 저장
	// 앞이랑 뒤로 제거하면서 만약 앞과 뒤가 하나라도 다르면  false 출력

	string input;
	cin >> input;

	if (CHECK(input)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}


	return 0;
}