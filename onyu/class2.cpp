#include<iostream>
#include <string>
using namespace std;
class Person {
private:
	string name_;
	int age_;
	string sex_;

public:
	Person(string name, int age, string sex) : name_(name), age_(age), sex_(sex) {}
	void show() {
		cout << "이름은 :" << name_ << endl;
		cout << "성별은 :" << sex_ << endl;
		cout << "나이는 :" << age_ << endl;

	}

};
class Class : public Person {
public:
	Class(int id, string name, int age, string sex) : Person(name, age, sex), id_(id) {}
	void show() {
		cout << "학번은 : " << id_ << endl;
		Person::show();
		cout << endl;
	}
private:
	int id_;
};
class Teacher : public Person {
public:
	Teacher(int id, string name, int age, string sex) : Person(name, age, sex), id_(id) {}
	void show() {
		cout << "교사 Id: " << id_ << endl;
		Person::show();
	}
private:
	int id_;
};

int main() {
	//반 클래스를 만들자
	//반에는 여러 명의 학생과 한 명의 교사가 존재한다.
	//학생과 교사는 Person 클래스를 상속받는다.
	//Person 클래스는 이름, 나이, 성별을 가지고 있다.
	//학생은 학번을 가지고 있고, 교사는 교사 ID를 가지고 있다.
	//반에는 학생과 교사를 추가할 수 있고, 반의 정보를 출력할 수 있다.
	//반의 정보를 출력할 때는 학생과 교사의 정보를 모두 출력한다.

	//학생의 정보는 다음과 같이 출력된다.
	//학번 : 60191892
	//이름 : 홍길동
	//나이 : 20
	//성별 : 남

	//교사의 정보는 다음과 같이 출력된다.
	//교사 id : 1
	//이름 : 홍길동
	//나이 : 20
	//성별 : 남

	//겹치는 것들은 상속을 통해 해결하라

	Class stu1(60232062, "조온유", 21, "남");
	Teacher tea(1, "으악", 10000, "남");

	stu1.show();
	tea.show();
}