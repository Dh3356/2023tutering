#include<iostream>
using namespace std;
class Operator {
public:
	virtual void show() {
		cout << "show" << endl;
	}
	virtual void operate(int a, int b) {
		cout << "operate" << endl;
	}
	virtual void operate(float a, float b) {
		cout << "operate" << endl;

	}
};
class Adder : public Operator {
public:
	void show() override {
		cout << "Adder" << endl;
	}
	void operate(int a, int b) override {
		cout << a + b << endl;
	}
	void operate(float a, float b) override {
		cout << a + b << endl;
	}
};
class Subtractor : public Operator {
public:
	void show() override {
		cout << "Subtractor" << endl;
	}
	void operate(int a, int b) override {
		cout << a - b << endl;
	}
	void operate(float a, float b) override {
		cout << a - b << endl;
	}
};
class Multiplier : public Operator {
public:
	void show() override {
		cout << "Multiplier" << endl;
	}

	void operate(int a, int b) override {
		cout << a * b << endl;
	}
	void operate(float a, float b) override {
		cout << a * b << endl;
	}
};
class Divider : public Operator {
public:
	void show() override {
		cout << "Divider" << endl;
	}
	void operate(int a, int b) override {
		cout << a / b << endl;
	}
	void operate(float a, float b) override {
		cout << a / b << endl;
	}
};
class IntAdder : public Adder {
public:
	void show() override {
		cout << "IntAdder" << endl;
	}
	void operate(int a, int b) override {
		Adder::operate(a, b);
	}
};
class FloatAdder : public Adder {
public:
	void show() override {
		cout << "FloatAdder" << endl;
	}
	void operate(float a, float b) override {
		Adder::operate(a, b);
	}
};
class IntSubtractor : public Subtractor {
public:
	void show() override {
		cout << "IntSubtractor" << endl;
	}
	void operate(int a, int b) override {
		Subtractor::operate(a, b);
	}
};
class FloatSubtractor : public Subtractor {
public:
	void show() override {
		cout << "FloatSubtractor" << endl;
	}
	void operate(float a, float b) override {
		Subtractor::operate(a, b);
	}
};
class IntMultiplier : public Multiplier {
public:
	void show() override {
		cout << "IntMultiplier" << endl;
	}
	void operate(int a, int b) override {
		Multiplier::operate(a, b);
	}
};
class FloatMultiplier : public Multiplier {
public:
	void show() override {
		cout << "FloatMultiplier" << endl;
	}
	void operate(float a, float b) override {
		Multiplier::operate(a, b);
	}
};
class IntDivider : public Divider {
	\
public:
	void show() override {
		cout << "IntDivider" << endl;
	}
	void operate(int a, int b) override {
		Divider::operate(a, b);
	}
};
class FloatDivider : public Divider {
public:
	void show() override {
		cout << "FloatDivider" << endl;
	}
	void operate(float a, float b) override {
		Divider::operate(a, b);

	}
};
class Calculator {

public:
	void addOperator(Operator* x) {
		operators[num++] = x;
	}
	void showOperator() {
		for (int i = 0; i < num; i++) {
			cout << i << " ";
			operators[i]->show();
		}
	}
	Operator* getOperator(int index) {
		if (index < num) {
			return operators[index];
		}

	}
private:
	Operator* operators[10];
	int num = 0;
};
int main() {

	Calculator cal;
	cal.addOperator(new IntAdder);
	cal.addOperator(new FloatAdder);
	cal.addOperator(new IntSubtractor);
	cal.addOperator(new FloatSubtractor);
	cal.addOperator(new IntMultiplier);
	cal.addOperator(new FloatMultiplier);
	cal.addOperator(new IntDivider);
	cal.addOperator(new FloatDivider);


	while (1) {
		cout << "-1. Exit" << endl;
		cal.showOperator();

		cout << "Enter your choice" << endl;
		int ch = 0;
		cin >> ch;

		if (ch == -1) {
			break;
		}
		else {
			Operator* choice = cal.getOperator(ch);
			if (choice) {
				if (ch % 2 == 0) {
					int a, b;
					cout << "Enter operands(op1, op2)" << endl;
					cin >> a >> b;
					choice->operate(a, b);
				}
				else {
					float a, b;
					cout << "Enter operands(op1, op2)" << endl;
					cin >> a >> b;
					choice->operate(a, b);
				}
			}
		}
	}

	return 0;
}

/*
1. 계산을 나타내는 Operator 클래스를 만든다.
Operator 클래스는 가상 함수인 show()와 operate()를 가진다.
show()는 자신이 어떤 역할은 하는지 출력하는 역할을 한다.ex) Adder
operate()는 두 개의 정수를 인자로 받아서 계산을 수행하고 출력하는 역할을 한다.

2. Operator를 상속받는 Adder, Subtractor, Multiplier, Divider 클래스를 만든다.
각각의 클래스는 자신이 어떤 연산을 하는지 출력하는 show()를 오버라이드하고,
두 개의 정수를 인자로 받아서 계산을 수행하고 출력하는 operate()를 오버라이드한다.

3. Adder, Subtractor, Multiplier, Divider를 상속받는 클래스들을 만든다.
IntAdder, floatAdder, IntSubtractor, FloatSubtractor, IntMultiplier, FloatMultiplier, IntDivider, FloatDivider를 만든다.
각각의 클래스는 자신이 어떤 연산을 하는지 출력하는 show()와
두 개의 정수를 인자로 받아서 계산을 수행하고 출력하는 operate()를 오버라이드한다.
이걸 완료한다면 현재 상속 구조는 다음과 같을 것이다.
Operator->상속->Adder->상속->IntAdder, FloatAdder 등등

4. Calculator 클래스를 만든다.
Calculator 클래스는 Operator * 를 저장하는 list인 operators를 가지고 있다.(왜 포인터를 사용하는지는 잘 생각해보라)
addOperator()는 Operator * 를 인자로 받아서 list에 추가한다.
showOperators()는 operators에 있는 모든 Operator * 들의 show()를 호출한다.
showOperators() 호출 예시는 다음과 같다.(operators에 IntAdder, FloatSubtractor가 들어있다고 가정)
IntAdder
FloatSubtractor
getOperator()는 인덱스를 인자로 받아서 해당 인덱스에 있는 Operator * 를 반환한다.
위 예시의 경우, 1을 인자로 넣으면 FloatSubtractor를 반환한다.

5. Calculator 클래스를 사용하는 main() 함수를 만든다.
Calculator 클래스를 하나 만들고, IntAdder, FloatSubtractor 등을 생성해서 addOperator()를 통해 Calculator에 추가한다.
addOperator()는 Operator* 를 매개변수로 받는 함수인데 어떻게 IntAdder, FloatSubtractor를 넣을 수 있을지 잘 생각해보라.
이후, 프로그램의 흐름은 다음과 같다.
사용자에게 operators에 있는 Operator* 들을 보여준다.
사용자에게 Operator* 를 선택하게 한다.(여기서 - 1을 선택하면 프로그램을 종료한다.)
사용자에게 두 개의 정수를 입력받는다.
선택한 Operator* 의 operate()를 호출한다.
1번으로 돌아간다.
main() 함수의 실행 예시는 다음과 같다.
- 1. Exit
0. IntAdder
1. FloatSubtractor
2. IntSubtractor
3. FloatAdder
4. IntMultiplier
5. FloatMultiplier
6. IntDivider
7. FloatDivider


Enter your choice : 1
Enter operands(op1, op2) : 1 2

result : -1

.....이후 생략(Exit 전까지 반복)

*/