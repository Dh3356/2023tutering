#include<iostream>
#include<list>

using namespace std;

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
	Operator<int>* intMultiplier = new Multiplier<int>();
	Operator<float>* floatDivider = new Divider<float>();

	//���Ĵ� �˾Ƽ� ����
	return 0;
}