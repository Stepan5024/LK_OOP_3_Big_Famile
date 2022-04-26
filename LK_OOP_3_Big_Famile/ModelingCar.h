#pragma once
#include <string>

using namespace std;
/*************************************************************************\
* Comment(s)    : ОБЪЯВЛЕНИЕ ТРЕХ КЛАССОВ. НАСЛЕДОВАНИЕ                   *
*                 СТАТИЧЕСКИЕ ПРАВИЛА						              *
*                 РАННЕЕ СВЯЗЫВАНИЕ						                  *
*                 ПОЗДНЕЕ СВЯЗЫВАНИЕ						              *
\*************************************************************************/

/*-----------------------     Класс Location    -------------------------*/
class Location
{
protected:							   
	int X;
	int Y;
public:
	Location(int InitX, int InitY); 
	int GetX();						// получить X координату точки
	int GetY();						// получить Y координату точки
	void SetX(int NewX);			// установить новое значение Х
	void SetY(int NewY);			// установить новое значение Y
};
  /*-----------------------  Класс Base ----------------------------------*/
class Canister : public Location {
private:
	int FuelCapacity; // емкость канистры
public:
	Canister(int InitX, int InitY, int FuelCapacity);
	void DrawCanister(HPEN Pen); // отрисовкка канистры
	void Show();				
	void Hide();				
	int GetFuelCapacity();				// получить емкость
	void SetFuelCapacity(int NewFuelCapacity);	// установить емкость
	void MoveTo(int NewX, int NewY);	// переместить объект по новым координатам
}; 


class Base : public Location {
private:

	int BodyCarLenght;					// длина корпуса
	int Speed;							// скорость
	string BaseColor;				// цвет корпуса

public:

	Base(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor = "red");
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
	string GetBaseColor();	// получить цвет машины
	string SetBaseColor(string NewBaseColor) { BaseColor = NewBaseColor; }	// получить цвет машины

};

/*-----------------------  Класс Car  -------------------------------*/
class Car : public Base {
private:								
	string ManufacturerName;			// название автопроизводителя
public:
	Car(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor = "red", string ManufactureName = "VAZ");
	virtual void Show();				// показать фигуру машины
	virtual void Hide();				// скрыть фигуру машины
	void DrawCarCabin(HPEN Pen);		// нарисовать кабину с окном заданного цвета
};

class CarWithHood : public Car {		// машина с капотом
private:
	int Price;			// цена машины, пока не описал сет и гет
public:
	CarWithHood(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // по умолчанию параметры конструктора
	virtual void Show();				// показать фигуру машины с капотом
	virtual void Hide();				// скрыть фигуру машины с капотом
	void DrawCarHood(HPEN Pen);			// нарисовать капот заданного цвета
};

class CarWithLuggade : public Car { // машина с багажником
private:
	int Price;			// цена машины, пока не описал сет и гет
public: 
	CarWithLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red");
	virtual void Show();				// показать фигуру машины с капотом
	virtual void Hide();				// скрыть фигуру машины с капотом
	void DrawCarLuggade(HPEN Pen);		// нарисовать багажник заданного цвета
};

class CarWithHoodAndLuggade : public Car {		// машина с капотом
private:
	int Price;			// цена машины, пока не описал сет и гет
public:
	CarWithHoodAndLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // по умолчанию параметры конструктора
	virtual void Show();				// показать фигуру машины с капотом
	virtual void Hide();				// скрыть фигуру машины с капотом
	void DrawCarHood(HPEN Pen);			// нарисовать капот заданного цвета
	void DrawCarLuggade(HPEN Pen);		// нарисовать багажник заданного цвета
};
