#ifndef CMPLX_H
#define CMPLX_H

#include <iostream>

using namespace std;

class CmplxArray;				// �迭Ŭ���� CmplxArray

/*			Ŭ���� Cmplx			*/	
class Cmplx
{
	friend ostream& operator<<(ostream&, const Cmplx&);		// ��� ������ �����ε� �Լ�
	friend istream& operator>>(istream&, Cmplx&);			// �Է� ������ �����ε� �Լ�
	friend class CmplxArray;								// friend Ŭ���� CmplxArray(�迭 Ŭ����)
public:
	Cmplx(double real_num = 0.0, double imag_num = 0.0);	// ������ (constructor)
	double mag() const;										// ���Ҽ� ũ��
	// ������ �����ε� �Լ� (+, -, *, /, ~)
	const Cmplx operator+(const Cmplx&);
	const Cmplx operator-(const Cmplx&);
	const Cmplx operator*(const Cmplx&);
	const Cmplx operator/(const Cmplx&);
	const Cmplx operator~();

	// bool ������ �����ε� �Լ� ( ==, !=, <, > ) 
	bool operator==(const Cmplx&);
	bool operator!=(const Cmplx&);
	bool operator<(const Cmplx&);
	bool operator>(const Cmplx&);

	// ���Կ����� �����ε�
	const Cmplx operator=(const Cmplx&);

private:
	double real;										// �Ǽ��κ�
	double imag;										// ����κ�
};

#endif // !CMPLX_H


