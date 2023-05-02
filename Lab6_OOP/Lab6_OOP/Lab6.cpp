#include "FazzyNumber.h"
#include "Fraction.h"
#include <Windows.h>

using namespace std;

template <typename T>
void operation(T first, T second)
{
	T result;
	char oper;
	bool label2 = true;
	while (label2)
	{
		cout << "Выберите операцию: 1)+, 2)-, 3)*, 4)/, 5)= ";
		cin >> oper;
		switch (oper)
		{
		case '1':
			result = *(first + second);
			cout << "Результат: " << result << endl;
			label2 = false;
			break;
		case '2':
			result = *(first - second);
			cout << "Результат: " << result << endl;
			label2 = false;
			break;
		case '3':
			result = *(first * second);
			cout << "Результат: " << result << endl;
			label2 = false;
			break;
		case '4':
			result = *(first / second);
			cout << "Результат: " << result << endl;
			label2 = false;
			break;
		case '5':
			if (first == second)
			{
				cout << first << " = " << second << endl;
			}
			else
			{
				cout << first << " != " << second << endl;
			}
			label2 = false;
			break;
		default:
			cout << "Неверный ввод!" << endl;
			label2 = true;
			break;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FazzyNumber p1, p2;
	Fraction p3, p4;

	bool flag = true;
	while (flag)
	{
		char mode;
		bool label1 = true;
		while (label1)
		{
			cout << "Выберите режим работы программы: 1)неявные числа, 2)десятичные дроби ";
			cin >> mode;
			switch (mode)
			{
			case '1':
				cout << "1) "; cin >> p1;
				cout << "2) "; cin >> p2;
				operation<FazzyNumber>(p1, p2);
				label1 = false;
				break;
			case '2':
				cout << "1) "; cin >> p3;
				cout << "2) "; cin >> p4;
				operation<Fraction>(p3, p4);
				label1 = false;
				break;
			default:
				cout << "Неверный ввод!" << endl;
				label1 = true;
				break;
			}
		}

		char choice;
		bool label3 = true;
		while (label3)
		{
			cout << "Желаете начать заново или выйти? 1 - заново, 2 - выйти ";
			cin >> choice;
			switch (choice)
			{
			default:
				cout << "Неверный ввод!" << endl;
				label3 = true;
				break;
			case '1':
				flag = true;
				label3 = false;
				break;
			case '2':
				flag = false;
				label3 = false;
				break;
			}
		}
	}
}
