#include<iostream>
#include<string>

using namespace std;

class Person {
public:
    string name;
    int age;
    string gender;

    Person(string n, int a, string g) : name(n), age(a), gender(g) {}

    void show() {
        cout << "�̸�: " << name << endl;
        cout << "����: " << age << endl;
        cout << "����: " << gender << endl;
    }
};

class Student : public Person {
public:
    int studentN;

    Student(string n, int a, string g, int sn) : Person(n, a, g), studentN(sn) {}

    void show() {
        cout << "�й�: " << studentN << endl;
        Person::show();
    }
};

class Teacher : public Person {
public:
    int tID;

    Teacher(string n, int a, string g, int tid) : Person(n, a, g), tID(tid) {}

    void show() {
        cout << "���� id: " << tID << endl;
        Person::show(); 
    }
};

class Classroom {
public:
    string className;
    Student* students[2];
    Teacher* teachers[1];

    int studentN;
    int teacherN;

    Classroom(string cn) : className(cn), studentN(0), teacherN(0) {
        for (int i = 0; i < 2; i++){
            students[i] = nullptr;
        }
        teachers[0] = nullptr;
    }

    void addStu(Student *s) {
        if (studentN < 2){
            students[studentN++] = s;
        }
        else {
            cout << "�� �̻� �л��� �߰��� �� �����ϴ�." << endl;
        }
    }

    void addTeacher(Teacher *t) {
        if (teacherN < 2){
            teachers[teacherN++] = t;
        }
        else {
            cout << "�̹� ���簡 �߰��Ǿ����ϴ�." << endl;
        }
    }

    void show() {
        cout << "�� �̸�: " << className << endl;

        cout << "�л� ����:" << endl;
        for (int i = 0; i < studentN; i++){
            students[i]->show();
            cout << endl;
        }

        cout << "���� ����:" << endl;
        for (int i = 0; i < teacherN; i++){
            teachers[i]->show();
            cout << endl;
        }
    }
};

int main() {
    int menu = 0;
    int id = 0;
    string name;
    int age;
    string gender;

    Classroom myClass("1��");

  
    while (1) {
        cout << "�޴�:\n1. �л��� ���� �Է�\n2.������ ���� �Է�\n3.���� ���\n4.����\n";
        cin >> menu;

        if (menu==1) {
            cout << "�л��� �̸��� ���� ����, �л� ���̵� �Է��ϼ���: " << endl;
            cin >> name >> age >> gender>>id;
            Student* student1 = new Student(name, age, gender, id);
            myClass.addStu(student1);
        }
        else if (menu==2) {
            cout << "������ �̸��� ���� ����, ���� ���̵� �Է��ϼ���: " << endl;
            cin >> name >> age >> gender >> id;
            Teacher* teacher1 = new Teacher(name, age, gender, id);
            myClass.addTeacher(teacher1);

        }
        else if (menu==3) {
            myClass.show();
        }
        else if (menu==4){
            cout << "����" << endl;
            break;
        }


    }
   

    return 0;
}