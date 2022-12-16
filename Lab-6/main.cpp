#include<iostream>
#include "Func.hpp"
#include <fstream>
#include<string>

int main()
{
	setlocale(LC_ALL, "RUS");

	int n = 0;
	int countStr = ch::sizeMatrix(n);

	int matrix[100][100], sumElement[100];
	ch::readingFile(matrix);
	
	ch::sortMatrix(matrix, countStr);
	
	std::cout << "Матрица успешно отсортирована и записана в файл!" << std::endl;
	ch::output(matrix, countStr);

	return 0;
}