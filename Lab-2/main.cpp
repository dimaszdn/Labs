#include<iostream>

int main()
{
	setlocale(LC_ALL, "RUS");

	std::cout << "Введите 3 значения: ";
	int a, b, c;
	std::cin >> a >> b >> c;

	if ((a > b) && (b > c))
		std::cout << a - b - c << std::endl;
	else if ((b > a) && (b % c == 0))
		std::cout << (b / c) + (b - a) << std::endl;
	else
		std::cout << a + b + c << std::endl;

	std::cout << "___________________________" << std::endl;

	std::cout << "Введите номер ошибки: ";
	int n;
	std::cin >> n;

	switch (n)
	{
	case 0:
		std::cout << "Всё хорошо!" << std::endl;
		break;
	case 1:
		std::cout << "Ошибка чтения файла!" << std::endl;
		break;
	case 2:
		std::cout << "Ошибка записи файла!" << std::endl;
		break;
	case 3:
		std::cout << "Не все поля определены!" << std::endl;
		break;
	default:
		std::cout << "Такой ошибки не существует!" << std::endl;
		break;
	}

	return 0;
}