#pragma once
#include <iostream>
#include <string>

template<class T>
class Pair
{
protected:
	T first;
	T second;
public:
	Pair() :first(0), second(0) {}
	Pair(T first, T second) :first(first), second(second) {}
};

