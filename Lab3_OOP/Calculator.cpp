#include "Calculator.h"

Calculator::Calculator()
{
	left = new Decimal;
	right = new Decimal;
	operation = '+';
}

Calculator::Calculator(std::string input)
{
	const char SEP = ' ';
	std::istringstream ist(input);
	std::string left_oper, right_oper, oper;
	std::getline(ist, left_oper, SEP);
	std::getline(ist, oper, SEP);
	std::getline(ist, right_oper, SEP);

	left = new Decimal(left_oper);
	operation = oper[0];
	right = new Decimal(right_oper);
}

Calculator::~Calculator()
{
	delete left;
	delete right;
}

Decimal Calculator::Result()
{
	Decimal result;
	switch (operation)
	{
	case '+':
		result = *left + *right;
		break;
	case '-':
		result = *left - *right;
		break;
	case '*':
		result = *left * *right;
		break;
	case '/':
		result = *left / *right;
		break;
	}
	return result;
}

std::ostream& operator<<(std::ostream& stream, Calculator& object)
{
	Decimal result = object.Result();
	stream << result;
	return stream;
}
