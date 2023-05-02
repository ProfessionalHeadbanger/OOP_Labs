#pragma once
#include "Pair.h"
class FazzyNumber : public Pair
{
private:
	int x;
public:
	FazzyNumber();
	FazzyNumber(int, int, int);
	Pair* add(Pair* object) override;
	Pair* sub(Pair* object) override;
	Pair* mul(Pair* object) override;
	Pair* div(Pair* object) override;
	bool is_equal(Pair* object) override;
	std::string print() override;
	Pair* input() override;
};

