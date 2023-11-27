#include<iostream>
#include<list>

using namespace std;

int main() {
	//지난 과제로 만들었던 계산기 프로그램을 generic을 사용해 리팩터링한다.
	//Calculator에서 list로 Operator를 저장하는 것을 반드시 수행한다.
	//기존에 intAdder, floatAdder 등등 자료형에 따라 분리되어 있었다.
	//이는 코드의 중복을 야기하고, 유지보수를 어렵게 만든다.
	//이를 generic을 사용해 리팩터링한다.
	//리팩터링을 하면서, 기존에 있던 기능을 유지한다.
	//Operator의 show와 operate를 순수 가상함수로 만들어 자식 클래스에서 구현하게 만든다.
	//Operator를 상속받는 Adder, Subtractor, Multiplier, Divider를 만든다.
	//Calculator의 코드는 변경이 적을 것이다.
	//리팩터링을 완료했으면 main에서 사용한다. 출력 예시는 다음과 같다.

	//-1. Exit
	//1. IntAdder
	//2. IntSubtractor
	//3. IntMultiplier
	//4. FloatDivider
	//Select operator: 1
	//insert op1: 1
	//insert op2: 2
	//result: 3
	//반복

	Operator<int>* intAdder = new Adder<int>();
	Operator<int>* intSubtractor = new Subtractor<int>();
	Operator<int>* intMultiplier = new Multiplier<int>();
	Operator<float>* floatDivider = new Divider<float>();

	//이후는 알아서 구현
	return 0;
}