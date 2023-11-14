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
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "최고속도: " << maxSpeed << endl;
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
		cout << "최대적재량: " << max_ << endl;
		cout << "현재적재량: " << current << endl;
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
		cout << "최대승객수: " << maxP << endl;
		cout << "현재승객수: " << minP << endl;
	}
};
int main() {
	//Car class를 상속받는 Truck과 Bus class를 작성하시오.
	//Truck은 최대적재량과 현재적재량을 가지고 있고, Bus는 최대승객수와 현재승객수를 가지고 있다.
	//Truck은 show() 호출 시 Car에 있는 내용과 추가로 최대적재량과 현재적재량을 출력하고,
	//Bus는 show() 호출 시 Car에 있는 내용과 추가로 최대승객수와 현재승객수를 출력한다.
	//추가로 아래 코드가 정상적으로 작동하도록 복사생성자를 만들어라
	//힌트: 복사생성자도 상속이 가능하다.
	Car car = Car(100, "자동차", "벤츠");
	Truck truck1 = Truck(100, "트럭", "벤츠", 100);
	Truck truck2 = Truck(car, 100);
	Truck truck3 = Truck(truck1);

	car.show();
	truck1.show();
	truck2.show();
	truck3.show();
	Bus bus = Bus(100, "시발버스", "벤츠", 100);
	Bus bus2 = Bus(car, 100);
	Bus bus3 = Bus(bus);

	bus.show();
	bus2.show();
	bus3.show();

}