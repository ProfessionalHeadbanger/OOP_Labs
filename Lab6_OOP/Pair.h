#pragma once
#include <iostream>
#include <string>

template<typename T>
class Pair
{
protected:
	T first;
	T second;
public:
	Pair()
	{
		first = 0;
		second = 0;
	}
	Pair(T first, T second)
	{
		this->first = first;
		this->second = second;
	}
	virtual Pair* add(Pair* object) = 0;
	virtual Pair* sub(Pair* object) = 0;
	virtual Pair* mul(Pair* object) = 0;
	virtual Pair* div(Pair* object) = 0;
	virtual bool is_equal(Pair* object) = 0;
	virtual std::string print() = 0;
	virtual Pair* input() = 0;
};

