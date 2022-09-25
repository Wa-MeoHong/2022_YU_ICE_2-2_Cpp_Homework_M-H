#ifndef CMPLXARRAY_H
#define CMPLXARRAY_H

#include <iostream>
#include "Cmplx.h"

/*						Ŭ���� CmplxArray						*/		
class CmplxArray
{
public:
	CmplxArray(int size);							// constructor (������)
	CmplxArray(const CmplxArray& CmArray);			// copy array
	~CmplxArray();									// desructor (�Ҹ���)
	int size() { return cmplxArraySIZE; }			// �迭 ũ�� ��ȯ
	Cmplx& operator[](int sub);						// �迭 ������ �����ε� []
private:
	Cmplx* pCA;										// Cmplx�� �迭�� ��� ����
	int cmplxArraySIZE;								// Cmplx�迭�� ũ��
	void subError();								// ���� �߻��� ������ ��
};

#endif 

