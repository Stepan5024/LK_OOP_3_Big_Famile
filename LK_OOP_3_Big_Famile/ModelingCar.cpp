/*******************************************************************\
 * Comment(s)    : ОБЪЯВЛЕНИЕ ТРЕХ КЛАССОВ. НАСЛЕДОВАНИЕ            *
 *                 СТАТИЧЕСКИЕ ПРАВИЛА						        *
 *                 РАННЕЕ СВЯЗЫВАНИЕ						        *
 *                                                                  *
 |******************************************************************/

#include <windows.h>
#include "ModelingCar.h"	//объявление классов
#include <iostream>
#include "CarExhaustPipe.h"
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   Г Л О Б А Л Ь Н Ы Е   П Е Р Е М Е Н Н Ы Е  И  К О Н С Т А Н Т Ы   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
 //глобальная переменная видна в двух файлах: Point05_03.cpp и Ex05_03_Con.cpp
 //внешнее обявление глобальной переменной
extern HDC hdc;      // объявим  контекст устройства
using namespace std;

// Макрос для проверки состояния клавиатуры
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

	/*----------------------------------------------------------------*/
	/*             Р Е А Л И З А Ц И Я    М Е Т О Д О В               */
	/*----------------------------------------------------------------*/

			/*----------------------------------------*/
			/*        МЕТОДЫ КЛАССА Location          */
			/*----------------------------------------*/

Location::Location(int InitX, int InitY) //конструктор
{
	//инициализация закрытых переменных своего класса
	X = InitX;
	Y = InitY;
};//end Location::Location()

 
int Location::GetX(void)  //получить X координату точки
{
	return X;
};//end Location::GetX()	

  
int Location::GetY(void) //получить Y координату точки
{
	return Y;
}; //end Location::GetY()


			/*----------------------------------------*/
			/*        МЕТОДЫ КЛАССА Base              */
			/*----------------------------------------*/

//для инициализации закрытых полей используем конструктор предка
Base::Base(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor) : Location(InitX, InitY) //конструктор
{
	BodyCarLenght = InitBodyCarLenght;
	Speed = InitSpeed;
	BaseColor = InitBaseColor;

}//end Base::Base()



BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL); //сделать текущими координаты x1, y1
	return LineTo(hdc, x2, y2);
}
void Base::DrawBaseBody() { // основание
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	//cout << "BodyLenght = " << BodyCarLenght << endl;
	int height = 50;
	// Нарисуем прямоугольник установленным цветом
	Rectangle(hdc, X - BodyCarLenght, Y, X, Y - height); // корпус
	
	int a = BodyCarLenght / 4;
	//cout << " a = " << a << endl;
	int radius = 70;
	Arc(hdc, X - a * 3 + radius / 10 + radius / 2, Y + 20, X - 3 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // левое подколесо
	Arc(hdc, X - 1 * a + radius / 10 + radius / 2, Y + 20, X - 1 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // правое подколесо

	// нарисуем кабину без окон
	int lenght = GetBaseLenght() / 3;
	// Нарисуем прямоугольник установленным цветом

	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght, Y - 50, X - GetBaseLenght() / 3, Y - 120);

	Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Line(hdc, X - a * 3 + radius / 10 + radius / 2 - 5, Y - 2, X - 3 * a - radius / 10 - radius / 2 + 5, Y - 2);
	Line(hdc, X - 1 * a + radius / 10 + radius / 2 - 5, Y - 2, X - 1 * a - radius / 10 - radius / 2 + 5, Y - 2);

	

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Base::DrawBackBody()



void Base::DrawBaseWheels() { // колеса 
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	//int radius = (Y + 35 - (X - 115)) / 2;
	
	int radius = 70;
	//cout << "Raius = " << radius << endl;
	int a = BodyCarLenght / 4;
	Ellipse(hdc, X  - a + radius / 2, Y + 35 - radius, X  - a - radius / 2, Y - 35 + radius);
	Ellipse(hdc, X  - 3 * a + radius / 2, Y + 35 - radius, X - 3 * a - radius / 2, Y - 35 + radius);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Base::DrawBaseWheels()

void Base::Show() {

	DrawBaseBody();
	DrawBaseWheels();

} // Base::Show()

void Base::HideBaseBody() {
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	//cout << "BodyLenght = " << BodyCarLenght << endl;
	int height = 50;
	// Нарисуем прямоугольник установленным цветом
	Rectangle(hdc, X - BodyCarLenght, Y, X, Y - height); // корпус

	int a = BodyCarLenght / 4;
	//cout << " a = " << a << endl;
	int radius = 70;
	Arc(hdc, X - a * 3 + radius / 10 + radius / 2, Y + 20, X - 3 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // левое подколесо
	Arc(hdc, X - 1 * a + radius / 10 + radius / 2, Y + 20, X - 1 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // правое подколесо

	// нарисуем кабину без окон
	int lenght = GetBaseLenght() / 3;
	// Нарисуем прямоугольник установленным цветом

	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght, Y - 50, X - GetBaseLenght() / 3, Y - 120);

	Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Line(hdc, X - a * 3 + radius / 10 + radius / 2 - 5, Y - 2, X - 3 * a - radius / 10 - radius / 2 + 5, Y - 2);
	Line(hdc, X - 1 * a + radius / 10 + radius / 2 - 5, Y - 2, X - 1 * a - radius / 10 - radius / 2 + 5, Y - 2);



	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Base::HideBaseBody()


void Base::HideBaseWheels() {
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	//int radius = (Y + 35 - (X - 115)) / 2;

	int radius = 70;
	//cout << "Raius = " << radius << endl;
	int a = BodyCarLenght / 4;
	Ellipse(hdc, X - a + radius / 2, Y + 35 - radius, X - a - radius / 2, Y - 35 + radius);
	Ellipse(hdc, X - 3 * a + radius / 2, Y + 35 - radius, X - 3 * a - radius / 2, Y - 35 + radius);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Base::hideBaseWheels()

void Base::Hide() {
	
	HideBaseBody();
	HideBaseWheels();

} // Base::Hide()

void Base::MoveTo(int NewX, int NewY) // поставить в соответствие новые координаты
{
	Hide();  //стирание старой окружности
	X = NewX; //поменять координаты
	Y = NewY;
	Show();  //показать окружность на новом месте
}//end Base::MoveTo()

void Base::Drag() //переместить МАШИНУ
{
	int FigX, FigY; // новые координаты фигуры

	FigX = GetX();    //получаем начальное положение фигуры
	FigY = GetY();

	while (1)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(VK_ESCAPE))     //конец работы 27 escape
		{	
			std::cout << "FigX = " << GetX();
			break;
		}
		//направление движения объекта

		if (KEY_DOWN(VK_LEFT)) //стрелка влево  37
		{
			FigX -= GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
		{
			FigX += GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
		{
			FigY += GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_UP)) //стрелка вверх  38
		{
			FigY -= GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if
	}//end while

};//end Base::Drag()

		/*----------------------------------------*/
		/*        МЕТОДЫ КЛАССА Car               */
		/*----------------------------------------*/


//для инициализации закрытых полей используем конструктор предка
Car::Car(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Base(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // конструктор Car
{
	//инициализация закрытых переменных своего класса
	//MaxSpeed = InitMaxSpeed;
}//end Car::Car ()



void Car::DrawCarCabin() {

	// кабина
	cout << "x = " << X << " y = " << Y << endl;
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	int height = 70;
	
	int lenght = GetBaseLenght() / 3;
	// Нарисуем прямоугольник установленным цветом
	
	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght, Y - 50, X - GetBaseLenght() / 3, Y - 120);
	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght * 0.2, Y - 60, X - GetBaseLenght() / 3 - lenght * 0.8, Y - 110); //окошечко
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Car::DrawBaseCabin()

void Car::HideCarCabin() {

	// кабина
	cout << "x = " << X << " y = " << Y << endl;
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	int height = 70;

	int lenght = GetBaseLenght() / 3;
	// Нарисуем прямоугольник установленным цветом

	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght, Y - 50, X - GetBaseLenght() / 3, Y - 120);
	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght * 0.2, Y - 60, X - GetBaseLenght() / 3 - lenght * 0.8, Y - 110); //окошечко
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Car::HideBaseCabin()

void Car::Show(void) // показать круг
{
	
	DrawBaseBody(); // корпус
	DrawBaseWheels(); // колеса
	DrawCarCabin(); // кабина

} // end Car::Show()


void Car::Hide(void) // скрыть машину
{
	HideBaseBody();
	HideBaseWheels();
	HideCarCabin();

}// end Car::Hide()

		/*----------------------------------------*/
		/*        МЕТОДЫ КЛАССА CarWithHood       */
		/*----------------------------------------*/

//для инициализации закрытых полей используем конструктор предка
CarWithHood::CarWithHood(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Car(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // конструктор CarExhaustPipe
{
	//инициализация закрытых переменных своего класса
	//MaxSpeed = InitMaxSpeed;
}//end CarExhaustPipe::CarExhaustPipe()

void CarWithHood::DrawCarHood() { // капот
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	int height = 50;
	int lenght = GetBaseLenght() / 3;
	// Нарисуем дугу установленным цветом
	int a = GetBaseLenght() / 2;
	//cout << " a = " << a << endl;
	int radius = 70;

	POINT poly[6];

	poly[0].x = X; // первая координата полигона
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
	//Arc(hdc, X - a + lenght / 2, Y - 150, X, Y , a * 20, Y - 50, a / 20, Y - 30); // правое подколесо
	int x0 = X - a + lenght / 2;
	int y0 = Y - height  - 50; // левая координата дуги крыша кабины
	int x1 = X;
	int y1 = Y + 70; // правая координата дуги
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
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Car::DrawCarHood()

void CarWithHood::HideCarHood() { // капот
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	int height = 50;
	int lenght = GetBaseLenght() / 3;
	// Нарисуем дугу установленным цветом
	int a = GetBaseLenght() / 2;
	//cout << " a = " << a << endl;
	int radius = 70;

	POINT poly[6];

	poly[0].x = X; // первая координата полигона
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
	//Arc(hdc, X - a + lenght / 2, Y - 150, X, Y , a * 20, Y - 50, a / 20, Y - 30); // правое подколесо
	int x0 = X - a + lenght / 2;
	int y0 = Y - height  - 50; // левая координата дуги крыша кабины
	int x1 = X;
	int y1 = Y + 70; // правая координата дуги
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
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Car::HideCarHood()

void CarWithHood::Show() {

	DrawBaseBody(); // корпус
	DrawBaseWheels(); // колеса
	DrawCarCabin(); // кабина
	DrawCarHood(); // капот
}

void CarWithHood::Hide() {
	HideBaseBody(); // корпус
	HideBaseWheels(); // колеса
	HideCarCabin();
	HideCarHood();
}

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА CarExhaustPipe    */
/*----------------------------------------*/

//для инициализации закрытых полей используем конструктор предка
CarExhaustPipe::CarExhaustPipe(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : CarWithHood(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // конструктор CarExhaustPipe
{
	//инициализация закрытых переменных своего класса
	//MaxSpeed = InitMaxSpeed;
}//end CarExhaustPipe::CarExhaustPipe()

void CarExhaustPipe::DrawExhaustPipe() {
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Rectangle(hdc, X - GetBaseLenght() - 30, Y - 30, X - GetBaseLenght(), Y - 10); // выхлопная труба

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} //CarExhaustPipe::DrawExhaustPipe()

void CarExhaustPipe::HideExhaustPipe() {
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным
	Rectangle(hdc, X - GetBaseLenght() - 30, Y - 30, X - GetBaseLenght(), Y - 10); // выхлопная труба

	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} //CarExhaustPipe::HideExhaustPipe()

void CarExhaustPipe::Show(void) // показать круг
{

	DrawBaseBody(); // корпус
	DrawBaseWheels(); // колеса
	DrawCarCabin(); // кабина
	DrawCarHood(); // капот
	DrawExhaustPipe(); // выхлопная труба
	
} // end CarExhaustPipe::Show()



void CarExhaustPipe::Hide(void) // показать круг
{

	HideBaseBody(); // корпус
	HideBaseWheels(); // колеса
	HideCarCabin(); // кабина
	HideCarHood();
	HideExhaustPipe(); // выхлопная труба

} // end CarExhaustPipe::Show()




/**************   End of File Point05_03.СPP   ********************/
