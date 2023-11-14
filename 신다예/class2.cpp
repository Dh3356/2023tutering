#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
	string name_;
	int age_;
	string gender_;

public:
	Person(string name, int age, string gender) : name_(name), age_(age), gender_(gender) {};
	
	void show() {
		cout << "이름: " << name_ << "\n나이: " << age_ << "\n성별: " << gender_ << endl;
	}

};

class Student : public Person {
private:
	int stuID_;
public:
	Student(int id, string name, int age, string gender) : stuID_(id), Person(name, age, gender) {};

	void show() {
		cout << "학번: " << stuID_ << endl;
		Person::show();
	}
};

class Teacher : public Person {
private:
	int tID_;
public:
	Teacher(int id, string name, int age, string gender) : tID_(id), Person(name, age, gender) {};
	
	void show() {
		cout << "교사 id: " << tID_ << endl;
		Person::show();
	}
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

	int stuNum = 0;
	int tNum = 0;
	Student* stuList[100];
	Teacher* tList[100];

	while (1) {
		int choice;

		int id;
		string name;
		int age;
		string gender;

		cout << "메뉴:\n1. 학생의 정보 입력\n2.교사의 정보 입력\n3.정보 출력\n4.종료\n";
		cin >> choice;

		if (choice == 1) {
			cout << "학생의 학번, 이름, 나이, 성별을 입력해주세요구르트\n";
			cin >> id >> name >> age >> gender;
			//Student student(id, name, age, gender);
			stuList[stuNum] = new Student(id, name, age, gender);
			stuNum++;
		}
		else if (choice == 2) {
			cout << "교사의 id, 이름, 나이, 성별을 입력해주세요구르트\n";
			cin >> id >> name >> age >> gender;
			//Teacher teacher(id, name, age, gender);
			tList[tNum] = new Teacher(id, name, age, gender);
			tNum++;
		}
		else if (choice == 3) {
			cout << "\n학생 정보: " << endl;
			for (int i = 0; i < stuNum; i++) {
				stuList[i]->show();
			}
			cout << "\n교사 정보: " << endl;
			for (int i = 0; i < tNum; i++) {
				tList[i]->show();
			}
			cout << endl;
		}
		else if (choice == 4) {
			cout << "\n프로그램을 종료합니다람쥐.\n";
			break;
		}

	}

}