#include<iostream>

int main()
{
	setlocale(LC_ALL, "RUS");

	const char ABC[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZzyxwvutsrqponmlkjihgfedcba";
	
	char str[100];
	std::cout << "Введите строку: ";
	gets_s(str, 100);
	
	int countLetter = 0;
	for (int letter = 0; letter < strlen(str); letter++)
	{
		for (int i = 0; i < strlen(ABC); i++)
		{
			if (str[letter] == ABC[i])
				countLetter++;
		}
	}

	std::cout << "Кол-во букв в строке следующее: " << countLetter << std::endl;
	
	return 0;
}