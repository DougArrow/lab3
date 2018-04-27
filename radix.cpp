#include "stdafx.h"
#include "gl.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

s_Radix::s_Radix(std::ofstream *File)
{
	this->type = 3;
	this->File = File;
	*this->File << "Radix\n";
	*this->File << std::setfill('-') << std::setw(25) << "" << "\n";
}

s_Radix::~s_Radix()
{
	*this->File << std::setfill('-') << std::setw(25) << "" << "";
}

void s_Radix::func(double &time, int &permut, int &comp, int *array, const int masSize)
{
	time = clock();
	int max = array[0];

	for (int i = 1; i < masSize; i++)
		if (max < array[i]) max = array[i];

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		int output[502];
		int i, count[10] = { 0 };

		for (i = 0; i < masSize; i++)
			count[(int)(array[i] / exp) % 10]++;
		comp++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		
		permut++;
		for (i = masSize - 1; i >= 0; i--)
		{
			output[count[(int)(array[i] / exp) % 10] - 1] = array[i];
			permut++;
			count[(int)(array[i] / exp) % 10]--;
		}

		for (i = 0; i < masSize; i++)
			array[i] = output[i];
	}
	time = clock() - time;
}