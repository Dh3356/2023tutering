#include<iostream>

using namespace std;

int main() {
	// ���� Ŭ������ ������.
	// 1. ����� ��Ÿ���� Operator Ŭ������ �����.
	// Operator Ŭ������ ���� �Լ��� show()�� operate()�� ������.
	// show()�� �ڽ��� � ������ �ϴ��� ����ϴ� ������ �Ѵ�. ex) Adder
	// operate()�� �� ���� ������ ���ڷ� �޾Ƽ� ����� �����ϰ� ����ϴ� ������ �Ѵ�.
	// 2. Operator�� ��ӹ޴� Adder, Subtractor, Multiplier, Divider Ŭ������ �����.
	// 
	// ������ Ŭ������ �ڽ��� � ������ �ϴ��� ����ϴ� show()��
	// �� ���� ������ ���ڷ� �޾Ƽ� ����� �����ϰ� ����ϴ� operate()�� �������̵��Ѵ�.
	// 
	// 3. Adder, Subtractor, Multiplier, Divider�� ��ӹ޴� Ŭ�������� �����.
	// IntAdder, floatAdder, IntSubtractor, FloatSubtractor, IntMultiplier, FloatMultiplier, IntDivider, FloatDivider�� �����.
	// ������ Ŭ������ �ڽ��� � ������ �ϴ��� ����ϴ� show()��
	// �� ���� ������ ���ڷ� �޾Ƽ� ����� �����ϰ� ����ϴ� operate()�� �������̵��Ѵ�.
	// �̰� �Ϸ��Ѵٸ� ���� ��� ������ ������ ���� ���̴�. 
	// Operator ->���-> Adder ->���-> IntAdder, FloatAdder ���
	// 
	// 4. Calculator Ŭ������ �����.
	// Calculator Ŭ������ Operator*�� �����ϴ� list�� operators�� ������ �ִ�.(�� �����͸� ����ϴ����� �� �����غ���)
	// addOperator()�� Operator*�� ���ڷ� �޾Ƽ� list�� �߰��Ѵ�.
	// showOperators()�� operators�� �ִ� ��� Operator*���� show()�� ȣ���Ѵ�.
	// 
	// showOperators() ȣ�� ���ô� ������ ����.(operators�� IntAdder, FloatSubtractor�� ����ִٰ� ����)
	// 0. IntAdder
	// 1. FloatSubtractor
	//
	// getOperator()�� �ε����� ���ڷ� �޾Ƽ� �ش� �ε����� �ִ� Operator*�� ��ȯ�Ѵ�.
	// �� ������ ���, 1�� ���ڷ� ������ FloatSubtractor�� ��ȯ�Ѵ�.
	//
	// 5. Calculator Ŭ������ ����ϴ� main() �Լ��� �����.
	// Calculator Ŭ������ �ϳ� �����, IntAdder, FloatSubtractor ���� �����ؼ� addOperator()�� ���� Calculator�� �߰��Ѵ�.
	// addOperator()�� Operator*�� �Ű������� �޴� �Լ��ε� ��� IntAdder, FloatSubtractor�� ���� �� ������ �� �����غ���.
	// 
	// ����, ���α׷��� �帧�� ������ ����.
	// 
	// 1. ����ڿ��� operators�� �ִ� Operator*���� �����ش�.
	// 2. ����ڿ��� Operator*�� �����ϰ� �Ѵ�.(���⼭ -1�� �����ϸ� ���α׷��� �����Ѵ�.)
	// 3. ����ڿ��� �� ���� ������ �Է¹޴´�.
	// 4. ������ Operator*�� operate()�� ȣ���Ѵ�.
	// 5. 1������ ���ư���.
	// main() �Լ��� ���� ���ô� ������ ����.
	// 
	// 0. IntAdder
	// 1. FloatSubtractor
	// 2. IntSubtractor
	// 3. FloatAdder
	// 4. IntMultiplier
	// 5. FloatMultiplier
	// 6. IntDivider
	// 7. FloatDivider
	// -1. Exit
	// 
	// Enter your choice: 1
	// Enter operands(op1, op2): 1 2
	// 
	// result: -1
	// .....���� ����
	return 0;
}