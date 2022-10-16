#include "Color.h"

ostream& printRGB(ostream& ostr, const COLORREF color)		// ���� ��� �Լ�
{
	COLORREF red, blue, green;

	// �Ű������� ���� COLORREF�� ���� RGB�� ������.	0x00BBGGRR ( ��, ��, �� ����)
	red		 = (color & RGB_RED) >> 0;		// �������� ä�� ( FF�� ���� ���� )
	blue	 = (color & RGB_BLUE) >> 16 ;	// �Ķ��� ä��
	green	 = (color & RGB_GREEN) >> 8;	// �ʷϻ� ä��
	
	// 6�ڸ��� ���, 16����, �빮�� ����
	ostr.fill('0');
	ostr << "RGB(" << hex << uppercase << setw(2) << red;
	ostr << ", " << hex << uppercase << setw(2) << green;
	ostr << ", " << hex << uppercase << setw(2) << blue;
	ostr << dec <<  ")";

	return ostr;
	// TODO: ���⿡ return ���� �����մϴ�.
}