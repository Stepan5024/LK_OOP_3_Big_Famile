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
	
	int BackCarLenght; // ����� �������
	int CabinLenght; // ����� ������
	int HoodLenght; // ����� ������
	std::string BaseColor; // ���� �������

public:
	// ����������� ������
	Base(int InitX, int InitY, int InitBackCarLenght = 80, int InitCabinLenght = 50, int InitHoodLenght = 80, std::string InitBaseColor = "red");
	virtual void DrawBackBase();
	virtual void DrawBaseWheels();
	virtual void HideBackBase();
	virtual void hideBaseWheels();
	virtual void Show();
	virtual void Hide();
	virtual int GetMaxSpeed() = 0;
	void Drag(); // ������������ ������ �� ��������
	void MoveTo(int NewX, int NewY);  //����� �� Point !!!!!!!
}; // end class Base

/*-----------------------  ����� Car  -------------------------------*/
// ����������� �� Base ����� Car � ��������� public � �� �����������
// ����������� �� Location

class Car : public Base
{
private:		//������������� , �.�. �� ���������
	int MaxSpeed; // ������������ ��������
public:
	//����������� � ����������� �� ���������
	Car(int InitX, int InitY, int InitBackCarLenght = 80, int InitCabinLenght = 50, int InitHoodLenght = 80, std::string InitBaseColor = "red", int InitMaxSpeed = 50); // �� ��������� ��������� ������������
	int GetMaxSpeed() { return MaxSpeed; }; // �������� ������� ��������
	void SetSpeed(int NewSpeed) { MaxSpeed = NewSpeed; }; // ���������� ����� ������
	virtual void Show();				// �������� ������  
	virtual void Hide();				// ������ ������ 
	
	
};//end class Car

//************************ ����� ����� **********************************/
/*-----------------------  ����� Car  -------------------------------*/
//����������� �� Point ����� Circle � ��������� public � �� �����������
// ����������� �� Location
