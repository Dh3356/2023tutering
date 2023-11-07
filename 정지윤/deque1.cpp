#include<iostream>
#include<deque>
#include<string>
#include<stack>

using namespace std;

bool same(const string &string_) {
	stack<char> stack_;
	string reversedS;

	for (char c : string_) {
		stack_.push(c);
	}

	while (!stack_.empty()) {
		reversedS += stack_.top();
		stack_.pop();
	}

	return string_ == reversedS;
}

int main() {
	string string_;

	cin >> string_;

	if (same(string_)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}