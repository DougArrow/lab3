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
	int buff = 0; // ��� ���������� �������� ��������, ��� ����������

	for (int i = 0; i < masSize - 1; i++) // 
	{
		// ��������� ���� �������� �� ���������� �������� 
		// �� �������, ������� � ������� if ����� "������" ��������,
		// ��������� �������� ���� ���������,
		// � ��������� ��� � ������� ������ �������
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
		// ����� �������� i ������������� �� 1
		// � ���������� ���� ����� ���������� �������� 
		// �� ���������� �� �������. ����� ������� �������� �����
		// "������" �������� �� ����������  � ������ ������ � �.�.
	}
	time = clock() - time;
}