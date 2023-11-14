#include<iostream>
#include<string>

using namespace std;

class Person {
public:
    string name;
    int age;
    char gender;

    Person(string n, int a, char g) : name(n), age(a), gender(g) {}

    void show() {
        cout << "�̸�: " << name << endl;
        cout << "����: " << age << endl;
        cout << "����: " << gender << endl;
    }
};

class Student : public Person {
public:
    int studentN;

    Student(string n, int a, char g, int sn) : Person(n, a, g), studentN(sn) {}

    void show() {
        cout << "�й�: " << studentN << endl;
        Person::show();
    }
};

class Teacher : public Person {
public:
    int tID;

    Teacher(string n, int a, char g, int tid) : Person(n, a, g), tID(tid) {}

    void show() {
        cout << "���� id: " << tID << endl;
        Person::show(); 
    }
};

class Classroom {
public:
    string className;
    Student students[10];
    Teacher teachers[1]; 

    int studentN;
    int teacherN;

    Classroom(string cn) {
        className = cn;
        studentN = 0;
        teacherN = 0;
        students[0] = Student("", 0, '\0', 0);
        teachers[0] = Teacher("", 0, '\0', 0);
    } 

    void addStu(Student s) {
        if (studentN < 10) {
            students[studentN++] = s;
        }
        else {
            cout << "�� �̻� �л��� �߰��� �� �����ϴ�." << endl;
        }
    }

    void addTeacher(Teacher t) {
        if (teacherN < 1) {
            teachers[teacherN++] = t;
        }
        else {
            cout << "�̹� ���簡 �߰��Ǿ����ϴ�." << endl;
        }
    }

    void show() {
        cout << "�� �̸�: " << className << endl;

        cout << "�л� ����:" << endl;
        for (int i = 0; i < studentN; ++i) {
            students[i].show();
            cout << endl;
        }

        cout << "���� ����:" << endl;
        for (int i = 0; i < teacherN; ++i) {
            teachers[i].show();
            cout << endl;
        }
    }
};

int main() {
    Classroom myClass("1��");

    Student student1("ȫ�浿", 20, '��', 60191892);
    myClass.addStu(student1);

    Teacher teacher1("ȫ�浿", 30, '��', 1);
    myClass.addTeacher(teacher1);

    myClass.show();

    return 0;
}