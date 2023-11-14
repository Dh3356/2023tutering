#include<iostream>
#include <cstring>
using namespace std;

class Car {
protected:
	int maxSpeed;
	char* name;
	char* company;
public:
	Car(int maxSpeed, const char* name, const char* company) {
		this->maxSpeed = maxSpeed;
		this->name = _strdup(name);
		this->company = _strdup(company);
	}
	void show() {
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "�ְ�ӵ�: " << maxSpeed << endl;
	}
};

class Truck : public Car {
private:
	int max_;
	int now_ = 0;
public:
	Truck(int maxSpeed, const char* name, const char* company, int max) : Car(maxSpeed, name, company), max_(max) {}
	Truck(const Car& car, int max) : Car(car), max_(max) {}
	Truck(const Truck& truck) : Car(truck), max_(truck.max_), now_(truck.now_) {}

	void show() {
		Car::show();
		cout << "�ִ� ���緮: " << max_ << "\n���� ���緮: " << now_ << endl;
	}

};

class Bus :public Car {
private:
	int max_;
	int now_ = 0;
public:
	Bus(int maxSpeed, const char* name, const char* company, int max) : Car(maxSpeed, name, company), max_(max) {}
	Bus(const Car& car, int max) : Car(car), max_(max) {}
	Bus(const Bus& bus) : Car(bus), max_(bus.max_), now_(bus.now_) {}

	void show() {
		Car::show();
		cout << "�ִ� �°���: " << max_ << "\n���� �°���: " << now_ << endl;
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