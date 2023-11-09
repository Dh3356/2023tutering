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
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "최고속도: " << maxSpeed << endl;
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