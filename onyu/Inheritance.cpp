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
1. ����� ��Ÿ���� Operator Ŭ������ �����.
Operator Ŭ������ ���� �Լ��� show()�� operate()�� ������.
show()�� �ڽ��� � ������ �ϴ��� ����ϴ� ������ �Ѵ�.ex) Adder
operate()�� �� ���� ������ ���ڷ� �޾Ƽ� ����� �����ϰ� ����ϴ� ������ �Ѵ�.

2. Operator�� ��ӹ޴� Adder, Subtractor, Multiplier, Divider Ŭ������ �����.
������ Ŭ������ �ڽ��� � ������ �ϴ��� ����ϴ� show()�� �������̵��ϰ�,
�� ���� ������ ���ڷ� �޾Ƽ� ����� �����ϰ� ����ϴ� operate()�� �������̵��Ѵ�.

3. Adder, Subtractor, Multiplier, Divider�� ��ӹ޴� Ŭ�������� �����.
IntAdder, floatAdder, IntSubtractor, FloatSubtractor, IntMultiplier, FloatMultiplier, IntDivider, FloatDivider�� �����.
������ Ŭ������ �ڽ��� � ������ �ϴ��� ����ϴ� show()��
�� ���� ������ ���ڷ� �޾Ƽ� ����� �����ϰ� ����ϴ� operate()�� �������̵��Ѵ�.
�̰� �Ϸ��Ѵٸ� ���� ��� ������ ������ ���� ���̴�.
Operator->���->Adder->���->IntAdder, FloatAdder ���

4. Calculator Ŭ������ �����.
Calculator Ŭ������ Operator * �� �����ϴ� list�� operators�� ������ �ִ�.(�� �����͸� ����ϴ����� �� �����غ���)
addOperator()�� Operator * �� ���ڷ� �޾Ƽ� list�� �߰��Ѵ�.
showOperators()�� operators�� �ִ� ��� Operator * ���� show()�� ȣ���Ѵ�.
showOperators() ȣ�� ���ô� ������ ����.(operators�� IntAdder, FloatSubtractor�� ����ִٰ� ����)
IntAdder
FloatSubtractor
getOperator()�� �ε����� ���ڷ� �޾Ƽ� �ش� �ε����� �ִ� Operator * �� ��ȯ�Ѵ�.
�� ������ ���, 1�� ���ڷ� ������ FloatSubtractor�� ��ȯ�Ѵ�.

5. Calculator Ŭ������ ����ϴ� main() �Լ��� �����.
Calculator Ŭ������ �ϳ� �����, IntAdder, FloatSubtractor ���� �����ؼ� addOperator()�� ���� Calculator�� �߰��Ѵ�.
addOperator()�� Operator* �� �Ű������� �޴� �Լ��ε� ��� IntAdder, FloatSubtractor�� ���� �� ������ �� �����غ���.
����, ���α׷��� �帧�� ������ ����.
����ڿ��� operators�� �ִ� Operator* ���� �����ش�.
����ڿ��� Operator* �� �����ϰ� �Ѵ�.(���⼭ - 1�� �����ϸ� ���α׷��� �����Ѵ�.)
����ڿ��� �� ���� ������ �Է¹޴´�.
������ Operator* �� operate()�� ȣ���Ѵ�.
1������ ���ư���.
main() �Լ��� ���� ���ô� ������ ����.
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

.....���� ����(Exit ������ �ݺ�)

*/