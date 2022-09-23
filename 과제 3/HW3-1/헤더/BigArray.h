#ifndef BIG_ARRAY_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

typedef struct ArrayStatistics {
	int min;					// 최소값
	int max;					// 최대값
	double avg;					// 평균
	double var;					// 분산
	double std_dev;				// 표준편차
}Statistics;

class BigArray
{
public:
	BigArray(int n);			// constructor (생성자)
	~BigArray();				// destructor (소멸자)
	int* genBigRandArray(int size, int offset);		// BigRand 배열을 생성하는 함수
	int size() { return num_elements; }				// 배열의 크기 반환
	void suffle();									// 배열 셔플
	void selection_sort();							// 배열 선택정렬
	void quick_sort();								// 배열 퀵정렬
	void getStatistics(Statistics&);				// 배열 데이터 계산
	void fprintStatistics(ostream& fout);			// 배열 데이터 계산결과 출력
	void fprintBigArray(ostream& fout, int num_per_line);		// 배열 파일 출력

private:
	int* big_array = NULL;				// 포인터 변수 big_array
	int num_elements = 0;				// 생성할 배열 사이즈
};

#endif