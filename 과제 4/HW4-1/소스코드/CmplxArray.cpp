#include "CmplxArray.h"

CmplxArray::CmplxArray(int size) 							// constructor (생성자)
{
	cmplxArraySIZE = size;							// 사이즈 대입
	this->pCA = new Cmplx[size];					// 배열 동적할당 
	for (int i = 0; i < size; i++)					// 모든 배열원소의 값을 0.0으로 초기화
	{
		this->pCA[i].real = 0.0;
		this->pCA[i].imag = 0.0;
	}

	/* this를 쓰는 이유 : 컴파일러는 자동으로 this라는 클래스 포인터(본인)을 추가한다.  
	 가끔씩 이름이 똑같은 매개변수를 가진 생성자(멤버함수)가 있는경우, this를 통해 구분이 가능하다
	 이럴 때, 구분을 좀더 명확하게 해줘 코드 이해를 빠르게 할 수 있다.	*/
}
CmplxArray::CmplxArray(const CmplxArray& CmArray)
{
	this->cmplxArraySIZE = CmArray.cmplxArraySIZE;			// 배열크기 복사
	this->pCA = new Cmplx[cmplxArraySIZE];					// 배열 동적할당
	for (int i = 0; i < cmplxArraySIZE; i++)				// 모든 배열원소의 값을 0.0으로 초기화
	{
		this->pCA[i] = CmArray.pCA[i];						// 대입연산자 오버로드로 인해 =만써도 해결됨
	}
}
CmplxArray::~CmplxArray()
{
	if (cmplxArraySIZE > 0)								// 만약 배열크기가 0이상이라면 동적할당 해제
		delete[] pCA;

}

Cmplx& CmplxArray::operator[](int sub)					// 연산자 오버로드 [ ] (배열의 인덱스번호를 통해 원소 반환)
{
	// sub = 배열 인덱스 번호, (0 부터 배열개수-1 까지가 인덱스범위이므로 벗어나면 에러)
	if (sub < 0 || sub >= cmplxArraySIZE)
		subError();

	return pCA[sub];									// 정상이면 그대로 반환
}
void CmplxArray::subError()								// 배열 인덱스 에러 함수
{
	cout << "ERROR : Subscript out of range." << endl; exit(0);
}
