#define _USE_MATH_DEFINES
#include "ElpsCylinder.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. name만 인수를 받는 constructor
		3. 모든 인자를 받는 constructor				*/
ElpsCylinder::ElpsCylinder()
{
	height = 0.0;
}
ElpsCylinder::ElpsCylinder(string n)
	:Elps(n)
{
	height = 0.0;
}
ElpsCylinder::ElpsCylinder(int px, int py, double r1, double r2, double h, double ang, COLORREF clr, string n)
	: Elps(px, py, r1, r2, ang, clr, n)
{
	height = h;
}

/*				destructor ( 소멸자 )			*/
ElpsCylinder::~ElpsCylinder()
{
	cout << "ElpsCylinder class terminated!" << endl;
	// height = 0.0;
}

/*				member functions ( 멤버 함수들 )
		1. draw() (미구현, 쓰는데가 없다..)
		2. print(ostream&) const ( 출력 함수 )
		3. Area()	( 타원의 겉넓이를 구하는 함수 )
		4. Volume()	( 타원의 부피를 구하는 함수 )				*/
void ElpsCylinder::draw()
{
	// draw Ellipse Cylinder 
}
void ElpsCylinder::print(ostream& out) const
{
	out.setf(ios::showpoint); out.setf(ios::fixed);				// 고정 소수점 2자리까지만 출력
	out.precision(2);

	// 출력 : 좌표 - 각도 - 색깔 - 반지름 - 높이 - 밑면넓이 - 겉넓이 - 부피
	out << "radius (" << this->Radius_1() << ", " << this->Radius_2() <<
		"), height (" << this->Height() << "), \n\t";
	out << "elipse_area (" << this->Elps::Area() << "), "
		<< "elp_cyl area (" << this->Area() << "), "
		<< "elp_cyl volume (" << this->Volume() << ")";
}
double ElpsCylinder::Area() const									// 겉넓이를 구하는 함수
{
	double round, elpsArea;

	elpsArea = this->Elps::Area();									// 타원의 넓이
	round = 2 * M_PI * sqrt((pow(Radius_1(), 2) + pow(Radius_2(), 2)) / 2); // 타원의 둘레
	
	return ((2 * elpsArea) + (height * round));						// 타원의 겉넓이 
}
double ElpsCylinder::Volume() const									// 타원의 부피를 구하는 함수
{
	double elpsArea;

	elpsArea = this->Elps::Area();									// 타원(밑면)의 넓이

	return elpsArea * height;										// 부피 = 밑면 넓이 * 높이
}

/*				operator Overloading ( 연산자 오버로드 )
		1. 대입 연산자 ( = )
		2. 출력 연산자 ( << )								*/
ElpsCylinder& ElpsCylinder::operator=(const ElpsCylinder& right)
{
	this->Elps::operator=(right);
	this->height = right.height;

	return *this;
}
ostream& operator<<(ostream& ostr, const ElpsCylinder& elpcyl)
{
	ostr << setw(15) << elpcyl.Name() << ": ";
	elpcyl.Shape::print(ostr); 
	ostr << ", ";	elpcyl.print(ostr);
	return ostr;
	// TODO: 여기에 return 문을 삽입합니다.
}
