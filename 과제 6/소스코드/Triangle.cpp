#include "Triangle.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. name�� �μ��� �޴� constructor ( ����� ���� ) 
		3. ��� ���ڸ� �޴� constructor					*/
Triangle::Triangle()
{
	this->Set_Base(0);
	this->Set_Height(0);
}
Triangle::Triangle(Position temp, int b, int h, double ang, COLORREF clr, string n)
	: Shape(temp, ang, clr, n)				// Funtion initialize�� �̸��� �������
{
	this->Set_Base(b);						// �غ� ����
	this->Set_Height(h);					// ���� ����
}
Triangle::Triangle(const Triangle& tri)
	: Shape(tri.Pos(), tri.angle, tri.Color(), tri.Name())
	// Funtion initialize�� �������, ������ ȣ��
{
	this->Set_Base(tri.Base());				// �غ�
	this->Set_Height(tri.Height());			// ����
}

/*				destructor ( �Ҹ��� )				*/
Triangle::~Triangle()
{
	// destruct Shape object
}

/*				member functions ( ��� �Լ��� )
		1. draw(ostream& ostr)	(virtual�� �����Ͽ���, sub-class���� �����ǿ뵵�� ����)
		2. Area() ( �ﰢ���� ����  )					*/
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

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( = )
		2. ��� ������ ( << )										*/
Triangle& Triangle::operator=(const Triangle& tri)
{
	this->Shape::operator=(tri);				// ���Կ����� ȣ��
	this->Set_Base(tri.Base());					// �غ� ����
	this->Set_Height(tri.Height());				// ���� ����

	return *this;								// �ڱ��ڽ� ��ȯ
	// TODO: ���⿡ return ���� �����մϴ�.
}
ostream& operator<<(ostream& ostr, const Triangle& tri)
{
	// ��� 
	ostr << "Triangle::draw() => ";
	ostr << "[name(" << tri.Name() << "), "
		<< tri.Pos() << ", "
		<< "Base (" << tri.Base() << "), "
		<< "tri_Height (" << tri.Height() << "), "
		<< "Color ("; printRGB(ostr, tri.Color()) << "), "
		<< "Tri_Area (" << tri.Area() << ")]" << endl;
	return ostr;
}
