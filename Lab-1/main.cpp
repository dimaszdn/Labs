#include<iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	
	std::cout << "Введите длину первой стороны: ";
	int a;
	std::cin >> a;

	std::cout << "Введите длину второй стороны: ";
	int b;
	std::cin >> b;

	std::cout << "Введите значение угла: ";
	double angle;
	std::cin >> angle;
	angle = angle * (acos(-1) / 180);

	double S;
	S = 0.5 * a * b * sin(angle);
	std::cout << "S = " << S << std::endl;

	return 0;
}