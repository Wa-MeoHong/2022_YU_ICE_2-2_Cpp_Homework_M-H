#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

using namespace std;

#define One_day 24			// 24시간
#define One_Hour 60			// 1시간
#define One_Minute 60		// 1분

class Time
{
	friend ostream& operator<< (ostream&, const Time&);
public:
	// constructor
	Time();								// 기본 생성자
	Time(int h, int m, int s);			// 인자를 받는 생성자
	Time(const Time& t);				// 복제생성자
	
	//member functions
	int elasedSec() const ;				// 초로 변환
	
	//getter ( 시간 정보를 반환 )
	Time getTime() const ;				// 시간 객체 반환
	int Hour() const { return hour; }	// 시
	int Min() const { return min; }		// 분
	int Sec() const { return sec; }		// 초

	//setter ( 시간 설정 함수들 )
	void set_H(int h) { hour = h; }		// 시
	void set_M(int m) { min = m; }		// 분
	void set_S(int s) { sec = s; }		// 초

	// operator Overloading ( 덧셈, 대입, 비교 )
	Time& operator+(int s);				// 시간 덧셈
	Time& operator=(const Time& t);		// 시간 대입
	bool operator< (const Time& t);		// 시간 비교
	bool operator<= (const Time& t);
	bool operator> (const Time& t);
	bool operator>= (const Time& t);
	bool operator==(const Time& t);
private:
	bool isValidTime(int, int, int);	// 시간 유효성 검사
	int hour;
	int min;
	int sec;
};

#endif // !TIME_H

