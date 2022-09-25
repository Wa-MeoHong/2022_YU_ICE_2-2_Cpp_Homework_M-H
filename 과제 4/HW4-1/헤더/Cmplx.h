#ifndef CMPLX_H
#define CMPLX_H

#include <iostream>

using namespace std;

class CmplxArray;				// 배열클래스 CmplxArray

/*			클래스 Cmplx			*/	
class Cmplx
{
	friend ostream& operator<<(ostream&, const Cmplx&);		// 출력 연산자 오버로드 함수
	friend istream& operator>>(istream&, Cmplx&);			// 입력 연산자 오버로드 함수
	friend class CmplxArray;								// friend 클래스 CmplxArray(배열 클래스)
public:
	Cmplx(double real_num = 0.0, double imag_num = 0.0);	// 생성자 (constructor)
	double mag() const;										// 복소수 크기
	// 연산자 오버로드 함수 (+, -, *, /, ~)
	const Cmplx operator+(const Cmplx&);
	const Cmplx operator-(const Cmplx&);
	const Cmplx operator*(const Cmplx&);
	const Cmplx operator/(const Cmplx&);
	const Cmplx operator~();

	// bool 연산자 오버로드 함수 ( ==, !=, <, > ) 
	bool operator==(const Cmplx&);
	bool operator!=(const Cmplx&);
	bool operator<(const Cmplx&);
	bool operator>(const Cmplx&);

	// 대입연산자 오버로드
	const Cmplx operator=(const Cmplx&);

private:
	double real;										// 실수부분
	double imag;										// 허수부분
};

#endif // !CMPLX_H


