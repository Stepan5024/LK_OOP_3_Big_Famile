/*******************************************************************\
 * Comment(s)    : ОБЪЯВЛЕНИЕ ТРЕХ КЛАССОВ. НАСЛЕДОВАНИЕ            *
 *                 СТАТИЧЕСКИЕ ПРАВИЛА						        *
 *                 РАННЕЕ СВЯЗЫВАНИЕ						        *
 *                                                                  *
 \******************************************************************/

#include <windows.h>
#include "ModelingCar.h"	//объявление классов
#include <iostream>
#include "CarExhaustPipe.h"
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   Г Л О Б А Л Ь Н Ы Е   П Е Р Е М Е Н Н Ы Е  И  К О Н С Т А Н Т Ы   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
 //глобальная переменная видна в файлах
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
	X = InitX;
	Y = InitY;
};

int Location::GetX()  // получить X координату точки
{	return X;	};

  
int Location::GetY() // получить Y координату точки
{	return Y;	};

void Location::SetX(int NewX)  // установить новое значение Х
{	X = NewX;	};


void Location::SetY(int NewY) // установить новое значение Y 
{	Y = NewY;	}; 


Canister::Canister(int InitX, int InitY, int InitFuelCapacity) : Location(InitX, InitY) {
	FuelCapacity = InitFuelCapacity; } 
			
void Canister::Show() { // отрисует канистру
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(0, 128, 0)); // Зададим перо и цвет пера - зеленый;
	DrawCanister(Pen);
	DeleteObject(Pen);			// Уничтожим нами созданные объекты
};

void Canister::Hide() { // спрячет канистру
	
};

int Canister::GetFuelCapacity() { // получить емкость канистры 
	return FuelCapacity;	}; 

void Canister::SetFuelCapacity(int NewFuelCapacity) {  // установить новую скорость
	FuelCapacity = NewFuelCapacity;		};

void Canister::MoveTo(int NewX, int NewY) {
	Hide();			// стирание канистры
	X = NewX;		// поменять координаты
	Y = NewY;
	Show();			// показать канистру на новом месте
};


void Canister::DrawCanister(HPEN Pen) {
	SelectObject(hdc, Pen);		// сделаем перо активным
	int height = 50; // высота канистры
	int lenght = 50; // длина канистры
	Rectangle(hdc, X - lenght, Y - height, X, Y); // канистра
	DeleteObject(Pen);			

}; 
			/*----------------------------------------*/
			/*        МЕТОДЫ КЛАССА Base              */
			/*----------------------------------------*/
Base::Base(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor) : Location(InitX, InitY) // конструктор
{
	BodyCarLenght = InitBodyCarLenght;
	Speed = InitSpeed;
	BaseColor = InitBaseColor;
}

BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);		// сделать текущими координаты x1, y1
	return LineTo(hdc, x2, y2);
} 

void Base::DrawBaseBody(HPEN Pen) {		// основание на котором сидят колеса

	SelectObject(hdc, Pen);				// сделаем перо активным
	int height = 50;
	Rectangle(hdc, X - BodyCarLenght, Y, X, Y - height); // корпус
	int a = BodyCarLenght / 4;
	int radius = 70;
	Arc(hdc, X - a * 3 + radius / 10 + radius / 2, Y + 20, X - 3 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // левое подколесо
	Arc(hdc, X - 1 * a + radius / 10 + radius / 2, Y + 20, X - 1 * a - radius / 10 - radius / 2, Y - 40, BodyCarLenght * 20, Y + 50, BodyCarLenght / 20, Y + 50); // правое подколесо
	int lenght = GetBaseLenght() / 3;
	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght, Y - 50, X - GetBaseLenght() / 3, Y - 120); // нарисуем кабину без окон

	Pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));
	SelectObject(hdc, Pen);				// сделаем перо активным
	Line(hdc, X - a * 3 + radius / 10 + radius / 2 - 5, Y - 2, X - 3 * a - radius / 10 - radius / 2 + 5, Y - 2); // за контуром колес
	Line(hdc, X - 1 * a + radius / 10 + radius / 2 - 5, Y - 2, X - 1 * a - radius / 10 - radius / 2 + 5, Y - 2); // за контуром колес	
	DeleteObject(Pen);					// Уничтожим нами созданные объекты

} 

