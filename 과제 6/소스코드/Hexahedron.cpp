#include "Hexahedron.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. name�� �μ��� �޴� constructor ( ����� ���� )
		3. ��� ���ڸ� �޴� constructor
		4. Copy Constructor		( ���� ������ )			*/
Hexahedron::Hexahedron()
{
	this->Set_Height(0);
}
Hexahedron::Hexahedron(Position temp, int w, int l, int h, double ang, COLORREF clr, string n)
	: Rect(temp, w, l, ang, clr, n)				// Funtion initialize�� �̸��� �������
{
	this->Set_Height(h);					// ���� ����
}
Hexahedron::Hexahedron(const Hexahedron& hexa)
	: Rect(hexa.Pos(), hexa.Width(), hexa.Length(), hexa.angle, hexa.Color(), hexa.Name())
	// Funtion initialize�� �������, ������ ȣ��
{
	this->Set_Height(hexa.Height());			// ����
}

/*				destructor ( �Ҹ��� )				*/
Hexahedron::~Hexahedron()
{
	// destruct Shape object
}

/*				member functions ( ��� �Լ��� )
		1. draw(ostream& ostr)	(virtual�� �����Ͽ���, sub-class���� �����ǿ뵵�� ����)
		2. Sur_Area() ( ����ü�� �ѳ���  )
		3. Volume() ( ����ü�� ���� )					*/
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
	// ����ü �ѳ��� = 2 * �ظ� ���� + ���� ����
	return ((2 * Area()) + ( (2 * (Width() + Length())) * Height()));
}
int Hexahedron::Volume() const
{
	// ����ü ���� = �ظ� ���� * ����
	return Area() * Height();
}

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( = )
		2. ��� ������ ( << )										*/
Hexahedron& Hexahedron::operator=(const Hexahedron& hexa)
{
	this->Rect::operator=(hexa);				// ���Կ����� ȣ��
	this->Set_Height(hexa.Height());				// ���� ����

	return *this;								// �ڱ��ڽ� ��ȯ
	// TODO: ���⿡ return ���� �����մϴ�.
}
ostream& operator<<(ostream& ostr, const Hexahedron& hexa)
{
	// ��� 
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
