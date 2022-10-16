#include "Shape.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. name만 인수를 받는 constructor
		3. 모든 인자를 받는 constructor				 */
Shape::Shape()
{
	SetPos(Position(0, 0));		// 좌표는 (0, 0)
	angle = 0.0;				// 각도는 0.0도
	NameSet(" ");				// 이름은 공백
	color = RGB_BLACK;			// 색깔은 검정으로 초기화
}
Shape::Shape(string n)
	: name(n)					// Funtion initialize로 이름을 집어넣음
{
	
	SetPos(Position(0,0));		// 좌표는 (0, 0)
	angle = 0.0;				// 각도는 0.0도
	color = RGB_BLACK;			// 색깔은 검정으로 초기화
}
Shape::Shape(Position pos, double ang, COLORREF clr, string n)
	: angle(ang), name(n), color(clr)
	//Funtion initialize로 정의를 하였음 
{
	SetPos(pos);				// 좌표는 (0, 0)
}

/*				destructor ( 소멸자 )				*/
Shape::~Shape()
{
	// destruct Shape object
}

/*				member functions ( 멤버 함수들 )
		1. draw(ostream& ostr)
		  (virtual로 정의하였고, sub-class에서 재정의용도로 만듦)
		2. print(ostream& ostr) const ( 출력 함수 )				*/
void Shape::draw(ostream& ostr)
{
	// virtual 함수로 구현되어 파생클래스의 재정의된 함수로 가게끔구성
	// Draw Shape Funtion, display Shape information 
	ostr << "Shape::draw() => ";
	this->print(ostr); ostr << endl;
}
void Shape::print(ostream& ostr) const
{
	//print form : Shape::draw() => [name(name), pos(x,y), color(RGB(RR,GG,BB))]
	ostr << "[name(" << this->Name() << "), "
		<< this->Pos() << ", "
		<< "color("; printRGB(ostr, this->Color()); ostr << ")]";
}

/*				operator Overloading ( 연산자 오버로드 )
		1. 대입 연산자 ( = )
		2. 출력 연산자 ( << )										*/
Shape& Shape::operator=(const Shape& s)
{
	//  좌표, 각도, 색깔, 이름을 대입함
	this->SetPos(s.Pos());
	this->angle = s.angle;
	this->color = s.Color();
	this->NameSet(s.Name());

	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}
ostream& operator<<(ostream& ostr, const Shape& s)
{
	// 출력
	ostr << "Shape::draw() => ";
	s.print(ostr);
	return ostr;
}
