#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack;  // ������ ���� ����

    // ���� �ֱ�
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    int stackSize = myStack.size();
    cout << "Stack size: " << stackSize << endl;

    // �� ����
    int topElement = myStack.top();
    cout << "Top element: " << topElement << endl;

    // ������ ����
    myStack.pop();

    bool isEmpty = myStack.empty();
    if (isEmpty) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack is not empty." << endl;
    }
	
	return 0;
}