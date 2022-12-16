//ЗАДАНИЕ 1
#include<iostream>

int main()
{
	setlocale(LC_ALL, "RUS");

	const int N = 10000;
	srand(time(0));
	int n, mas[N];
	std::cout << "Введите n: ";
	std::cin >> n;

	//Дабы избежать проблем с выходом за границы
	if (n <= 10000)
	{
		//Создание и вывод исходного
		for (int i = 0; i < n; i++)
		{
			mas[i] = rand() % 100;
			std::cout << mas[i] << " ";
		}
		std::cout << std::endl << std::endl;

		//Если есть простое число, то сортируем
		for (int i = 0; i < n; i++)
		{
			bool isPrime = true;
			for (int d = 2; d <= sqrt(mas[i]); d++)
			{
				if (mas[i] % d == 0)
				{
					isPrime = false;
					break;
				}
			}

			if (isPrime)
			{
				std::cout << "Простое число: " << mas[i] << std::endl;
				for (int i = 0; i < n; i++)
				{
					for (int j = i + 1; j < n; j++)
					{
						if (mas[i] > mas[j])
						{
							std::swap(mas[i], mas[j]);
						}
					}
				}
				break;
			}
		}

		//Вывод
		for (int i = 0; i < n; i++)
			std::cout << mas[i] << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "\nНет такого количества места" << std::endl;
	}
	return 0;
}