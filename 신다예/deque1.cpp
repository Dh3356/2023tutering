#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	//�� ���ڿ��� �Է¹޾� �ش� ���ڿ��� ������ �о �ڷ� �о ���� ���ڿ����� �Ǻ�,
	//true �Ǵ� false�� ����ϴ� ���α׷��� �ۼ�.
	//dequq, stack ���� ����� ���� ���̺귯���� include �Ͽ� ����ض�.
	//�Է� ����: helleh
	//��� ����: true
	//�Է� ����: hello
	//��� ����: false

    
    

    deque<char> input; 
    char str[100];
    
    for (int i = 0; cin >> str[i]; i++) {
        input.push_back(str[i]);
    }
    
   
    int isSame = 1;
    int Size = input.size();
    if (Size % 2 == 0) {
        while (input.size() != 0) {
            if (input.front() != input.back()) {
                isSame = 0;
                break;
            }
            input.pop_back();
            input.pop_front();
            isSame = 1;
        }
    }
    else {
        while (input.size() != 1) {
            if (input.front() != input.back()) {
                isSame = 0;
                break;
            }
            input.pop_back();
            input.pop_front();
            isSame = 1;
        }
    }


    if (isSame == 1) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }


	return 0;
}