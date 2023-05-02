#pragma once
#include "Pair.h"
#include <sstream>

class Fraction : public Pair<int>
{
private:
	int scale_koef;
	bool minus;
	int Scale(int);
	void Reduce();
	void Merge(Fraction object, int& left, int& right, char oper);

public:
	Fraction();
	Fraction(int, int, int, bool);
	
	Fraction* operator +(Fraction&);
	Fraction* operator -(Fraction&);
	Fraction* operator *(Fraction&);
	Fraction* operator /(Fraction&);
	bool operator == (Fraction&);
	friend std::ostream& operator << (std::ostream&, Fraction&);
	friend std::istream& operator >> (std::istream&, Fraction&);
};

