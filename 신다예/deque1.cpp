#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	//한 문자열을 입력받아 해당 문자열이 앞으로 읽어도 뒤로 읽어도 같은 문자열인지 판별,
	//true 또는 false를 출력하는 프로그램을 작성.
	//dequq, stack 등을 사용할 때는 라이브러리를 include 하여 사용해라.
	//입력 예시: helleh
	//출력 예시: true
	//입력 예시: hello
	//출력 예시: false

    
    

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