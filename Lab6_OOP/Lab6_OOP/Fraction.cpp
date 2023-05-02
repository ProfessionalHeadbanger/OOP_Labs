#include "Fraction.h"

int Fraction::Scale(int scale_koef)
{
	int scale = 1;
	for (int i = 0; i < scale_koef; i++)
	{
		scale *= 10;
	}
	return scale;
}

void Fraction::Reduce()
{
	while (second % 10 == 0)
	{
		second /= 10;
		scale_koef--;
	}
}

void Fraction::Merge(Fraction object, int& left, int& right, char oper)
{
	if (oper == '+' || oper == '-')
	{
		if (scale_koef > object.scale_koef)
		{
			if (minus)
			{
				left = -(abs(first * Scale(scale_koef)) + second);
			}
			else
			{
				left = (abs(first * Scale(scale_koef)) + second);
			}
			if (object.minus)
			{
				right = -(abs(object.first * Scale(scale_koef)) + object.second * Scale(scale_koef - object.scale_koef));
			}
			else
			{
				right = (abs(object.first * Scale(scale_koef)) + object.second * Scale(scale_koef - object.scale_koef));
			}
		}

		else if (object.scale_koef > scale_koef)
		{
			if (minus)
			{
				left = -abs((first * Scale(object.scale_koef) + second * Scale(object.scale_koef - scale_koef)));
			}
			else
			{
				left = abs((first * Scale(object.scale_koef) + second * Scale(object.scale_koef - scale_koef)));
			}
			if (object.minus)
			{
				right = -abs((object.first * Scale(object.scale_koef) + object.second));
			}
			else
			{
				right = abs((object.first * Scale(object.scale_koef) + object.second));
			}
		}
		else if (scale_koef == object.scale_koef)
		{
			if (minus)
			{
				left = -abs((first * Scale(object.scale_koef) + second));
			}
			else
			{
				left = abs((first * Scale(object.scale_koef) + second));
			}
			if (object.minus)
			{
				right = -abs((object.first * Scale(object.scale_koef) + object.second));
			}
			else
			{
				right = abs((object.first * Scale(object.scale_koef) + object.second));
			}
		}
	}
	else if (oper == '*' || oper == '/')
	{
		if (minus)
		{
			left = -(abs(first * Scale(scale_koef)) + second);
		}
		else
		{
			left = (abs(first * Scale(scale_koef)) + second);
		}
		if (object.minus)
		{
			right = -abs((object.first * Scale(object.scale_koef) + object.second));
		}
		else
		{
			right = abs((object.first * Scale(object.scale_koef) + object.second));
		}
	}
}

Fraction::Fraction()
{
	first = 0;
	second = 0;
	scale_koef = 1;
	minus = false;
}

Fraction::Fraction(int left, int right, int scale_koef, bool minus)
{
	first = left;
	second = right;
	this->scale_koef = scale_koef;
	this->minus = minus;
}

Fraction* Fraction::operator+(Fraction& object)
{
	scale_koef = std::max(scale_koef, object.scale_koef);
	int left, right;
	Merge(object, left, right, '+');
	first = left + right;
	if (first < 0)
	{
		minus = true;
	}
	else
	{
		minus = false;
	}
	second = abs(first) % Scale(scale_koef);
	Reduce();
	first /= Scale(scale_koef);
	return this;
}

Fraction* Fraction::operator-(Fraction& object)
{
	scale_koef = std::max(scale_koef, object.scale_koef);
	int left, right;
	Merge(object, left, right, '-');
	first = left - right;
	if (first < 0)
	{
		minus = true;
	}
	else
	{
		minus = false;
	}
	second = abs(first) % Scale(scale_koef);
	Reduce();
	first /= Scale(scale_koef);
	return this;
}

Fraction* Fraction::operator*(Fraction& object)
{
	int left, right;
	Merge(object, left, right, '*');
	first = left * right;
	if (first < 0)
	{
		minus = true;
	}
	else
	{
		minus = false;
	}
	scale_koef = scale_koef + object.scale_koef;
	int second_buffer = abs(first) % Scale(scale_koef);
	int scale_koef_buffer = scale_koef;
	if (scale_koef > 4)
	{
		scale_koef = 4;
	}
	second = second_buffer / Scale(scale_koef_buffer - scale_koef);
	first /= Scale(scale_koef_buffer);
	Reduce();
	return this;
}

Fraction* Fraction::operator/(Fraction& object)
{
	int left, right;
	Merge(object, left, right, '/');
	first = left / right;
	if (first < 0)
	{
		minus = true;
	}
	else
	{
		minus = false;
	}
	scale_koef = scale_koef + object.scale_koef;
	int second_buffer = abs(first) % Scale(scale_koef);
	int scale_koef_buffer = scale_koef;
	if (scale_koef > 4)
	{
		scale_koef = 4;
	}
	second = second_buffer / Scale(scale_koef_buffer - scale_koef);
	first /= Scale(scale_koef_buffer);
	Reduce();
	return this;
}

bool Fraction::operator==(Fraction& object)
{
	return (first == object.first) && (second == object.second);
}

std::ostream& operator<<(std::ostream& output, Fraction& object)
{
	std::stringstream stream;
	if (object.minus && object.first == 0)
	{
		stream << '-';
	}
	stream << object.first << '.';
	std::string fr = std::to_string(object.second);
	int fr_size = fr.size();
	while (object.scale_koef > fr_size)
	{
		fr = '0' + fr;
		fr_size++;
	}
	stream << fr;
	std::string str;
	stream >> str;
	output << str;
	return output;
}

std::istream& operator>>(std::istream& input, Fraction& object)
{
	const char SEP = '.';
	std::string inp;
	input >> inp;
	std::stringstream ss(inp);
	std::string left;
	std::string right;
	std::getline(ss, left, SEP);
	std::getline(ss, right, SEP);

	if (left[0] == '-')
	{
		object.minus = true;
	}
	object.first = std::stoi(left);

	object.second = std::stoi(right);
	object.scale_koef = right.size();
	object.Reduce();
	return input;
}