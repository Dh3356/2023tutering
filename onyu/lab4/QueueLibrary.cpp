#include <queue>
#include <iostream>
using namespace std;
int main() {
	//C++������ Queue ���̺귯���� �����Ѵ�.
	//�˻��� ���� ������ ������, Queue ���̺귯���� �ִ� �Լ����� ����ϴ� ������ ���α׷��� ���� ��������.
	//���� ����� �ݵ�� ���� �Ѵ�.
	// 
	//1.push
	//2.pop
	//3.front
	//4.back
	//5.size
	//6.empty
	//
	//stdio.h�� ������� �ʴ´�.

	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	cout << "������� " << q.size() << endl;

	cout << "�� �� ���Ҵ� : " << q.front() << endl;
	cout << "�� �� ���Ҵ� : " << q.back() << endl;

	cout << "������� " << q.size() << endl;

	while (!q.empty()) {
		cout << q.front() << "�� �������ϴ�" << endl;
		q.pop();
	}

	return 0;
}