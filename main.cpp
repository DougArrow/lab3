#include "stdafx.h"
#include "gl.h"
#include <iostream>
#include <fstream>

void main()
{
	int size[] = { 1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 50, 75, 100, 250, 500 };
	const int isSize = 15;
	std::ofstream File("1.txt");
	Sort *ptr;

	ptr = new s_bubble(&File);
	ptr->work(isSize, size);
	delete ptr;

	ptr = new s_Comb(&File);
	ptr->work(isSize, size);
	delete ptr;

	ptr = new s_Radix(&File);
	ptr->work(isSize, size);
	delete ptr;

	File.close();
	system("pause");
}
