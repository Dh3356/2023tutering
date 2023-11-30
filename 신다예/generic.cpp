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
	//���� ������ ������� ���� ���α׷��� generic�� ����� �����͸��Ѵ�.
	//Calculator���� list�� Operator�� �����ϴ� ���� �ݵ�� �����Ѵ�.
	//������ intAdder, floatAdder ��� �ڷ����� ���� �и��Ǿ� �־���.
	//�̴� �ڵ��� �ߺ��� �߱��ϰ�, ���������� ��ư� �����.
	//�̸� generic�� ����� �����͸��Ѵ�.
	//�����͸��� �ϸ鼭, ������ �ִ� ����� �����Ѵ�.
	//Operator�� show�� operate�� ���� �����Լ��� ����� �ڽ� Ŭ�������� �����ϰ� �����.
	//Operator�� ��ӹ޴� Adder, Subtractor, Multiplier, Divider�� �����.
	//Calculator�� �ڵ�� ������ ���� ���̴�.
	//�����͸��� �Ϸ������� main���� ����Ѵ�. ��� ���ô� ������ ����.

	//-1. Exit
	//1. IntAdder
	//2. IntSubtractor
	//3. IntMultiplier
	//4. FloatDivider
	//Select operator: 1
	//insert op1: 1
	//insert op2: 2
	//result: 3
	//�ݺ�

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
        cout << "-1. Exit\n1.int��� \n2.float���" << endl;
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
            cout << "�߸��� �޴���ȣ\n";
        }

    }

    return 0;

}