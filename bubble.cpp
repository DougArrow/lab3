#include "stdafx.h"
#include "gl.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

s_bubble::s_bubble(std::ofstream *File)
{
	this->type = 1;
	this->File = File;
	*this->File << "Bubble\n";
	*this->File << std::setfill('-') << std::setw(25) << "" << "\n";
}

s_bubble::~s_bubble()
{
	*this->File << std::setfill('-') << std::setw(25) << "" << "\n\n";
}

void s_bubble::func(double &time, int &permut, int &comp, int *array, const int masSize)
{
	
	time = clock();
	int buff = 0; // для временного хранения значения, при перезаписи

	for (int i = 0; i < masSize - 1; i++) // 
	{
	
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

	}
	time = clock() - time;
}