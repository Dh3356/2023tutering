#include <iostream>
#include <stack>
using namespace std;

int main() {
	//C++������ Stack ���̺귯���� �����Ѵ�.
	//�˻��� ���� ������ ������, Stack ���̺귯���� �ִ� �Լ����� ����ϴ� ������ ���α׷��� ���� ��������.
	//���� ����� �ݵ�� ���� �Ѵ�.
	// 
	//1.push()
	//2.size()
	//3.top()
	//4.pop()
	//5.empty()
	//
	//stdio.h�� ������� �ʴ´�.
	stack<int> Stack;

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		Stack.push(i);
	}
	cout << "stack�� size:" << Stack.size() << endl;
	if (Stack.empty()) {
		cout << "stack�� ������ϴ�." << endl;
	}
	else {
		cout << "stack�� top:" << Stack.top() << endl;
	}
	

	for (int i = 0; i < num; i++) {
		cout << "pop stack: " << Stack.top() << endl;
		Stack.pop();
	}

	cout << "stack�� ������ϱ�? : ";

	if (Stack.empty()) {
		cout << "��" << endl;
	}
	else {
		cout << "�ƴϿ�" << endl;
	}

	
	
	return 0;
}