#include "Pair.h"
#include "Money.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Pair a, b, c;
	Money x, y, z;
	bool flag = true;
	while (flag)
	{
		bool menu = true;
		while (menu)
		{
			char mode;
			std::cout << "Выберите режим работы программы: 1 - с парой чисел, 2 - с деньгами (рубли и копейки) ";
			std::cin >> mode;
			switch (mode)
			{
			default:
				std::cout << "Неверный ввод!" << std::endl;
				menu = true;
				break;
			case '1':
				std::cout << "Введите первую пару целых чисел: ";
				std::cin >> a;

				char choice1;
				std::cout << "Выберите действие для пары чисел: 1 - сложить с другой парой, 2 - умножить на число ";
				std::cin >> choice1;
				switch (choice1)
				{
				default:
					std::cout << "Неверный ввод!" << std::endl;
					break;
				case '1':
					std::cout << "Введите вторую пару целых чисел: ";
					std::cin >> b;
					c = *(a + b);
					std::cout << "Результат: " << c;
					break;
				case '2':
					int number;
					std::cout << "Введите число, на которое будет умножаться пара: ";
					std::cin >> number;
					c = *(a * number);
					std::cout << "Результат: " << c;
					break;
				}
				menu = false;
				break;
			case '2':
				std::cout << "Введите первую денежную сумму(рубли и копейки): ";
				std::cin >> x;

				char choice2;
				std::cout << "Выберите действие для денежной суммы: 1 - сложить с другой суммой, 2 - вычесть из введенной суммы другую, 3 - умножить на число, 4 - разделить на число, 5 - сравнить ";
				std::cin >> choice2;
				switch (choice2)
				{
				default:
					std::cout << "Неверный ввод!" << std::endl;
					break;
				case '1':
					std::cout << "Введите вторую денежную сумму: ";
					std::cin >> y;
					z = *(x + y);
					std::cout << "Результат: " << z;
					break;
				case '2':
					std::cout << "Введите вторую денежную сумму: ";
					std::cin >> y;
					z = *(x - y);
					std::cout << "Результат: " << z;
					break;
				case '3':
					int number1;
					std::cout << "Введите число, на которое будет умножаться денежная сумма: ";
					std::cin >> number1;
					z = *(x * number1);
					std::cout << "Результат: " << z;
					break;
				case '4':
					int number2;
					std::cout << "Введите число, на которое будет делиться денежная сумма: ";
					std::cin >> number2;
					z = *(x / number2);
					std::cout << "Результат: " << z;
					break;
				case '5':
					std::cout << "Введите вторую денежную сумму: ";
					std::cin >> y;
					if (x > y)
					{
						std::cout << x << " > " << y << std::endl;
					}
					else if (x < y)
					{
						std::cout << x << " < " << y << std::endl;
					}
					else if (x == y)
					{
						std::cout << x << " = " << y << std::endl;
					}
					break;
				}
				menu = false;
				break;
			}
		}
		

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
