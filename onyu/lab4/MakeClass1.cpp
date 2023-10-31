#include <iostream>
#include<string>
using namespace std;
class myScore {
private:
	string subject;
	int midterm;
	int final;
	double total;
	void show() {
		cout << subject << "�߰�" << midterm << "�⸻" << final << "����" << total << endl;
	}
	void comTotal() {
		total = (midterm * 0.4) + (final * 0.6);
		show();
	}
public:
	double getTotal() {
		return total;
	}
	string getSubject() {
		return subject;
	}

	void setScore(string subject, int midterm, int final) {
		this->subject = subject;
		this->midterm = midterm;
		this->final = final;
		comTotal();
	}
};
void compMyScore(myScore* score, int num) {

	for (int i = 0; i < num; i++) {
		double total = score[i].getTotal();
		if (total >= 90.0) {
			cout << score[i].getSubject() << " A ";
		}
		else if (total >= 70.0) {
			cout << score[i].getSubject() << " B ";
		}
		else if (total >= 50.0) {
			cout << score[i].getSubject() << " C ";
		}
		else if (total >= 30.0) {
			cout << score[i].getSubject() << " D ";
		}
		else {
			cout << score[i].getSubject() << " F ";
		}
	}
	cout << endl;

}
int main() {
	//�Ʒ� ��°� ���� ����ǵ��� myScore Ŭ������ �ۼ��Ͻÿ�.
	// 
	//(1) ��������� string subject, int midterm, int final, double total�� private���� ������.
	// 
	//(2) private ����Լ� show()�� ����������� ���� ������ �߰� 75 �⸻ 84 ���� 80.4���� ���� �������� �����.
	// 
	//(3) private ����Լ� compTotal()�� �ش� ������ total ���� ����� ���� midterm �� 40 %, final �� 60 % �� ������ �ݿ��Ͽ� ������� total�� ������.�� �� show() �Լ��� ȣ����.
	// 
	//(4) ������� subject �� total ���� �ܺο� ��ȯ�� �ִ� public ����Լ� getSubject()�� getTotal()�� ������.
	// 
	//(5) public ����Լ� setScore(string subject, int midterm, int final)�� �Ű������� ������ ��������� ������. (�Ű��������� ��������� �����Ƿ� this ������ Ȱ���� �ʿ���) �� ��, compTotal() �Լ��� ȣ���Ͽ� ������ �����.
	// 
	//(6) �Ϲ��Լ�(����Լ� �ƴ�) compMyScore(...)�� myScore ��ü�迭�� �Ű������� ���� ������,
	//	(6 - 1) �迭�� ���Ҹ��� setScore() �Լ��� ȣ���Ͽ� �ش� ������� ������ �Ʒ� ��� ���� ���� ��µǵ��� ���� ������.
	//	(6 - 2) for loop�� �����Ͽ� �� �迭���Ҹ� �湮�ϸ�, �Ʒ� ��¿��� ����, �� ���� ������ 90 �̻��� A, �� �Ʒ� 70 �̻��� B, �� �Ʒ� 50 �̻��� C, �� �Ʒ� 30 �̻��� D, �� �Ʒ��� F�� �ǵ��� �� �ٿ� �����.
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

	myScore* score = new myScore[3];
	int num = 0;
	score[num++].setScore("����", 75, 84);
	score[num++].setScore("����", 65, 72);
	score[num++].setScore("����", 83, 95);
	compMyScore(score, num);

	return 0;
}