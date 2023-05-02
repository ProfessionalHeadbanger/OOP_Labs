#pragma once

#include <iostream>
#include "Decimal.h"

class Calculator
{
private:
	Decimal *left, *right;
	char operation;
public:
	Calculator();
	Calculator(std::string);
	~Calculator();
	Decimal Result();

	friend std::ostream& operator << (std::ostream&, Calculator&);
};