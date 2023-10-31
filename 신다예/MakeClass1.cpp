#include <iostream>
#include <string>
using namespace std;

class myScore {
private:
	string subject_;
	int midterm_;
	int final_;
	double total_;
	void show() {     //������ �߰� 75 �⸻ 84 ���� 80.4�����·� ���.
		cout << subject_ << ": �߰� " << midterm_ << ", �⸻ " << final_ << ", ���� " << total_ << endl;
	}
	void compTotal() { //compTotal() : �ش������ total��������� ���� midterm:40% final:60% �� ������ �ݿ�->total�� ����->show() �Լ��� ȣ����.
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
	//�Ʒ� ��°� ���� ����ǵ��� myScore Ŭ������ �ۼ��Ͻÿ�.
	// 
	//(1) ��������� string subject, int midterm, int final, double total�� private���� ������.
	// 
	//(2) private ����Լ� show()�� ����������� ���� ������ �߰� 75 �⸻ 84 ���� 80.4���� ���� �������� �����.
	// 
	//(3) private ����Լ� compTotal()�� �ش� ������ total ���� ����� ���� midterm �� 40 %, final �� 60 % �� ������ �ݿ��Ͽ� 
	// ������� total�� ������. �� �� show() �Լ��� ȣ����.
	// 
	//(4) ������� subject �� total ���� �ܺο� ��ȯ�� �ִ� public ����Լ� getSubject()�� getTotal()�� ������.
	// 
	//(5) public ����Լ� setScore(string subject, int midterm, int final)�� �Ű������� ������ ��������� ������. 
	// (�Ű��������� ��������� �����Ƿ� this ������ Ȱ���� �ʿ���) 
	// �� ��, compTotal() �Լ��� ȣ���Ͽ� ������ �����.
	

	//(6) �Ϲ��Լ�(����Լ� �ƴ�) compMyScore(...)�� myScore ��ü�迭�� �Ű������� ���� ������,
	//	(6 - 1) �迭�� ���Ҹ��� setScore() �Լ��� ȣ���Ͽ� �ش� ������� ������ �Ʒ� ��� ���� ���� ��µǵ��� ���� ������.
	//	(6 - 2) for loop�� �����Ͽ� �� �迭���Ҹ� �湮�ϸ�, �Ʒ� ��¿��� ����, 
	//	�� ���� ������ 90 �̻��� A, �� �Ʒ� 70 �̻��� B, �� �Ʒ� 50 �̻��� C, �� �Ʒ� 30 �̻��� D, �� �Ʒ��� F�� �ǵ��� �� �ٿ� �����.
	// 
	//(7) �Ʒ��� ���� main() �Լ��� ������
	//	(7 - 1) Ŭ���� myScore�� �����͸� �����Ͽ� ��ü 3���� ���� �迭�� �������� ������.
	//	(7 - 2) compMyScore() �Լ��� ȣ���ϸ� ���� �迭�� �Ű������� ������.
	// 
	//(8) stdio.h�� ������� �ʰ� ������.
	//��� ��:
	//���� �߰� 75 �⸻ 84 ���� 80.4
	//���� �߰� 65 �⸻ 72 ���� 69.2
	//���� �߰� 83 �⸻ 95 ���� 90.2
	//���� B ���� C ���� A


	
	myScore* scores = new myScore[3];

	scores[0].setScore("����", 75, 84);
	scores[1].setScore("����", 65, 72);
	scores[2].setScore("����", 83, 95);

	compMyScore(scores, 3);
	
	/*
	int subNum;
	string subName;
	int midterm;
	int final;

	cout << "���� ���� �Է�: ";
	cin >> subNum;
	myScore* scores = new myScore[subNum];
	

	for (int i = 0; i < subNum; i++) {
		cout << "���� �̸�, �߰���� ����, �⸻��� ���� �Է�: \n";
		cin >> subName >> midterm >> final;
		scores[i].setScore(subName, midterm, final);
	}

	compMyScore(scores, subNum);
	*/

	return 0;
}
