/*******************************************************************\
 * Comment(s)    : ���������� ���� �������. ������������            *
 *                 ����������� �������						        *
 *                 ������ ����������						        *
 *                                                                  *
 |******************************************************************/

#include <windows.h>
#include "ModelingCar.h"	//���������� �������
#include <iostream>
#include "CarExhaustPipe.h"
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
};// end Location::Location()

 
int Location::GetX(void)  //�������� X ���������� �����
{
	return X;
};// end Location::GetX()	

  
int Location::GetY(void) //�������� Y ���������� �����
{
	return Y;
}; // end Location::GetY()


			/*----------------------------------------*/
			/*        ������ ������ Base              */
			/*----------------------------------------*/

//��� ������������� �������� ����� ���������� ����������� ������
Base::Base(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor) : Location(InitX, InitY) //�����������
{
	BodyCarLenght = InitBodyCarLenght;
	Speed = InitSpeed;
	BaseColor = InitBaseColor;

}// end Base::Base()

BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);		// ������� �������� ���������� x1, y1
	return LineTo(hdc, x2, y2);
} // end Line()

void Base::DrawBaseBody(HPEN Pen) {		// ��������� �� ������� ����� ������

	SelectObject(hdc, Pen);				// ������� ���� ��������
	
	int height = 50;
	// �������� ������������� ������������� ������
	Rectangle(hdc, X - BodyCarLenght, Y, X, Y - height); // ������
	
	int a = BodyCarLenght / 4;
	
	int radius = 70;
	Arc(hdc, X - a * 3 + radius / 10 + radius / 2, Y + 20, X - 3 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // ����� ���������
	Arc(hdc, X - 1 * a + radius / 10 + radius / 2, Y + 20, X - 1 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // ������ ���������

	int lenght = GetBaseLenght() / 3;
	// �������� ������������� ������������� ������

	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght, Y - 50, X - GetBaseLenght() / 3, Y - 120); // �������� ������ ��� ����

	Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);				// ������� ���� ��������
	Line(hdc, X - a * 3 + radius / 10 + radius / 2 - 5, Y - 2, X - 3 * a - radius / 10 - radius / 2 + 5, Y - 2); // �� �������� �����
	Line(hdc, X - 1 * a + radius / 10 + radius / 2 - 5, Y - 2, X - 1 * a - radius / 10 - radius / 2 + 5, Y - 2); // �� �������� �����	

	DeleteObject(Pen);					// ��������� ���� ��������� �������

} // Base::DrawBackBody()

void Base::DrawBaseWheels(HPEN Pen) {	// ������ 
	
	SelectObject(hdc, Pen);				//������� ���� ��������
	
	int radius = 70;					// ������ �����
	
	int a = BodyCarLenght / 4;
	Ellipse(hdc, X  - a + radius / 2, Y + 35 - radius, X  - a - radius / 2, Y - 35 + radius); // ������ ������
	Ellipse(hdc, X  - 3 * a + radius / 2, Y + 35 - radius, X - 3 * a - radius / 2, Y - 35 + radius); // ����� ������
	DeleteObject(Pen); // ��������� ���� ��������� �������
} // Base::DrawBaseWheels()

void Base::Show() { // ���������� ������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // ������� ���� � ���� ���� - �������
	DrawBaseBody(Pen);
	DrawBaseWheels(Pen);
	DeleteObject(Pen); // ��������� ���� ��������� �������  
} // Base::Show()

void Base::Hide() { // �������� ������ ������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); // ������� ���� � ���� ���� - �������
	DrawBaseBody(Pen);
	DrawBaseWheels(Pen);
	DeleteObject(Pen); // ��������� ���� ��������� �������  
} // Base::Hide()

void Base::MoveTo(int NewX, int NewY) // ��������� � ������������ ����� ����������
{
	Hide();			// �������� ������� ������� ������
	X = NewX;		// �������� ����������
	Y = NewY;
	Show();			// �������� ������ ������ �� ����� �����
}// end Base::MoveTo()

