#ifndef CMPLXARRAY_H
#define CMPLXARRAY_H

#include <iostream>
#include "Cmplx.h"

/*						클래스 CmplxArray						*/		
class CmplxArray
{
public:
	CmplxArray(int size);							// constructor (생성자)
	CmplxArray(const CmplxArray& CmArray);			// copy array
	~CmplxArray();									// desructor (소멸자)
	int size() { return cmplxArraySIZE; }			// 배열 크기 반환
	Cmplx& operator[](int sub);						// 배열 연산자 오버로드 []
private:
	Cmplx* pCA;										// Cmplx의 배열을 담는 변수
	int cmplxArraySIZE;								// Cmplx배열의 크기
	void subError();								// 에러 발생시 나가는 곳
};

#endif 

