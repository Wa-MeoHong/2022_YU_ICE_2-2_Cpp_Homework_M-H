#include "Triangle.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. name만 인수를 받는 constructor ( 헤더에 정의 ) 
		3. 모든 인자를 받는 constructor					*/
Triangle::Triangle()
{
	this->Set_Base(0);
	this->Set_Height(0);
}
Triangle::Triangle(Position temp, int b, int h, double ang, COLORREF clr, string n)
	: Shape(temp, ang, clr, n)				// Funtion initialize로 이름을 집어넣음
{
	this->Set_Base(b);						// 밑변 세팅
	this->Set_Height(h);					// 높이 세팅
}
Triangle::Triangle(const Triangle& tri)
	: Shape(tri.Pos(), tri.angle, tri.Color(), tri.Name())
	// Funtion initialize로 집어넣음, 생성자 호출
{
	this->Set_Base(tri.Base());				// 밑변
	this->Set_Height(tri.Height());			// 높이
}

/*				destructor ( 소멸자 )				*/
Triangle::~Triangle()
{
	// destruct Shape object
}

/*				member functions ( 멤버 함수들 )
		1. draw(ostream& ostr)	(virtual로 정의하였고, sub-class에서 재정의용도로 만듦)
		2. Area() ( 삼각형의 넓이  )					*/
void Triangle::draw(ostream& ostr)
{
	//print form : Triangle::draw() => [name(name), pos(x,y), base(base), tri_height(height), color(RGB(RR,GG,BB)), Triangle area (area)]
	ostr << "Triangle::draw() => ";
	ostr << "[name(" << this->Name() << "), "
		<< this->Pos() << ", "
		<< "Base (" << this->Base() << "), "
		<< "tri_Height (" << this->Height() << "), "
		<< "Color ("; printRGB(ostr, this->Color()) << "), "
		<< "Tri_Area (" << this->Area() << ")]" << endl;

}
int Triangle::Area() const
{
	return 0.5 * Base() * Height();
}

/*				operator Overloading ( 연산자 오버로드 )
		1. 대입 연산자 ( = )
		2. 출력 연산자 ( << )										*/
Triangle& Triangle::operator=(const Triangle& tri)
{
	this->Shape::operator=(tri);				// 대입연산자 호출
	this->Set_Base(tri.Base());					// 밑변 대입
	this->Set_Height(tri.Height());				// 높이 대입

	return *this;								// 자기자신 반환
	// TODO: 여기에 return 문을 삽입합니다.
}
ostream& operator<<(ostream& ostr, const Triangle& tri)
{
	// 출력 
	ostr << "Triangle::draw() => ";
	ostr << "[name(" << tri.Name() << "), "
		<< tri.Pos() << ", "
		<< "Base (" << tri.Base() << "), "
		<< "tri_Height (" << tri.Height() << "), "
		<< "Color ("; printRGB(ostr, tri.Color()) << "), "
		<< "Tri_Area (" << tri.Area() << ")]" << endl;
	return ostr;
}
