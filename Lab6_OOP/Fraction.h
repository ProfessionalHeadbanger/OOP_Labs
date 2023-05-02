#pragma once
#include "Pair.h"
#include <sstream>
class Fraction : public Pair<int>
{
private:
	int scale_koef;
	bool minus;
	int Scale(int);
	void Reduce();
	void Merge(Fraction object, int& left, int& right, char oper);

public:
	Fraction();
	Fraction(int, int, int, bool);
	Pair* add(Pair* object) override;
	Pair* sub(Pair* object) override;
	Pair* mul(Pair* object) override;
	Pair* div(Pair* object) override;
	bool is_equal(Pair* object) override;
	std::string print() override;
	Pair* input() override;
};

