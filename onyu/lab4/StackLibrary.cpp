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

	stack<int> s;

	for (int i = 1; i <= 5; i++) {
		s.push(i);
		cout << s.top() << " �� �߰��߽��ϴ�" << endl;
	}
	cout << "�������: " << s.size() << endl;

	cout << "���� ����� ���� :" << s.top() << endl;

	s.pop();

	cout << "���� ����� ���� :" << s.top() << endl;

	if (!s.empty()) {
		cout << "������ " << endl;
	}


	return 0;
}