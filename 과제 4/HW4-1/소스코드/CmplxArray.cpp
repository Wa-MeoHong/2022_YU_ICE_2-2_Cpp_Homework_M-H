#include "CmplxArray.h"

CmplxArray::CmplxArray(int size) 							// constructor (������)
{
	cmplxArraySIZE = size;							// ������ ����
	this->pCA = new Cmplx[size];					// �迭 �����Ҵ� 
	for (int i = 0; i < size; i++)					// ��� �迭������ ���� 0.0���� �ʱ�ȭ
	{
		this->pCA[i].real = 0.0;
		this->pCA[i].imag = 0.0;
	}

	/* this�� ���� ���� : �����Ϸ��� �ڵ����� this��� Ŭ���� ������(����)�� �߰��Ѵ�.  
	 ������ �̸��� �Ȱ��� �Ű������� ���� ������(����Լ�)�� �ִ°��, this�� ���� ������ �����ϴ�
	 �̷� ��, ������ ���� ��Ȯ�ϰ� ���� �ڵ� ���ظ� ������ �� �� �ִ�.	*/
}
CmplxArray::CmplxArray(const CmplxArray& CmArray)
{
	this->cmplxArraySIZE = CmArray.cmplxArraySIZE;			// �迭ũ�� ����
	this->pCA = new Cmplx[cmplxArraySIZE];					// �迭 �����Ҵ�
	for (int i = 0; i < cmplxArraySIZE; i++)				// ��� �迭������ ���� 0.0���� �ʱ�ȭ
	{
		this->pCA[i] = CmArray.pCA[i];						// ���Կ����� �����ε�� ���� =���ᵵ �ذ��
	}
}
CmplxArray::~CmplxArray()
{
	if (cmplxArraySIZE > 0)								// ���� �迭ũ�Ⱑ 0�̻��̶�� �����Ҵ� ����
		delete[] pCA;

}

Cmplx& CmplxArray::operator[](int sub)					// ������ �����ε� [ ] (�迭�� �ε�����ȣ�� ���� ���� ��ȯ)
{
	// sub = �迭 �ε��� ��ȣ, (0 ���� �迭����-1 ������ �ε��������̹Ƿ� ����� ����)
	if (sub < 0 || sub >= cmplxArraySIZE)
		subError();

	return pCA[sub];									// �����̸� �״�� ��ȯ
}
void CmplxArray::subError()								// �迭 �ε��� ���� �Լ�
{
	cout << "ERROR : Subscript out of range." << endl; exit(0);
}
