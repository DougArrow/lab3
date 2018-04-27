#include "stdafx.h"
#include "gl.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

int srand(int(clock));

void gen(int, int, const int, int *array);

Sort::~Sort()
{
}

void Sort::swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void Sort::work(const int isSize, int size[])
{
	for (int j = 0; j<isSize; j++)
	{
		double time = 0;	
		double permut = 0;	
		double comp = 0;	

		for (int i = 0; i<100; i++)
		{
			double nTime = 0;
			int nPermut = 0;
			int nComp = 0;
			int *array = new int[size[j]];

			gen(0, this->type, size[j], array);
			this->func(nTime, nPermut, nComp, array, size[j]);


			/*std::cout<<j<<"::\n";
			for (int k = 0; k < size[j]; k++)
			{
			std::cout<<array[k]<<" ";
			}
			std::cout<<"\n\n"; */


			delete[] array;
			time += nTime;
			permut += nPermut;
			comp += nComp;
		}
		time /= 100;
		permut /= 100;
		comp /= 100;
		*this->File << "Array Size = " << std::setfill(' ') << std::left << std::setw(7) << size[j] << "Time = " << std::left << std::setw(7) << time << "Permutation: " << std::left << std::setw(10) << permut << "Comparison: " << std::left << std::setw(7) << comp << std::endl;
	}
}