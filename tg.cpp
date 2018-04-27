#include "stdafx.h"
#include <iostream>

int srand(int(clock));

//remake
void gen(int t, int type, const int masSize, int *array)
{
	if (t == 0)
	{
		for (int i = 0; i < masSize; i++)
		{
			array[i] = rand();
		}
	}
	else if (t == 1)//good
	{
		if (type == 1) //cocktail
		{
			for (int i = 0; i < masSize; i++)
			{
				array[i] = i;
			}
		}
		else if (type == 2) //comb
		{
			for (int i = 0; i < masSize; i++)
			{
				array[i] = i;
			}
		}
		else //radix
		{
			for (int i = 0; i < masSize; i++)
			{
				array[i] = i;
			}
		}
	}
	else//bad
	{
		if (type == 1) //cocktail
		{
			for (int i = 0; i < masSize; i++)
			{
				array[i] = masSize - i;
			}
		}
		else if (type == 2) //comb
		{
			for (int i = 0; i < masSize; i++)
			{
				array[i] = masSize - i;
			}
		}
		else //radix
		{
			for (int i = 0; i < masSize; i++)
			{
				array[i] = masSize - i;
			}
		}
	}
}