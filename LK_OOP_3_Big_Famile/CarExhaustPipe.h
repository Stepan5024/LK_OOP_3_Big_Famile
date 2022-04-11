#pragma once
#include "ModelingCar.h"

class CarExhaustPipe :
    public CarWithHood
{
public:
	CarExhaustPipe(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // по умолчанию параметры конструктора

	virtual void Show();				// показать фигуру  
	virtual void Hide();				// скрыть фигуру 
    void DrawExhaustPipe(HPEN Pen);		// выхлопная труба

};// end class CarExhaustPipe

