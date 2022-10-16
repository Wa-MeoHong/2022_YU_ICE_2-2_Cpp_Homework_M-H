#include "Shape.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. name�� �μ��� �޴� constructor
		3. ��� ���ڸ� �޴� constructor				 */
Shape::Shape()
{
	SetPos(Position(0, 0));		// ��ǥ�� (0, 0)
	angle = 0.0;				// ������ 0.0��
	NameSet(" ");				// �̸��� ����
	color = RGB_BLACK;			// ������ �������� �ʱ�ȭ
}
Shape::Shape(string n)
	: name(n)					// Funtion initialize�� �̸��� �������
{
	
	SetPos(Position(0,0));		// ��ǥ�� (0, 0)
	angle = 0.0;				// ������ 0.0��
	color = RGB_BLACK;			// ������ �������� �ʱ�ȭ
}
Shape::Shape(Position pos, double ang, COLORREF clr, string n)
	: angle(ang), name(n), color(clr)
	//Funtion initialize�� ���Ǹ� �Ͽ��� 
{
	SetPos(pos);				// ��ǥ�� (0, 0)
}

/*				destructor ( �Ҹ��� )				*/
Shape::~Shape()
{
	// destruct Shape object
}

/*				member functions ( ��� �Լ��� )
		1. draw(ostream& ostr)
		  (virtual�� �����Ͽ���, sub-class���� �����ǿ뵵�� ����)
		2. print(ostream& ostr) const ( ��� �Լ� )				*/
void Shape::draw(ostream& ostr)
{
	// virtual �Լ��� �����Ǿ� �Ļ�Ŭ������ �����ǵ� �Լ��� ���Բ�����
	// Draw Shape Funtion, display Shape information 
	ostr << "Shape::draw() => ";
	this->print(ostr); ostr << endl;
}
void Shape::print(ostream& ostr) const
{
	//print form : Shape::draw() => [name(name), pos(x,y), color(RGB(RR,GG,BB))]
	ostr << "[name(" << this->Name() << "), "
		<< this->Pos() << ", "
		<< "color("; printRGB(ostr, this->Color()); ostr << ")]";
}

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( = )
		2. ��� ������ ( << )										*/
Shape& Shape::operator=(const Shape& s)
{
	//  ��ǥ, ����, ����, �̸��� ������
	this->SetPos(s.Pos());
	this->angle = s.angle;
	this->color = s.Color();
	this->NameSet(s.Name());

	return *this;
	// TODO: ���⿡ return ���� �����մϴ�.
}
ostream& operator<<(ostream& ostr, const Shape& s)
{
	// ���
	ostr << "Shape::draw() => ";
	s.print(ostr);
	return ostr;
}
