#pragma once
#include <iostream>

class Pair
{
protected:
	int first, second;
public:
	Pair();
	Pair(int, int);

	Pair* operator +(Pair&);
	Pair* operator *(int);
	friend std::ostream& operator <<(std::ostream&, Pair&);
	friend std::istream& operator >>(std::istream&, Pair&);
};

