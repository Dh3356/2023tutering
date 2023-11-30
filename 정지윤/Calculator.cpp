#include<iostream>
#include<list>
using namespace std;

template<class T>
class Operator {
public:
	Operator() {}
	virtual void operate(T op1, T op2) = 0;
	virtual void show() = 0;
};

template<class T>
class Adder : public Operator<T> {
public:
	Adder() {}
	void operate(T op1, T op2) override {
		cout << op1 + op2 << endl;
	}
	void show() override {
		cout << "Adder" << endl;
	}
};


template<class T>
class Subtractor : public Operator<T> {
public:
	Subtractor() {}
	void show() override {
		cout << "Subtractor" << endl;
	}
	void operate(T op1, T op2) override {
		cout <<op1 -op2 << endl;
	}
};

template<class T>
class Multiplier : public Operator<T> {
public:
	Multiplier() {}
	void show() override {
		cout << "Multiplier" << endl;
	}
	void operate(T op1, T op2) override {
		cout <<op1 *op2 << endl;
	}
};

template<class T>
class Divider : public Operator<T> {
public:
	Divider() {}
	void show() override {
		cout << "Divider" << endl;
	}
	void operate(T op1, T op2) override {
		if (isOpValid(op1, op2)) {
			cout << "Invalid operation" << endl;
			return;
		}
		cout << op1 / op2 << endl;
	}
	bool isOpValid(T op1, T op2) {
		return op2 != 0;
	}
};

template<class T>
class Calculator {
private:
	list<Operator<T>*> operators;
public:
	Calculator() {
		operators = list<Operator<T>*>();
	}
	void addOperator(Operator<T>* op) {
		operators.push_back(op);
	}
	void showOperators() {
		int i = 0;
		for (auto op : operators) {
			cout << i++ << ". ";
			(*op).show();
		}
	}
	Operator<T>* getOperator(int index) {
		int i = 0;
		for (auto op : operators) {
			if (i == index) {
				return op;
			}
			i++;
		}
		throw "Invalid index";
	}
};

int main() {
	
	int menu;
	int choice;

	Calculator<int> intCalculator;
	Calculator<float> floatCalculator;

	Operator<int>* intAdder = new Adder<int>();
	Operator<int>* intSubtractor = new Subtractor<int>();
	Operator<int>* intMultiplier = new Multiplier<int>();
	Operator<int>* intDivider = new Divider<int>();
	Operator<float>* floatAdder = new Adder<float>();
	Operator<float>* floatSubtractor = new Subtractor<float>();
	Operator<float>* floatMultiplier = new Multiplier<float>();
	Operator<float>* floatDivider = new Divider<float>();

	intCalculator.addOperator(intAdder);
	intCalculator.addOperator(intSubtractor);
	intCalculator.addOperator(intMultiplier);
	intCalculator.addOperator(intDivider);
	floatCalculator.addOperator(floatAdder);
	floatCalculator.addOperator(floatSubtractor);
	floatCalculator.addOperator(floatMultiplier);
	floatCalculator.addOperator(floatDivider);
	
	while (1) {

		cout << "-1. Exit" << endl;
		printf("정수 계산을 하고 싶다면 1을 누르세요.\n");
		printf("유리수 계산을 하고 싶다면 2를 누르세요.\n");
		cin >> menu;

		if (menu == -1) {
			break;
		}

		else if (menu == 1) {

			intCalculator.showOperators();
			printf("계산을 그만하고 싶다면 -1을 누르세요. \n");

			cout << "\nEnter your choice: ";
			cin >> choice;
			if (choice == -1) {
				break;
			}
			else if (choice >= 0 && choice <= 3) {

				Operator<int>* opt = intCalculator.getOperator(choice);

				int a;
				int b;

				cout << "Enter operands(op1, op2): ";
				cin >> a >> b;

				cout << "result: ";
				opt->operate(a, b);
			}
		}
		else if (menu==2) {

			floatCalculator.showOperators();
			printf("계산을 그만하고 싶다면 -1을 누르세요. \n");

			cout << "\nEnter your choice: ";
			cin >> choice;

			if (choice == -1) {
				break;
			}
			else if (choice >= 0 && choice <= 3) {
				Operator<float>* opt = floatCalculator.getOperator(0);

				float a, b;

				cout << "Enter operands(op1, op2): ";
				cin >> a >> b;

				cout << "Result: ";
				opt->operate(a, b);
			}
		}
		else {
			cout << "잘못된 메뉴\n";
			continue;
		}
	}
	return 0;
}