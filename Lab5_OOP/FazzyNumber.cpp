#include "FazzyNumber.h"

FazzyNumber::FazzyNumber()
{
	first = 0;
	x = 0;
	second = 0;
}

FazzyNumber::FazzyNumber(int e1, int x, int e2)
{
	first = e1;
	this->x = x;
	second = e2;
}

Pair* FazzyNumber::add(Pair* object)
{
	FazzyNumber* _object = dynamic_cast<FazzyNumber*>(object);
	first = first + _object->first;
	x = x + _object->x;
	second = second + _object->second;
	return object;
}

Pair* FazzyNumber::sub(Pair* object)
{
	FazzyNumber* _object = dynamic_cast<FazzyNumber*>(object);
	first = first + _object->first;
	x = x - _object->x;
	second = second + _object->second;
	return object;
}

Pair* FazzyNumber::mul(Pair* object)
{
	FazzyNumber* _object = dynamic_cast<FazzyNumber*>(object);
	first = _object->x*first + x*_object->first - first*_object->first;
	x = x * _object->x;
	second = _object->x*second + x*_object->second + second*_object->second;
	return object;
}

Pair* FazzyNumber::div(Pair* object)
{
	FazzyNumber* _object = dynamic_cast<FazzyNumber*>(object);
	first = (x*_object->second + _object->x*first)/(_object->x*_object->x + _object->x*_object->second);
	x = x / _object->x;
	second = (_object->x*second + x*_object->first)/(_object->x * _object->x - _object->x*_object->first);
	return object;
}

bool FazzyNumber::is_equal(Pair* object)
{
	FazzyNumber* _object = dynamic_cast<FazzyNumber*>(object);
	return (first == _object->first) && (x == _object->x) && (second == _object->second);
}

std::string FazzyNumber::print()
{
	return "(" + std::to_string(x - first) + ", " + std::to_string(x) + ", " + std::to_string(x + second) + ")";
}

Pair* FazzyNumber::input()
{
	std::cin >> first >> x >> second;
	return this;
}
