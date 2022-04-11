#pragma once
#include "ModelingCar.h"

class CarExhaustPipe :
    public CarWithHood
{
public:
	CarExhaustPipe(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // �� ��������� ��������� ������������

	virtual void Show();				// �������� ������  
	virtual void Hide();				// ������ ������ 
    void DrawExhaustPipe(HPEN Pen);		// ��������� �����

};// end class CarExhaustPipe

