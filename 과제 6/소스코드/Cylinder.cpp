#include "Cylinder.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. name�� �μ��� �޴� constructor ( ����� ���� )
		3. ��� ���ڸ� �޴� constructor
		4. Copy Constructor		( ���� ������ )			*/
Cylinder::Cylinder()
{
	this->Set_Height(0);
}
Cylinder::Cylinder(Position temp, int r, int h, double ang, COLORREF clr, string n)
	: Circle(temp, r, ang, clr, n)				// Funtion initialize�� �̸��� �������
{
	this->Set_Height(h);					// ���� ����
}
Cylinder::Cylinder(const Cylinder& cyl)
	: Circle(cyl.Pos(), cyl.Ra(), cyl.angle, cyl.Color(), cyl.Name())
	// Funtion initialize�� �������, ������ ȣ��
{
	this->Set_Height(cyl.Height());			// ����
}

/*				destructor ( �Ҹ��� )				*/
Cylinder::~Cylinder()
{
	// destruct Shape object
}

/*				member functions ( ��� �Լ��� )
		1. draw(ostream& ostr)	(virtual�� �����Ͽ���, sub-class���� �����ǿ뵵�� ����)
		2. Sur_Area() ( ������� �ѳ���  )
		3. Volume() ( ������� ���� )					*/
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
	// ����� �ѳ��� = 2 * �ظ� ���� + ���� ����
	return ((2.0 * Area()) + ( 2.0 * PI * (double)Ra() * (double)Height()));
}
double Cylinder::Volume() const
{
	// ����� ���� = �ظ� ���� * ����
	return Area() * (double)Height();
}

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( = )
		2. ��� ������ ( << )										*/
Cylinder& Cylinder::operator=(const Cylinder& cyl)
{
	this->Circle::operator=(cyl);				// ���Կ����� ȣ��
	this->Set_Height(cyl.Height());				// ���� ����

	return *this;								// �ڱ��ڽ� ��ȯ
	// TODO: ���⿡ return ���� �����մϴ�.
}
ostream& operator<<(ostream& ostr, const Cylinder& cyl)
{
	// ��� 
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
