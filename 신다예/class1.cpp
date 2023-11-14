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
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "최고속도: " << maxSpeed << endl;
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
		cout << "최대 적재량: " << max_ << "\n현재 적재량: " << now_ << endl;
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
		cout << "최대 승객수: " << max_ << "\n현재 승객수: " << now_ << endl;
	}

};

int main() {
	//Car class를 상속받는 Truck과 Bus class를 작성하시오.
	//Truck은 최대적재량과 현재적재량을 가지고 있고, Bus는 최대승객수와 현재승객수를 가지고 있다.
	//Truck은 show() 호출 시 Car에 있는 내용과 추가로 최대적재량과 현재적재량을 출력하고,
	//Bus는 show() 호출 시 Car에 있는 내용과 추가로 최대승객수와 현재승객수를 출력한다.
	//추가로 아래 코드가 정상적으로 작동하도록 복사생성자를 만들어라
	//힌트: 복사생성자도 상속이 가능하다.
	Car car = Car(100, "시발자동차", "벤츠");  
	Truck truck = Truck(100, "시발트럭", "벤츠", 100);
	Truck truck2 = Truck(car, 100);
	Truck truck3 = Truck(truck);

	car.show();
	truck.show();
	truck2.show();
	truck3.show();

	Bus bus = Bus(100, "시발버스", "벤츠", 100);
	Bus bus2 = Bus(car, 100);
	Bus bus3 = Bus(bus);

	bus.show();
	bus2.show();
	bus3.show();
}