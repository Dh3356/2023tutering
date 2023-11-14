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
		cout << "�̸�: " << name_ << "\n����: " << age_ << "\n����: " << gender_ << endl;
	}

};

class Student : public Person {
private:
	int stuID_;
public:
	Student(int id, string name, int age, string gender) : stuID_(id), Person(name, age, gender) {};

	void show() {
		cout << "�й�: " << stuID_ << endl;
		Person::show();
	}
};

class Teacher : public Person {
private:
	int tID_;
public:
	Teacher(int id, string name, int age, string gender) : tID_(id), Person(name, age, gender) {};
	
	void show() {
		cout << "���� id: " << tID_ << endl;
		Person::show();
	}
};

int main() {
	//�� Ŭ������ ������
	//�ݿ��� ���� ���� �л��� �� ���� ���簡 �����Ѵ�.
	//�л��� ����� Person Ŭ������ ��ӹ޴´�.
	//Person Ŭ������ �̸�, ����, ������ ������ �ִ�.
	//�л��� �й��� ������ �ְ�, ����� ���� ID�� ������ �ִ�.
	//�ݿ��� �л��� ���縦 �߰��� �� �ְ�, ���� ������ ����� �� �ִ�.
	//���� ������ ����� ���� �л��� ������ ������ ��� ����Ѵ�.

	//�л��� ������ ������ ���� ��µȴ�.
	//�й� : 60191892
	//�̸� : ȫ�浿
	//���� : 20
	//���� : ��

	//������ ������ ������ ���� ��µȴ�.
	//���� id : 1
	//�̸� : ȫ�浿
	//���� : 20
	//���� : ��

	//��ġ�� �͵��� ����� ���� �ذ��϶�

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

		cout << "�޴�:\n1. �л��� ���� �Է�\n2.������ ���� �Է�\n3.���� ���\n4.����\n";
		cin >> choice;

		if (choice == 1) {
			cout << "�л��� �й�, �̸�, ����, ������ �Է����ּ��䱸��Ʈ\n";
			cin >> id >> name >> age >> gender;
			//Student student(id, name, age, gender);
			stuList[stuNum] = new Student(id, name, age, gender);
			stuNum++;
		}
		else if (choice == 2) {
			cout << "������ id, �̸�, ����, ������ �Է����ּ��䱸��Ʈ\n";
			cin >> id >> name >> age >> gender;
			//Teacher teacher(id, name, age, gender);
			tList[tNum] = new Teacher(id, name, age, gender);
			tNum++;
		}
		else if (choice == 3) {
			cout << "\n�л� ����: " << endl;
			for (int i = 0; i < stuNum; i++) {
				stuList[i]->show();
			}
			cout << "\n���� ����: " << endl;
			for (int i = 0; i < tNum; i++) {
				tList[i]->show();
			}
			cout << endl;
		}
		else if (choice == 4) {
			cout << "\n���α׷��� �����մϴٶ���.\n";
			break;
		}

	}

}