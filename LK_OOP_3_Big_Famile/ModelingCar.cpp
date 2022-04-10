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
Base::Base(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor) : Location(InitX, InitY) //�����������
{
	BodyCarLenght = InitBodyCarLenght;
	Speed = InitSpeed;
	BaseColor = InitBaseColor;

}//end Base::Base()



BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL); //������� �������� ���������� x1, y1
	return LineTo(hdc, x2, y2);
}
void Base::DrawBaseBody() { // ���������
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	//cout << "BodyLenght = " << BodyCarLenght << endl;
	int height = 50;
	// �������� ������������� ������������� ������
	Rectangle(hdc, X - BodyCarLenght, Y, X, Y - height); // ������
	
	int a = BodyCarLenght / 4;
	//cout << " a = " << a << endl;
	int radius = 70;
	Arc(hdc, X - a * 3 + radius / 10 + radius / 2, Y + 20, X - 3 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // ����� ���������
	Arc(hdc, X - 1 * a + radius / 10 + radius / 2, Y + 20, X - 1 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // ������ ���������

	// �������� ������ ��� ����
	int lenght = GetBaseLenght() / 3;
	// �������� ������������� ������������� ������

	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght, Y - 50, X - GetBaseLenght() / 3, Y - 120);

	Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//������� ���� ��������
	Line(hdc, X - a * 3 + radius / 10 + radius / 2 - 5, Y - 2, X - 3 * a - radius / 10 - radius / 2 + 5, Y - 2);
	Line(hdc, X - 1 * a + radius / 10 + radius / 2 - 5, Y - 2, X - 1 * a - radius / 10 - radius / 2 + 5, Y - 2);

	

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Base::DrawBackBody()



void Base::DrawBaseWheels() { // ������ 
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	//int radius = (Y + 35 - (X - 115)) / 2;
	
	int radius = 70;
	//cout << "Raius = " << radius << endl;
	int a = BodyCarLenght / 4;
	Ellipse(hdc, X  - a + radius / 2, Y + 35 - radius, X  - a - radius / 2, Y - 35 + radius);
	Ellipse(hdc, X  - 3 * a + radius / 2, Y + 35 - radius, X - 3 * a - radius / 2, Y - 35 + radius);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Base::DrawBaseWheels()

void Base::Show() {

	DrawBaseBody();
	DrawBaseWheels();

} // Base::Show()

void Base::HideBaseBody() {
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//������� ���� ��������
	//cout << "BodyLenght = " << BodyCarLenght << endl;
	int height = 50;
	// �������� ������������� ������������� ������
	Rectangle(hdc, X - BodyCarLenght, Y, X, Y - height); // ������

	int a = BodyCarLenght / 4;
	//cout << " a = " << a << endl;
	int radius = 70;
	Arc(hdc, X - a * 3 + radius / 10 + radius / 2, Y + 20, X - 3 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // ����� ���������
	Arc(hdc, X - 1 * a + radius / 10 + radius / 2, Y + 20, X - 1 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // ������ ���������

	// �������� ������ ��� ����
	int lenght = GetBaseLenght() / 3;
	// �������� ������������� ������������� ������

	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght, Y - 50, X - GetBaseLenght() / 3, Y - 120);

	Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//������� ���� ��������
	Line(hdc, X - a * 3 + radius / 10 + radius / 2 - 5, Y - 2, X - 3 * a - radius / 10 - radius / 2 + 5, Y - 2);
	Line(hdc, X - 1 * a + radius / 10 + radius / 2 - 5, Y - 2, X - 1 * a - radius / 10 - radius / 2 + 5, Y - 2);



	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Base::HideBaseBody()


void Base::HideBaseWheels() {
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//������� ���� ��������
	//int radius = (Y + 35 - (X - 115)) / 2;

	int radius = 70;
	//cout << "Raius = " << radius << endl;
	int a = BodyCarLenght / 4;
	Ellipse(hdc, X - a + radius / 2, Y + 35 - radius, X - a - radius / 2, Y - 35 + radius);
	Ellipse(hdc, X - 3 * a + radius / 2, Y + 35 - radius, X - 3 * a - radius / 2, Y - 35 + radius);
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Base::hideBaseWheels()

void Base::Hide() {
	
	HideBaseBody();
	HideBaseWheels();

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
Car::Car(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Base(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // ����������� Car
{
	//������������� �������� ���������� ������ ������
	//MaxSpeed = InitMaxSpeed;
}//end Car::Car ()



void Car::DrawCarCabin() {

	// ������
	cout << "x = " << X << " y = " << Y << endl;
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	int height = 70;
	
	int lenght = GetBaseLenght() / 3;
	// �������� ������������� ������������� ������
	
	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght, Y - 50, X - GetBaseLenght() / 3, Y - 120);
	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght * 0.2, Y - 60, X - GetBaseLenght() / 3 - lenght * 0.8, Y - 110); //��������
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Car::DrawBaseCabin()

void Car::HideCarCabin() {

	// ������
	cout << "x = " << X << " y = " << Y << endl;
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//������� ���� ��������
	int height = 70;

	int lenght = GetBaseLenght() / 3;
	// �������� ������������� ������������� ������

	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght, Y - 50, X - GetBaseLenght() / 3, Y - 120);
	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght * 0.2, Y - 60, X - GetBaseLenght() / 3 - lenght * 0.8, Y - 110); //��������
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Car::HideBaseCabin()

void Car::Show(void) // �������� ����
{
	
	DrawBaseBody(); // ������
	DrawBaseWheels(); // ������
	DrawCarCabin(); // ������

} // end Car::Show()


void Car::Hide(void) // ������ ������
{
	HideBaseBody();
	HideBaseWheels();
	HideCarCabin();

}// end Car::Hide()

		/*----------------------------------------*/
		/*        ������ ������ CarWithHood       */
		/*----------------------------------------*/

//��� ������������� �������� ����� ���������� ����������� ������
CarWithHood::CarWithHood(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Car(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // ����������� CarExhaustPipe
{
	//������������� �������� ���������� ������ ������
	//MaxSpeed = InitMaxSpeed;
}//end CarExhaustPipe::CarExhaustPipe()

void CarWithHood::DrawCarHood() { // �����
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	int height = 50;
	int lenght = GetBaseLenght() / 3;
	// �������� ���� ������������� ������
	int a = GetBaseLenght() / 2;
	//cout << " a = " << a << endl;
	int radius = 70;

	POINT poly[6];

	poly[0].x = X; // ������ ���������� ��������
	poly[0].y = Y - height;

	poly[1].x = X - lenght / 2 + 50;
	poly[1].y = Y - height - 30;

	poly[2].x = X - lenght / 2 - 10;
	poly[2].y = Y - height - 35;

	poly[3].x = X - a + lenght / 2 + lenght / 3;
	poly[3].y = Y - height - 40;

	poly[4].x = X - a + lenght / 2 + lenght / 4;
	poly[4].y = Y - height - 50;

	poly[5].x = X - a + lenght / 2;
	poly[5].y = Y - height - 50;

	Polyline(hdc, poly, 6);

	/*
	//Arc(hdc, X - a + lenght / 2, Y - 150, X, Y , a * 20, Y - 50, a / 20, Y - 30); // ������ ���������
	int x0 = X - a + lenght / 2;
	int y0 = Y - height  - 50; // ����� ���������� ���� ����� ������
	int x1 = X;
	int y1 = Y + 70; // ������ ���������� ����
	int stAngle = 0;
	int arcAngle = 60;
	int Center_x = (x0 + x1) / 2;
	int Center_y = (y0 + y1) / 2;
	int StartArc_x, StartArc_y;
	int EndArc_x, EndArc_y;

	double startAngle, endAngle, convrt = 3.14 / 180; //degrees to radians

	startAngle = stAngle * convrt;
	endAngle = (arcAngle + stAngle) * convrt;

	radius = (((x1 - x0) > (y1 - y0)) ? x1 - x0 : y1 - y0) / 2;
	StartArc_x = Center_x + (int)(radius * cos((double)startAngle));
	StartArc_y = Center_y - (int)(radius * sin((double)startAngle));
	EndArc_x = Center_x + (int)(radius * cos((double)endAngle));
	EndArc_y = Center_y - (int)(radius * sin((double)endAngle));

	Arc(hdc, x0, y0, x1, y1, StartArc_x, StartArc_y, EndArc_x, EndArc_y);
	Line(hdc, X - lenght / 4 + 6, Y - height - 30 , X - GetBaseLenght() / 2 + lenght / 2, Y - height - 30);
	*/
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Car::DrawCarHood()

void CarWithHood::HideCarHood() { // �����
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//������� ���� ��������
	int height = 50;
	int lenght = GetBaseLenght() / 3;
	// �������� ���� ������������� ������
	int a = GetBaseLenght() / 2;
	//cout << " a = " << a << endl;
	int radius = 70;

	POINT poly[6];

	poly[0].x = X; // ������ ���������� ��������
	poly[0].y = Y - height;

	poly[1].x = X - lenght / 2 + 50;
	poly[1].y = Y - height - 30;

	poly[2].x = X - lenght / 2 - 10;
	poly[2].y = Y - height - 35;

	poly[3].x = X - a + lenght / 2 + lenght / 3;
	poly[3].y = Y - height - 40;

	poly[4].x = X - a + lenght / 2 + lenght / 4;
	poly[4].y = Y - height - 50;

	poly[5].x = X - a + lenght / 2;
	poly[5].y = Y - height - 50;

	Polyline(hdc, poly, 6);

	/*
	//Arc(hdc, X - a + lenght / 2, Y - 150, X, Y , a * 20, Y - 50, a / 20, Y - 30); // ������ ���������
	int x0 = X - a + lenght / 2;
	int y0 = Y - height  - 50; // ����� ���������� ���� ����� ������
	int x1 = X;
	int y1 = Y + 70; // ������ ���������� ����
	int stAngle = 0;
	int arcAngle = 60;
	int Center_x = (x0 + x1) / 2;
	int Center_y = (y0 + y1) / 2;
	int StartArc_x, StartArc_y;
	int EndArc_x, EndArc_y;

	double startAngle, endAngle, convrt = 3.14 / 180; //degrees to radians

	startAngle = stAngle * convrt;
	endAngle = (arcAngle + stAngle) * convrt;

	radius = (((x1 - x0) > (y1 - y0)) ? x1 - x0 : y1 - y0) / 2;
	StartArc_x = Center_x + (int)(radius * cos((double)startAngle));
	StartArc_y = Center_y - (int)(radius * sin((double)startAngle));
	EndArc_x = Center_x + (int)(radius * cos((double)endAngle));
	EndArc_y = Center_y - (int)(radius * sin((double)endAngle));

	Arc(hdc, x0, y0, x1, y1, StartArc_x, StartArc_y, EndArc_x, EndArc_y);
	Line(hdc, X - lenght / 4 + 6, Y - height - 30 , X - GetBaseLenght() / 2 + lenght / 2, Y - height - 30);
	*/
	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} // Car::HideCarHood()

void CarWithHood::Show() {

	DrawBaseBody(); // ������
	DrawBaseWheels(); // ������
	DrawCarCabin(); // ������
	DrawCarHood(); // �����
}

void CarWithHood::Hide() {
	HideBaseBody(); // ������
	HideBaseWheels(); // ������
	HideCarCabin();
	HideCarHood();
}

/*----------------------------------------*/
/*        ������ ������ CarExhaustPipe    */
/*----------------------------------------*/

//��� ������������� �������� ����� ���������� ����������� ������
CarExhaustPipe::CarExhaustPipe(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : CarWithHood(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // ����������� CarExhaustPipe
{
	//������������� �������� ���������� ������ ������
	//MaxSpeed = InitMaxSpeed;
}//end CarExhaustPipe::CarExhaustPipe()

void CarExhaustPipe::DrawExhaustPipe() {
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//������� ���� ��������
	Rectangle(hdc, X - GetBaseLenght() - 30, Y - 30, X - GetBaseLenght(), Y - 10); // ��������� �����

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} //CarExhaustPipe::DrawExhaustPipe()

void CarExhaustPipe::HideExhaustPipe() {
	// ������� ���� � ���� ���� - �������
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//������� ���� ��������
	Rectangle(hdc, X - GetBaseLenght() - 30, Y - 30, X - GetBaseLenght(), Y - 10); // ��������� �����

	// ��������� ���� ��������� �������  
	DeleteObject(Pen);
} //CarExhaustPipe::HideExhaustPipe()

void CarExhaustPipe::Show(void) // �������� ����
{

	DrawBaseBody(); // ������
	DrawBaseWheels(); // ������
	DrawCarCabin(); // ������
	DrawCarHood(); // �����
	DrawExhaustPipe(); // ��������� �����
	
} // end CarExhaustPipe::Show()



void CarExhaustPipe::Hide(void) // �������� ����
{

	HideBaseBody(); // ������
	HideBaseWheels(); // ������
	HideCarCabin(); // ������
	HideCarHood();
	HideExhaustPipe(); // ��������� �����

} // end CarExhaustPipe::Show()




/**************   End of File Point05_03.�PP   ********************/
