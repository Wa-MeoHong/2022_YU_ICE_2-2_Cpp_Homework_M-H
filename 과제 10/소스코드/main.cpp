/*
  파일명 : "HW10_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- Binary Search Tree를 구성하고, BST의 단점을 보완하기위해, 리밸런싱을 진행하는 알고리즘
  프로그램 작성자 : 신대홍(2022년 11월 15일)
  최종 Update : Version 1.0.1, 2022년 11월 18일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자	  수정일			버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
	신대홍		 2022/11/15		v1.0.0		  최초작성
	신대홍		 2022/11/17		v1.1.0		  코드완성
	신대홍		 2022/11/18		v1.1.1		  rotate_RL 수정
===========================================================================================================
*/

#include "T_BST.h"
#include "T_Array.h"
#include "T_Entry.h"
#include "Date.h"
#include "Student.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#define INPUT "students.txt"
#define OUTPUT "output.txt"

Student* fGetStudentRecords(string f_name, int* num_students)		// 파일입력을 받게하는 함수
{
	ifstream fin(f_name);
	Student* pSts = NULL;
	string name, date_str;
	int st_id = 0, year = 0, month = 0, day = 0;
	double gpa = 0.0;

	if (fin.fail())
	{
		cout << "Error! does not open students.txt!\n";
		exit(-1);
	}

	fin >> *num_students;
	pSts = new Student[*num_students];				// 배열 동적할당
	
	cout << "Number of Students (from file) = " << *num_students << endl;

	for (int i = 0; i < *num_students; i++)
	{
		fin >> st_id >> name >> date_str >> gpa;	// 학번, 이름, 생년월일 문자열, 학점 순으로 받아옴
		
		for (int i = 0; i < date_str.size(); i++)
		{
			if (date_str[i] == '-')
				date_str[i] = ' ';
		}
		stringstream date_ss;
		date_ss.str(date_str);					// 분리한 문자열을 stringstream객체에 넣고
		date_ss >> year >> month >> day;		// 공백으로 분리하면서 값을 넣어줌

		// 받아온 데이터를 토대로 Student객체 생성
		pSts[i] = Student(st_id, name, Date(year, month, day), gpa);

	}

	fin.close();
	return pSts;			// 파일을 닫고 반환


}

