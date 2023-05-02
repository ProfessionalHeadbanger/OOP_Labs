#pragma once
#include "Pair.h"

class FazzyNumber : public Pair<double>
{
private:
	double x;
public:
	FazzyNumber();
	FazzyNumber(double, double, double);
	
	FazzyNumber* operator +(FazzyNumber&);
	FazzyNumber* operator -(FazzyNumber&);
	FazzyNumber* operator *(FazzyNumber&);
	FazzyNumber* operator /(FazzyNumber&);
	bool operator == (FazzyNumber&);
	friend std::ostream& operator << (std::ostream&, FazzyNumber&);
	friend std::istream& operator >> (std::istream&, FazzyNumber&);
};

