#include "Money.h"

void Money::Reduce()
{
	if (second >= 100)
	{
		first += second / 100;
		second = second % 100;
	}
	else if (second < 0 && first > 0)
	{
		second += 100;
		first--;
	}
}

Money::Money()
{
	first = 0;
	second = 0;
}

Money::Money(int rubles, int kopecks) :Pair(rubles, kopecks)
{
	Reduce();
}

Money* Money::operator+(Money& object)
{
	Pair::operator+(object);
	Reduce();
	return this;
}

Money* Money::operator-(Money& object)
{
	int temp_left = first * 100 + second;
	int temp_right = object.first * 100 + object.second;
	temp_left = temp_left - temp_right;
	first = temp_left / 100;
	second = temp_left % 100;
	return this;
}

Money* Money::operator*(int number)
{
	Pair::operator*(number);
	Reduce();
	return this;
}

Money* Money::operator/(int number)
{
	int temp_left = first * 100 + second;;
	temp_left = temp_left / number;
	first = temp_left / 100;
	second = temp_left % 100;
	return this;
}

bool Money::operator>(Money& object)
{
	int temp_left = first * 100 + second;
	int temp_right = object.first * 100 + object.second;
	if (temp_left > temp_right)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Money::operator<(Money& object)
{
	int temp_left = first * 100 + second;
	int temp_right = object.first * 100 + object.second;
	if (temp_left < temp_right)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Money::operator==(Money& object)
{
	int temp_left = first * 100 + second;
	int temp_right = object.first * 100 + object.second;
	if (temp_left == temp_right)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator <<(std::ostream& output, Money& object)
{
	output << object.first << " рублей " << object.second << " копеек";
	return output;
}

std::istream& operator >>(std::istream& input, Money& object)
{
	input >> object.first >> object.second;
	object.Reduce();
	return input;
}
