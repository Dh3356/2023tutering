#include<iostream>
#include<deque>
using namespace std;

int main() {
	//2 개의 덱을 생성하고
	//해당 덱에 정수 n개(n은 입력받음)를 넣은 후, 두 덱의 내용을 비교하여
	//더 큰 덱을 출력하는 프로그램을 작성.
	//입력 예시
	//3
	//1 3 5
	//9 5 2
	// 
	//출력 예시
	//9 5 5

	deque<int> first;
	deque<int> second;


	int num;
	cin >> num;
	
	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		first.push_back(temp);
	}
	for (int i = 0; i < num; i++) {
		int temp;
		cin >> temp;
		second.push_back(temp);
	}

	deque<int> output;

	while (first.size() != 0) {
		if (first.front() > second.front()) {
			output.push_back(first.front());
			first.pop_front();
			second.pop_front();
		}
		else {
			output.push_back(second.front());
			first.pop_front();
			second.pop_front();
		}
	}

	cout << "결과" << endl;
	for (int i = 0; i < num; i++) {
		cout << output.front() << " ";
		output.pop_front();
	}

	return 0;
}