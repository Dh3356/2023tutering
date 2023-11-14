#include<iostream>
#include<cstring>

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
	Car(const Car& newC) {
		maxSpeed = newC.maxSpeed;
		name = _strdup(newC.name);
		company = _strdup(newC.company);
	}
	void show() {
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "최고속도: " << maxSpeed << endl;
	}
	~Car() {
		delete[] name;
		delete[] company;
	}
};

class Truck:public Car{
private:
	int maxLoad_;
	int currentLoad_;
public:
	Truck(int maxSpeed, const char* name, const char* company, int maxLoad) 
		:maxLoad_(maxLoad), currentLoad_(0), Car(maxSpeed, name, company) {}

	Truck(const Car& car, int maxLoad) 
		: Car(car), maxLoad_(maxLoad), currentLoad_(0) {}

	Truck(const Truck& newT)
		:maxLoad_(newT.maxLoad_), currentLoad_(newT.currentLoad_), Car(newT.maxSpeed, newT.name, newT.company) {}

	void Show() {
		Car::show();
		cout<<"최대적재량은 "<<maxLoad_<<"입니다."<<endl;
		cout<<""<<currentLoad_<<"입니다."<<endl;
	}
};

class Bus:public Car{
private:
	int maxPass;
	int currentPass;
public:
	Bus(int maxSpeed, const char* name, const char* company, int maxPass) 
		:Car(maxSpeed, name, company), maxPass(maxPass), currentPass(0) {}

	Bus(const Car& car, int maxPass) 
		: Car(car), maxPass(maxPass), currentPass(0) {}

	Bus(const Bus& newB)
		:Car(newB.maxSpeed, newB.name, newB.company), maxPass(newB.maxPass), currentPass(newB.currentPass) {}

	void show() {
		Car::show();
		cout << "최대승객수는 " << maxPass <<"입니다."<< endl;
		cout << "현재승객수는 " << currentPass<<"입니다."<< endl;
	}

};

int main() {
	
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