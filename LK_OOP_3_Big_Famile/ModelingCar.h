#pragma once
#include <string>

using namespace std;
/*************************************************************************\
* Comment(s)    : ���������� ���� �������. ������������                   *
*                 ����������� �������						              *
*                 ������ ����������						                  *
*                 ������� ����������						              *
\*************************************************************************/

/*-----------------------     ����� Location    -------------------------*/
class Location
{
protected:							   
	int X;
	int Y;
public:
	Location(int InitX, int InitY); 
	int GetX();						// �������� X ���������� �����
	int GetY();						// �������� Y ���������� �����
	void SetX(int NewX);			// ���������� ����� �������� �
	void SetY(int NewY);			// ���������� ����� �������� Y
};
  /*-----------------------  ����� Base ----------------------------------*/
class Canister : public Location {
private:
	int FuelCapacity; // ������� ��������
public:
	Canister(int InitX, int InitY, int FuelCapacity);
	void DrawCanister(HPEN Pen); // ���������� ��������
	void Show();				
	void Hide();				
	int GetFuelCapacity();				// �������� �������
	void SetFuelCapacity(int NewFuelCapacity);	// ���������� �������
	void MoveTo(int NewX, int NewY);	// ����������� ������ �� ����� �����������
}; 


class Base : public Location {
private:

	int BodyCarLenght;					// ����� �������
	int Speed;							// ��������
	string BaseColor;				// ���� �������

public:

	Base(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor = "red");
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
	string GetBaseColor();	// �������� ���� ������
	string SetBaseColor(string NewBaseColor) { BaseColor = NewBaseColor; }	// �������� ���� ������

};

/*-----------------------  ����� Car  -------------------------------*/
class Car : public Base {
private:								
	string ManufacturerName;			// �������� �����������������
public:
	Car(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor = "red", string ManufactureName = "VAZ");
	virtual void Show();				// �������� ������ ������
	virtual void Hide();				// ������ ������ ������
	void DrawCarCabin(HPEN Pen);		// ���������� ������ � ����� ��������� �����
};

class CarWithHood : public Car {		// ������ � �������
private:
	int Price;			// ���� ������, ���� �� ������ ��� � ���
public:
	CarWithHood(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // �� ��������� ��������� ������������
	virtual void Show();				// �������� ������ ������ � �������
	virtual void Hide();				// ������ ������ ������ � �������
	void DrawCarHood(HPEN Pen);			// ���������� ����� ��������� �����
};

class CarWithLuggade : public Car { // ������ � ����������
private:
	int Price;			// ���� ������, ���� �� ������ ��� � ���
public: 
	CarWithLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red");
	virtual void Show();				// �������� ������ ������ � �������
	virtual void Hide();				// ������ ������ ������ � �������
	void DrawCarLuggade(HPEN Pen);		// ���������� �������� ��������� �����
};

class CarWithHoodAndLuggade : public Car {		// ������ � �������
private:
	int Price;			// ���� ������, ���� �� ������ ��� � ���
public:
	CarWithHoodAndLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // �� ��������� ��������� ������������
	virtual void Show();				// �������� ������ ������ � �������
	virtual void Hide();				// ������ ������ ������ � �������
	void DrawCarHood(HPEN Pen);			// ���������� ����� ��������� �����
	void DrawCarLuggade(HPEN Pen);		// ���������� �������� ��������� �����
};
