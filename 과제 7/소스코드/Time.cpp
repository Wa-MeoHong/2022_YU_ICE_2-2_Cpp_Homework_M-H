#include "Time.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. 모든 인자를 받는 constructor				
		3. Copy constructor							*/
Time::Time()
{
	// hh : mm : ss 
	hour = 0; min = 0; sec = 0;
}
Time::Time(int h, int m, int s)
{
	if (isValidTime(h, m, s))		// 먼저 시간이 유효한지 확인
	{
		set_H(h); set_M(m); set_S(s);	// 유효하면 대입
	}
	else
	{
		cout << "illegal time!!" << endl;	// 아니면 오류메세지 출력 후 강제종료
		exit(-1);
	}
}
Time::Time(const Time& t)
	: hour(t.Hour()), min(t.Min()), sec(t.Sec())
{
	// 굳이 유효성검사를 할 필요 없음 ( 복사하는 것이기 때문 ) 
	// Funtion initialize로 집어넣음
}


/*				member functions ( 멤버 함수들 )
		1. elasedSec() ( 시간을 초로 환산해서 반환 )
		2. getTime()	( 시간을 반환함 ) 		
		3. isValidTime(int, int, int) (시간이 유효한지 확인)		*/
int Time::elasedSec() const
{
	int e_sec = 0;				// 초로 계산 (시작은 0)

	e_sec += this->Sec();		// 먼저 초를 더함
	e_sec += this->Min() * One_Minute;	// 1분 = 60초
	e_sec += this->Hour() * One_Minute * One_Hour;	// 1시간 = 3600초

	return e_sec;				// 반환
}
Time Time::getTime() const 
{
	// Time 객체를 반환하기 위해 임시객체를 하나 선언해줌, 그 후, 반환
	Time get(*this);

	return get;
}
bool Time::isValidTime(int h, int m, int s)
{
	// 시, 분, 초가 모두 정상인지 확인
	if (h < One_day && m < One_Hour && s < One_Minute)
		return true;
	return false;
}

/*				operator Overloading ( 연산자 오버로드 )
		1. 덧셈 연산자 ( + )
		2. 대입 연산자 ( = )
		3. 비교 연산자 ( <, <=, >, >=, == )						
		4. 출력 연산자 ( << )							*/
Time& Time::operator+(int s)
{
	this->sec += s;

	// int형이라 나누기 한 값은 내림연산을 함
	// 초가 60을 넘게 된다면, 현재 초 / 60회 만큼 분을 더한 후, 나머지는 초에 저장
	if (Sec() >= One_Minute)
	{
		for (int i = 0; i < Sec() / One_Minute; i++)
			min++;
		set_S(Sec() % One_Minute);
	}

	// 그 후, 분이 60을 넘게 되면, 현재 분/60 만큼 분을 더한 후, 나머지는 분에 저장
	if (Min() >= One_Hour)
	{
		for (int i = 0; i < Min() / One_Hour; i++)
			hour++;
		set_M(Min() % One_Hour);
	}

	// 시각이 23시를 넘기게 되면 day는 없으므로 24를 나눈 나머지만 저장
	if (Hour() >= One_day)
	{
		set_H(Hour() % One_day);
	}

	return *this;	// 반환
}
Time& Time::operator=(const Time& t)
{
	// 시간 대입 후 자기자신 반환
	this->set_S(t.Sec());
	this->set_M(t.Min());
	this->set_H(t.Hour());

	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}
bool Time::operator<(const Time& t)				// 작은지 비교
{
	// 비교는 elasedSec()으로 초로 변환 후, 비교
	if (this->elasedSec() < t.elasedSec())			
		return true;
	return false;
}
bool Time::operator<=(const Time& t)			// 작거나 같은지
{
	// 비교는 elasedSec()으로 초로 변환 후, 비교
	if (this->elasedSec() <= t.elasedSec())
		return true;
	return false;
}
bool Time::operator>(const Time& t)				// 큰지 비교
{
	// 비교는 elasedSec()으로 초로 변환 후, 비교
	if (this->elasedSec() > t.elasedSec())
		return true;
	return false;
}
bool Time::operator>=(const Time& t)			// 크거나 같은지 비교
{
	// 비교는 elasedSec()으로 초로 변환 후, 비교
	if (this->elasedSec() >= t.elasedSec())
		return true;
	return false;
}
bool Time::operator==(const Time& t)			// 둘이 같은지 비교
{
	// 비교는 elasedSec()으로 초로 변환 후, 비교
	if (this->elasedSec() == t.elasedSec())
		return true;
	return false;
}
ostream& operator<<(ostream& ostr, const Time& t)
{
	// print format : (hh:mm:ss)
	ostr << "(";
	ostr << setw(2) << t.Hour() << ":"
		<< setw(2) << t.Min() << ":"
		<< setw(2) << t.Sec() << ")";

	return ostr;			// ostream 객체 반환
}
