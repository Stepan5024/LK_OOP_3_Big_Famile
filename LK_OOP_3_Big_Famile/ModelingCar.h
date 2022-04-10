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
protected:		//предоставляет возможность потомкам (производному 
				//классу) иметь доступ к частным данным
	int X;		//координата X
	int Y;		//координата Y

public:   // эти методы доступны извне всем в программе
	Location(int InitX, int InitY); //конструктор
	int GetX();						//получить X координату точки
	int GetY();						//получить Y координату точки
	/*virtual void Show() = 0;						// показать фигуру 
	virtual void Hide() = 0;						// скрыть фигуру 
	virtual void MoveTo(int NewX, int NewY) = 0;	// переместить фигуру
	virtual void Drag() = 0;						// буксировка фигуры*/
};//end class Location

  /*-----------------------  Класс Base ----------------------------------*/


// производный от Location класс Base с атрибутом public и по определению


class Base : public Location {
private:
	
	int BackCarLenght; // длина корпуса
	int CabinLenght; // длина кабины
	int HoodLenght; // длина капота
	std::string BaseColor; // цвет корпуса

public:
	// конструктор класса
	Base(int InitX, int InitY, int InitBackCarLenght = 80, int InitCabinLenght = 50, int InitHoodLenght = 80, std::string InitBaseColor = "red");
	virtual void DrawBackBase();
	virtual void DrawBaseWheels();
	virtual void HideBackBase();
	virtual void hideBaseWheels();
	virtual void Show();
	virtual void Hide();
	virtual int GetMaxSpeed() = 0;
	void Drag(); // передвижение фигуры по стрелкам
	void MoveTo(int NewX, int NewY);  //берем из Point !!!!!!!
}; // end class Base

/*-----------------------  Класс Car  -------------------------------*/
// производный от Base класс Car с атрибутом public и по определению
// производный от Location

class Car : public Base
{
private:		//необязательно , т.к. по умолчанию
	int MaxSpeed; // максимальная скорость
public:
	//конструктор с параметрами по умолчанию
	Car(int InitX, int InitY, int InitBackCarLenght = 80, int InitCabinLenght = 50, int InitHoodLenght = 80, std::string InitBaseColor = "red", int InitMaxSpeed = 50); // по умолчанию параметры конструктора
	int GetMaxSpeed() { return MaxSpeed; }; // получить текущую скорость
	void SetSpeed(int NewSpeed) { MaxSpeed = NewSpeed; }; // установить новый радиус
	virtual void Show();				// показать фигуру  
	virtual void Hide();				// скрыть фигуру 
	
	
};//end class Car

//************************ новый класс **********************************/
/*-----------------------  Класс Car  -------------------------------*/
//производный от Point класс Circle с атрибутом public и по определению
// производный от Location
