#include "Color.h"

ostream& printRGB(ostream& ostr, const COLORREF color)		// 색깔 출력 함수
{
	COLORREF red, blue, green;

	// 매개변수로 받은 COLORREF를 각각 RGB로 나눈다.	0x00BBGGRR ( 파, 초, 빨 순서)
	red		 = (color & RGB_RED) >> 0;		// 빨간색의 채도 ( FF가 가장 진함 )
	blue	 = (color & RGB_BLUE) >> 16 ;	// 파란색 채도
	green	 = (color & RGB_GREEN) >> 8;	// 초록색 채도
	
	// 6자리만 출력, 16진수, 대문자 형식
	ostr.fill('0');
	ostr << "RGB(" << hex << uppercase << setw(2) << red;
	ostr << ", " << hex << uppercase << setw(2) << green;
	ostr << ", " << hex << uppercase << setw(2) << blue;
	ostr << dec <<  ")";

	return ostr;
	// TODO: 여기에 return 문을 삽입합니다.
}