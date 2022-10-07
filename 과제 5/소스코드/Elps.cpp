#define _USE_MATH_DEFINES
#include "Elps.h"
#include <math.h>

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. name�� �μ��� �޴� constructor
		3. ��� ���ڸ� �޴� constructor				*/
Elps::Elps()
{
	setRadius(0.0, 0.0);							// �������� �⺻ 0.0���� ����
}
Elps::Elps(string name)
	: Shape(name)									// Shape �����ڸ� �ҷ��ͼ� Shape�� ���� ����
{
	setRadius(0.0, 0.0);							// ������ �ʱⰪ�� 0.0����
}
Elps::Elps(int px, int py, double r1, double r2, double ang, COLORREF clr, string name)
	: Shape(px, py, ang, clr, name)					// ��ǥ, ����, ����, �̸��� Shape�� �����ڸ� �̿��� ����
{
	setRadius(r1, r2);								// ������ �ʱⰪ ����
}

/*				destructor ( �Ҹ��� )			*/
Elps::~Elps()
{
	cout << "Elps class terminated!" << endl;
	// setRadius(0.0, 0.0);
}

/*				member functions ( ��� �Լ��� )
		1. draw() (�̱���, ���µ��� ����..)
		2. print(ostream&) const ( ��� �Լ� )
		3. Area()	( Ÿ���� ���̸� ���ϴ� �Լ� )				*/
void Elps::draw()
{
	// draw elps shape
}
void Elps::print(ostream& out) const
{
	out.setf(ios::showpoint); out.setf(ios::fixed);						// ���� �Ҽ��� 2�ڸ������� ���
	out.precision(2);

	// ��� : ��ǥ - ���� - ���� - ������ - ����
	out << "radius (" << this->Radius_1() << "), " << this->Radius_2() <<
		", elipse_area (" << this->Area() << ")";
}
double Elps::Area() const
{
	return radius_1 * radius_2 * M_PI;						// Ÿ���� ���� = r1 * r2 * �� 
}

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( = )
		2. ��� ������ ( << )										*/
Elps& Elps::operator=(const Elps& elp)
{
	this->Shape::operator=(elp);						// Shape�� ���Կ����ڸ� �����ͼ� ������ ��Ŵ (����� �ȵǱ� ����)
	this->setRadius(elp.Radius_1(), elp.Radius_2());	// ������ 2���� ������

	return *this;
	// TODO: ���⿡ return ���� �����մϴ�.
}
ostream& operator<<(ostream& out , const Elps& elps)
{
	out << setw(15) << elps.Name() << ": ";	elps.Shape::print(out);
	out << ", "; elps.print(out); 
	return out;
	// TODO: ���⿡ return ���� �����մϴ�.
}
