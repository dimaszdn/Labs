#include<iostream>
#define N 4

int main()
{
	setlocale(LC_ALL, "RUS");

	std::cout << "Введите число: ";
	int a;
	std::cin >> a;

	char* p; //Создадим указатель
	p = (char*)&a; //Поместим в указатель ссылку на a, причём приведём к типу char*
	unsigned char mas[N]; //Создадим массив, куда будем помещать байты
	int k = 0, i = 0;
	while (k < N)
	{
		mas[i] = *(p + i);
		i++;
		k++;
	}
	for (int x = 0; x < N; x++)
	{
		std::cout << static_cast<int>(mas[x]) << " ";
	}
	std::cout << std::endl;
	//Соберём число по байтам и проверем на правильность
	std::cout << *((int*)mas) << std::endl;
	return 0;
}