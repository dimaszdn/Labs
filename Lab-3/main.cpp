#include<iostream>

int main()
{
	setlocale(LC_ALL, "RUS");

	int n;
	std::cout << "Введите n (кол-во эл-ов): ";
	std::cin >> n;

	bool firstNumber = true;
	int max = 0, k = -1, pos = 0, pr = 1;

	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;

		if (abs(x) % 10 == 2)
		{
			pr *= x;
			if (firstNumber)
			{
				firstNumber = false;
				max = x;
				pos = i;
			}
			if (x > max)
			{
				max = x;
				pos = i;
			}
		}
	}

	std::cout << "\nПроизведение: " << pr << std::endl;
	std::cout << "Максимальный эл.: " << max << std::endl;
	std::cout << "Номер максимального эл.: " << pos << std::endl;

	return 0;
}