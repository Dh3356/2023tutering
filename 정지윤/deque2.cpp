#include<iostream>
#include<deque>
#include<stack>

using namespace std;

int main() {
	int num;
	int input1, input2;
	deque<int> deck1, deck2;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> input1;
		deck1.push_back(input1);
	}
	for (int i = 0; i < num; i++) {
		cin >> input2;
		deck2.push_back(input2);
	}

	while (!deck1.empty() && !deck2.empty()) {
		if (deck1.front() > deck2.front()) {
			cout << deck1.front() << " ";
			deck1.pop_front();
		}
		else {
			cout << deck2.front() << " ";
			deck2.pop_front();
		}
	}

	return 0;
}