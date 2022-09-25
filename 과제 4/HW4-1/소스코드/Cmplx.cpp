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
	Cmplx result;

	// (a + jb) + (c + jd) = (a + b) + j(c + d) 

	result.real = real + c.real;						// �Ǽ��κ� ����
	result.imag = imag + c.imag;						// ����κ� ����

	return result;
}
const Cmplx Cmplx::operator-(const Cmplx&c)				// ������ �����ε� ( - )
{
	Cmplx result;

	// (a + jb) - (c + jd) = (a - b) + j(c - d) 

	result.real = real - c.real;						// �Ǽ��κ� �E��
	result.imag = imag - c.imag;						// ����κ� �E��

	return result;
}
const Cmplx Cmplx::operator*(const Cmplx& c)			// ������ �����ε� ( * )
{
	Cmplx result;

	// (a + jb)(c + jd) = (ac - bd) + j(bc + ad) (������ ���� �̿�)

	result.real = (real * c.real) - (imag * c.imag);	// �Ǽ��κ� ����
	result.imag = (real * c.imag) + (imag * c.real);	// ����κ� ����

	return result;
}
const Cmplx Cmplx::operator/(const Cmplx& c)			// ������ �����ε� ( / )
{
	Cmplx result;
	double denom;

	// (a + jb) / (c + jd) = ((ac + bd)/(c�� + d��)) + j((bc - ad)/(c�� + d��)) (��� �� ������ ���� �̿�)

	denom = pow(c.real, 2) + pow(c.imag, 2);							// (c�� + d��)		

	result.real = ((real * c.real) + (imag * c.imag)) / denom;		// �Ǽ��κ� ������ ���
	result.imag = ((imag * c.real) - (real * c.imag)) / denom;		// ����κ� ������

	return result;
}
const Cmplx Cmplx::operator~()							// ������ �����ε� ( ~ , ���� ���Ҽ�)
{
	Cmplx result;

	// ~(a +jb) = a - jb

	result.real = real;									// �Ǽ��κ��� �ٲ��� �ʰ�
	result.imag = -imag;						// ����κ��� ������ �ȴ�

	return result;
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
	if ((real == c.real) && (imag == c.imag))			// ���� �Ǽ��κ�, ����κ� ��� ���ٸ� true
		return true;
	else
		return false;									// �� ������̶� �ƴϸ� false
}
bool Cmplx::operator!=(const Cmplx& c)					// ������ �����ε� ( != )
{
	if ((real == c.real) && (imag == c.imag))			// ���� ==�� ���ǿ� �����ϸ� false ��ȯ
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

const Cmplx Cmplx::operator=(const Cmplx& c)
{
	real = c.real;
	imag = c.imag;

	return *this;
}

