#include "FazzyNumber.h"
#include "Fraction.h"
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool flag = true;
	while (flag)
	{
		Pair* p1 = nullptr;
		Pair* p2 = nullptr;
		char mode, oper;
		bool label1 = true;
		while (label1)
		{
			cout << "Выберите режим работы программы: 1)неявные числа, 2)десятичные дроби ";
			cin >> mode;
			switch (mode)
			{
			case '1':
				p1 = new FazzyNumber;
				p2 = new FazzyNumber;
				p1->input();
				p2->input();
				label1 = false;
				break;
			case '2':
				p1 = new Fraction;
				p2 = new Fraction;
				p1->input();
				p2->input();
				label1 = false;
				break;
			default:
				cout << "Неверный ввод!" << endl;
				label1 = true;
				break;
			}
		}

		bool label2 = true;
		while (label2)
		{
			cout << "Выберите операцию: 1)+, 2)-, 3)*, 4)/, 5)= ";
			cin >> oper;
			switch (oper)
			{
			case '1':
				p1->add(p2);
				label2 = false;
				break;
			case '2':
				p1->sub(p2);
				label2 = false;
				break;
			case '3':
				p1->mul(p2);
				label2 = false;
				break;
			case '4':
				p1->div(p2);
				label2 = false;
				break;
			case '5':
				p1->is_equal(p2);
				label2 = false;
				break;
			default:
				cout << "Неверный ввод!" << endl;
				label2 = true;
				break;
			}
		}
		cout << "Результат: " << p1->print() << endl;
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
