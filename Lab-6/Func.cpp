#include "Func.hpp"
#include <fstream>
#include<string>

namespace ch
{
	int sizeMatrix(int n)
	{
		std::ifstream fin("input.txt", std::ios::in);
		while (!fin.eof())
		{
			std::string str;
			std::getline(fin, str);
			n++;
		}
		fin.close();
		return n;
	}

	void readingFile(int m[][100])
	{
		std::ifstream fin("input.txt", std::ios::in);
		int x = 0, y = 0;
		while (!fin.eof())
		{
			std::string number = "";
			std::getline(fin, number);

			y = 0;
			int i = 0;
			std::string tmp = "";
			while (i < number.length())
			{
				if (number[i] == ' ')
				{
					m[x][y] = std::stoi(tmp);
					y++;
					tmp = "";
				}
				else
					tmp += number[i];
				i++;
			}
			m[x][y] = std::stoi(tmp);
			y++;
			x++;
		}
		fin.close();
	}

	int sumDigit(int n)
	{
		int sum = 0;
		while (abs(n) > 0)
		{
			sum += abs(n) % 10;
			n = abs(n) / 10;
		}
		return sum;
	}

	bool difference(int matrix[][100], int countStr)
	{
		bool firstNumber = true;
		int max = 0, min = 0;
		for (int i = 0; i < countStr; i++)
		{
			for (int j = 0; j < countStr; j++)
			{
				if (firstNumber)
				{
					firstNumber = false;
					max = matrix[i][j];
					min = matrix[i][j];
				}

				if (matrix[i][j] > max)
					max = matrix[i][j];

				if (matrix[i][j] < min)
					min = matrix[i][j];
			}
		}
		if (sumDigit(max) - sumDigit(min) <= 2)
			return true;
		else
			return false;
	}

	void sortMatrix(int matrix[][100], int countStr)
	{
		if (difference(matrix, countStr))
		{
			//Массив суммы чисел столбцов
			int sumEl[100];
			for (int col = 0; col < countStr; col++)
			{
				int sum = 0;
				for (int row = 0; row < countStr; row++)
				{
					sum += matrix[row][col];
				}
				sumEl[col] = sum;
			}

			//Изменённая матрица, где элементы увеличены на сумму столбца
			for (int x = 0; x < countStr; x++)
			{
				for (int y = 0; y < countStr; y++)
				{
					matrix[x][y] = matrix[x][y] + sumEl[y];
				}
			}

			//Сортировка матрицы
			for (int i = 0; i < countStr; i++)
			{
				for (int j = 0; j < countStr; j++)
				{
					for (int o = 0; o < countStr - 1; o++)
					{
						if (matrix[i][o] > matrix[i][o + 1])
						{
							int tmp = matrix[i][o];
							matrix[i][o] = matrix[i][o + 1];
							matrix[i][o + 1] = tmp;
						}

					}
				}

			}

			//Сортировка массива с суммами элементов столбца
			for (int i = 0; i < countStr; i++)
			{
				for (int j = i + 1; j < countStr; j++)
				{
					if (sumEl[i] > sumEl[j])
						std::swap(sumEl[i], sumEl[j]);
				}
			}

			//Вычитаем из элементов матрицы суммы столбцов соответ. и получаем отсортированную матрицу
			for (int x = 0; x < countStr; x++)
			{
				for (int y = 0; y < countStr; y++)
				{
					matrix[x][y] = matrix[x][y] - sumEl[y];
				}
			}
		}
	}

	void output(int matrix[][100], int countStr)
	{
		std::ofstream fout("output.txt", std::ios::out);
		for (int row = 0; row < countStr; row++)
		{
			for (int col = 0; col < countStr; col++)
			{
				fout << matrix[row][col] << "\t";
			}
			fout << "\n";
		}
	}
}
