/*программа почему первой строчкой пишет :
Введите выражение (поддерживаемые оперции: '+', '-', '*'): Результат: 0
и я не знаю как это исправить, поэтому сделано через костыль, так сказать (94 строчка)
 */

#include <iostream>

using namespace std;

int search() 
{
	int res = 0;

	while (1)
	{
		char a = cin.get();
		if (a >= '0' && a <= '9')
			res = res * 10 + a - '0';
		else 
		{
			cin.putback(a);
			return res;
		}
	}
}

int multiplication() 
{	
	int x  = search();

	while (1)
	{
		char a = cin.get();
		switch (a)
		{
			case '*':
				x *= search();
				break;

			default:
				cin.putback(a);
				return x;
		}
	}
}

int plus_and_minus() 
{
	int x = multiplication();
	while (1) 
	{
		char a = cin.get();
		switch (a) 
		{
			case '+':
				x += multiplication();

				break;
			case '-':
				x -= multiplication();
				break;

			default:
				cin.putback(a);
				return x;
		}
	}
}

void Task()
{
	int res;

	cout << "Введите выражение (поддерживаемые оперции: '+', '-', '*'): ";

	res = plus_and_minus();

	cout << "Результат: " << res << endl;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void menu()
{
	while (1)
	{
		float check;

		cout << "1 - выполнить программу;" << endl << "0 - закрыть программу;" << endl << "Введите число для выбора действия: ";
		cin >> check;

		if (check == 1) for (int i = 0; i < 2; i++) Task(); //здесь программа вызывается два раза и поэто первый уходит как раз под мою проблему, а второй уже на решение самой задачи
		else if (check == 0) break;
		else cout << "Введенно не коректное значение" << endl;
	}
}

int main()
{
	setlocale(0, "");
	menu();
}