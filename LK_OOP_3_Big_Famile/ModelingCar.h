#pragma once
#include <string>

/*************************************************************************\
* Comment(s)    : ОБЪЯВЛЕНИЕ ТРЕХ КЛАССОВ. НАСЛЕДОВАНИЕ                   *
*                 СТАТИЧЕСКИЕ ПРАВИЛА						              *
*                 РАННЕЕ СВЯЗЫВАНИЕ						                  *
*                 ПОЗДНЕЕ СВЯЗЫВАНИЕ						              *
\*************************************************************************/

/*-----------------------------------------------------------------------*/
/*                         Т И П Ы    Д А Н Н Ы Х                        */
/*-----------------------------------------------------------------------*/

/*-----------------------     Класс Location    -------------------------*/
class Location
{
protected:							   // предоставляет возможность потомкам (производному 
									   // классу) иметь доступ к частным данным
	int X;							   // координата X
	int Y;							   // координата Y

public:   // эти методы доступны извне всем в программе
	Location(int InitX, int InitY); // конструктор
	int GetX();						// получить X координату точки
	int GetY();						// получить Y координату точки
	void SetX(int NewX);			// установить новое значение Х
	void SetY(int NewY);			// установить новое значение Y
};//end class Location

  /*-----------------------  Класс Base ----------------------------------*/

class Canister : public Location {

private:

	int FuelCapacity;					// длина корпуса

public:
	// конструктор класса
	Canister(int InitX, int InitY, int FuelCapacity);
	void DrawCanister(HPEN Pen);		// отрисует заданным цветом основу на которую садятся колеса
	void Show();				// отрисует базовый автомобиль
	void Hide();				// спрячет базовый автомобиль
	int GetFuelCapacity();				// получить текущую скорость
	void SetFuelCapacity(int NewFuelCapacity);	// установить новую скорость
	void MoveTo(int NewX, int NewY);	// переместить объект по новым координатам
	
}; // end class Canister


// производный от Location класс Base с атрибутом public и по определению

class Base : public Location {
private:

	int BodyCarLenght;					// длина корпуса
	int Speed;
	std::string BaseColor;				// цвет корпуса

public:
	// конструктор класса
	Base(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red");
	void DrawBaseBody(HPEN Pen);		// отрисует заданным цветом основу на которую садятся колеса
	void DrawBaseWheels(HPEN Pen);		// отрисует заданным колеса
	virtual void Show();				// отрисует базовый автомобиль
	virtual void Hide();				// спрячет базовый автомобиль
	int GetMaxSpeed() { return Speed; };				// получить текущую скорость
	void SetSpeed(int NewSpeed) { Speed = NewSpeed; };	// установить новую скорость
	int GetBaseLenght() { return BodyCarLenght; };		// получить длину корпуса
	void SetBaseLenght(int NewBaseLenght) { BodyCarLenght = NewBaseLenght; };
	void Drag();						// передвижение фигуры по стрелкам
	void MoveTo(int NewX, int NewY);	// переместить объект по новым координатам
	std::string GetBaseColor();	// получить цвет машины
	std::string SetBaseColor(std::string NewBaseColor) { BaseColor = NewBaseColor; }	// получить цвет машины

}; // end class Base

/*-----------------------  Класс Car  -------------------------------*/
// производный от Base класс Car с атрибутом public и по определению
// производный от Location

class Car : public Base
{
private:								// необязательно , т.к. по умолчанию
	
public:
	//конструктор с параметрами по умолчанию
	Car(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); 
	virtual void Show();				// показать фигуру машины
	virtual void Hide();				// скрыть фигуру машины
	void DrawCarCabin(HPEN Pen);		// нарисовать кабину с окном заданного цвета
	
};// end class Car

class CarWithHood : public Car {		// машина с капотом

public:
	// конструктор с параметрами по умолчанию
	CarWithHood(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // по умолчанию параметры конструктора
	virtual void Show();				// показать фигуру машины с капотом
	virtual void Hide();				// скрыть фигуру машины с капотом
	void DrawCarHood(HPEN Pen);			// нарисовать капот заданного цвета
};

class CarWithLuggade : public Car { // машина с багажником

public: 
	CarWithLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red");
	virtual void Show();				// показать фигуру машины с капотом
	virtual void Hide();				// скрыть фигуру машины с капотом
	void DrawCarLuggade(HPEN Pen);		// нарисовать багажник заданного цвета

};

class CarWithHoodAndLuggade : public Car {		// машина с капотом

public:
	// конструктор с параметрами по умолчанию
	CarWithHoodAndLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // по умолчанию параметры конструктора
	virtual void Show();				// показать фигуру машины с капотом
	virtual void Hide();				// скрыть фигуру машины с капотом
	void DrawCarHood(HPEN Pen);			// нарисовать капот заданного цвета
	void DrawCarLuggade(HPEN Pen);		// нарисовать багажник заданного цвета
};
