#include "Circle.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. name만 인수를 받는 constructor ( 헤더에 정의 )
		3. 모든 인자를 받는 constructor
		4. Copy Constructor		( 복제 생성자 )			*/
Circle::Circle()
{
	radius = 0;
}
Circle::Circle(Position temp, int r, double ang, COLORREF clr, string n)
	: Shape(temp, ang, clr, n)
{
	this->Set_Ra(r);
}
Circle::Circle(const Circle& cir)
	: Shape(cir.Pos(), cir.angle, cir.Color(), cir.Name())
{
	this->Set_Ra(cir.Ra());
}

/*				destructor ( 소멸자 )				*/
Circle::~Circle()
{
	// destruct Shape object
}

/*				member functions ( 멤버 함수들 )
		1. draw(ostream& ostr)	(virtual로 정의하였고, sub-class에서 재정의용도로 만듦)
		2. Area() ( 원의 넓이  )					*/
void Circle::draw(ostream&ostr)
{
	//print form : Circle::draw() => [name(name), pos(x,y), radius (ra), color(RGB(RR,GG,BB)), circle Area (area)]
	ostr << "Circle::draw() => ";
	ostr << "[name(" << this->Name() << "), "
		<< this->Pos() << ", "
		<< "Radius (" << this->Ra() << "), "
		<< "Color ("; printRGB(ostr, this->Color()) << "), "
		<< "Circle_Area (" << this->Area() << ")]" << endl;
}
double Circle::Area() const
{
	return PI * (double)Ra() * (double)Ra();
}

/*				operator Overloading ( 연산자 오버로드 )
		1. 대입 연산자 ( = )
		2. 출력 연산자 ( << )										*/
Circle& Circle::operator=(const Circle& cir)
{
	this->Shape::operator=(cir);				// 대입연산자를 불러옴(상속이 안되기 때문)
	this->Set_Ra(cir.Ra());						// 반지름 세팅

	return *this;								// 자기 자신 반환
	// TODO: 여기에 return 문을 삽입합니다.
}
ostream& operator<<(ostream& ostr, const Circle& cir)
{
	ostr << "Circle::draw() => ";
	ostr << "[name(" << cir.Name() << "), "
		<< cir.Pos() << ", "
		<< "Radius (" << cir.Ra() << "), "
		<< "Color ("; printRGB(ostr, cir.Color()) << "), "
		<< "Circle_Area (" << cir.Area() << ")]" << endl;

	return ostr;
	// TODO: 여기에 return 문을 삽입합니다.
}