void Base::DrawBaseWheels(HPEN Pen) {	// колеса 
	
	SelectObject(hdc, Pen);				//сделаем перо активным
	int radius = 70;					// радиус колес
	int a = BodyCarLenght / 4;
	Ellipse(hdc, X  - a + radius / 2, Y + 35 - radius, X  - a - radius / 2, Y - 35 + radius); // правое колесо
	Ellipse(hdc, X  - 3 * a + radius / 2, Y + 35 - radius, X - 3 * a - radius / 2, Y - 35 + radius); // левое колесо
	DeleteObject(Pen); 
} 

string Base::GetBaseColor()
{	return BaseColor;	}

void Base::Show() { // отобразить объект

	string CarColor = GetBaseColor(); // получаем цвет из класса Base
	HPEN Pen;
	if (CarColor == "red") 
	Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // Зададим перо и цвет пера - красный
	else if (CarColor == "black")
		Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); // Зададим перо и цвет пера - черный
	else Pen = CreatePen(PS_SOLID, 2, RGB(255, 165, 0)); // Зададим перо и цвет пера - оранжевый

	DrawBaseBody(Pen);
	DrawBaseWheels(Pen);
	DeleteObject(Pen); // Уничтожим нами созданные объекты  
}

void Base::Hide() { // спрятать корпус машины

	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); // Зададим перо и цвет пера - красный
	DrawBaseBody(Pen);
	DrawBaseWheels(Pen);
	DeleteObject(Pen); 
} 

void Base::MoveTo(int NewX, int NewY) // поставить в соответствие новые координаты
{
	Hide();			// стирание старого контура машины
	X = NewX;		// поменять координаты
	Y = NewY;
	Show();			// показать контур машины на новом месте
}

void Base::Drag() // переместить объект
{
	int FigX, FigY; // новые координаты фигуры

	FigX = GetX();    // получаем начальное положение фигуры
	FigY = GetY();

	while (1)	// цикл буксировки фигуры
	{
		if (KEY_DOWN(VK_ESCAPE))     // конец работы 27 escape
		{	
			std::cout << "FigX = " << GetX();
			break;
		}
		// направление движения объекта
		if (KEY_DOWN(VK_LEFT)) // стрелка влево  37
		{
			FigX -= GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}

		if (KEY_DOWN(VK_RIGHT)) // стрелка вправо  39
		{
			FigX += GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}

		if (KEY_DOWN(VK_DOWN)) // стрелка вниз  40
		{
			FigY += GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}

		if (KEY_DOWN(VK_UP)) // стрелка вверх  38
		{
			FigY -= GetMaxSpeed();
			MoveTo(FigX, FigY);
			Sleep(500);
		}
	}

};

		/*----------------------------------------*/
		/*        МЕТОДЫ КЛАССА Car               */
		/*----------------------------------------*/

Car::Car(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor, string ManufactureName) : Base(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // конструктор Car
{}

void Car::DrawCarCabin(HPEN Pen) { // кабина 
	
	cout << "x = " << X << " y = " << Y << endl;
	SelectObject(hdc, Pen);		// сделаем перо активным
	int height = 70;
	int lenght = GetBaseLenght() / 3;
	Rectangle(hdc, X - GetBaseLenght() / 3 - lenght * 0.2, Y - 60, X - GetBaseLenght() / 3 - lenght * 0.8, Y - 110); //окошечко
	DeleteObject(Pen);			// Уничтожим нами созданные объекты
} 

void Car::Show()				// показать круг
{
	string CarColor = GetBaseColor(); // получаем цвет из класса Base
	HPEN Pen;
	if (CarColor == "red")
		Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // Зададим перо и цвет пера - красный
	else if (CarColor == "black")
		Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); // Зададим перо и цвет пера - черный
	else Pen = CreatePen(PS_SOLID, 2, RGB(255, 165, 0)); // Зададим перо и цвет пера - оранжевый

	DrawBaseBody(Pen);			// корпус
	DrawBaseWheels(Pen);		// колеса
	DrawCarCabin(Pen);			// кабина
	DeleteObject(Pen);			// Уничтожим нами созданные объекты  
}

void Car::Hide()				// скрыть машину
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)); // зададим перо и цвет пера - белый
	DrawBaseBody(Pen);			// корпус
	DrawBaseWheels(Pen);		// колеса
	DrawCarCabin(Pen);			// кабина
	DeleteObject(Pen);			// Уничтожим нами созданные объекты  
}

		/*----------------------------------------*/
		/*        МЕТОДЫ КЛАССА CarWithHood       */
		/*----------------------------------------*/

