#include<iostream>

using namespace std;

class Car {
private:
	int maxSpeed;
	char* name;
	char* company;
public:
	Car(int maxSpeed, char* name, char* company) {
		this->maxSpeed = maxSpeed;
		this->name = name;
		this->company = company;
	}
	void show() {
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "�ְ�ӵ�: " << maxSpeed << endl;
	}
};

int main() {
	//Car class�� ��ӹ޴� Truck�� Bus class�� �ۼ��Ͻÿ�.
	//Truck�� �ִ����緮�� �������緮�� ������ �ְ�, Bus�� �ִ�°����� ����°����� ������ �ִ�.
	//Truck�� show() ȣ�� �� Car�� �ִ� ����� �߰��� �ִ����緮�� �������緮�� ����ϰ�,
	//Bus�� show() ȣ�� �� Car�� �ִ� ����� �߰��� �ִ�°����� ����°����� ����Ѵ�.
	//�߰��� �Ʒ� �ڵ尡 ���������� �۵��ϵ��� ��������ڸ� ������
	//��Ʈ: ��������ڵ� ����� �����ϴ�.
	Car car = Car(100, "�ù��ڵ���", "����");
	Truck truck = Truck(100, "�ù�Ʈ��", "����", 100);
	Truck truck2 = Truck(car, 100);
	Truck truck3 = Truck(truck);

	car.show();
	truck.show();
	truck2.show();
	truck3.show();

	Bus bus = Bus(100, "�ù߹���", "����", 100);
	Bus bus2 = Bus(car, 100);
	Bus bus3 = Bus(bus);

	bus.show();
	bus2.show();
	bus3.show();
}