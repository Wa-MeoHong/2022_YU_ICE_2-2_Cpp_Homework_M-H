#include "Prism.h"

/*				constructor ( 생성자 )
		1. default constructor ( 디폴트 생성자 )
		2. name만 인수를 받는 constructor ( 헤더에 정의 )
		3. 모든 인자를 받는 constructor
		4. Copy Constructor		( 복제 생성자 )			*/

Prism::Prism()
{
	this->Set_PriH(0);
}
Prism::Prism(Position temp, int b, int h, int ph, double ang, COLORREF clr, string n)
	: Triangle(temp, b, h, ang, clr, n)
{
	this->Set_PriH(ph);
}
Prism::Prism(const Prism& pri)
	: Triangle(pri.Pos(), pri.Base(), pri.Height(), pri.angle, pri.Color(), pri.Name())
{
	this->Set_PriH(pri.Pri_Hei());
}

/*				destructor ( 소멸자 )				*/
Prism::~Prism()
{
	// destruct Shape object
}

/*				member functions ( 멤버 함수들 )
		1. draw(ostream& ostr)	(virtual로 정의하였고, sub-class에서 재정의용도로 만듦)
		2. Sur_Area() ( 프리즘의 겉넓이  )
		3. Volume() ( 프리즘의 부피 )					*/
void Prism::draw(ostream& ostr)
{
	//print form : Prism::draw() => [name(name), pos(x,y), base(base), height(height), base_area(area)\
	//prism height(pri_height), color(RGB(RR,GG,BB)), Prism surface area (sur_area), Prism volume (volume)]
	ostr << "Prism::draw() => ";
	ostr << "[name(" << this->Name() << "), "
		<< this->Pos() << ", "
		<< "base (" << this->Base() << "), "
		<< "height (" << this->Height() << "), "
		<< "Base Area (" << this->Area() << "), "
		<< "Color ("; printRGB(ostr, this->Color()) << "), \n\t"
		<< "Prism height (" << this->Pri_Hei() << "), "
		<< "Prism Surface Area (" << this->Sur_Area() << "), "
		<< "Prism Volume (" << this->Volume() << ")]" << endl;
}
double Prism::Sur_Area() const
{
	double base_side;

	// 밑면의 빗변 = √(a² + b²)
	base_side = sqrt(pow(((double)Base() / 2.0), 2) + pow((double)Height(), 2));

	// 프리즘의 겉넓이 = 밑면 2개 넓이 + 옆면 넓이
	return (2 * Area()) + (((double)Base() + base_side + base_side) * (double)Pri_Hei());
}
double Prism::Volume() const
{
	// 프리즘의 부피 = 밑면 넓이 * 높이
	return (double)Area() * (double)Pri_Hei();
}

/*				operator Overloading ( 연산자 오버로드 )
		1. 대입 연산자 ( = )
		2. 출력 연산자 ( << )										*/
Prism& Prism::operator=(const Prism& pri)
{
	this->Triangle::operator=(pri);
	this->Set_PriH(pri.Pri_Hei());

	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}
ostream& operator<<(ostream& ostr, const Prism& pri)
{
	//print form : Prism::draw() => [name(name), pos(x,y), base(base), height(height), base_area(area)\
	//prism height(pri_height), color(RGB(RR,GG,BB)), Prism surface area (sur_area), Prism volume (volume)]
	ostr << "Prism::draw() => ";
	ostr << "[name(" << pri.Name() << "), "
		<< pri.Pos() << ", "
		<< "base (" << pri.Base() << "), "
		<< "height (" << pri.Height() << "), "
		<< "Base Area (" << pri.Area() << "), "
		<< "Color ("; printRGB(ostr, pri.Color()) << "), \n\t"
		<< "Prism height (" << pri.Pri_Hei() << "), "
		<< "Prism Surface Area (" << pri.Sur_Area() << "), "
		<< "Prism Volume (" << pri.Volume() << ")]" << endl;

	return ostr;
	// TODO: 여기에 return 문을 삽입합니다.
}
