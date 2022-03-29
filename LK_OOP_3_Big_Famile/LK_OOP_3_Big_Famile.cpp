﻿/*******************************************************************\
 * Comment(s)    : НАСЛЕДОВАНИЕ										*
 *                 РИСОВАНИЕ ОКРУЖНОСТИ								*
 *                 ПЕРЕМЕЩЕНИЕ  ТОЧКИ/ОКРУЖНОСТИ, ОКРУЖНОСТИ        *
 *                 ИЗМЕНЕНИЕ РАДИУСА								*
 *                 РАБОТА В КОНСОЛЬНОМ ОКНЕ                         *
 *                                                                  *
 \******************************************************************/

#pragma once                  
#include <windows.h>
#include <conio.h>
#include <iostream>    
using namespace std;        // Пространство имен std

#include "Point05_03.h" 	//объявление классов
#include "GetConWin.h"		//указатель на консольное окно

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

using namespace std;        // Пространство имен std

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   Г Л О Б А Л Ь Н Ы Е   П Е Р Е М Е Н Н Ы Е  И  К О Н С Т А Н Т Ы   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

//глобальная переменная видна в двух файлах: Point05_03.cpp и Ex05_03_Con.cpp
//первичное объявление глобальной переменной
//глобальная переменная действует от места объявления до конца файла
//, в котором объявлена

HDC hdc;	// Объявим контекст устройства
			// Контекст устройства по сути это структура,
			// содержащая описание видеокарты на вашем компьютере
			// и всех необходимых графических элементов

/*---------------------------------------------------------------------*/
/*               П Р О Т О Т И П Ы    Ф У Н К Ц И Й                    */
/*---------------------------------------------------------------------*/
//HWND GetConcolWindow(); //указатель на консольное окно теперь в  "GetConlWin.h"

/***********************************************************************/
/*               О С Н О В Н А Я    П Р О Г Р А М М А                  */
/***********************************************************************/
int main()
{
	system("color F0");
	setlocale(LC_ALL, "Russian");

	//объявление и инициализация переменных
	int x0 = 400, y0 = 300;  //стартовые координаты центра
	int x1 = 700, y1 = 800;  //стартовые координаты центра
	int Speed0 = 50;     //начальное значение скорости
	int DeltaSpeed = 30;     //начальное изменение скорости

						 //получим дескриптор консольного окна
	HWND hwnd = GetConcolWindow();

	//если дескриптор существует
	if (hwnd != NULL)
	{
		//получим контекст устройства для консольного окна
		hdc = GetWindowDC(hwnd);

		//если контекст существует - можем работать
		if (hdc != 0)
		{
			//===================================================================

		
			/************  Т О Ч К А  ***********/
			Point APoint(x0, y0);	//инициализация точки
			APoint.Show();			//показать точку

			//APoint.MoveTo(2*x0, y0);  //показать ТОЧКУ на новом месте
			while (1)
				if (KEY_DOWN(49))   //цифра 1 
					break;

			/************  К Р У Г   ***********/
			Car  ACar(600, 400, Speed0);  //инициализация окружности
			Car  BCar(720, 200, Speed0);  //инициализация окружности
			BCar.Show();
			ACar.Show();			//показать окружность
			while (1)
				if (KEY_DOWN(50))	//цифра 2        
					break;

			//переместили ТОЧКУ/ОКРУЖНОСТЬ наверх
			ACar.MoveTo(x0, y0 - 2 * Speed0);
			while (1)
				if (KEY_DOWN(51))	//цифра 3
					break;

			ACar.Show();			//показать окружность
			while (1)
				if (KEY_DOWN(52))	//цифра 4        
					break;

			//увеличить радиус окружности на DeltaRad
			ACar.Expand(DeltaSpeed);
			while (1)
				if (KEY_DOWN(53))	//цифра 5        
					break;

			//уменьшить радиус окружности на DeltaRad1
			ACar.Reduce(DeltaSpeed);
			while (1)
				if (KEY_DOWN(54))	//цифра 6
					break;

			//===================================================================



		}// end if
	}// end if
}//end main()
/**********************  End Of Ex05_03_Con.CPP File ********************/