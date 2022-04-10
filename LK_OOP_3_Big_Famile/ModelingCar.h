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
protected:		//������������� ����������� �������� (������������ 
				//������) ����� ������ � ������� ������
	int X;		//���������� X
	int Y;		//���������� Y

public:   // ��� ������ �������� ����� ���� � ���������
	Location(int InitX, int InitY); //�����������
	int GetX();						//�������� X ���������� �����
	int GetY();						//�������� Y ���������� �����
	/*virtual void Show() = 0;						// �������� ������ 
	virtual void Hide() = 0;						// ������ ������ 
	virtual void MoveTo(int NewX, int NewY) = 0;	// ����������� ������
	virtual void Drag() = 0;						// ���������� ������*/
};//end class Location

  /*-----------------------  ����� Base ----------------------------------*/


// ����������� �� Location ����� Base � ��������� public � �� �����������


class Base : public Location {
private:
	
	int BodyCarLenght; // ����� �������
	int Speed;
	std::string BaseColor; // ���� �������

public:
	// ����������� ������
	Base(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red");
	void DrawBaseBody(); // �������� ������ �� ������� ������� ������
	void DrawBaseWheels(); // �������� ������

	void HideBaseBody();
	void HideBaseWheels();
	virtual void Show();
	virtual void Hide();
	int GetMaxSpeed() { return Speed; }; // �������� ������� ��������
	void SetSpeed(int NewSpeed) { Speed = NewSpeed; }; // ���������� ����� ������
	int GetBaseLenght() { return BodyCarLenght; }; // �������� ����� �������
	void Drag(); // ������������ ������ �� ��������
	void MoveTo(int NewX, int NewY);  //����� �� Point !!!!!!!
}; // end class Base

/*-----------------------  ����� Car  -------------------------------*/
// ����������� �� Base ����� Car � ��������� public � �� �����������
// ����������� �� Location

class Car : public Base
{
private:		//������������� , �.�. �� ���������
	//int MaxSpeed; // ������������ ��������
public:
	//����������� � ����������� �� ���������
	Car(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // �� ��������� ��������� ������������
	
	virtual void Show();				// �������� ������  
	virtual void Hide();				// ������ ������ 
	void DrawCarCabin(); // ���������� ������ � �����
	void HideCarCabin(); // ���������� ������ � �����
	
};//end class Car

class CarWithHood : public Car { // ������ � �������

public:
	// ����������� � ����������� �� ���������
	CarWithHood(int InitX, int InitY, int InitBodyCarLenght, int InitSpeed, std::string InitBaseColor = "red"); // �� ��������� ��������� ������������

	virtual void Show();				// �������� ������  
	virtual void Hide();				// ������ ������ 
	void DrawCarHood(); // ���������� �����
	void HideCarHood(); // ���������� �����

};
