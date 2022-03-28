/*******************************************************************\
 * Comment(s)    : ���������� ���� �������. ������������            *
 *                 ����������� �������						        *
 *                 ������ ����������						        *
 *                                                                  *
 |******************************************************************/

#include <windows.h>
#include "Point05_03.h"	//���������� �������

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   � � � � � � � � � �   � � � � � � � � � �  �  � � � � � � � � �   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
 //���������� ���������� ����� � ���� ������: Point05_03.cpp � Ex05_03_Con.cpp
 //������� ��������� ���������� ����������
extern HDC hdc;      // �������  �������� ����������


	/*----------------------------------------------------------------*/
	/*             � � � � � � � � � �    � � � � � � �               */
	/*----------------------------------------------------------------*/

			/*----------------------------------------*/
			/*        ������ ������ Location          */
			/*----------------------------------------*/

Location::Location(int InitX, int InitY) //�����������
{
	//������������� �������� ���������� ������ ������
	X = InitX;
	Y = InitY;
};//end Location::Location()

 
Location::~Location(void)  //���������� 
{//��������� ������ ����
};//end Location::~Location()

 
int Location::GetX(void)  //�������� X ���������� �����
{
	return X;
};//end Location::GetX()	

  
int Location::GetY(void) //�������� Y ���������� �����
{
	return Y;
}; //end Location::GetY()


			/*----------------------------------------*/
			/*        ������ ������ Point             */
			/*----------------------------------------*/

//��� ������������� �������� ����� ���������� ����������� ������
Point::Point(int InitX, int InitY) : Location(InitX, InitY) //�����������
{
	//������������� �������� ���������� ������ ������
	Visible = false;
}//end Point::Point()


Point::~Point(void)  //����������  
{//��������� ������ ����
}//end Point::~Point()


void Point::Show(void)  //�������� �����
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));	//������ ������� ������
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	// 4 ����� ��� ��������
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));
}//end Point::Show()

 //--------------------------------------------------------------

void Point::Hide(void)  //������ �����
{
	Visible = false;

	SetPixel(hdc, X, Y, RGB(0, 0, 255));//������ ����� ������ ��� ����
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 255));
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
}//end Point::Hide()

 //--------------------------------------------------------------

bool Point::IsVisible(void)  //������ ��� ���������� �����
{
	return Visible;
};//end Point::IsVisible()

//--------------------------------------------------------------

void Point::MoveTo(int NewX, int NewY) //����������� �����
{
	Hide();		//������� ����� ���������
	X = NewX;	//�������� ���������� �����
	Y = NewY;
	Show();		//�������� ����� �� ����� �����
};//end Point::MoveTo()

		/*----------------------------------------*/
		/*        ������ ������ Circle            */
		/*----------------------------------------*/

//��� ������������� �������� ����� ���������� ����������� ������
Circle::Circle(int InitX, int InitY, int InitRadius) :Point(InitX, InitY) // ����������� Circle
{
	//������������� �������� ���������� ������ ������
	Radius = InitRadius;
}//end Circle::Circle ()


Circle::~Circle(void) // ����������
{ //��������� ������ ����
};//end Circle::~Circle ()


void Circle::Show(void) // �������� ����
{
	Visible = true;

	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������

	// �������� ���� ������������� ������
	Ellipse(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius);

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);

} // end Circle::Show()


void Circle::Hide(void) // ������ ����
{
	Visible = false;

	// ������� ���� � ���� ����
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); //�����
	//	HPEN Pen=::CreatePen(PS_SOLID,2,RGB(255,255,255));
	SelectObject(hdc, Pen);

	// �������� ���� ������������� ������
	Ellipse(hdc, X - Radius, Y - Radius, X + Radius, Y + Radius);

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);

}// end Circle::Hide()

// ��������� ����� �� Point   !!!! 
// � ������� ���������� ����, � � ������� ���������� ���  !!!

void Circle::MoveTo(int NewX, int NewY) // ��������� � ������������ ����� ����������
{
	Hide();  //�������� ������ ����������
	X = NewX; //�������� ����������
	Y = NewY;
	Show();  //�������� ���������� �� ����� �����
}//end Circle::MoveTo()


void Circle::Expand(int DeltaRad)  //��������� ������ �����
{
	Hide();             //�������� ���������� �� ������ ��������
	Radius += DeltaRad; //�������� ������ 
	if (Radius < 0)     //��� �������������� ���������� �������
		Radius = 5;
	Show();             //�������� ���������� � ����� ��������
}//end Circle::Expand ()


void Circle::Reduce(int DeltaRad) //��������� ������ �����
{
	Expand(-DeltaRad); //������������� ���������� �������
}//end Circle::Reduce ()

/**************   End of File Point05_03.�PP   ********************/
