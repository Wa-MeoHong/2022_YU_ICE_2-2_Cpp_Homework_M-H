#include "Hexahedron.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. name만 인수를 받는 constructor ( 헤더에 정의 )
		3. 모든 인자를 받는 constructor
		4. Copy Constructor		( 복제 생성자 )			*/
Hexahedron::Hexahedron()
{
	this->Set_Height(0);
}
Hexahedron::Hexahedron(Position temp, int w, int l, int h, double ang, COLORREF clr, string n)
	: Rect(temp, w, l, ang, clr, n)				// Funtion initialize로 이름을 집어넣음
{
	this->Set_Height(h);					// 높이 세팅
}
Hexahedron::Hexahedron(const Hexahedron& hexa)
	: Rect(hexa.Pos(), hexa.Width(), hexa.Length(), hexa.angle, hexa.Color(), hexa.Name())
	// Funtion initialize로 집어넣음, 생성자 호출
{
	this->Set_Height(hexa.Height());			// 높이
}

/*				destructor ( 소멸자 )				*/
Hexahedron::~Hexahedron()
{
	// destruct Shape object
}

/*				member functions ( 멤버 함수들 )
		1. draw(ostream& ostr)	(virtual로 정의하였고, sub-class에서 재정의용도로 만듦)
		2. Sur_Area() ( 육면체의 겉넓이  )
		3. Volume() ( 육면체의 부피 )					*/
void Hexahedron::draw(ostream& ostr)
{
	//print form : Hexahedron::draw() => [name(name), pos(x,y), width(width), length(length), \
	//height(height), color(RGB(RR,GG,BB)), Hexahedron area (area), Hexahedron volume (volume)]
	ostr << "Hexahedron::draw() => ";
	ostr << "[name(" << this->Name() << "), "
		<< this->Pos() << ", "
		<< "Width (" << this->Width() << "), "
		<< "Lenght (" << this->Length() << "), "
		<< "Height (" << this->Height() << "), "
		<< "Color ("; printRGB(ostr, this->Color()) << "), \n\t"
		<< "Hexahedron Surface Area (" << this->Sur_Area() << "), "
		<< "Hexahedron Volume (" << this->Volume() << ")]" << endl;
}
int Hexahedron::Sur_Area() const
{
	// 육면체 겉넓이 = 2 * 밑면 넓이 + 옆면 넓이
	return ((2 * Area()) + ( (2 * (Width() + Length())) * Height()));
}
int Hexahedron::Volume() const
{
	// 육면체 부피 = 밑면 넓이 * 넓이
	return Area() * Height();
}

/*				operator Overloading ( 연산자 오버로드 )
		1. 대입 연산자 ( = )
		2. 출력 연산자 ( << )										*/
Hexahedron& Hexahedron::operator=(const Hexahedron& hexa)
{
	this->Rect::operator=(hexa);				// 대입연산자 호출
	this->Set_Height(hexa.Height());				// 높이 대입

	return *this;								// 자기자신 반환
	// TODO: 여기에 return 문을 삽입합니다.
}
ostream& operator<<(ostream& ostr, const Hexahedron& hexa)
{
	// 출력 
	ostr << "Hexahedron::draw() => ";
	ostr << "[name(" << hexa.Name() << "), "
		<< hexa.Pos() << ", "
		<< "Width (" << hexa.Width() << "), "
		<< "Lenght (" << hexa.Length() << "), "
		<< "Height (" << hexa.Height() << "), "
		<< "Color ("; printRGB(ostr, hexa.Color()) << "), \n\t"
		<< "Hexahedron Surface Area (" << hexa.Sur_Area() << "), "
		<< "Hexahedron Volume (" << hexa.Volume() << ")]" << endl;

	return ostr;
}
