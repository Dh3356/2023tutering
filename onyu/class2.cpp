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
		cout << "�̸��� :" << name_ << endl;
		cout << "������ :" << sex_ << endl;
		cout << "���̴� :" << age_ << endl;

	}

};
class Class : public Person {
public:
	Class(int id, string name, int age, string sex) : Person(name, age, sex), id_(id) {}
	void show() {
		cout << "�й��� : " << id_ << endl;
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
		cout << "���� Id: " << id_ << endl;
		Person::show();
	}
private:
	int id_;
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

	Class stu1(60232062, "������", 21, "��");
	Teacher tea(1, "����", 10000, "��");

	stu1.show();
	tea.show();
}