void Base::Drag() // ����������� ������
{
	int FigX, FigY; // ����� ���������� ������

	FigX = GetX();    // �������� ��������� ��������� ������
	FigY = GetY();

	while (1)	// ����������� ���� ���������� ������
	{
		if (KEY_DOWN(VK_ESCAPE))     // ����� ������ 27 escape
		{	
			std::cout << "FigX = " << GetX();
			break;
		}
		// ����������� �������� �������
		if (KEY_DOWN(VK_LEFT)) // ������� �����  37
		{
			FigX -= GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}// end if

		if (KEY_DOWN(VK_RIGHT)) // ������� ������  39
		{
			FigX += GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}// end if

		if (KEY_DOWN(VK_DOWN)) // ������� ����  40
		{
			FigY += GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}// end if

		if (KEY_DOWN(VK_UP)) // ������� �����  38
		{
			FigY -= GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}// end if
	}// end while

};// end Base::Drag()

		/*----------------------------------------*/
		/*        ������ ������ Car               */
		/*----------------------------------------*/


//��� ������������� �������� ����� ���������� ����������� ������
Car::Car(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Base(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // ����������� Car
{
	//������������� �������� ���������� ������ ������
	//MaxSpeed = InitMaxSpeed;
}// end Car::Car ()

void Car::DrawCarCabin(HPEN Pen) { // ���������� ������ � �����

	// ������
	cout << "x = " << X << " y = " << Y << endl;
	SelectObject(hdc, Pen);		// ������� ���� ��������
	int height = 70;
	
	int lenght = GetBaseLenght() / 3;
	
	// �������� ������������� ������������� ������
	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght * 0.2, Y - 60, X - GetBaseLenght() / 3 - lenght * 0.8, Y - 110); //��������
	DeleteObject(Pen);			// ��������� ���� ��������� �������
} // Car::DrawBaseCabin()

void Car::Show(void)			// �������� ����
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // ������� ���� � ���� ���� - �������
	DrawBaseBody(Pen);			// ������
	DrawBaseWheels(Pen);		// ������
	DrawCarCabin(Pen);			// ������
	DeleteObject(Pen);			// ��������� ���� ��������� �������  
} // end Car::Show()

void Car::Hide(void)			// ������ ������
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); // ������� ���� � ���� ���� - �������
	DrawBaseBody(Pen);			// ������
	DrawBaseWheels(Pen);		// ������
	DrawCarCabin(Pen);			// ������
	DeleteObject(Pen);			// ��������� ���� ��������� �������  
}// end Car::Hide()

		/*----------------------------------------*/
		/*        ������ ������ CarWithHood       */
		/*----------------------------------------*/

//��� ������������� �������� ����� ���������� ����������� ������
CarWithHood::CarWithHood(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Car(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // ����������� CarExhaustPipe
{
	//������������� �������� ���������� ������ ������
	//MaxSpeed = InitMaxSpeed;
}// end CarExhaustPipe::CarExhaustPipe()

void CarWithHood::DrawCarHood(HPEN Pen) { // �����
	
	
	SelectObject(hdc, Pen);			// ������� ���� ��������
	int heightBase = 50;
	int heightCabin = 70;
	int lenght = GetBaseLenght() / 3;
	
	int a = GetBaseLenght() / 2;
	
	int radius = 70;
	POINT poly[6];

	poly[0].x = X;					// ������ ���������� ��������
	poly[0].y = Y - heightBase;

	poly[1].x = X - lenght / 2 + 50;
	poly[1].y = Y - heightBase - heightBase / 2;

	poly[2].x = X - lenght / 2 - 10;
	poly[2].y = Y - heightCabin / 2 - heightBase + heightCabin / 13;

	poly[3].x = X - a + lenght / 2 + lenght / 3;
	poly[3].y = Y - heightCabin / 2 - heightBase + heightCabin / 18;

	poly[4].x = X - a + lenght / 2 + lenght / 4;
	poly[4].y = Y - heightCabin / 2 - heightBase + heightCabin / 25;

	poly[5].x = X - a + lenght / 2;
	poly[5].y = Y - heightCabin / 2 - heightBase;

	Polyline(hdc, poly, 6);			// �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
} // Car::DrawCarHood()

void CarWithHood::Show() {
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// ������� ���� � ���� ���� - �������
	DrawBaseBody(Pen);				// ������
	DrawBaseWheels(Pen);			// ������
	DrawCarCabin(Pen);				// ������
	DrawCarHood(Pen);				// �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
}

void CarWithHood::Hide() {
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));	// ������� ���� � ���� ���� - �����
	DrawBaseBody(Pen);				// ������
	DrawBaseWheels(Pen);			// ������
	DrawCarCabin(Pen);				// ������
	DrawCarHood(Pen);				// �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
}

