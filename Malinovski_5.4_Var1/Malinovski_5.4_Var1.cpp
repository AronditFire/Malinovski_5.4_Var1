#include <iostream>
#include <cstdlib> // malloc, realloc
#include <windows.h>
#include <sstream>

using namespace std;

bool isInt(const string& str)
{
	istringstream check_is_Int(str);
	int num;
	return (check_is_Int >> num) && (check_is_Int.eof());
}

int GetInput()
{
	string input = " ";
	while (true)
	{
		if (input != "")
		{
			cout << "Введите число: ";
		}

		getline(cin, input);

		if (input != "")
		{
			if (isInt(input) && stoi(input) >= 0)
			{
				return stoi(input);
			}
			else
			{
				cout << "Ошибка! Введите число верно!\n\n";
			}
		}

	}
}

void DeleteSymbolFromPosition(char* str, int &position, int &amount, int &length)
{
	int temp;
	if (position > length - 1)
	{
		cout << str << endl;
		return void();
	}

	if (amount > (length - 1 - position))
	{
		amount = length - 1 - position;
	}

	for (int i = position; i < length; i++)
	{
		if (str[i + amount] == '\0')
		{
			str[i] = '\0';
			length = i;
			break;
		}
		str[i] = str[i + amount];
	}
	str = (char*)realloc(str, (length + 1) * sizeof(char));
	cout << str << endl;
}

int main()
{
	setlocale(LC_CTYPE, "RU");

	int size = 100;
	int index = 0;

	char* str = (char*)malloc(size * sizeof(char)); // выделяем память 100 byte

	cout << "Введите строку: " << endl;

	char ch;

	SetConsoleCP(1251); // меняем кодировку для считывания русских символов
	while ((ch = cin.get()) != '\n' && ch != EOF) // cin.get() для посимвольного ввода до перехода на след. строку
	{
		str[index++] = ch;

		if (index >= size - 1)
		{
			size *= 2;
			str = (char*)realloc(str, size * sizeof(char)); // увеличивает в 2 раза с копированием
		
		}		
	}
	

	str[index] = '\0';

	int length = strlen(str);
	int position{}, amount{};
		
	cout << "С какой позиции удалять символы?\n";
	position = GetInput();
	cout << "Сколько символов удалить?\n";
	amount = GetInput();

	DeleteSymbolFromPosition(str, position, amount, length);

	SetConsoleCP(866);

	free(str); // освобождаем память 
	return 0;
}