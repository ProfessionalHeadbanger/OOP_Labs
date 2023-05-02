#pragma once
#include "Pair.h"

class Money : public Pair
{
private:
	void Reduce();
public:
	Money();
	Money(int, int);
	
	Money* operator +(Money&);
	Money* operator -(Money&);
	Money* operator *(int);
	Money* operator /(int);
	bool operator >(Money&);
	bool operator <(Money&);
	bool operator ==(Money&);
	friend std::ostream& operator <<(std::ostream&, Money&);
	friend std::istream& operator >>(std::istream&, Money&);
};

