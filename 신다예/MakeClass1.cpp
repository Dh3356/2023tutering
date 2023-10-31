#include <iostream>
#include <string>
using namespace std;

class myScore {
private:
	string subject_;
	int midterm_;
	int final_;
	double total_;
	void show() {     //“수학 중간 75 기말 84 총점 80.4”형태로 출력.
		cout << subject_ << ": 중간 " << midterm_ << ", 기말 " << final_ << ", 총점 " << total_ << endl;
	}
	void compTotal() { //compTotal() : 해당과목의 total점수계산을 위해 midterm:40% final:60% 로 점수를 반영->total에 저장->show() 함수를 호출함.
		total_ = midterm_ * 0.4 + final_ * 0.6;
		show();
	}

public:
	string getSubject() {
		return subject_;
	}

	int getTotal() {
		return total_;
	}

	void setScore(string subject, int midterm, int final) {
		subject_ = subject;
		midterm_ = midterm;
		final_ = final;
		compTotal();
	}

};

void compMyScore(myScore* score, int SubNum) {
	for (int i = 0; i < SubNum; i++) {
		if (score[i].getTotal() >= 90) {
			cout << score[i].getSubject() << " A ";
		}
		else if (score[i].getTotal() >= 70) {
			cout << score[i].getSubject() << " B ";
		}
		else if (score[i].getTotal() >= 50) {
			cout << score[i].getSubject() << " C ";
		}
		else if (score[i].getTotal() >= 30) {
			cout << score[i].getSubject() << " D ";
		}
		else {
			cout << score[i].getSubject() << " F ";
		}
	}
	cout << endl;

}


int main(){
	//아래 출력과 같이 실행되도록 myScore 클래스를 작성하시오.
	// 
	//(1) 멤버변수들 string subject, int midterm, int final, double total을 private으로 선언함.
	// 
	//(2) private 멤버함수 show()는 멤버변수들의 값을 “수학 중간 75 기말 84 총점 80.4”와 같은 형식으로 출력함.
	// 
	//(3) private 멤버함수 compTotal()은 해당 과목의 total 점수 계산을 위해 midterm 은 40 %, final 은 60 % 로 점수를 반영하여 
	// 멤버변수 total에 저장함. 그 후 show() 함수를 호출함.
	// 
	//(4) 멤버변수 subject 와 total 값을 외부에 반환해 주는 public 멤버함수 getSubject()와 getTotal()을 선언함.
	// 
	//(5) public 멤버함수 setScore(string subject, int midterm, int final)는 매개변수의 값들을 멤버변수에 저장함. 
	// (매개변수명이 멤버변수와 같으므로 this 포인터 활용이 필요함) 
	// 그 후, compTotal() 함수를 호출하여 총점을 계산함.
	

	//(6) 일반함수(멤버함수 아님) compMyScore(...)는 myScore 객체배열을 매개변수로 전달 받으며,
	//	(6 - 1) 배열의 원소마다 setScore() 함수를 호출하여 해당 과목들의 내용이 아래 출력 예와 같이 출력되도록 값을 전달함.
	//	(6 - 2) for loop를 실행하여 각 배열원소를 방문하며, 아래 출력예와 같이, 
	//	각 과목별 학점을 90 이상은 A, 그 아래 70 이상은 B, 그 아래 50 이상은 C, 그 아래 30 이상은 D, 그 아래는 F가 되도록 한 줄에 출력함.
	// 
	//(7) 아래와 같이 main() 함수를 정의함
	//	(7 - 1) 클래스 myScore의 포인터를 선언하여 객체 3개를 갖는 배열을 동적으로 생성함.
	//	(7 - 2) compMyScore() 함수를 호출하며 위의 배열을 매개변수로 전달함.
	// 
	//(8) stdio.h를 사용하지 않고 구현함.
	//출력 예:
	//수학 중간 75 기말 84 총점 80.4
	//영어 중간 65 기말 72 총점 69.2
	//물리 중간 83 기말 95 총점 90.2
	//수학 B 영어 C 물리 A


	
	myScore* scores = new myScore[3];

	scores[0].setScore("수학", 75, 84);
	scores[1].setScore("영어", 65, 72);
	scores[2].setScore("물리", 83, 95);

	compMyScore(scores, 3);
	
	/*
	int subNum;
	string subName;
	int midterm;
	int final;

	cout << "과목 개수 입력: ";
	cin >> subNum;
	myScore* scores = new myScore[subNum];
	

	for (int i = 0; i < subNum; i++) {
		cout << "과목 이름, 중간고사 점수, 기말고사 점수 입력: \n";
		cin >> subName >> midterm >> final;
		scores[i].setScore(subName, midterm, final);
	}

	compMyScore(scores, subNum);
	*/

	return 0;
}
