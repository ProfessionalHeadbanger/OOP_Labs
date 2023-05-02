#include "Triangle.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Triangle triangle(3, 3, 3, 1);
	double h1, h2, h3;
	triangle.CalcHeights(h1, h2, h3);
	std::cout << triangle.toString() << triangle.TriType() << triangle.CalcArea() << "\n" << triangle.CalcPerim();
}