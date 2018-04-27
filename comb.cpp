#include "stdafx.h"
#include "gl.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

s_Comb::s_Comb(std::ofstream *File)
{
	this->type = 2;
	this->File = File;
	*this->File << "Comb\n";
	*this->File << std::setfill('-') << std::setw(25) << "" << "\n";
}

s_Comb::~s_Comb()
{
	*this->File << std::setfill('-') << std::setw(25) << "" << "\n\n";
}

//remake
void s_Comb::func(double &time, int &permut, int &comp, int *array, const int masSize)
{
	time = clock();
	const double cnst = 1.247330950103979;
	int j = masSize - 1;
	bool flag = true;

	while (j > 1 || flag)
	{
		if (j > 1) j = (int)(j / cnst);

		int i = 0;
		flag = false;

		while (i + j < masSize - 1)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + j]);
				permut++;
				flag = true;
			}
			comp++;
			i++;
		}
	}
	time = clock() - time;
}