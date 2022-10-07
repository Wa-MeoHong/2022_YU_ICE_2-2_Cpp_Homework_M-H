#define _USE_MATH_DEFINES
#include "ElpsCylinder.h"

/*				constructor ( ������ )
		1. default constructor ( ����Ʈ ������ )
		2. name�� �μ��� �޴� constructor
		3. ��� ���ڸ� �޴� constructor				*/
ElpsCylinder::ElpsCylinder()
{
	height = 0.0;
}
ElpsCylinder::ElpsCylinder(string n)
	:Elps(n)
{
	height = 0.0;
}
ElpsCylinder::ElpsCylinder(int px, int py, double r1, double r2, double h, double ang, COLORREF clr, string n)
	: Elps(px, py, r1, r2, ang, clr, n)
{
	height = h;
}

/*				destructor ( �Ҹ��� )			*/
ElpsCylinder::~ElpsCylinder()
{
	cout << "ElpsCylinder class terminated!" << endl;
	// height = 0.0;
}

/*				member functions ( ��� �Լ��� )
		1. draw() (�̱���, ���µ��� ����..)
		2. print(ostream&) const ( ��� �Լ� )
		3. Area()	( Ÿ���� �ѳ��̸� ���ϴ� �Լ� )
		4. Volume()	( Ÿ���� ���Ǹ� ���ϴ� �Լ� )				*/
void ElpsCylinder::draw()
{
	// draw Ellipse Cylinder 
}
void ElpsCylinder::print(ostream& out) const
{
	out.setf(ios::showpoint); out.setf(ios::fixed);				// ���� �Ҽ��� 2�ڸ������� ���
	out.precision(2);

	// ��� : ��ǥ - ���� - ���� - ������ - ���� - �ظ���� - �ѳ��� - ����
	out << "radius (" << this->Radius_1() << ", " << this->Radius_2() <<
		"), height (" << this->Height() << "), \n\t";
	out << "elipse_area (" << this->Elps::Area() << "), "
		<< "elp_cyl area (" << this->Area() << "), "
		<< "elp_cyl volume (" << this->Volume() << ")";
}
double ElpsCylinder::Area() const									// �ѳ��̸� ���ϴ� �Լ�
{
	double round, elpsArea;

	elpsArea = this->Elps::Area();									// Ÿ���� ����
	round = 2 * M_PI * sqrt((pow(Radius_1(), 2) + pow(Radius_2(), 2)) / 2); // Ÿ���� �ѷ�
	
	return ((2 * elpsArea) + (height * round));						// Ÿ���� �ѳ��� 
}
double ElpsCylinder::Volume() const									// Ÿ���� ���Ǹ� ���ϴ� �Լ�
{
	double elpsArea;

	elpsArea = this->Elps::Area();									// Ÿ��(�ظ�)�� ����

	return elpsArea * height;										// ���� = �ظ� ���� * ����
}

/*				operator Overloading ( ������ �����ε� )
		1. ���� ������ ( = )
		2. ��� ������ ( << )								*/
ElpsCylinder& ElpsCylinder::operator=(const ElpsCylinder& right)
{
	this->Elps::operator=(right);
	this->height = right.height;

	return *this;
}
ostream& operator<<(ostream& ostr, const ElpsCylinder& elpcyl)
{
	ostr << setw(15) << elpcyl.Name() << ": ";
	elpcyl.Shape::print(ostr); 
	ostr << ", ";	elpcyl.print(ostr);
	return ostr;
	// TODO: ���⿡ return ���� �����մϴ�.
}
