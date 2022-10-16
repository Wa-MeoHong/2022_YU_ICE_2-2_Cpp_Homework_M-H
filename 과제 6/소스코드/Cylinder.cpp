#include "Cylinder.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. name만 인수를 받는 constructor ( 헤더에 정의 )
		3. 모든 인자를 받는 constructor
		4. Copy Constructor		( 복제 생성자 )			*/
Cylinder::Cylinder()
{
	this->Set_Height(0);
}
Cylinder::Cylinder(Position temp, int r, int h, double ang, COLORREF clr, string n)
	: Circle(temp, r, ang, clr, n)				// Funtion initialize로 이름을 집어넣음
{
	this->Set_Height(h);					// 높이 세팅
}
Cylinder::Cylinder(const Cylinder& cyl)
	: Circle(cyl.Pos(), cyl.Ra(), cyl.angle, cyl.Color(), cyl.Name())
	// Funtion initialize로 집어넣음, 생성자 호출
{
	this->Set_Height(cyl.Height());			// 높이
}

/*				destructor ( 소멸자 )				*/
Cylinder::~Cylinder()
{
	// destruct Shape object
}

/*				member functions ( 멤버 함수들 )
		1. draw(ostream& ostr)	(virtual로 정의하였고, sub-class에서 재정의용도로 만듦)
		2. Sur_Area() ( 원기둥의 겉넓이  )
		3. Volume() ( 원기둥의 부피 )					*/
void Cylinder::draw(ostream& ostr)
{
	//print form : Hexahedron::draw() => [name(name), pos(x,y), radius(radius), height(height), \
	color(RGB(RR,GG,BB)), Cylinder surface_area (surface_area), Cylinder volume (volume)]

	ostr << "Cylinder::draw() => ";
	ostr << "[name(" << this->Name() << "), "
		<< this->Pos() << ", "
		<< "radius (" << this->Ra() << "), "
		<< "Height (" << this->Height() << "), "
		<< "Color ("; printRGB(ostr, this->Color()) << "), \n\t"
		<< "Cylinder Surface Area (" << this->Sur_Area() << "), "
		<< "Cylinder Volume (" << this->Volume() << ")]" << endl;
}
double Cylinder::Sur_Area() const
{
	// 원기둥 겉넓이 = 2 * 밑면 넓이 + 옆면 넓이
	return ((2.0 * Area()) + ( 2.0 * PI * (double)Ra() * (double)Height()));
}
double Cylinder::Volume() const
{
	// 원기둥 부피 = 밑면 넓이 * 높이
	return Area() * (double)Height();
}

/*				operator Overloading ( 연산자 오버로드 )
		1. 대입 연산자 ( = )
		2. 출력 연산자 ( << )										*/
Cylinder& Cylinder::operator=(const Cylinder& cyl)
{
	this->Circle::operator=(cyl);				// 대입연산자 호출
	this->Set_Height(cyl.Height());				// 높이 대입

	return *this;								// 자기자신 반환
	// TODO: 여기에 return 문을 삽입합니다.
}
ostream& operator<<(ostream& ostr, const Cylinder& cyl)
{
	// 출력 
	ostr << "Cylinder::draw() => ";
	ostr << "[name(" << cyl.Name() << "), "
		<< cyl.Pos() << ", "
		<< "radius (" << cyl.Ra() << "), "
		<< "Height (" << cyl.Height() << "), "
		<< "Color ("; printRGB(ostr, cyl.Color()) << "), \n\t"
		<< "Cylinder Surface Area (" << cyl.Sur_Area() << "), "
		<< "Cylinder Volume (" << cyl.Volume() << ")]" << endl;

	return ostr;
}
