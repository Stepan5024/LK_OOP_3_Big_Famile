/*******************************************************************\
 * Comment(s)    : ���������� ���� �������. ������������            *
 *                 ����������� �������						        *
 *                 ������ ����������						        *
 *                                                                  *
 |******************************************************************/

#include <windows.h>
#include "ModelingCar.h"	//���������� �������
#include <iostream>

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   � � � � � � � � � �   � � � � � � � � � �  �  � � � � � � � � �   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
 //���������� ���������� ����� � ���� ������: Point05_03.cpp � Ex05_03_Con.cpp
 //������� ��������� ���������� ����������
extern HDC hdc;      // �������  �������� ����������
using namespace std;

// ������ ��� �������� ��������� ����������
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

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

 
int Location::GetX(void)  //�������� X ���������� �����
{
	return X;
};//end Location::GetX()	

  
int Location::GetY(void) //�������� Y ���������� �����
{
	return Y;
}; //end Location::GetY()


			/*----------------------------------------*/
			/*        ������ ������ Base              */
			/*----------------------------------------*/

//��� ������������� �������� ����� ���������� ����������� ������
Base::Base(int InitX, int InitY, int InitBackCarLenght, int InitCabinLenght, int InitHoodLenght, string InitBaseColor) : Location(InitX, InitY) //�����������
{
	BackCarLenght = InitBackCarLenght;
	CabinLenght = InitCabinLenght;
	HoodLenght = InitHoodLenght;
	BaseColor = InitBaseColor;

}//end Base::Base()

void Base::DrawBackBase() {
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������

	// �������� ������������� ������������� ������
	Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	/*Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);*/
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Base::DrawBackBase()

void Base::DrawBaseWheels() {
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������

	//// �������� ������������� ������������� ������
	//Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Base::DrawBaseWheels()

void Base::Show() {

	DrawBackBase();
	DrawBaseWheels();

} // Base::Show()

void Base::HideBackBase() {
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//������� ���� ��������

	// �������� ���� ������������� ������
	Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	/*Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);*/
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Base::HideBackBase()

void Base::hideBaseWheels() {
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//������� ���� ��������

	//// �������� ���� ������������� ������
	//Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Base::hideBaseWheels()

void Base::Hide() {
	
	HideBackBase();
	hideBaseWheels();

} // Base::Hide()

void Base::MoveTo(int NewX, int NewY) // ��������� � ������������ ����� ����������
{
	Hide();  //�������� ������ ����������
	X = NewX; //�������� ����������
	Y = NewY;
	Show();  //�������� ���������� �� ����� �����
}//end Base::MoveTo()

void Base::Drag() //����������� ������
{
	int FigX, FigY; // ����� ���������� ������

	FigX = GetX();    //�������� ��������� ��������� ������
	FigY = GetY();

	while (1)	//����������� ���� ���������� ������
	{
		if (KEY_DOWN(VK_ESCAPE))     //����� ������ 27 escape
		{	
			std::cout << "FigX = " << GetX();
			break;
		}
		//����������� �������� �������

		if (KEY_DOWN(VK_LEFT)) //������� �����  37
		{
			FigX -= GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_RIGHT)) //������� ������  39
		{
			FigX += GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_DOWN)) //������� ����  40
		{
			FigY += GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_UP)) //������� �����  38
		{
			FigY -= GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if
	}//end while

};//end Base::Drag()

		/*----------------------------------------*/
		/*        ������ ������ Car               */
		/*----------------------------------------*/


//��� ������������� �������� ����� ���������� ����������� ������
Car::Car(int InitX, int InitY, int InitBackCarLenght, int InitCabinLenght, int InitHoodLenght, std::string InitBaseColor, int InitMaxSpeed) : Base(InitX, InitY, InitBackCarLenght, InitCabinLenght, InitHoodLenght, InitBaseColor) // ����������� Car
{
	//������������� �������� ���������� ������ ������
	MaxSpeed = InitMaxSpeed;
}//end Car::Car ()



void Car::Show(void) // �������� ����
{
	DrawBackBase();
	DrawBaseWheels();
	/*
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������

	// �������� ������������� ������������� ������
	Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
	*/
} // end Car::Show()


void Car::Hide(void) // ������ ������
{
	HideBackBase();
	hideBaseWheels();

	//// ������� ���� � ���� ���� - �������
	//HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	//SelectObject(hdc, Pen);	//������� ���� ��������

	//// �������� ���� ������������� ������
	//Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	//Rectangle(hdc, X, Y, X - 370, Y - 70);
	//Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	//Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);
	//// ��������� ���� ��������� �������  
	//DeleteObject(Pen);

}// end Car::Hide()



/**************   End of File Point05_03.�PP   ********************/