CarWithHood::CarWithHood(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Car(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // конструктор CarExhaustPipe
{}

void CarWithHood::DrawCarHood(HPEN Pen) { // капот
	SelectObject(hdc, Pen);			// сделаем перо активным
	int heightBase = 50;
	int heightCabin = 70;
	int lenght = GetBaseLenght() / 3;
	int a = GetBaseLenght() / 2;
	int radius = 70;
	POINT poly[6];

	poly[0].x = X;					// первая координата полигона
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

	Polyline(hdc, poly, 6);			// капот
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
} 

void CarWithHood::Show() {
	string CarColor = GetBaseColor(); // получаем цвет из класса Base
	HPEN Pen;
	if (CarColor == "red")
		Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // Зададим перо и цвет пера - красный
	else if (CarColor == "black")
		Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); // Зададим перо и цвет пера - черный
	else Pen = CreatePen(PS_SOLID, 2, RGB(255, 165, 0)); // Зададим перо и цвет пера - оранжевый
	DrawBaseBody(Pen);				// корпус
	DrawBaseWheels(Pen);			// колеса
	DrawCarCabin(Pen);				// кабина
	DrawCarHood(Pen);				// капот
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
}

void CarWithHood::Hide() {
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// Зададим перо и цвет пера - белый
	DrawBaseBody(Pen);				// корпус
	DrawBaseWheels(Pen);			// колеса
	DrawCarCabin(Pen);				// кабина
	DrawCarHood(Pen);				// капот
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
}

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА CarExhaustPipe    */
/*----------------------------------------*/


CarExhaustPipe::CarExhaustPipe(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : CarWithHood(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // конструктор CarExhaustPipe
{}

void CarExhaustPipe::DrawExhaustPipe(HPEN Pen) {
	SelectObject(hdc, Pen);			// сделаем перо активным
	Rectangle(hdc, X - GetBaseLenght() - 30, Y - 30, X - GetBaseLenght(), Y - 10); // выхлопная труба
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
} 

void CarExhaustPipe::Show()			  // показать машину с выхлопной трубой
{
	string CarColor = GetBaseColor(); // получаем цвет из класса Base
	HPEN Pen;
	if (CarColor == "red")
		Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // Зададим перо и цвет пера - красный
	else if (CarColor == "black")
		Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); // Зададим перо и цвет пера - черный
	else Pen = CreatePen(PS_SOLID, 2, RGB(255, 165, 0)); // Зададим перо и цвет пера - оранжевый

	DrawBaseBody(Pen);				// корпус
	DrawBaseWheels(Pen);			// колеса
	DrawCarCabin(Pen);				// кабина
	DrawCarHood(Pen);				// капот
	DrawExhaustPipe(Pen);			// выхлопная труба
	DeleteObject(Pen);				// Уничтожим нами созданные объекты
} 

void CarExhaustPipe::Hide()			// спрятать 
{
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// Зададим перо и цвет пера - белый
	DrawBaseBody(Pen);				// корпус
	DrawBaseWheels(Pen);			// колеса
	DrawCarCabin(Pen);				// кабина
	DrawCarHood(Pen);				// капот
	DrawExhaustPipe(Pen);			// выхлопная труба
	DeleteObject(Pen);				// Уничтожим нами созданные объекты
}

/*----------------------------------------*/
/*        МЕТОДЫ КЛАССА CarWithLuggade    */
/*----------------------------------------*/

CarWithLuggade::CarWithLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Car(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // конструктор CarExhaustPipe
{

}

void CarWithLuggade::DrawCarLuggade(HPEN Pen) { // багажник


	SelectObject(hdc, Pen);			// сделаем перо активным
	int heightCabin = 70;
	int heightBase = 50;
	int lenght = GetBaseLenght() / 3;
	int a = GetBaseLenght() / 2;
	int radius = 70;
	POINT poly[4];

	poly[0].x = X - 2 * GetBaseLenght() / 3;					// первая координата полигона
	poly[0].y = Y - heightCabin / 2 - heightBase;

	poly[1].x = X - 2 * GetBaseLenght() / 3 - GetBaseLenght() / 3 + lenght / 5;
	poly[1].y = Y - heightCabin / 2 - heightBase;

	poly[2].x = X - 2 * GetBaseLenght() / 3 - GetBaseLenght() / 3;
	poly[2].y = Y - heightCabin / 2 - heightBase + lenght / 5;

	poly[3].x = X - GetBaseLenght();
	poly[3].y = Y - heightBase;

	Polyline(hdc, poly, 4);			// капот
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
} 

void CarWithLuggade::Show() {
	string CarColor = GetBaseColor(); // получаем цвет из класса Base
	HPEN Pen;
	if (CarColor == "red")
		Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // Зададим перо и цвет пера - красный
	else if (CarColor == "black")
		Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); // Зададим перо и цвет пера - черный
	else Pen = CreatePen(PS_SOLID, 2, RGB(255, 165, 0)); // Зададим перо и цвет пера - оранжевый

	DrawBaseBody(Pen);				// корпус
	DrawBaseWheels(Pen);			// колеса
	DrawCarCabin(Pen);				// кабина
	DrawCarLuggade(Pen);			// капот
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
}

void CarWithLuggade::Hide() {
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// Зададим перо и цвет пера - белый
	DrawBaseBody(Pen);				// корпус
	DrawBaseWheels(Pen);			// колеса
	DrawCarCabin(Pen);				// кабина
	DrawCarLuggade(Pen);			// капот
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
}

/*-----------------------------------------------*/
/*        МЕТОДЫ КЛАССА CarWithHoodAndLuggade    */
/*-----------------------------------------------*/

CarWithHoodAndLuggade::CarWithHoodAndLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor) : Car(InitX, InitY, InitBodyCarLenght, InitSpeed, InitBaseColor) // конструктор CarExhaustPipe
{

}

void CarWithHoodAndLuggade::DrawCarLuggade(HPEN Pen) { // багажник
	SelectObject(hdc, Pen);			// сделаем перо активным
	int heightCabin = 70;
	int heightBase = 50;
	int lenght = GetBaseLenght() / 3;
	int a = GetBaseLenght() / 2;
	int radius = 70;
	POINT poly[4];

	poly[0].x = X - 2 * GetBaseLenght() / 3;					// первая координата полигона
	poly[0].y = Y - heightCabin / 2 - heightBase;

	poly[1].x = X - 2 * GetBaseLenght() / 3 - GetBaseLenght() / 3 + lenght / 5;
	poly[1].y = Y - heightCabin / 2 - heightBase;

	poly[2].x = X - 2 * GetBaseLenght() / 3 - GetBaseLenght() / 3;
	poly[2].y = Y - heightCabin / 2 - heightBase + lenght / 5;

	poly[3].x = X - GetBaseLenght();
	poly[3].y = Y - heightBase;

	Polyline(hdc, poly, 4);			// капот
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
} 

void CarWithHoodAndLuggade::DrawCarHood(HPEN Pen) { // капот
	SelectObject(hdc, Pen);			// сделаем перо активным
	int heightBase = 50;
	int heightCabin = 70;
	int lenght = GetBaseLenght() / 3;
	int a = GetBaseLenght() / 2;
	int radius = 70;
	POINT poly[6];

	poly[0].x = X;					// первая координата полигона
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

	Polyline(hdc, poly, 6);			// капот
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
}

void CarWithHoodAndLuggade::Show() {
	string CarColor = GetBaseColor(); // получаем цвет из класса Base
	HPEN Pen;
	if (CarColor == "red")
		Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // Зададим перо и цвет пера - красный
	else if (CarColor == "black")
		Pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0)); // Зададим перо и цвет пера - черный
	else Pen = CreatePen(PS_SOLID, 2, RGB(255, 165, 0)); // Зададим перо и цвет пера - оранжевый
	DrawBaseBody(Pen);				// корпус
	DrawBaseWheels(Pen);			// колеса
	DrawCarCabin(Pen);				// кабина
	DrawCarLuggade(Pen);			// капот
	DrawCarHood(Pen);				// багажник
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
}

void CarWithHoodAndLuggade::Hide() {
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));	// Зададим перо и цвет пера - белый
	DrawBaseBody(Pen);				// корпус
	DrawBaseWheels(Pen);			// колеса
	DrawCarCabin(Pen);				// кабина
	DrawCarLuggade(Pen);			// капот
	DrawCarHood(Pen);				// багажник
	DeleteObject(Pen);				// Уничтожим нами созданные объекты  
}