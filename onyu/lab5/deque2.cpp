#include<iostream>
#include <deque>
using namespace std;

int main() {
	//2 ���� ���� �����ϰ�
	//�ش� ���� ���� n��(n�� �Է¹���)�� ���� ��, �� ���� ������ ���Ͽ�
	//�� ū ���� ����ϴ� ���α׷��� �ۼ�.
	//�Է� ����
	//3
	//1 3 5
	//9 5 2
	// 
	//��� ����
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