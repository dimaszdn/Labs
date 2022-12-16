//2 ЗАДАНИЕ
#include<iostream>

int main()
{
	setlocale(LC_ALL, "RUS");

	const int N = 1000;
	int mas[N], composition[N], firstDigit[N];
	
	int n;
	std::cout << "Введите кол-во n: ";
	std::cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		//Создание массива
		int pr = 1;
		std::cin >> mas[i];
		
		int tmp1 = mas[i];
		//Произведение цифр числа
		while (tmp1 > 0)
		{
			int digit = tmp1 % 10;
			pr *= digit;
			tmp1 /= 10;
		}
		composition[i] = pr;

		//Первая цифра числа
		int tmp2 = mas[i];
		while (tmp2 > 9)
			tmp2 /= 10;
		firstDigit[i] = tmp2;
	}

	//Сортировка
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//1 условие
			if (composition[i] > composition[j])
			{
				std::swap(mas[i], mas[j]);
				std::swap(composition[i], composition[j]);
				std::swap(firstDigit[i], firstDigit[j]);
			}

			//2 условие
			else if ((composition[i] == composition[j]))
			{
				if (firstDigit[i] > firstDigit[j])
				{
					std::swap(mas[i], mas[j]);
					std::swap(firstDigit[i], firstDigit[j]);
					std::swap(composition[i], composition[j]);
				}
			}

			//3 условие
			else if ((composition[i] == composition[j]) &&
				(firstDigit[i] == firstDigit[j]))
			{
				if (mas[i] > mas[j])
				{
					std::swap(mas[i], mas[j]);
					std::swap(firstDigit[i], firstDigit[j]);
					std::swap(composition[i], composition[j]);
				}
			}
		}
	}

	std::cout << std::endl << "Отсортированный массив: ";
		
	//Вывод
	for (int i = 0; i < n; i++)
		std::cout << mas[i] << " ";
	std::cout << std::endl;
	
	return 0;
}