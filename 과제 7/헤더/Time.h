#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

using namespace std;

#define One_day 24			// 24�ð�
#define One_Hour 60			// 1�ð�
#define One_Minute 60		// 1��

class Time
{
	friend ostream& operator<< (ostream&, const Time&);
public:
	// constructor
	Time();								// �⺻ ������
	Time(int h, int m, int s);			// ���ڸ� �޴� ������
	Time(const Time& t);				// ����������
	
	//member functions
	int elasedSec() const ;				// �ʷ� ��ȯ
	
	//getter ( �ð� ������ ��ȯ )
	Time getTime() const ;				// �ð� ��ü ��ȯ
	int Hour() const { return hour; }	// ��
	int Min() const { return min; }		// ��
	int Sec() const { return sec; }		// ��

	//setter ( �ð� ���� �Լ��� )
	void set_H(int h) { hour = h; }		// ��
	void set_M(int m) { min = m; }		// ��
	void set_S(int s) { sec = s; }		// ��

	// operator Overloading ( ����, ����, �� )
	Time& operator+(int s);				// �ð� ����
	Time& operator=(const Time& t);		// �ð� ����
	bool operator< (const Time& t);		// �ð� ��
	bool operator<= (const Time& t);
	bool operator> (const Time& t);
	bool operator>= (const Time& t);
	bool operator==(const Time& t);
private:
	bool isValidTime(int, int, int);	// �ð� ��ȿ�� �˻�
	int hour;
	int min;
	int sec;
};

#endif // !TIME_H

