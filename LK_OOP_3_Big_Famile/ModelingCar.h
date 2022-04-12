#pragma once
#include <string>

/*************************************************************************\
* Comment(s)    : ���������� ���� �������. ������������                   *
*                 ����������� �������						              *
*                 ������ ����������						                  *
*                 ������� ����������						              *
\*************************************************************************/

/*-----------------------------------------------------------------------*/
/*                         � � � �    � � � � � �                        */
/*-----------------------------------------------------------------------*/

/*-----------------------     ����� Location    -------------------------*/
class Location
{
protected:							   // ������������� ����������� �������� (������������ 
									   // ������) ����� ������ � ������� ������
	int X;							   // ���������� X
	int Y;							   // ���������� Y

public:   // ��� ������ �������� ����� ���� � ���������
	Location(int InitX, int InitY); // �����������
	int GetX();						// �������� X ���������� �����
	int GetY();						// �������� Y ���������� �����
	void SetX(int NewX);			// ���������� ����� �������� �
	void SetY(int NewY);			// ���������� ����� �������� Y
};//end class Location

  /*-----------------------  ����� Base ----------------------------------*/

class Canister : public Location {

private:

	int FuelCapacity;					// ����� �������

public:
	// ����������� ������
	Canister(int InitX, int InitY, int FuelCapacity);
	void DrawCanister(HPEN Pen);		// �������� �������� ������ ������ �� ������� ������� ������
	void Show();				// �������� ������� ����������
	void Hide();				// ������� ������� ����������
	int GetFuelCapacity();				// �������� ������� ��������
	void SetFuelCapacity(int NewFuelCapacity);	// ���������� ����� ��������
	void MoveTo(int NewX, int NewY);	// ����������� ������ �� ����� �����������
	
}; // end class Canister


// ����������� �� Location ����� Base � ��������� public � �� �����������

class Base : public Location {
private:

	int BodyCarLenght;					// ����� �������
	int Speed;
	std::string BaseColor;				// ���� �������

public:
	// ����������� ������
	Base(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red");
	void DrawBaseBody(HPEN Pen);		// �������� �������� ������ ������ �� ������� ������� ������
	void DrawBaseWheels(HPEN Pen);		// �������� �������� ������
	virtual void Show();				// �������� ������� ����������
	virtual void Hide();				// ������� ������� ����������
	int GetMaxSpeed() { return Speed; };				// �������� ������� ��������
	void SetSpeed(int NewSpeed) { Speed = NewSpeed; };	// ���������� ����� ��������
	int GetBaseLenght() { return BodyCarLenght; };		// �������� ����� �������
	void SetBaseLenght(int NewBaseLenght) { BodyCarLenght = NewBaseLenght; };
	void Drag();						// ������������ ������ �� ��������
	void MoveTo(int NewX, int NewY);	// ����������� ������ �� ����� �����������
	std::string GetBaseColor();	// �������� ���� ������
	std::string SetBaseColor(std::string NewBaseColor) { BaseColor = NewBaseColor; }	// �������� ���� ������

}; // end class Base

/*-----------------------  ����� Car  -------------------------------*/
// ����������� �� Base ����� Car � ��������� public � �� �����������
// ����������� �� Location

class Car : public Base
{
private:								// ������������� , �.�. �� ���������
	
public:
	//����������� � ����������� �� ���������
	Car(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); 
	virtual void Show();				// �������� ������ ������
	virtual void Hide();				// ������ ������ ������
	void DrawCarCabin(HPEN Pen);		// ���������� ������ � ����� ��������� �����
	
};// end class Car

class CarWithHood : public Car {		// ������ � �������

public:
	// ����������� � ����������� �� ���������
	CarWithHood(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // �� ��������� ��������� ������������
	virtual void Show();				// �������� ������ ������ � �������
	virtual void Hide();				// ������ ������ ������ � �������
	void DrawCarHood(HPEN Pen);			// ���������� ����� ��������� �����
};

class CarWithLuggade : public Car { // ������ � ����������

public: 
	CarWithLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red");
	virtual void Show();				// �������� ������ ������ � �������
	virtual void Hide();				// ������ ������ ������ � �������
	void DrawCarLuggade(HPEN Pen);		// ���������� �������� ��������� �����

};

class CarWithHoodAndLuggade : public Car {		// ������ � �������

public:
	// ����������� � ����������� �� ���������
	CarWithHoodAndLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // �� ��������� ��������� ������������
	virtual void Show();				// �������� ������ ������ � �������
	virtual void Hide();				// ������ ������ ������ � �������
	void DrawCarHood(HPEN Pen);			// ���������� ����� ��������� �����
	void DrawCarLuggade(HPEN Pen);		// ���������� �������� ��������� �����
};
