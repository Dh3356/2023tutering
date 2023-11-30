#include<iostream>
#include<list>
#include<string>
using namespace std;

template<class T>
class Operator {
public:
    virtual void operate(T op1, T op2) = 0;
    virtual void show(string s) = 0;
};

template<class T>
class Adder : public Operator<T> {
public:
    void show(string s) {
        cout << s;
        cout << "Adder" << endl;
    }
    void operate(T op1, T op2) override {
        cout << op1 + op2 << endl;
    }
};

template<class T>
class Subtractor : public Operator<T> {
public:
    void show(string s) {
        cout << s;
        cout << "Subtractor" << endl;
    }
    void operate(T op1, T op2) override {
        cout << op1 - op2 << endl;
    }
};

template<class T>
class Multiplier : public Operator<T> {
public:
    void show(string s) {
        cout << s;
        cout << "Multiplier" << endl;
    }
    void operate(T op1, T op2) override {
        cout << op1 * op2 << endl;
    }
};

template<class T>
class Divider : public Operator<T> {
public:
    void show(string s) {
        cout << s;
        cout << "Divider" << endl;
    }
    void operate(T op1, T op2) override {
        cout << op1 / op2 << endl;
    }
};

template<class T>
class Calculator {
private:
    list<Operator<T>*> operators_;

public:
    
    Calculator() {
        operators_ = list<Operator<T>*>();
    }
    void addOperator(Operator<T>* o) {
        operators_.push_back(o);    
    }
    void showOperators(string s) {
        int i = 0;
        for (auto op : operators_) {
            cout << i++ << ". ";
            (*op).show(s);
        }     
    }

    Operator<T>* getOperator(int c) {
        int i = 0;
        for (auto op : operators_) {
            if (i == c) {
                return op;
            }
            i++;
        }
    }
    
};


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
	Operator<float>* intMultiplier = new Multiplier<float>();
	Operator<float>* floatDivider = new Divider<float>();

    Calculator<int> calculator;
    Calculator<float> Fcalculator;
    
    calculator.addOperator(intAdder);
    calculator.addOperator(intSubtractor);
    Fcalculator.addOperator(intMultiplier);
    Fcalculator.addOperator(floatDivider);

    int choiceCalcurator;
    int choice;
    string s;

    while (1) {

        int i = 0;
        cout << "-1. Exit\n1.int계산 \n2.float계산" << endl;
        cin >> choiceCalcurator;

        if (choiceCalcurator == 1) {
            s = "Int";
            calculator.showOperators(s);
            cout << "\nSelect operator: ";
            cin >> choice;

            Operator<int>* opt = calculator.getOperator(choice);
            int a;
            int b;

            cout << "insert op1: ";
            cin >> a;
            cout << "insert op2: ";
            cin >> b;

            cout << "result: ";
            opt->operate(a, b);

        }
        else if (choiceCalcurator == 2) {
            s = "Float";
            Fcalculator.showOperators(s);
            cout << "\nSelect operator: ";
            cin >> choice;

            Operator<float>* Fopt = Fcalculator.getOperator(choice);
            float a;
            float b;

            cout << "insert op1: ";
            cin >> a;
            cout << "insert op2: ";
            cin >> b;

            cout << "result: ";
            Fopt->operate(a, b);

        }
        else if (choiceCalcurator == -1) {
            break;
        }
        else {
            cout << "잘못된 메뉴번호\n";
        }

    }

    return 0;

}