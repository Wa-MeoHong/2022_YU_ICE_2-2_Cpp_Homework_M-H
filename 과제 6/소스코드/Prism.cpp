#include "Prism.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. name�� �μ��� �޴� constructor ( ����� ���� )
		3. ��� ���ڸ� �޴� constructor
		4. Copy Constructor		( ���� ������ )			*/

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

/*				destructor ( �Ҹ��� )				*/
Prism::~Prism()
{
	// destruct Shape object
}

/*				member functions ( ��� �Լ��� )
		1. draw(ostream& ostr)	(virtual�� �����Ͽ���, sub-class���� �����ǿ뵵�� ����)
		2. Sur_Area() ( �������� �ѳ���  )
		3. Volume() ( �������� ���� )					*/
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

	// �ظ��� ���� = ��(a�� + b��)
	base_side = sqrt(pow(((double)Base() / 2.0), 2) + pow((double)Height(), 2));

	// �������� �ѳ��� = �ظ� 2�� ���� + ���� ����
	return (2 * Area()) + (((double)Base() + base_side + base_side) * (double)Pri_Hei());
}
double Prism::Volume() const
{
	// �������� ���� = �ظ� ���� * ����
	return (double)Area() * (double)Pri_Hei();
}

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( = )
		2. ��� ������ ( << )										*/
Prism& Prism::operator=(const Prism& pri)
{
	this->Triangle::operator=(pri);
	this->Set_PriH(pri.Pri_Hei());

	return *this;
	// TODO: ���⿡ return ���� �����մϴ�.
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
	// TODO: ���⿡ return ���� �����մϴ�.
}
