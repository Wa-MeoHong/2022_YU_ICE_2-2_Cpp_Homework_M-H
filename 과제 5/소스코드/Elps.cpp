#define _USE_MATH_DEFINES
#include "Elps.h"
#include <math.h>

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. name만 인수를 받는 constructor
		3. 모든 인자를 받는 constructor				*/
Elps::Elps()
{
	setRadius(0.0, 0.0);							// 반지름은 기본 0.0으로 설정
}
Elps::Elps(string name)
	: Shape(name)									// Shape 생성자를 불러와서 Shape를 먼저 생성
{
	setRadius(0.0, 0.0);							// 반지름 초기값은 0.0으로
}
Elps::Elps(int px, int py, double r1, double r2, double ang, COLORREF clr, string name)
	: Shape(px, py, ang, clr, name)					// 좌표, 각도, 색깔, 이름은 Shape의 생성자를 이용해 설정
{
	setRadius(r1, r2);								// 반지름 초기값 설정
}

/*				destructor ( 소멸자 )			*/
Elps::~Elps()
{
	cout << "Elps class terminated!" << endl;
	// setRadius(0.0, 0.0);
}

/*				member functions ( 멤버 함수들 )
		1. draw() (미구현, 쓰는데가 없다..)
		2. print(ostream&) const ( 출력 함수 )
		3. Area()	( 타원의 넓이를 구하는 함수 )				*/
void Elps::draw()
{
	// draw elps shape
}
void Elps::print(ostream& out) const
{
	out.setf(ios::showpoint); out.setf(ios::fixed);						// 고정 소수점 2자리까지만 출력
	out.precision(2);

	// 출력 : 좌표 - 각도 - 색깔 - 반지름 - 넓이
	out << "radius (" << this->Radius_1() << "), " << this->Radius_2() <<
		", elipse_area (" << this->Area() << ")";
}
double Elps::Area() const
{
	return radius_1 * radius_2 * M_PI;						// 타원의 넓이 = r1 * r2 * π 
}

/*				operator Overloading ( 연산자 오버로드 )
		1. 대입 연산자 ( = )
		2. 출력 연산자 ( << )										*/
Elps& Elps::operator=(const Elps& elp)
{
	this->Shape::operator=(elp);						// Shape의 대입연산자를 가져와서 대입을 시킴 (상속이 안되기 때문)
	this->setRadius(elp.Radius_1(), elp.Radius_2());	// 반지름 2개를 설정함

	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}
ostream& operator<<(ostream& out , const Elps& elps)
{
	out << setw(15) << elps.Name() << ": ";	elps.Shape::print(out);
	out << ", "; elps.print(out); 
	return out;
	// TODO: 여기에 return 문을 삽입합니다.
}
