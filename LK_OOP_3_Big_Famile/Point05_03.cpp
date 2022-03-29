/*******************************************************************\
 * Comment(s)    : ОБЪЯВЛЕНИЕ ТРЕХ КЛАССОВ. НАСЛЕДОВАНИЕ            *
 *                 СТАТИЧЕСКИЕ ПРАВИЛА						        *
 *                 РАННЕЕ СВЯЗЫВАНИЕ						        *
 *                                                                  *
 |******************************************************************/

#include <windows.h>
#include "Point05_03.h"	//объявление классов

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*   Г Л О Б А Л Ь Н Ы Е   П Е Р Е М Е Н Н Ы Е  И  К О Н С Т А Н Т Ы   */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
 //глобальная переменная видна в двух файлах: Point05_03.cpp и Ex05_03_Con.cpp
 //внешнее обявление глобальной переменной
extern HDC hdc;      // объявим  контекст устройства

// Макрос для проверки состояния клавиатуры – из ШАБЛОНА
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

	/*----------------------------------------------------------------*/
	/*             Р Е А Л И З А Ц И Я    М Е Т О Д О В               */
	/*----------------------------------------------------------------*/

			/*----------------------------------------*/
			/*        МЕТОДЫ КЛАССА Location          */
			/*----------------------------------------*/

Location::Location(int InitX, int InitY) //конструктор
{
	//инициализация закрытых переменных своего класса
	X = InitX;
	Y = InitY;
};//end Location::Location()

 
//Location::~Location(void)  //деструктор 
//{//формально пустое тело
//};//end Location::~Location()

 
int Location::GetX(void)  //получить X координату точки
{
	return X;
};//end Location::GetX()	

  
int Location::GetY(void) //получить Y координату точки
{
	return Y;
}; //end Location::GetY()


			/*----------------------------------------*/
			/*        МЕТОДЫ КЛАССА Point             */
			/*----------------------------------------*/

//для инициализации закрытых полей используем конструктор предка
Point::Point(int InitX, int InitY) : Location(InitX, InitY) //конструктор
{
	//инициализация закрытых переменных своего класса
	Visible = false;
}//end Point::Point()


//Point::~Point(void)  //деструктор  
//{//формально пустое тело
//}//end Point::~Point()


void Point::Show(void)  //показать ТОЧКУ
{
	Visible = true;
	SetPixel(hdc, X, Y, RGB(255, 0, 0));	//рисуем красным цветом
	SetPixel(hdc, X + 1, Y, RGB(255, 0, 0));	// 4 точки для удобства
	SetPixel(hdc, X, Y + 1, RGB(255, 0, 0));
	SetPixel(hdc, X + 1, Y + 1, RGB(255, 0, 0));
}//end Point::Show()

 //--------------------------------------------------------------

void Point::Hide(void)  //скрыть ТОЧКУ
{
	Visible = false; // ЗАЧЕМ?

	SetPixel(hdc, X, Y, RGB(0, 0, 255));//рисуем синим цветом или фона
	SetPixel(hdc, X + 1, Y, RGB(0, 0, 255));
	SetPixel(hdc, X, Y + 1, RGB(0, 0, 255));
	SetPixel(hdc, X + 1, Y + 1, RGB(0, 0, 255));
}//end Point::Hide()

 //--------------------------------------------------------------

bool Point::IsVisible(void)  //узнать про светимость ТОЧКИ
{
	return Visible;
};//end Point::IsVisible()

//--------------------------------------------------------------

void Point::MoveTo(int NewX, int NewY) //переместить ТОЧКУ
{
	Hide();		//сделать точку невидимой
	X = NewX;	//поменять координаты ТОЧКИ
	Y = NewY;
	Show();		//показать точку на новом месте
};//end Point::MoveTo()

void Point::Drag(int Step) //переместить ТОЧКУ
{
	int FigX, FigY; // новые координаты фигуры

	FigX = GetX();    //получаем начальное положение фигуры
	FigY = GetY();

	while (1)	//бесконечный цикл буксировки фигуры
	{
		if (KEY_DOWN(VK_ESCAPE))     //конец работы 27 пробел
			break;

		//направление движения объекта

		if (KEY_DOWN(VK_LEFT)) //стрелка влево  37
		{
			FigX -= Step;
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_RIGHT)) //стрелка вправо  39
		{
			FigX += Step;
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_DOWN)) //стрелка вниз  40
		{
			FigY += Step;
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if

		if (KEY_DOWN(VK_UP)) //стрелка вверх  38
		{
			FigY -= Step;
			MoveTo(FigX, FigY);
			Sleep(500);
		}//end if
	}   //while
	
};//end Point::Drag()


		/*----------------------------------------*/
		/*        МЕТОДЫ КЛАССА Circle            */
		/*----------------------------------------*/

//для инициализации закрытых полей используем конструктор предка
Car::Car(int InitX, int InitY, int InitSpeed) : Point(InitX, InitY) // конструктор Circle
{
	//инициализация закрытых переменных своего класса
	Speed = InitSpeed;
}//end Circle::Circle ()


//Circle::~Circle(void) // деструктор
//{ //формально пустое тело
//};//end Circle::~Circle ()


void Car::Show(void) // показать круг
{
	Visible = true;

	// Зададим перо и цвет пера - красный
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, Pen);	//сделаем перо активным

	// Нарисуем круг установленным цветом
	Rectangle(hdc, X - 100, Y - 70, X - 280, Y - 140);
	Rectangle(hdc, X, Y, X - 370, Y - 70);
	Ellipse(hdc, X - 115, Y + 35, X - 45, Y - 35);
	Ellipse(hdc, X - 325, Y + 35, X - 255, Y - 35);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);

} // end Circle::Show()


void Car::Hide(void) // скрыть круг
{
	Visible = false;

	// Зададим перо и цвет пера
	HPEN Pen = ::CreatePen(PS_SOLID, 2, RGB(0, 0, 255)); //синий

	SelectObject(hdc, Pen);

	// Нарисуем круг установленным цветом
	Ellipse(hdc, X - Speed, Y - Speed, X + Speed, Y + Speed);
	Rectangle(hdc, 400, 300, 30, 20);
	// Уничтожим нами созданные объекты  
	DeleteObject(Pen);

}// end Circle::Hide()

// попробуем взять из Point   !!!! 
// в разделе объявления есть, а в разделе реализации нет  !!!


void Car::MoveTo(int NewX, int NewY) // поставить в соответствие новые координаты
{
	Hide();  //стирание старой окружности
	X = NewX; //поменять координаты
	Y = NewY;
	Show();  //показать окружность на новом месте
}//end Circle::MoveTo()


void Car::Expand(int DeltaRad)  //увеличить радиус КРУГА
{
	Hide();             //спрятать окружность со старым радиусом
	Speed += DeltaRad; //изменить радиус 
	if (Speed < 0)     //для отрицательного приращения радиуса
		Speed = 5;
	Show();             //показать окружность с новым радиусом
}//end Circle::Expand ()


void Car::Reduce(int DeltaRad) //уменьшить радиус КРУГА
{
	Expand(-DeltaRad); //отрицательное приращение радиуса
}//end Circle::Reduce ()


		


/**************   End of File Point05_03.СPP   ********************/