/*----------------------------------------*/
/*        ������ ������ CarExhaustPipe    */
/*----------------------------------------*/

//��� ������������� �������� ����� ���������� ����������� ������
CarExhaustPipe::CarExhaustPipe(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : CarWithHood(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // ����������� CarExhaustPipe
{
	//������������� �������� ���������� ������ ������
	//MaxSpeed = InitMaxSpeed;
}// end CarExhaustPipe::CarExhaustPipe()

void CarExhaustPipe::DrawExhaustPipe(HPEN Pen) {
	SelectObject(hdc, Pen);			// ������� ���� ��������
	Rectangle(hdc, X - GetBaseLenght() - 30, Y - 30, X - GetBaseLenght(), Y - 10); // ��������� �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
} //CarExhaustPipe::DrawExhaustPipe()

void CarExhaustPipe::Show(void)		// �������� ������ � ��������� ������
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// ������� ���� � ���� ���� - �������
	DrawBaseBody(Pen);				// ������
	DrawBaseWheels(Pen);			// ������
	DrawCarCabin(Pen);				// ������
	DrawCarHood(Pen);				// �����
	DrawExhaustPipe(Pen);			// ��������� �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������
} // end CarExhaustPipe::Show()

void CarExhaustPipe::Hide(void)		// �������� 
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));	// ������� ���� � ���� ���� - �������
	DrawBaseBody(Pen);				// ������
	DrawBaseWheels(Pen);			// ������
	DrawCarCabin(Pen);				// ������
	DrawCarHood(Pen);				// �����
	DrawExhaustPipe(Pen);			// ��������� �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������
} // end CarExhaustPipe::Show()

/*----------------------------------------*/
/*        ������ ������ CarWithLuggade    */
/*----------------------------------------*/

//��� ������������� �������� ����� ���������� ����������� ������
CarWithLuggade::CarWithLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Car(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // ����������� CarExhaustPipe
{
	//������������� �������� ���������� ������ ������
	//MaxSpeed = InitMaxSpeed;
}// end CarWithLuggade::CarWithLuggade()

void CarWithLuggade::DrawCarLuggade(HPEN Pen) { // ��������


	SelectObject(hdc, Pen);			// ������� ���� ��������
	int heightCabin = 70;
	int heightBase = 50;

	int lenght = GetBaseLenght() / 3;

	int a = GetBaseLenght() / 2;

	int radius = 70;
	POINT poly[4];

	// �������� ������������� ������������� ������
	//Rectangle(hdc, X - GetBaseLenght() / 3 - lenght * 0.2, Y - 60, X - GetBaseLenght() / 3 - lenght * 0.8, Y - 110); //��������


	poly[0].x = X - 2 * GetBaseLenght() / 3;					// ������ ���������� ��������
	poly[0].y = Y - heightCabin / 2 - heightBase;

	poly[1].x = X - 2 * GetBaseLenght() / 3 - GetBaseLenght() / 3 + lenght / 5;
	poly[1].y = Y - heightCabin / 2 - heightBase;

	poly[2].x = X - 2 * GetBaseLenght() / 3 - GetBaseLenght() / 3;
	poly[2].y = Y - heightCabin / 2 - heightBase + lenght / 5;

	poly[3].x = X - GetBaseLenght();
	poly[3].y = Y - heightBase;

	Polyline(hdc, poly, 4);			// �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
} // CarWithLuggade::DrawCarLuggade()

void CarWithLuggade::Show() {
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// ������� ���� � ���� ���� - �������
	DrawBaseBody(Pen);				// ������
	DrawBaseWheels(Pen);			// ������
	DrawCarCabin(Pen);				// ������
	DrawCarLuggade(Pen);			// �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
}

void CarWithLuggade::Hide() {
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));	// ������� ���� � ���� ���� - �����
	DrawBaseBody(Pen);				// ������
	DrawBaseWheels(Pen);			// ������
	DrawCarCabin(Pen);				// ������
	DrawCarLuggade(Pen);			// �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
}

