#include<iostream>
#include<list>
using namespace std;


class Operator {
public:

	virtual void show() {}
	virtual int operate(int a, int b) { 
		return 0; 
	}  
	virtual float operate(float a, float b) {
		return 0.0;
	}
	
};

class Adder : public Operator { //더하기
public:
	void show() {}
	int operate(int a, int b) {
		return a + b;
	}
};

class Substractor : public Operator { //빼기
public:
	void show() {}
	int operate(int a, int b) {
		return a - b;
	}
};

class Multiplier : public Operator { //곱하기
public:
	void show() {}
	int operate(int a, int b) {
		return a * b;
	}
};

class Divider : public Operator { //나누기
public:
	void show() {}
	int operate(int a, int b) {
		return a / b;
	}
};

class IntAdder : public Adder {
public:
	void show() {
		cout << "IntAdder" << std::endl;
	}
	int operate(int a, int b) {
		return Adder::operate(a, b);
	}
};

class FloatAdder : public Adder {
public:
	void show() {
		cout << "floatAdder" << std::endl;
	}
	float operate(float a, float b) {
		return (float)a + (float)b;
	}
};

class IntSubtractor : public Substractor {
public:
	void show() {
		cout << "IntSubtractor" << std::endl;
	}
	int operate(int a, int b) {
		return Substractor::operate(a, b);
	}
};

class FloatSubtractor : public Substractor {
public:
	void show() {
		cout << "FloatSubtractor" << std::endl;
	}
	float operate(float a, float b) {
		return (float)a - b;
	}
};

class IntMultiplier : public Multiplier {
public:
	void show() {
		cout << "IntMultiplier" << std::endl;
	}
	int operate(int a, int b) {
		return Multiplier::operate(a, b);
	}
};

class FloatMultiplier : public Multiplier {
public:
	void show() {
		cout << "FloatMultiplier" << std::endl;
	}
	float operate(float a, float b) {
		return (float)a * b;
	}
};

class IntDivider : public Divider{
public:
	void show() {
		cout << "IntDivider" << std::endl;
	}
	int operate(int a, int b) {
		return Divider::operate(a, b);
	}
};

class FloatDivider : public Divider {
public:
	void show() {
		cout << "FloatDivider" << std::endl;
	}
	float operate(float a, float b) {
		return (float)a / b;
	}
};


class Calculator {
private:
	list<Operator*> operators_;
	int num_ = 0;

public:

	Calculator() {
		
	}

	void addOperator(Operator * o) {
		operators_.push_back(o);
		num_++;
	}

	void showOperators() { 

		cout << "\n-1. Exit" << endl;
		int i = 0;
		list<Operator*>::iterator it;
		for (it = operators_.begin(); it != operators_.end(); it++) {
			cout << i << ". ";  
			(*it)->show();     
			i++;
		}
		cout << "\n" << endl;
	}

	Operator* getOperator(int choice) {

		list<Operator*>::iterator it = operators_.begin();
		advance(it, choice);
		
			return *it;
	}

	
};

int main() {

	
	int choice;
	Calculator calculator;

	calculator.addOperator(new IntAdder());
	calculator.addOperator(new FloatAdder());
	calculator.addOperator(new IntSubtractor());
	calculator.addOperator(new FloatSubtractor());
	calculator.addOperator(new IntMultiplier());
	calculator.addOperator(new FloatMultiplier());
	calculator.addOperator(new IntDivider());
	calculator.addOperator(new FloatDivider());

	while (1) {

		calculator.showOperators();

		cout << "\nEnter your choice: ";
		cin >> choice;
		if (choice == -1) {
			break;
		}
		else if (choice >= 0 && choice <= 7) {
			if ((choice % 2) == 0) {
				Operator* opt = calculator.getOperator(choice);
				
				int a;
				int b;

				cout << "Enter operands(op1, op2): ";
				cin >> a >> b;

				cout << "result: " << opt->operate(a, b) << endl;
			}
			else {
				Operator* opt = calculator.getOperator(choice);
				
				float a;
				float b;

				cout << "Enter operands(op1, op2): ";
				cin >> a >> b;

				cout << "result: " << opt->operate(a, b) << endl;
			}
			
		}
		else {
			cout << "잘못된 메뉴\n";
			continue;
		}

	}



	return 0;
}