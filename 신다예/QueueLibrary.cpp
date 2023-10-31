#include <iostream>
#include <queue>
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

	queue<int> Queue;

	int num;
	cout << "���ڸ� �Է��ϼ���." << endl;
	cin >> num;

	for (int i = 0; i < num; i++) {
		Queue.push(i);
	}
	cout << "queue�� size:" << Queue.size() << endl;
	if (Queue.empty()) {
		cout << "queue�� ����ֽ��ϴ�." << endl;
	}
	else {
		cout << "queue�� front:" << Queue.front() << endl;
		cout << "queue�� back:" << Queue.back() << endl;
	}


	for (int i = 0; i < num; i++) {
		cout << "pop queue: " << Queue.front() << endl;
		Queue.pop();
	}

	cout << "queue�� ������ϱ�? : ";

	if (Queue.empty()) {
		cout << "��" << endl;
	}
	else {
		cout << "�ƴϿ�" << endl;
	}

	return 0;
}