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
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
        cout << "성별: " << gender << endl;
    }
};

class Student : public Person {
public:
    int studentN;

    Student(string n, int a, char g, int sn) : Person(n, a, g), studentN(sn) {}

    void show() {
        cout << "학번: " << studentN << endl;
        Person::show();
    }
};

class Teacher : public Person {
public:
    int tID;

    Teacher(string n, int a, char g, int tid) : Person(n, a, g), tID(tid) {}

    void show() {
        cout << "교사 id: " << tID << endl;
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
            cout << "더 이상 학생을 추가할 수 없습니다." << endl;
        }
    }

    void addTeacher(Teacher t) {
        if (teacherN < 1) {
            teachers[teacherN++] = t;
        }
        else {
            cout << "이미 교사가 추가되었습니다." << endl;
        }
    }

    void show() {
        cout << "반 이름: " << className << endl;

        cout << "학생 정보:" << endl;
        for (int i = 0; i < studentN; ++i) {
            students[i].show();
            cout << endl;
        }

        cout << "교사 정보:" << endl;
        for (int i = 0; i < teacherN; ++i) {
            teachers[i].show();
            cout << endl;
        }
    }
};

int main() {
    Classroom myClass("1반");

    Student student1("홍길동", 20, '남', 60191892);
    myClass.addStu(student1);

    Teacher teacher1("홍길동", 30, '남', 1);
    myClass.addTeacher(teacher1);

    myClass.show();

    return 0;
}