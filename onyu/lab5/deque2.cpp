#include<iostream>
#include <deque>
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

	int num = 0;
	cin >> num;

	deque<int> deque1;
	deque<int> deque2;


	for (int i = 0; i < num; i++) {
		int temp = 0;
		cin >> temp;
		deque1.push_back(temp);
	}

	for (int i = 0; i < num; i++) {
		int temp = 0;
		cin >> temp;
		deque2.push_back(temp);
	}

	for (int i = 0; i < num; i++) {
		if (deque1[i] > deque2[i]) {
			cout << deque1[i] << " ";
		}
		else {
			cout << deque2[i] << " ";
		}
	}

	cout << endl;

	return 0;
}