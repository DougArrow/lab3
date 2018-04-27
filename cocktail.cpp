#include "stdafx.h"
#include "gl.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

s_Cocktail::s_Cocktail(std::ofstream *File)
{
	this->type = 1;
	this->File = File;
	*this->File << "Cocktail\n";
	*this->File << std::setfill('-') << std::setw(25) << "" << "\n";
}

s_Cocktail::~s_Cocktail()
{
	*this->File << std::setfill('-') << std::setw(25) << "" << "\n\n";
}

void s_Cocktail::func(double &time, int &permut, int &comp, int *array, const int masSize)
{
	
	time = clock();
	int buff = 0; // дл€ временного хранени€ значени€, при перезаписи

	for (int i = 0; i < masSize - 1; i++) // 
	{
		// вложенный цикл проходит от четвертого элемента 
		// до первого, находит с помощью if самое "легкое" значение,
		// сравнива€ соседние пары элементов,
		// и поднимает его в нулевую €чейку массива
		for (int j = masSize - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				comp++;
				buff = array[j - 1];
				array[j - 1] = array[j];
				array[j] = buff;
			}permut++;
		}
		// далее значение i увеличиваетс€ на 1
		// и внутренний цикл будет перебирать элементы 
		// от четвертого до второго. “аким образом поднимет самое
		// "легкое" значение из оставшихс€  в первую €чейку и т.д.
	}
	time = clock() - time;
}