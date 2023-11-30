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
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
        cout << "성별: " << gender << endl;
    }
};

class Student : public Person {
public:
    int studentN;

    Student(string n, int a, string g, int sn) : Person(n, a, g), studentN(sn) {}

    void show() {
        cout << "학번: " << studentN << endl;
        Person::show();
    }
};

class Teacher : public Person {
public:
    int tID;

    Teacher(string n, int a, string g, int tid) : Person(n, a, g), tID(tid) {}

    void show() {
        cout << "교사 id: " << tID << endl;
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
            cout << "더 이상 학생을 추가할 수 없습니다." << endl;
        }
    }

    void addTeacher(Teacher *t) {
        if (teacherN < 2){
            teachers[teacherN++] = t;
        }
        else {
            cout << "이미 교사가 추가되었습니다." << endl;
        }
    }

    void show() {
        cout << "반 이름: " << className << endl;

        cout << "학생 정보:" << endl;
        for (int i = 0; i < studentN; i++){
            students[i]->show();
            cout << endl;
        }

        cout << "교사 정보:" << endl;
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

    Classroom myClass("1반");

  
    while (1) {
        cout << "메뉴:\n1. 학생의 정보 입력\n2.교사의 정보 입력\n3.정보 출력\n4.종료\n";
        cin >> menu;

        if (menu==1) {
            cout << "학생의 이름과 나이 성별, 학생 아이디를 입력하세요: " << endl;
            cin >> name >> age >> gender>>id;
            Student* student1 = new Student(name, age, gender, id);
            myClass.addStu(student1);
        }
        else if (menu==2) {
            cout << "교사의 이름과 나이 성별, 교사 아이디를 입력하세요: " << endl;
            cin >> name >> age >> gender >> id;
            Teacher* teacher1 = new Teacher(name, age, gender, id);
            myClass.addTeacher(teacher1);

        }
        else if (menu==3) {
            myClass.show();
        }
        else if (menu==4){
            cout << "종료" << endl;
            break;
        }


    }
   

    return 0;
}