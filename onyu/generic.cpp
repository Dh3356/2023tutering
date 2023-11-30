#include<iostream>
#include<list>
using namespace std;

template <class T>
class Operator {
public:
    Operator() {}
    virtual ~Operator() {}
    virtual T operate(T op1, T op2) = 0;
    virtual void show() = 0;
};

template<class T>
class Adder : public Operator<T> {
public:
    void show() override {
        cout << "Adder" << endl;
    }
    T operate(T op1, T op2) override {
        return op1 + op2;
    }
};
template <class T>
class Subtractor : public Operator<T> {
public:
    void show() override {
        cout << "Substractor" << endl;
    }
    T operate(T op1, T op2) {
        return op1 - op2;
    }
};
template <class T>
class Multiplier : public Operator<T> {
public:
    void show() override {
        cout << "Multiplier" << endl;
    }
    T operate(T op1, T op2) override {
        return op1 * op2;
    }
};
template <class T>
class Divider : public Operator<T> {
public:
    void show() override {
        cout << "Divider" << endl;
    }
    T operate(T op1, T op2) override {
        return op1 / op2;
    }
};

template <class T>
class Calculator {
private:
    list<Operator<T>*> operators;
public:
    Calculator() {}

    void addOperator(Operator<T>* op) {
        operators.push_back(op);
    }

    void showOperators() const {
        int i = 1;
        for (const auto op : operators) {
            cout << i++ << ". ";
            op->show();
        }
    }
    void showFOperators() const {
        int i = 1;
        for (const auto op : operators) {
            cout << i++ << ". ";
            op->show();
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
    }
};

int main() {
    Operator<int>* intAdder = new Adder<int>();
    Operator<int>* intSubtractor = new Subtractor<int>();
    Operator<int>* intMultiplier = new Multiplier<int>();
    Operator<float>* floatDivider = new Divider<float>();

    Calculator<int> cal;
    Calculator<float> Fcal;

    cal.addOperator(intAdder);
    cal.addOperator(intSubtractor);
    cal.addOperator(intMultiplier);
    Fcal.addOperator(floatDivider);


    int op1, op2;
    float opp1, opp2;

    while (true) {
        cout << "-1. Exit" << endl;
        cout << "1번. int계산" << endl;
        cout << "2번. float계산" << endl;
        int ch = 0;
        cin >> ch;
        if (ch == -1) {
            break;
        }
        if (ch == 1) {
            int chose = 0;
            cal.showOperators();
            cin >> chose;
            if (chose >= 1 && chose <= 3) {
                Operator<int>* selectedIntOp = cal.getOperator(chose - 1);
                int op1, op2;
                cout << "insert op1: ";
                cin >> op1;
                cout << "insert op2: ";
                cin >> op2;
                cout << "result: " << selectedIntOp->operate(op1, op2) << endl;
            }
        }
        else if (ch == 2) {
            int chose = 0;
            Fcal.showFOperators();
            cin >> chose;
            if (chose >= 1 && chose <= 1) {
                Operator<float>* selectedFloatOp = Fcal.getOperator(chose - 1);
                float opp1, opp2;
                cout << "insert op1: ";
                cin >> opp1;
                cout << "insert op2: ";
                cin >> opp2;
                cout << "result: " << selectedFloatOp->operate(opp1, opp2) << endl;
            }
        }
        else {
            cout << "잘못된 선택" << endl;
        }
    }





    return 0;
}