/*-----------------------------------------------*/
/*        ������ ������ CarWithHoodAndLuggade    */
/*-----------------------------------------------*/

//��� ������������� �������� ����� ���������� ����������� ������
CarWithHoodAndLuggade::CarWithHoodAndLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Car(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // ����������� CarExhaustPipe
{
	//������������� �������� ���������� ������ ������
	//MaxSpeed = InitMaxSpeed;
}// end CarWithHoodAndLuggade::CarWithHoodAndLuggade()


void CarWithHoodAndLuggade::DrawCarLuggade(HPEN Pen) { // ��������


	SelectObject(hdc, Pen);			// ������� ���� ��������
	int heightCabin = 70;
	int heightBase = 50;

	int lenght = GetBaseLenght() / 3;

	int a = GetBaseLenght() / 2;

	int radius = 70;
	POINT poly[4];

	// �������� ������������� ������������� ������
	//Rectangle(hdc, X - GetBaseLenght() / 3 - lenght * 0.2, Y - 60, X - GetBaseLenght() / 3 - lenght * 0.8, Y - 110); //��������

	poly[0].x = X - 2 * GetBaseLenght() / 3;					// ������ ���������� ��������
	poly[0].y = Y - heightCabin / 2 - heightBase;

	poly[1].x = X - 2 * GetBaseLenght() / 3 - GetBaseLenght() / 3 + lenght / 5;
	poly[1].y = Y - heightCabin / 2 - heightBase;

	poly[2].x = X - 2 * GetBaseLenght() / 3 - GetBaseLenght() / 3;
	poly[2].y = Y - heightCabin / 2 - heightBase + lenght / 5;

	poly[3].x = X - GetBaseLenght();
	poly[3].y = Y - heightBase;

	Polyline(hdc, poly, 4);			// �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
} // CarWithHoodAndLuggade::DrawCarLuggade()

void CarWithHoodAndLuggade::DrawCarHood(HPEN Pen) { // �����


	SelectObject(hdc, Pen);			// ������� ���� ��������
	int heightBase = 50;
	int heightCabin = 70;
	int lenght = GetBaseLenght() / 3;

	int a = GetBaseLenght() / 2;

	int radius = 70;
	POINT poly[6];

	poly[0].x = X;					// ������ ���������� ��������
	poly[0].y = Y - heightBase;

	poly[1].x = X - lenght / 2 + 50;
	poly[1].y = Y - heightBase - 30;

	poly[2].x = X - lenght / 2 - 10;
	poly[2].y = Y - heightCabin / 2 - heightBase + heightCabin / 13;

	poly[3].x = X - a + lenght / 2 + lenght / 3;
	poly[3].y = Y - heightCabin / 2 - heightBase + heightCabin / 18;

	poly[4].x = X - a + lenght / 2 + lenght / 4;
	poly[4].y = Y - heightCabin / 2 - heightBase + heightCabin / 25;

	poly[5].x = X - a + lenght / 2;
	poly[5].y = Y - heightCabin / 2 - heightBase;

	Polyline(hdc, poly, 6);			// �����
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
} // CarWithHood::DrawCarHood()

void CarWithHoodAndLuggade::Show() {
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));	// ������� ���� � ���� ���� - �������
	DrawBaseBody(Pen);				// ������
	DrawBaseWheels(Pen);			// ������
	DrawCarCabin(Pen);				// ������
	DrawCarLuggade(Pen);			// �����
	DrawCarHood(Pen);				// ��������
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
}

void CarWithHoodAndLuggade::Hide() {
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));	// ������� ���� � ���� ���� - �����
	DrawBaseBody(Pen);				// ������
	DrawBaseWheels(Pen);			// ������
	DrawCarCabin(Pen);				// ������
	DrawCarLuggade(Pen);			// �����
	DrawCarHood(Pen);				// ��������
	DeleteObject(Pen);				// ��������� ���� ��������� �������  
}


/**************   End of File ModelingCar.�PP   ********************/