#include "FazzyNumber.h"

FazzyNumber::FazzyNumber()
{
	first = 0;
	x = 0;
	second = 0;
}

FazzyNumber::FazzyNumber(double e1, double x, double e2)
{
	first = e1;
	this->x = x;
	second = e2;
}

FazzyNumber* FazzyNumber::operator+(FazzyNumber& object)
{
	first = first + object.first;
	x = x + object.x;
	second = second + object.second;
	return this;
}

FazzyNumber* FazzyNumber::operator-(FazzyNumber& object)
{
	first = first + object.first;
	x = x - object.x;
	second = second + object.second;
	return this;
}

FazzyNumber* FazzyNumber::operator*(FazzyNumber& object)
{
	first = object.x * first + x * object.first - first * object.first;
	x = x * object.x;
	second = object.x * second + x * object.second + second * object.second;
	return this;
}

FazzyNumber* FazzyNumber::operator/(FazzyNumber& object)
{
	first = (x * object.second + object.x * first) / (object.x * object.x + object.x * object.second);
	x = x / object.x;
	second = (object.x * second + x * object.first) / (object.x * object.x - object.x * object.first);
	return this;
}

bool FazzyNumber::operator==(FazzyNumber& object)
{
	return (first == object.first) && (x == object.x) && (second == object.second);
}

std::ostream& operator<<(std::ostream& output, FazzyNumber& object)
{
	output << "(" << std::to_string(object.x - object.first) << ", " << std::to_string(object.x) << ", "
		<< std::to_string(object.x + object.second) << ")";
	return output;
}

std::istream& operator>>(std::istream& input, FazzyNumber& object)
{
	input >> object.first >> object.x >> object.second;
	return input;
}