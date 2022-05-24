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
class Point : public Location
{
protected:
	COLORREF color; //����

public:
	Point(int InitX, int InitY);	//����������� ������
	~Point();						//����������
	COLORREF get_color(COLORREF color);  //�������� ����
	void set_color(COLORREF new_color);  //���������� ����� ����
};
/************** ��������� ������� *******************/
class IDraw : public Point
{
public:
	IDraw(int InitX, int InitY);
	~IDraw();
	virtual void DrawBaseBody(HPEN Pen) = 0;		// �������� �������� ������ ������ �� ������� ������� ������
	virtual void DrawBaseWheels(HPEN Pen) = 0;		// �������� �������� ������
	virtual void Show() = 0;              //�������� ������ 
	virtual void Hide() = 0;              //�������� ������
	virtual void MoveTo(int NewX, int NewY) = 0;//����������� �����
};

class Barriers : public Location {
private:
	int Width = 50;			// ������
	int Length = 50;			// �����
	int id = 0;							// id ������
public:
	Barriers(int InitX, int InitY);
	virtual void Show() = 0;
	virtual void Hide() = 0;
	void MoveTo(int NewX, int NewY);			// ����������� ������ �� ����� �����������
	virtual int GetLength() {
		return Length;
	};
	virtual int GetTypeId() {
		return id;
	}
};

  /*-----------------------  ����� Canister ----------------------------------*/
class Canister : public Barriers {
private:
	int Width;			// ������
	int Length;			// �����
	int FuelCapacity; // ������� ��������
	int id = 1;							// id ������
public:
	Canister(int InitX, int InitY, int InitFuelCapacity, int InitWidth, int InitLength);
	void DrawCanister(HPEN Pen); // ���������� ��������
	virtual void Show();
	virtual void Hide();
	int GetFuelCapacity();						// �������� �������
	void SetFuelCapacity(int NewFuelCapacity);	// ���������� �������
	void MoveTo(int NewX, int NewY);			// ����������� ������ �� ����� �����������
	int GetCanisterWidth();						// �������� ������
	void SetCanisterWidth(int NewWidth);			// ���������� ������
	int GetCanisterLength();						// �������� �����
	void SetCanisterLength(int NewLength);			// ���������� �����
	virtual int GetTypeId() {
		return id;
	}
}; 
/*-----------------------  ����� Brick ----------------------------------*/
class Brick : public Barriers {
private:
	int Width;			// ������
	int Length;			// �����
	int id = 0;							// id ������
public:
	Brick(int InitX, int InitY, int InitWidth, int InitLength);
	void DrawBrick(HBRUSH Pen); // ���������� ��������
	virtual void Show();
	virtual void Hide();
	int GetBrickWidth();						// �������� ������
	void SetBrickWidth(int NewWidth);			// ���������� ������
	int GetBrickLength();						// �������� �����
	void SetBrickLength(int NewLength);			// ���������� �����
	void MoveTo(int NewX, int NewY);			// ����������� ������ �� ����� �����������
	bool Touch(int AnotherXCarCoord, int AnotherYCarCoord, int CarLenght, int CarHeight, int AnotherXBrickCoord, int AnotherYBrickCoord);		// ��������� ��������� ��������� ������� � �������
	virtual int GetTypeId() {
		return id;
	}
};

/*-----------------------  ����� Base ----------------------------------*/
class ABase : public IDraw { // ����������� �����
private:

	int BodyCarLenght;				// ����� �������
	int Speed;						// ��������
	string BaseColor;				// ���� �������
	int id = -1;
public:

	ABase(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor = "red");
	virtual void DrawBaseBody(HPEN Pen);		// �������� �������� ������ ������ �� ������� ������� ������
	virtual void DrawBaseWheels(HPEN Pen);		// �������� �������� ������
	void Show();				// �������� ������� ����������
	void Hide();				// ������� ������� ����������
	int GetMaxSpeed() { return Speed; };				// �������� ������� ��������
	void SetSpeed(int NewSpeed) { Speed = NewSpeed; };	// ���������� ����� ��������
	int GetBaseLenght() { return BodyCarLenght; };		// �������� ����� �������
	void SetBaseLenght(int NewBaseLenght) { BodyCarLenght = NewBaseLenght; };
	void Drag();						// ������������ ������ �� ��������
	void MoveTo(int NewX, int NewY);	// ����������� ������ �� ����� �����������
	string GetBaseColor();	// �������� ���� ������
	string SetBaseColor(string NewBaseColor) { BaseColor = NewBaseColor; }	// �������� ���� ������
	virtual int GetTypeId();
	virtual bool Touch(int AnotherXCarCoord, int AnotherYCarCoord, int CarLenght, int CarHeight, int AnotherXBrickCoord, int AnotherYBrickCoord, int BrickLength) = 0;

};

/*-----------------------  ����� Car  -------------------------------*/
class Car : public ABase {
private:	
	int id = 0;							// id ������
	string ManufacturerName;			// �������� �����������������

public:
	Car(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, string InitBaseColor = "red", string ManufactureName = "VAZ");
	virtual void Show();				// �������� ������ ������
	virtual void Hide();				// ������ ������ ������
	void DrawCarCabin(HPEN Pen);		// ���������� ������ � ����� ��������� �����
	bool Touch(int AnotherXCarCoord, int AnotherYCarCoord, int CarLenght, int CarHeight, int AnotherXBrickCoord, int AnotherYBrickCoord, int BrickLength);		// ��������� ��������� ��������� ������� � �������
	virtual int GetTypeId() {
		return id;
	}
};

class CarWithHood : public Car {		// ������ � �������
private:
	int id = 1;							// id ������
	int Price;			// ���� ������, ���� �� ������ ��� � ���
public:
	CarWithHood(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // �� ��������� ��������� ������������
	virtual void Show();				// �������� ������ ������ � �������
	virtual void Hide();				// ������ ������ ������ � �������
	void DrawCarHood(HPEN Pen);			// ���������� ����� ��������� �����
	virtual int GetTypeId() {
		return id;
	}
};

class CarWithLuggade : public Car { // ������ � ����������
private:
	int id = 2;							// id ������
	int Price;			// ���� ������, ���� �� ������ ��� � ���
public: 
	CarWithLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red");
	virtual void Show();				// �������� ������ ������ � �������
	virtual void Hide();				// ������ ������ ������ � �������
	void DrawCarLuggade(HPEN Pen);		// ���������� �������� ��������� �����
	virtual int GetTypeId() {
		return id;
	}
};

class CarWithHoodAndLuggade : public Car {		// ������ � �������
private:
	int id = 3;							// id ������
	int Price;			// ���� ������, ���� �� ������ ��� � ���
public:
	CarWithHoodAndLuggade(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // �� ��������� ��������� ������������
	virtual void Show();				// �������� ������ ������ � �������
	virtual void Hide();				// ������ ������ ������ � �������
	void DrawCarHood(HPEN Pen);			// ���������� ����� ��������� �����
	void DrawCarLuggade(HPEN Pen);		// ���������� �������� ��������� �����
	virtual int GetTypeId() {
		return id;
	}
};