int main(void)
{
	ofstream fout(OUTPUT);
	int num_students = 0;
	Student* students = fGetStudentRecords(INPUT, &num_students);

	if (fout.fail())
	{
		cout << "Error! does not open output.txt!\n";
		exit(-1);
	}

	fout << "Input students[] array : " << endl;
	for (int i = 0; i < num_students; i++)
	{
		fout << students[i] << endl;					// 파일로부터 가져온 Student객체를 출력(1줄씩)
	}
	fout << endl;

	/* 1. Balanced 이진탐색트리 제작 ( Key는 학생의 이름 ) */
	fout << endl << "Balanced Binary Search Tree (BBST) with key Student_Name" << endl;
	T_Entry<string, Student*> entry_name_pST;
	T_BST<string, Student*> BBST_keyname("BBST_keyname");
	T_BSTN<string, Student*>* pRoot = NULL, ** ppBBST_Root = NULL;
	ppBBST_Root = BBST_keyname.RootAddr();

	// 이진탐색트리에 값을 집어넣음. (리밸런싱도 같이 진행)
	for (int i = 0; i < num_students; i++)
	{
		entry_name_pST.SetKey(students[i].Name());
		entry_name_pST.SetVal(&students[i]);
		BBST_keyname.insertAndReBal(entry_name_pST);			// insert와 리밸런싱을 동시에 처리
	}
	// 넣은 이진탐색트리를 출력함
	fout << "\nEntries in " << BBST_keyname.Name() << " (in order to Student_Name) : " << endl;
	BBST_keyname.print_with_Depth(fout);


	/* 2. Balanced 이진탐색트리 제작 ( Key는 학번 ) */
	fout << endl << "Balanced Binary Search Tree (BBST) with key student_StID " << endl;
	T_Entry<int, Student*> entry_StID_pST;
	T_BST<int, Student*> BBST_keyStID("BBST_keyStID");
	T_BSTN<int, Student*>* pBBST_keyStID = NULL, ** ppRoot_BBST_keyStID= NULL;
	ppRoot_BBST_keyStID = BBST_keyStID.RootAddr();

	// 이진탐색트리에 값을 집어넣음. (리밸런싱도 같이 진행)
	for (int i = 0; i < num_students; i++)
	{
		entry_StID_pST.SetKey(students[i].StID());
		entry_StID_pST.SetVal(&students[i]);
		BBST_keyStID.insertAndReBal(entry_StID_pST);			// insert와 리밸런싱을 동시에 처리
	}
	// 넣은 이진탐색트리를 출력함
	fout << "\nEntries in " << BBST_keyStID.Name() << " (in order to Book Title) : " << endl;
	BBST_keyStID.print_with_Depth(fout);

	/* 3. Balanced 이진탐색트리 제작 ( Key는 학생의 생년월일 ) */
	fout << endl << "Balanced Binary Search Tree (BBST) with key Birth-date" << endl;
	T_Entry<Date, Student*> entry_BirthDate_pST;		// 학생 엔트리
	T_BST<Date, Student*> BBST_keyBirthDate("BBST_keyBirthDate");
	T_BSTN<Date, Student*>*pBBST_keyBirth = NULL, ** ppRoot_BBST_keyBirthDate = NULL;
	ppRoot_BBST_keyBirthDate = BBST_keyBirthDate.RootAddr();

	for (int i = 0; i < num_students; i++)
	{
		// 이진탐색트리에 값을 집어넣음. (리밸런싱도 같이 진행)
		entry_BirthDate_pST.SetKey(students[i].BirthDate());
		entry_BirthDate_pST.SetVal(&students[i]);
		BBST_keyBirthDate.insertAndReBal(entry_BirthDate_pST);
	}
	// 넣은 이진탐색트리를 출력함
	fout << "\nEntries in " << BBST_keyBirthDate.Name() << " (in order to Student BirthDate) : " << endl;
	BBST_keyBirthDate.print_with_Depth(fout);


	// Testing Search on Binary Search Tree
	Date StDoB = students[0].BirthDate();
	Date d1(1995, 1, 1), d2(1999, 12, 31);				// 1995.01.01 ~ 1999.12.31 까지의 날짜안에서
	Student* pSt;
	T_Array<Student*> array_pST(1, string("Array_Student"));
	pBBST_keyBirth = BBST_keyBirthDate.searchBSTN(StDoB);			// 이 값에 해당되는 노드를 찾는다. 
	BBST_keyBirthDate.travelsal_inOrder(pBBST_keyBirth, array_pST);	// 순회하면서 만난 값들을 기록
	cout << "\nStudents of birth date during " << d1 << " ~ " << d2 << ": " << endl;
	for (int i = 0; i < array_pST.size(); i++)
	{
		// 만약 날짜 d1, d2사이의 생년월일이라면 출력한다.
		pSt = array_pST[i];
		if ((pSt->BirthDate() >= d1) && (pSt->BirthDate() <= d2))
			cout << *pSt << endl;
	}

	/* 4. Remove root entry */
	fout << "\nRemoving the root entry in sequence . . ." << endl;
	for (int i = 0; i < num_students; i++)
	{
		pRoot = BBST_keyname.Root();				// 루트노드(최상위 노드) 가져옴
		entry_name_pST = pRoot->Entry();			// 루트노드의 엔트리( 값)을 가져옴
		fout << "\nremove " << entry_name_pST << endl;		
		BBST_keyname.eraseBSTN(&pRoot);				// 루트노드 삭제
		BBST_keyname.print_with_Depth(fout);		// 출력
	}

	// 다 했기 때문에 이제 값을 지움
	fout << "\nClearing BBST_STs . . . " << endl;
	BBST_keyStID.clear();
	BBST_keyBirthDate.clear();
	fout << "All BBST_STs cleared !! " << endl;

	fout.close();
	if (students != NULL)
		delete[] students;

	return  0;

}