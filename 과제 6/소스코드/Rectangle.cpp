#include "Rectangle.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. name만 인수를 받는 constructor ( 헤더에 정의 )
		3. 모든 인자를 받는 constructor					*/
Rect::Rect()
{
	this->Set_Width(0);
	this->Set_Length(0);
}
Rect::Rect(Position temp, int w, int l, double ang, COLORREF clr, string n)
	: Shape(temp, ang, clr, n)				// Funtion initialize로 이름을 집어넣음
{
	this->Set_Width(w);						// 밑변 세팅
	this->Set_Length(l);					// 높이 세팅
}
Rect::Rect(const Rect& rect)
	: Shape(rect.Pos(), rect.angle, rect.Color(), rect.Name())
	// Funtion initialize로 집어넣음, 생성자 호출
{
	this->Set_Width(rect.Width());				// 밑변
	this->Set_Length(rect.Length());			// 높이
}

/*				destructor ( 소멸자 )				*/
Rect::~Rect()
{
	// destruct Shape object
}

/*				member functions ( 멤버 함수들 )
		1. draw(ostream& ostr)	(virtual로 정의하였고, sub-class에서 재정의용도로 만듦)
		2. Area() ( 사각형의 넓이  )					*/
void Rect::draw(ostream& ostr)
{
	//print form : Rect::draw() => [name(name), pos(x,y), width(width), rect_length(length), color(RGB(RR,GG,BB)), Rect area (area)]
	ostr << "Rect::draw() => ";
	ostr << "[name(" << this->Name() << "), "
		<< this->Pos() << ", "
		<< "width (" << this->Width() << "), "
		<< "lenght (" << this->Length() << "), "
		<< "Color ("; printRGB(ostr, this->Color()) << "), "
		<< "Rect_Area (" << this->Area() << ")]" << endl;

}
int Rect::Area() const
{
	return Width() * Length();
}

/*				operator Overloading ( 연산자 오버로드 )
		1. 대입 연산자 ( = )
		2. 출력 연산자 ( << )										*/
Rect& Rect::operator=(const Rect& rect)
{
	this->Shape::operator=(rect);				// 대입연산자 호출
	this->Set_Width(rect.Width());					// 밑변 대입
	this->Set_Length(rect.Length());				// 높이 대입

	return *this;								// 자기자신 반환
	// TODO: 여기에 return 문을 삽입합니다.
}
ostream& operator<<(ostream& ostr, const Rect& rect)
{
	// 출력 
	ostr << "Rect::draw() => ";
	ostr << "[name(" << rect.Name() << "), "
		<< rect.Pos() << ", "
		<< "width (" << rect.Width() << "), "
		<< "length (" << rect.Length() << "), "
		<< "Color ("; printRGB(ostr, rect.Color()) << "), "
		<< "Rect_Area (" << rect.Area() << ")]" << endl;
	return ostr;
}
