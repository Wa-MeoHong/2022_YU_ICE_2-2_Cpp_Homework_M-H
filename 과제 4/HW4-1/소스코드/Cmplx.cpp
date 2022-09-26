#include "Cmplx.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*					 friend 함수 (입출력 오버로드) 
		1. 출력 오버로드 ( << , 출력 형식을 지정) 
		2. 입력 오버로드 ( >> . 입력 방식을 지정)					*/
ostream& operator<<(ostream& output, const Cmplx& c)		// 출력 연산자 오버로딩 ( << )
{
	output.unsetf(ios::adjustfield);			// 출력 정렬방식 포맷지정 해제
	output.setf(ios::showpoint); output.setf(ios::fixed);		// 고정 소수점 2자리까지만 출력
	output.precision(2);

	// 출력
	output << "(" << setw(6) << c.real;	// 출력 칸은 6자리씩
	if (c.imag < 0)
		cout << " - j" << setw(5) << -(c.imag) << ")";						// 만약 허수부분이 -일 경우, -j를 출력
	else
		cout << " + j" << setw(5) << c.imag << ")";							// 아니면 정상출력

	return output;
}
istream& operator>>(istream& input, Cmplx& c)	//  입력 연산자 오버로딩 ( >> )
{
	input >> c.real >> c.imag;						// 입력

	return input;									// 반환
}

/*					 생성자 (constructor)				*/
Cmplx::Cmplx(double r, double i)						// constructor (생성자)
	:real(r), imag(i)
{ }
/*					 연산자 오버로드 ( 사칙 연산 )				
		1. + 연산자 오버로드 ( 복소수 덧셈 )
		2. - 연산자 오버로드 ( 복소수 뺄셈 )
		3. * 연산자 오버로드 ( 복소수 곱셈 )
		4. / 연산자 오버로드 ( 복소수 나눗셈 )
		4. ~ 연산자 오버로드 ( 음의 복소수 )				*/
const Cmplx Cmplx::operator+(const Cmplx& c)			// 연산자 오버로딩 ( + )
{
	double real, imag;
	// (a + jb) + (c + jd) = (a + b) + j(c + d) 

	real = this->real + c.real;							// 실수부분 덧셈
	imag = this->real + c.imag;							// 허수부분 덧셈

	return Cmplx(real, imag);
}
const Cmplx Cmplx::operator-(const Cmplx&c)				// 연산자 오버로딩 ( - )
{
	double real, imag;

	// (a + jb) - (c + jd) = (a - b) + j(c - d) 

	real = this->real - c.real;						// 실수부분 뺼셈
	imag = this->imag - c.imag;						// 허수부분 뺼셈

	return Cmplx(real, imag);
}
const Cmplx Cmplx::operator*(const Cmplx& c)			// 연산자 오버로딩 ( * )
{
	double real, imag;

	// (a + jb)(c + jd) = (ac - bd) + j(bc + ad) (이차식 곱셈 이용)

	real = (this->real * c.real) - (this->imag * c.imag);	// 실수부분 곱셈
	imag = (this->real * c.imag) + (this->imag * c.real);	// 허수부분 곱셈

	return Cmplx(real, imag);
}
const Cmplx Cmplx::operator/(const Cmplx& c)			// 연산자 오버로딩 ( / )
{
	double real, imag;
	double denom;

	// (a + jb) / (c + jd) = ((ac + bd)/(c² + d²)) + j((bc - ad)/(c² + d²)) (통분 및 이차식 곱셈 이용)

	denom = pow(c.real, 2) + pow(c.imag, 2);							// (c² + d²)		

	real = ((this->real * c.real) + (this->imag * c.imag)) / denom;		// 실수부분 나눗셈 방식
	imag = ((this->imag * c.real) - (this->real * c.imag)) / denom;		// 허수부분 나눗셈

	return Cmplx(real, imag);
}
const Cmplx Cmplx::operator~()							// 연산자 오버로딩 ( ~ , 음의 복소수)
{
	double real, imag;
	// ~(a +jb) = a - jb

	real = this->real;									// 실수부분은 바뀌지 않고
	imag = -(this->imag);						// 허수부분은 음수가 된다

	return Cmplx(real, imag);
}

/*						bool 연산자 오버로드	
		1. mag() (복소수의 크기를 구하는 함수)
		2. == (두 복소수가 같은지 확인)
		3. != (두 복소수가 다른지 확인)
		4. <  (두 복소수중 첫번째가 더 작은지)
		5. >  (두 복소수중 첫번째가 더 큰지)				*/
double Cmplx::mag() const								// a +jb의 크기를 구함
{
	double magnitude;

	// 복소수 크기비교는 좌표계로써 계산하여 원점에서 떨어진 거리로 구한다.
	magnitude = sqrt(pow(real, 2) + pow(imag, 2));		// (a + jb) 의 magnitude = √(a² + b²)

	return magnitude;
}
bool Cmplx::operator==(const Cmplx& c)					// 연산자 오버로딩 ( == )
{
	if ((this->real == c.real) && (this->imag == c.imag))			// 만약 실수부분, 허수부분 모두 같다면 true
		return true;
	else
		return false;									// 그 어느것이라도 아니면 false
}
bool Cmplx::operator!=(const Cmplx& c)					// 연산자 오버로딩 ( != )
{
	if ((this->real == c.real) && (this->imag == c.imag))			// 위의 ==의 조건에 부합하면 false 반환
		return false;
	else
		return true;									// 그 외엔 모두 true
}
bool Cmplx::operator<(const Cmplx& c)					// 연산자 오버로딩 ( < )
{
	if ( mag() < c.mag())								// 두 복소수의 magnitude를 비교하여 첫번째가 작다면 true
		return true;
	else
		return false;									// 아니면 false
}
bool Cmplx::operator>(const Cmplx& c)					// 연산자 오버로딩 ( > )
{
	if (mag() > c.mag())
		return true;									// 두 복소수의 magnitude를 비교하여 첫번째가 크다면 true	
	else
		return false;									// 아니면 false
}

const Cmplx Cmplx::operator=(const Cmplx& c)			// 연산자 오버로딩 ( = )
{
	this->real = c.real;								// 실수부분 대입
	this->imag = c.imag;								// 허수부분 대입

	return *this;										// 자기자신 반환
}

