#include "Rectangle.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. name�� �μ��� �޴� constructor ( ����� ���� )
		3. ��� ���ڸ� �޴� constructor					*/
Rect::Rect()
{
	this->Set_Width(0);
	this->Set_Length(0);
}
Rect::Rect(Position temp, int w, int l, double ang, COLORREF clr, string n)
	: Shape(temp, ang, clr, n)				// Funtion initialize�� �̸��� �������
{
	this->Set_Width(w);						// �غ� ����
	this->Set_Length(l);					// ���� ����
}
Rect::Rect(const Rect& rect)
	: Shape(rect.Pos(), rect.angle, rect.Color(), rect.Name())
	// Funtion initialize�� �������, ������ ȣ��
{
	this->Set_Width(rect.Width());				// �غ�
	this->Set_Length(rect.Length());			// ����
}

/*				destructor ( �Ҹ��� )				*/
Rect::~Rect()
{
	// destruct Shape object
}

/*				member functions ( ��� �Լ��� )
		1. draw(ostream& ostr)	(virtual�� �����Ͽ���, sub-class���� �����ǿ뵵�� ����)
		2. Area() ( �簢���� ����  )					*/
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

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( = )
		2. ��� ������ ( << )										*/
Rect& Rect::operator=(const Rect& rect)
{
	this->Shape::operator=(rect);				// ���Կ����� ȣ��
	this->Set_Width(rect.Width());					// �غ� ����
	this->Set_Length(rect.Length());				// ���� ����

	return *this;								// �ڱ��ڽ� ��ȯ
	// TODO: ���⿡ return ���� �����մϴ�.
}
ostream& operator<<(ostream& ostr, const Rect& rect)
{
	// ��� 
	ostr << "Rect::draw() => ";
	ostr << "[name(" << rect.Name() << "), "
		<< rect.Pos() << ", "
		<< "width (" << rect.Width() << "), "
		<< "length (" << rect.Length() << "), "
		<< "Color ("; printRGB(ostr, rect.Color()) << "), "
		<< "Rect_Area (" << rect.Area() << ")]" << endl;
	return ostr;
}
