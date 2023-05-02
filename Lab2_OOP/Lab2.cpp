#include "Decimal.h"
#include <iostream>
#include <Windows.h>

void Compare(Decimal a, Decimal b)
{
	if (a > b)
	{
		std::cout << a << " > " << b << std::endl;
	}
	if (a < b)
	{
		std::cout << a << " < " << b << std::endl;
	}
	if (a == b)
	{
		std::cout << a << " = " << b << std::endl;
	}
}

Decimal Operation(Decimal a, Decimal b)
{
	Decimal result;
	bool menu = true;
	while (menu)
	{
		char choice;
		std::cout << "�������� �������������� ��������: + - * / ";
		std::cin >> choice;
		switch (choice)
		{
		case '+':
			result = a + b;
			menu = false;
			break;
		case '-':
			result = a - b;
			menu = false;
			break;
		case '*':
			result = a * b;
			menu = false;
			break;
		case '/':
			result = a / b;
			menu = false;
			break;
		default:
			std::cout << "�������� ����! " << std::endl;
			menu = true;
			break;
		}
	}
	return result;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	bool flag = true;
	while (flag)
	{
		bool menu = true;
		while (menu)
		{
			Decimal a, b, result;
			char choice;
			std::cout << "�������� �������� � ����� ����������� �������: 1 - ���������, 2 - �������������� �������� ";
			std::cin >> choice;
			std::cout << "������� ������ �����: "; std::cin >> a;
			std::cout << "������� ������ �����: "; std::cin >> b;
			switch (choice)
			{
			case '1':
				Compare(a, b);
				menu = false;
				break;
			case '2':
				result = Operation(a, b);
				std::cout << "���������: " << result << std::endl;
				menu = false;
				break;
			default:
				std::cout << "�������� ����! " << std::endl;
				menu = true;
				break;
			}
		}

		char choice;
		bool label = true;
		while (label)
		{
			std::cout << "������� ������ ������ ��� �����? 1 - ������, 2 - ����� ";
			std::cin >> choice;
			switch (choice)
			{
			default:
				std::cout << "�������� ����!" << std::endl;
				label = true;
				break;
			case '1':
				flag = true;
				label = false;
				break;
			case '2':
				flag = false;
				label = false;
				break;
			}
		}
	}
}