#pragma once
#include "ModelingCar.h"

class CarExhaustPipe : public CarWithHood {
private:
	int id = 4;							// id ������
	int EmissionsLevel;			// ������� ��������
public:
	CarExhaustPipe(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // �� ��������� ��������� ������������

	virtual void Show();				// �������� ������  
	virtual void Hide();				// ������ ������ 
    void DrawExhaustPipe(HPEN Pen);		// ��������� ����� ��������� �����
	virtual int GetTypeId() {
		return id;
	}
};

