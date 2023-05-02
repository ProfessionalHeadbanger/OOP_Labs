#include "Calculator.h"
#include <Windows.h>
#include <limits>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::cout << "Калькулятор  V\"вставить какое то число\"" << std::endl;
	std::cout << "Все выражения вводятся в виде \"левая часть выражения\" \"символ операции\" \"правая часть выражения\"" << std::endl;
	std::cout << "Левая и правая части представлены десятичными дробями, символы операции: +, -, *, / " << std::endl << std::endl;

	bool flag = true;
	while (flag)
	{
		std::string input;
		std::cout << "Введите выражение: " << std::endl;
		getline(std::cin >> std::ws, input);
		Calculator calc(input);
		std::cout << " = " << calc << std::endl;
		char choice;
		bool label = true;
		while (label)
		{
			std::cout << "Желаете начать заново или выйти? 1 - заново, 2 - выйти ";
			std::cin >> choice;
			switch (choice)
			{
			default:
				std::cout << "Неверный ввод!" << std::endl;
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
