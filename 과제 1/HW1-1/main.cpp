/*
  파일명 : "HW1-1_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- 파일로부터 데이터를 입력 받고, 연산한 결과를 파일로 출력하는 프로그램

  프로그램 작성자 : 신대홍(2022년 8월 29일)
  최종 Update : Version 1.0.0, 2022년 8월 29일 (신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자		   수정일		 버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
   신대홍		 2022/08/29		v1.0.0		  최초작성

===========================================================================================================
*/

#include <iostream>
#include <fstream>
#include <iomanip>

#define INPUT "Input_data.txt"								// INPUT (Input_data.txt) 매크로
#define OUTPUT "Output.txt"									// OUTPUT (Output.txt) 매크로
#define MAX(x, y) ((x) > (y)) ? (x) : (y)					// 최대값 찾기 매크로함수
#define MIN(x, y) ((x) < (y)) ? (x) : (y)					// 최소값 찾기 매크로함수

using namespace std;

int fileInputData(ifstream& fin, int* &data_array, int* max_num_data);		// input 파일에서 읽어오기
void StaticData(ofstream& fout, int* data_array, int num_data);				// 읽어온 데이터를 파일 출력하기

int main()
{
	ifstream fin;											// 읽어올 파일용 ifstream 변수
	ofstream fout;											// 출력용 파일용 ofstream 변수

	int* data_array = NULL;									// 파일안에 있는 데이터 갯수에 따라 동적할당함
	int max_num_data;										// 데이터내부의 MAX값
	int num_data;											// 읽어온 데이터의 개수

	/*			>> 입출력 파일 열기 <<
		1. 입력용, 출력용 파일을 연다.
		2. 열지 못하였을 꼉우 에러메세지 출력후 종료.
	*/
	fin.open(INPUT);
	if (fin.fail())
	{
		cout << "Error! Doesn't Open File!" << endl;
		exit;
	}

	fout.open(OUTPUT);
	if (fout.fail())
	{
		cout << "Error! Doesn't Open File!" << endl;
		exit;
	}

	/*				>> 데이터를 읽고 출력 <<
		1. 먼저 데이터를 읽어와 데이터의 개수를 반환 받음
		2. 읽어온 데이터를 가지고 계산 후, 최대, 최소, 평균, 분산, 표준편차를 출력
	*/
	num_data = fileInputData(fin, data_array, &max_num_data);
	cout << "Input Data Complete..!" << endl;
	StaticData(fout, data_array, num_data);
	cout << "Calculate Data Complete..!" << endl;

	/*					>> 마무리 <<
		1. data_array는 동적할당을 하였으므로 해제해준다.
		2. 열린 파일들을 모두 닫아준다.
	*/
	free(data_array);
	fin.close();
	fout.close();
}

int fileInputData(ifstream& fin, int* &data_array, int* max_num_data)		// input 파일에서 읽어오기 (배열도 반환하므로 &(참조연산자)를 활용함)
{
	int count = 0;										// 읽어들인 데이터의 개수
	int temp = 0;										// 데이터를 읽기위해서 필요한 임시변수

	/*				>> 파일안에 있는 데이터 개수 세기 <<
		1. 파일을 읽어와야 커서가 이동하므로 임시변수 temp를 이용해 읽고 카운트함
		2. 끝났으면 다시 읽어야하므로 커서를 맨 처음으로 돌린다.
	*/

	while (!fin.eof())									// 파일이 끝날때까지
	{
		fin >> temp;									// 파일에서 데이터를 읽어옴
		count++;										// 읽어온 데이터의 수를 체크
	}
	fin.seekg(ios::beg);								// 끝났으면 다시 처음으로 커서를 이동

	/*				>> 파일안에 있는 데이터 개수 읽기 <<
		1. 읽어온 데이터의 개수에 따라 data_array를 동적할당 해준다.
		2. 처음부터 데이터를 읽어서 하나하나 대입해준다.
		3. 그 후, 최대값을 찾기위해 max_num_data에 초기값을 설정 해준 후, 최대값을 찾는다.
		4. 읽어온 데이터의 개수를 반환한다.
	*/
	data_array = (int*)calloc(sizeof(int), count);
	if (data_array == NULL)
	{
		cout << "Error! Doesn't calloc data_array!" << endl;
		exit;
	}


	for (int i = 0; i < count; i++)
		fin >> data_array[i];

	*max_num_data = data_array[0];						// max_num_data를 초기화

	for (int j = 1; j < count; j++)							// 최대값 찾기
	{
		*max_num_data = MAX(data_array[j], * max_num_data);	// MAX매크로를 이용해 찾는다. (조건연산자 활용)
	}

	return count;										// 데이터 개수 반환
}

void StaticData(ofstream& fout, int* data_array, int num_data)		// 데이터 연산 함수
{
	int min = data_array[0], max = data_array[0], sum = 0;			// min, max, sum 설정
	double powSUM = 0, avg = 0, var = 0, std_dev = 0;				// double형 변수, powSUM(제곱의 합), avg, var, std_dev(표준편차)

	// 정보 출력
	fout << "Total " << num_data << " input from input data file." << endl;
	fout << "Total " << num_data << " integer data : (";

	// 데이터 출력
	for (int i = 0; i < num_data; i++)
	{
		fout << data_array[i] << ", ";								// 데이터 출력
		min = MIN(data_array[i], min);								// min 값 찾기 (조건연산자 이용)
		max = MAX(data_array[i], max);								// max 값 찾기 (조건연산자 이용)
		sum += data_array[i];										// sum 구하기 (합산중)
		powSUM += pow(data_array[i], 2);							// powSUM 구하기 (제곱합 중)
	}
	fout << ")" <<  endl;

	// 평균, 분산, 표준편차 구하기 
	avg = (double)sum / (double)num_data;							// 평균 = 합 / 개수
	var = (powSUM / (double)num_data) - pow(avg, 2);				// 분산 = 제곱의 평균 - 평균의 제곱
	std_dev = sqrt(var);											// 표준편차 = √분산
	
	// 연산결과 출력
	fout << "min(" << min << "), max(" << max << "), avg(" << avg << "), var(" << var
		<< "), std_dev (" << std_dev << ")" << endl;
}

