//ЗАДАНИЕ 3
#include<iostream>

int main()
{
	setlocale(LC_ALL, "RUS");

	const int N = 100;
	int matrix[N][N];
	srand(time(0));

	std::cout << "Введите кол-во строчек n: ";
	int n;
	std::cin >> n;
	std::cout << "Введите кол-во столбцов m: ";
	int m;
	std::cin >> m;

	int min = INT_MAX, minString = INT_MAX;
	std::cout << "\nИсходная матрица" << std::endl;

	//Дабы избежать проблем с выходом за границу
	if ((n <= 100) && (m <= 100))
	{
		for (int i = 0; i < n; i++)
		{
			int count = 0;
			for (int j = 0; j < m; j++)
			{
				//Создание матрицы и вывод
				matrix[i][j] = rand() % 100;
				std::cout << matrix[i][j] << " ";

				//Условие
				if (abs(matrix[i][j]) % 2 == 0)
					count++;
			}
			
			//Ищем строку содержащую min чётных эл.
			if (min > count)
			{
				min = count;
				minString = i;
			}
			std::cout << "|" << count << std::endl;
		}

		std::cout << "\nМинимальная такая строка: ";
		std::cout << minString << std::endl;

		//Замена
		for (int j = 0; j < m; j++)
			matrix[minString][j] = matrix[minString][j] * matrix[minString][j];

		std::cout << "\nПреобразованная матрица" << std::endl;

		//Вывод
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cout << matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else
		std::cout << "Нет такого кол-ва места" << std::endl;
	
	return 0;
}