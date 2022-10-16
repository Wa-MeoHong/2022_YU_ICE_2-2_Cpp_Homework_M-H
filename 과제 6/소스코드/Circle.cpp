#include "Circle.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. name�� �μ��� �޴� constructor ( ����� ���� )
		3. ��� ���ڸ� �޴� constructor
		4. Copy Constructor		( ���� ������ )			*/
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

/*				destructor ( �Ҹ��� )				*/
Circle::~Circle()
{
	// destruct Shape object
}

/*				member functions ( ��� �Լ��� )
		1. draw(ostream& ostr)	(virtual�� �����Ͽ���, sub-class���� �����ǿ뵵�� ����)
		2. Area() ( ���� ����  )					*/
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

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( = )
		2. ��� ������ ( << )										*/
Circle& Circle::operator=(const Circle& cir)
{
	this->Shape::operator=(cir);				// ���Կ����ڸ� �ҷ���(����� �ȵǱ� ����)
	this->Set_Ra(cir.Ra());						// ������ ����

	return *this;								// �ڱ� �ڽ� ��ȯ
	// TODO: ���⿡ return ���� �����մϴ�.
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
	// TODO: ���⿡ return ���� �����մϴ�.
}
