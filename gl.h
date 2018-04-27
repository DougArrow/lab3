#ifndef GL_H
#define GL_H
#include "stdafx.h"
#include <iostream>
#include <fstream>

class Sort
{
protected:
	std::ofstream *File;
	void swap(int *, int *);
	int type;
public:
	virtual void func(double &, int &, int &, int *, const int) = 0;
	virtual ~Sort();
	void work(int, int[]);
};

class s_Cocktail : public Sort
{
public:
	void func(double &, int &, int &, int *,  const int);
	s_Cocktail(std::ofstream *);
	~s_Cocktail();
};

class s_Comb : public Sort
{
public:
	void func(double &, int &, int &, int *, const int);
	s_Comb(std::ofstream *);
	~s_Comb();
};

class s_Radix : public Sort
{
public:
	void func(double &, int &, int &, int *, const int);
	s_Radix(std::ofstream *);
	~s_Radix();
};

#endif
