#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
	int maxSpeed;
	char* name;
	char* company;
public:

	Car(int maxSpeed, const char* name, const char* company) : maxSpeed(maxSpeed) {
		this->name = _strdup(name);
		this->company = _strdup(company);
	}
	Car(const Car& carr) {
		maxSpeed = carr.maxSpeed;
		this->name = _strdup(carr.name);
		this->company = _strdup(carr.company);
	}
	~Car() {
		delete[] name;
		delete[] company;
	}

	void show() {
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "�ְ�ӵ�: " << maxSpeed << endl;
	}
};
class Truck : public Car {

public:

	Truck(int max, const char* name, const char* com, int n) : Car(0, name, com), max_(max), current(n) {}

	Truck(const Car& car, int max) :Car(car), max_(max), current(0) {
	}
	Truck(const Truck& truck) : Car(truck), max_(truck.max_), current(truck.current) {}
	void show() {
		Car::show();
		cout << "�ִ����緮: " << max_ << endl;
		cout << "�������緮: " << current << endl;
	}
private:
	int max_;
	int current;
};
class Bus : public Car {
private:
	int maxP;
	int minP;
public:
	Bus(int min, const char* name, const char* com, int max) : Car(0, name, com), minP(min), maxP(max) {}
	Bus(const Car& car, int max) : Car(car), maxP(max), minP(0) {}
	Bus(const Bus& bus) : Car(bus), maxP(bus.maxP), minP(bus.minP) {}
	void show() {
		Car::show();
		cout << "�ִ�°���: " << maxP << endl;
		cout << "����°���: " << minP << endl;
	}
};
int main() {
	//Car class�� ��ӹ޴� Truck�� Bus class�� �ۼ��Ͻÿ�.
	//Truck�� �ִ����緮�� �������緮�� ������ �ְ�, Bus�� �ִ�°����� ����°����� ������ �ִ�.
	//Truck�� show() ȣ�� �� Car�� �ִ� ����� �߰��� �ִ����緮�� �������緮�� ����ϰ�,
	//Bus�� show() ȣ�� �� Car�� �ִ� ����� �߰��� �ִ�°����� ����°����� ����Ѵ�.
	//�߰��� �Ʒ� �ڵ尡 ���������� �۵��ϵ��� ��������ڸ� ������
	//��Ʈ: ��������ڵ� ����� �����ϴ�.
	Car car = Car(100, "�ڵ���", "����");
	Truck truck1 = Truck(100, "Ʈ��", "����", 100);
	Truck truck2 = Truck(car, 100);
	Truck truck3 = Truck(truck1);

	car.show();
	truck1.show();
	truck2.show();
	truck3.show();
	Bus bus = Bus(100, "�ù߹���", "����", 100);
	Bus bus2 = Bus(car, 100);
	Bus bus3 = Bus(bus);

	bus.show();
	bus2.show();
	bus3.show();

}