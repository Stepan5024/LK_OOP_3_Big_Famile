/*******************************************************************\
 * Comment(s)    : ОБЪЯВЛЕНИЕ ТРЕХ КЛАССОВ. НАСЛЕДОВАНИЕ            *
 *                 СТАТИЧЕСКИЕ ПРАВИЛА						        *
 *                 РАННЕЕ СВЯЗЫВАНИЕ						        *
 *                                                                  *
 |******************************************************************/

#include <windows.h>
#include "ModelingCar.h"	//объявление классов
#include <iostream>

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
Base::Base(int InitX, int InitY, int InitBackCarLenght, int InitCabinLenght, int InitHoodLenght, string InitBaseColor) : Location(InitX, InitY) //конструктор
{
	BackCarLenght = InitBackCarLenght;
	CabinLenght = InitCabinLenght;
	HoodLenght = InitHoodLenght;
	BaseColor = InitBaseColor;

}//end Base::Base()

void Base::DrawBackBase() {
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем прямоугольник установленным цветом
	Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	/*Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);*/
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Base::DrawBackBase()

void Base::DrawBaseWheels() {
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным

	//// Нарисуем прямоугольник установленным цветом
	//Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Base::DrawBaseWheels()

void Base::Show() {

	DrawBackBase();
	DrawBaseWheels();

} // Base::Show()

void Base::HideBackBase() {
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем круг установленным цветом
	Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	/*Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);*/
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Base::HideBackBase()

void Base::hideBaseWheels() {
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	SelectObject(hdc, Pen);	//сделаем перо активным

	//// Нарисуем круг установленным цветом
	//Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
} // Base::hideBaseWheels()

void Base::Hide() {
	
	HideBackBase();
	hideBaseWheels();

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
Car::Car(int InitX, int InitY, int InitBackCarLenght, int InitCabinLenght, int InitHoodLenght, std::string InitBaseColor, int InitMaxSpeed) : Base(InitX, InitY, InitBackCarLenght, InitCabinLenght, InitHoodLenght, InitBaseColor) // конструктор Car
{
	//инициализация закрытых переменных своего класса
	MaxSpeed = InitMaxSpeed;
}//end Car::Car ()



void Car::Show(void) // показать круг
{
	DrawBackBase();
	DrawBaseWheels();
	/*
	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем прямоугольник установленным цветом
	Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);
	*/
} // end Car::Show()


void Car::Hide(void) // скрыть машину
{
	HideBackBase();
	hideBaseWheels();

	//// Зададим перо и цвет пера - красный
	//HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	//SelectObject(hdc, Pen);	//сделаем перо активным

	//// Нарисуем круг установленным цветом
	//Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	//Rectangle(hdc, X, Y, X - 370, Y - 70);
	//Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	//Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);
	//// Уничтожим нами созданные объекты  
	//DeleteObject(Pen);

}// end Car::Hide()



/**************   End of File Point05_03.СPP   ********************/
