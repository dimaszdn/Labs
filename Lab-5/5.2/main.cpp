#include<iostream>
#include<string>
#include<fstream>


int main()
{
	setlocale(LC_ALL, "RUS");
	
	std::string volwes = "AEIOUYaeiouy";
	std::string consonants = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	std::string signs = ".,?!-";

	const int N = 100;
	std::string words[N];
	int len[N];

	std::ifstream fin("input.txt", std::ios::in);
	std::ofstream fout("output.txt", std::ios::out);

	std::string str;
	int countWord = 0;
	int k = 0;
	if (!fin.is_open())
	{
		std::cout << "Не удалось открыть файл!" << std::endl;
	}
	else
	{
		std::cout << "Файл успешно открыт!" << std::endl << std::endl;

		while (!fin.eof())
		{
			for (int i = 0; i < N; i++)
			{
				str = "";
				fin >> str;
				int countVolwe = 0, countCons = 0;
				std::string word = "";
				//Переводим в нижний регистр и считаем кол-во гласных и согласных
				for (char letter = 0; letter < str.size(); letter++)
				{
					for (int volwe = 0; volwe < volwes.size(); volwe++)
					{
						if (volwes[volwe] == str[letter])
							countVolwe++;
					}
					for (int consonant = 0; consonant < consonants.size(); consonant++)
					{
						if (consonants[consonant] == str[letter])
							countCons++;
					}
					word += (char)tolower(str[letter]);
				}
				//Убираем знаки препинания
				for (int sign = word.size() - 1; sign >= 0; sign--)
				{
					for (int y = 0; y < signs.size(); y++)
					{
						if (word[sign] == signs[y])
							word.erase(sign, 1);
					}
				}
				//Проверяем не содержится ли уже слово в массиве
				bool word_empty = true;
				for (int x = 0; x < N; x++)
				{
					if (word == words[x])
					{
						word_empty = false;
						k++;
					}
				}
				if (word_empty) //Если не содержится, то проверяем на условие и записываем
				{
					if (countCons != 0 && countVolwe != 0 && (countCons == countVolwe))
					{
						countWord++;
						words[i - k] = word;
						len[i - k] = word.size();

					}
					else
						k++;
				}
			}
		}
	}
	fin.close();
	
	//Сортировка по убыванию
	for (int i = 0; i < countWord; i++)
	{
		for (int j = i + 1; j < countWord; j++)
		{
			if (len[i] < len[j])
			{
				std::swap(words[i], words[j]);
				std::swap(len[i], len[j]);
			}
		}
	}
	
	std::cout << "Слова успешно записаны! Проверьте файл output." << std::endl;

	for (int i = 0; i < countWord; i++)
		fout << words[i] << std::endl;
	fout.close();

	return 0;
}
