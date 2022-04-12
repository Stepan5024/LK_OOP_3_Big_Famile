﻿/*******************************************************************\
 * Comment(s)    : ПРОСТЕЙШАЯ ИЕРАРХИЯ КЛАССОВ. НАСЛЕДОВАНИЕ        *
 *				   РИСОВАНИЕ МАШИНЫ							    	*
 *                 ПЕРЕМЕЩЕНИЕ  МАШИНЫ                              *
 *                                                                  *
 \******************************************************************/

#pragma once                  
#include <windows.h>
#include <conio.h>
#include <iostream>    
using namespace std;        // пространство имен std

#include "ModelingCar.h" 	// объявление классов
#include "GetConWin.h"		// указатель на консольное окно
#include "CarExhaustPipe.h"

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

	// объявление и инициализация переменных
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

		
			/************  Б А З О В Ы Й   К Л А С С  ***********/
			Base ABase(990, 200, 300, 40, "black");
			ABase.Show();

			/************	 М А Ш И Н А	 ***********/

			Car  ACar(950, 400, 300, 50, "red");  // инициализация машины
			ACar.Show();			// показать машину
			/************	 М А Ш И Н А  С   К А П О Т О М	 ***********/
			CarWithHood ACarWithHood(350, 350, 300, 50, "red");
			ACarWithHood.Show();
			
			/************	 М А Ш И Н А  С   Б А Г А Ж Н И К О М	 ***********/
			CarWithLuggade ACarWithLuggade(950, 590, 300, 50, "black");
			ACarWithLuggade.Show();


			/************	 М А Ш И Н А  С  К А П О Т О М   И   Б А Г А Ж Н И К О М	 ***********/
			CarWithHoodAndLuggade ACarWithHoodAndLuggade(650, 250, 300, 50, "gren");
			ACarWithHoodAndLuggade.Show();

			Canister ACanister(625, 550, 100);
			ACanister.Show();

			/************	 М А Ш И Н А  С   К А П О Т О М	  И  В Ы Х Л О П Н О Й   Т Р У Б О Й	***********/
			CarExhaustPipe ACarExhaustPipe(550, 550, 500, 50, "red");
			ACarExhaustPipe.Show();
			ACarExhaustPipe.Drag();

			

			/*while (1)
				if (KEY_DOWN(50))	//цифра 2        
					break;*/

			while (1)
				if (KEY_DOWN(49))   //цифра 1 
					break;
			/*
			while (1)
				if (KEY_DOWN(51))	//цифра 3
					break;*/
			
			//===================================================================
		}// end if
	}// end if
}//end main()
/**********************  End Of Ex05_03_Con.CPP File ********************/