#include "Shape.h"
#include "Color.h"

/*				constructor ( ������ )				
		1. default constructor ( ����Ʈ ������ )
		2. name�� �μ��� �޴� constructor
		3. ��� ���ڸ� �޴� constructor				*/
Shape::Shape()
{
	pos_x = 0;
	pos_y = 0;							// ��ǥ�� ���� (0, 0)
	angle = 0.0;						// ���� 0.0���� �ʱ�ȭ
	name = "";							// �̸��� ����
	color = RGB_BLACK;					// ����Ʈ �ʱⰪ�� ���������� ����
}
Shape::Shape(string name)
{
	pos_x = 0;
	pos_y = 0;							// ��ǥ�� ���� (0, 0)
	angle = 0.0;						// ���� 0.0���� �ʱ�ȭ
	NameSet(name);						// �̸��� ����
	color = RGB_BLACK;					// ����Ʈ �ʱⰪ�� ���������� ����
}
Shape::Shape(int px, int py, double angle, COLORREF color, string name)
	: color(color), angle(angle)		// �̸� ������ ������ ����
{
	set_Pos_X(px);						// �Լ��� ���� ����
	set_Pos_Y(py);
	NameSet(name);
}

/*				destructor ( �Ҹ��� )			*/
Shape::~Shape()
{
	cout << "Shape class terminated!" << endl;
	// pos_x = 0;
	// pos_y = 0;
	// angle = 0.0;
	// name = "";
	// color = 
}

/*				member functions ( ��� �Լ��� )				
		1. draw() (�̱���, ���µ��� ����..)
		2. print(ostream&) const ( ��� �Լ� )				*/
void Shape::draw()
{
	// draw shape
}
void Shape::print(ostream& out) const
{
	// ��� ���� : ��ǥ - ���� - ���� (������ �����Ҽ��� 2�ڸ����� )
	out << "pos (" << setw(3) << this->Pos_X() << ", " << setw(3) << this->Pos_Y() << "), ";
	out.setf(ios::showpoint); out.setf(ios::fixed);						// ���� �Ҽ��� 2�ڸ������� ���
	out.precision(2);
	out << "angle (" << this->angle << "), ";	out.unsetf(ios::adjustfield);
	out << "color ("; printRGB(out, this->color) << ")";
}

/*				operator Overloading ( ������ �����ε� )				
		1. ���� ������ ( = )
		2. ��� ������ ( << )										*/
Shape& Shape::operator=(const Shape& s)
{
	this->set_Pos_X(s.Pos_X());				// ��ǥ ���� ( x, y )
	this->set_Pos_Y(s.Pos_Y());
	this->NameSet(s.Name());				// �̸� ����
	this->angle = s.angle;					// ���� ����
	this->color = s.color;					// ���� ����

	return *this;							// �ڱ��ڽ� ��ȯ
	// TODO: ���⿡ return ���� �����մϴ�.
}
ostream& operator<<(ostream& out, const Shape s)			// ������ �����ε� ���
{
	out << setw(15) << s.Name() << ": ";	s.print(out);			// ���
	return out; 
	// TODO: ���⿡ return ���� �����մϴ�.
}