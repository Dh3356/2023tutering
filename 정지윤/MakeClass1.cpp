#include <iostream>
#include <string>

class myScore {
private:
    std::string subject;
    int midterm;
    int final;
    double total;

    void show() {
        std::cout << subject << " �߰� " << midterm << " �⸻ " << final << " ���� " << total << std::endl;
    }

    void compTotal() {
        total = midterm * 0.4 + final * 0.6;
        show();
    }

public:
    std::string getSubject() {
        return subject;
    }

    double getTotal() {
        return total;
    }

    void setScore(std::string subject, int midterm, int final) {
        this->subject = subject;
        this->midterm = midterm;
        this->final = final;
        compTotal();
    }
};

void compMyScore(myScore* scores, int count) {
    for (int i = 0; i < count; i++) {
        std::string subject = scores[i].getSubject();
        double total = scores[i].getTotal();

        char grade;
        if (total >= 90) {
            grade = 'A';
        }
        else if (total >= 70) {
            grade = 'B';
        }
        else if (total >= 50) {
            grade = 'C';
        }
        else if (total >= 30) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }

        std::cout << subject << " " << grade << " ";
    }
    std::cout << std::endl;
}
int main(){
    myScore* scores = new myScore[3];
    scores[0].setScore("����", 75, 84);
    scores[1].setScore("����", 65, 72);
    scores[2].setScore("����", 83, 95);

    compMyScore(scores, 3);
	
	return 0;
}
