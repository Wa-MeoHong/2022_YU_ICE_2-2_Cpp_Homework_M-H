#include "Time.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. ��� ���ڸ� �޴� constructor				
		3. Copy constructor							*/
Time::Time()
{
	// hh : mm : ss 
	hour = 0; min = 0; sec = 0;
}
Time::Time(int h, int m, int s)
{
	if (isValidTime(h, m, s))		// ���� �ð��� ��ȿ���� Ȯ��
	{
		set_H(h); set_M(m); set_S(s);	// ��ȿ�ϸ� ����
	}
	else
	{
		cout << "illegal time!!" << endl;	// �ƴϸ� �����޼��� ��� �� ��������
		exit(-1);
	}
}
Time::Time(const Time& t)
	: hour(t.Hour()), min(t.Min()), sec(t.Sec())
{
	// ���� ��ȿ���˻縦 �� �ʿ� ���� ( �����ϴ� ���̱� ���� ) 
	// Funtion initialize�� �������
}


/*				member functions ( ��� �Լ��� )
		1. elasedSec() ( �ð��� �ʷ� ȯ���ؼ� ��ȯ )
		2. getTime()	( �ð��� ��ȯ�� ) 		
		3. isValidTime(int, int, int) (�ð��� ��ȿ���� Ȯ��)		*/
int Time::elasedSec() const
{
	int e_sec = 0;				// �ʷ� ��� (������ 0)

	e_sec += this->Sec();		// ���� �ʸ� ����
	e_sec += this->Min() * One_Minute;	// 1�� = 60��
	e_sec += this->Hour() * One_Minute * One_Hour;	// 1�ð� = 3600��

	return e_sec;				// ��ȯ
}
Time Time::getTime() const 
{
	// Time ��ü�� ��ȯ�ϱ� ���� �ӽð�ü�� �ϳ� ��������, �� ��, ��ȯ
	Time get(*this);

	return get;
}
bool Time::isValidTime(int h, int m, int s)
{
	// ��, ��, �ʰ� ��� �������� Ȯ��
	if (h < One_day && m < One_Hour && s < One_Minute)
		return true;
	return false;
}

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( + )
		2. ���� ������ ( = )
		3. �� ������ ( <, <=, >, >=, == )						
		4. ��� ������ ( << )							*/
Time& Time::operator+(int s)
{
	this->sec += s;

	// int���̶� ������ �� ���� ���������� ��
	// �ʰ� 60�� �Ѱ� �ȴٸ�, ���� �� / 60ȸ ��ŭ ���� ���� ��, �������� �ʿ� ����
	if (Sec() >= One_Minute)
	{
		for (int i = 0; i < Sec() / One_Minute; i++)
			min++;
		set_S(Sec() % One_Minute);
	}

	// �� ��, ���� 60�� �Ѱ� �Ǹ�, ���� ��/60 ��ŭ ���� ���� ��, �������� �п� ����
	if (Min() >= One_Hour)
	{
		for (int i = 0; i < Min() / One_Hour; i++)
			hour++;
		set_M(Min() % One_Hour);
	}

	// �ð��� 23�ø� �ѱ�� �Ǹ� day�� �����Ƿ� 24�� ���� �������� ����
	if (Hour() >= One_day)
	{
		set_H(Hour() % One_day);
	}

	return *this;	// ��ȯ
}
Time& Time::operator=(const Time& t)
{
	// �ð� ���� �� �ڱ��ڽ� ��ȯ
	this->set_S(t.Sec());
	this->set_M(t.Min());
	this->set_H(t.Hour());

	return *this;
	// TODO: ���⿡ return ���� �����մϴ�.
}
bool Time::operator<(const Time& t)				// ������ ��
{
	// �񱳴� elasedSec()���� �ʷ� ��ȯ ��, ��
	if (this->elasedSec() < t.elasedSec())			
		return true;
	return false;
}
bool Time::operator<=(const Time& t)			// �۰ų� ������
{
	// �񱳴� elasedSec()���� �ʷ� ��ȯ ��, ��
	if (this->elasedSec() <= t.elasedSec())
		return true;
	return false;
}
bool Time::operator>(const Time& t)				// ū�� ��
{
	// �񱳴� elasedSec()���� �ʷ� ��ȯ ��, ��
	if (this->elasedSec() > t.elasedSec())
		return true;
	return false;
}
bool Time::operator>=(const Time& t)			// ũ�ų� ������ ��
{
	// �񱳴� elasedSec()���� �ʷ� ��ȯ ��, ��
	if (this->elasedSec() >= t.elasedSec())
		return true;
	return false;
}
bool Time::operator==(const Time& t)			// ���� ������ ��
{
	// �񱳴� elasedSec()���� �ʷ� ��ȯ ��, ��
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

	return ostr;			// ostream ��ü ��ȯ
}
