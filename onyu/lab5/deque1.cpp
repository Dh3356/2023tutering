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
	// �� ���ڿ��� �Է¹޾� �ش� ���ڿ��� ������ �о �ڷ� �о ���� ���ڿ����� �Ǻ�,
	// true �Ǵ� false�� ����ϴ� ���α׷��� �ۼ�.
	// dequq, stack ���� ����� ���� ���̺귯���� include �Ͽ� ����ض�.
	// �Է� ����: helleh
	// ��� ����: true
	// �Է� ����: hello
	// ��� ����: false

	// �� �ܾ  deque�� ����
	// ���̶� �ڷ� �����ϸ鼭 ���� �հ� �ڰ� �ϳ��� �ٸ���  false ���

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