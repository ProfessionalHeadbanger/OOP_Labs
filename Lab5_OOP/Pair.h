#pragma once
#include <iostream>
#include <string>

class Pair
{
protected:
	int first;
	int second;
public:
	Pair();
	Pair(int, int);
	virtual Pair* add(Pair* object) = 0;
	virtual Pair* sub(Pair* object) = 0;
	virtual Pair* mul(Pair* object) = 0;
	virtual Pair* div(Pair* object) = 0;
	virtual bool is_equal(Pair* object) = 0;
	virtual std::string print() = 0;
	virtual Pair* input() = 0;
};

