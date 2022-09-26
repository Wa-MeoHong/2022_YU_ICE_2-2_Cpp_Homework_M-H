#include "Cmplx.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*					 friend �Լ� (����� �����ε�) 
		1. ��� �����ε� ( << , ��� ������ ����) 
		2. �Է� �����ε� ( >> . �Է� ����� ����)					*/
ostream& operator<<(ostream& output, const Cmplx& c)		// ��� ������ �����ε� ( << )
{
	output.unsetf(ios::adjustfield);			// ��� ���Ĺ�� �������� ����
	output.setf(ios::showpoint); output.setf(ios::fixed);		// ���� �Ҽ��� 2�ڸ������� ���
	output.precision(2);

	// ���
	output << "(" << setw(6) << c.real;	// ��� ĭ�� 6�ڸ���
	if (c.imag < 0)
		cout << " - j" << setw(5) << -(c.imag) << ")";						// ���� ����κ��� -�� ���, -j�� ���
	else
		cout << " + j" << setw(5) << c.imag << ")";							// �ƴϸ� �������

	return output;
}
istream& operator>>(istream& input, Cmplx& c)	//  �Է� ������ �����ε� ( >> )
{
	input >> c.real >> c.imag;						// �Է�

	return input;									// ��ȯ
}

/*					 ������ (constructor)				*/
Cmplx::Cmplx(double r, double i)						// constructor (������)
	:real(r), imag(i)
{ }
/*					 ������ �����ε� ( ��Ģ ���� )				
		1. + ������ �����ε� ( ���Ҽ� ���� )
		2. - ������ �����ε� ( ���Ҽ� ���� )
		3. * ������ �����ε� ( ���Ҽ� ���� )
		4. / ������ �����ε� ( ���Ҽ� ������ )
		4. ~ ������ �����ε� ( ���� ���Ҽ� )				*/
const Cmplx Cmplx::operator+(const Cmplx& c)			// ������ �����ε� ( + )
{
	double real, imag;
	// (a + jb) + (c + jd) = (a + b) + j(c + d) 

	real = this->real + c.real;							// �Ǽ��κ� ����
	imag = this->real + c.imag;							// ����κ� ����

	return Cmplx(real, imag);
}
const Cmplx Cmplx::operator-(const Cmplx&c)				// ������ �����ε� ( - )
{
	double real, imag;

	// (a + jb) - (c + jd) = (a - b) + j(c - d) 

	real = this->real - c.real;						// �Ǽ��κ� �E��
	imag = this->imag - c.imag;						// ����κ� �E��

	return Cmplx(real, imag);
}
const Cmplx Cmplx::operator*(const Cmplx& c)			// ������ �����ε� ( * )
{
	double real, imag;

	// (a + jb)(c + jd) = (ac - bd) + j(bc + ad) (������ ���� �̿�)

	real = (this->real * c.real) - (this->imag * c.imag);	// �Ǽ��κ� ����
	imag = (this->real * c.imag) + (this->imag * c.real);	// ����κ� ����

	return Cmplx(real, imag);
}
const Cmplx Cmplx::operator/(const Cmplx& c)			// ������ �����ε� ( / )
{
	double real, imag;
	double denom;

	// (a + jb) / (c + jd) = ((ac + bd)/(c�� + d��)) + j((bc - ad)/(c�� + d��)) (��� �� ������ ���� �̿�)

	denom = pow(c.real, 2) + pow(c.imag, 2);							// (c�� + d��)		

	real = ((this->real * c.real) + (this->imag * c.imag)) / denom;		// �Ǽ��κ� ������ ���
	imag = ((this->imag * c.real) - (this->real * c.imag)) / denom;		// ����κ� ������

	return Cmplx(real, imag);
}
const Cmplx Cmplx::operator~()							// ������ �����ε� ( ~ , ���� ���Ҽ�)
{
	double real, imag;
	// ~(a +jb) = a - jb

	real = this->real;									// �Ǽ��κ��� �ٲ��� �ʰ�
	imag = -(this->imag);						// ����κ��� ������ �ȴ�

	return Cmplx(real, imag);
}

/*						bool ������ �����ε�	
		1. mag() (���Ҽ��� ũ�⸦ ���ϴ� �Լ�)
		2. == (�� ���Ҽ��� ������ Ȯ��)
		3. != (�� ���Ҽ��� �ٸ��� Ȯ��)
		4. <  (�� ���Ҽ��� ù��°�� �� ������)
		5. >  (�� ���Ҽ��� ù��°�� �� ū��)				*/
double Cmplx::mag() const								// a +jb�� ũ�⸦ ����
{
	double magnitude;

	// ���Ҽ� ũ��񱳴� ��ǥ��ν� ����Ͽ� �������� ������ �Ÿ��� ���Ѵ�.
	magnitude = sqrt(pow(real, 2) + pow(imag, 2));		// (a + jb) �� magnitude = ��(a�� + b��)

	return magnitude;
}
bool Cmplx::operator==(const Cmplx& c)					// ������ �����ε� ( == )
{
	if ((this->real == c.real) && (this->imag == c.imag))			// ���� �Ǽ��κ�, ����κ� ��� ���ٸ� true
		return true;
	else
		return false;									// �� ������̶� �ƴϸ� false
}
bool Cmplx::operator!=(const Cmplx& c)					// ������ �����ε� ( != )
{
	if ((this->real == c.real) && (this->imag == c.imag))			// ���� ==�� ���ǿ� �����ϸ� false ��ȯ
		return false;
	else
		return true;									// �� �ܿ� ��� true
}
bool Cmplx::operator<(const Cmplx& c)					// ������ �����ε� ( < )
{
	if ( mag() < c.mag())								// �� ���Ҽ��� magnitude�� ���Ͽ� ù��°�� �۴ٸ� true
		return true;
	else
		return false;									// �ƴϸ� false
}
bool Cmplx::operator>(const Cmplx& c)					// ������ �����ε� ( > )
{
	if (mag() > c.mag())
		return true;									// �� ���Ҽ��� magnitude�� ���Ͽ� ù��°�� ũ�ٸ� true	
	else
		return false;									// �ƴϸ� false
}

const Cmplx Cmplx::operator=(const Cmplx& c)			// ������ �����ε� ( = )
{
	this->real = c.real;								// �Ǽ��κ� ����
	this->imag = c.imag;								// ����κ� ����

	return *this;										// �ڱ��ڽ� ��ȯ
}

