#include<iostream>
#include<deque>
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

	cout << "���" << endl;
	for (int i = 0; i < num; i++) {
		cout << output.front() << " ";
		output.pop_front();
	}

	return 0;
}