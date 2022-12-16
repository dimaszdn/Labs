#include<iostream>

class Parallelogram
{
private:
	unsigned int m_side;
	unsigned int m_base;

public:
	
	Parallelogram()
	{
		m_side = 0;
		m_base = 0;
	}
	~Parallelogram()
	{

	}

	void setSide(int side)
	{
		if (side > 0)
			m_side = side;
		else
			std::cout << "Сторона не может быть отрицательной!" << std::endl;
	}

	void setBase(int base)
	{
		if (base > 0)
			m_base = base;
		else
			std::cout << "Основание не может быть отрицательным!" << std::endl;
	}

	int perimetr()
	{
		return 2 * (m_side + m_base);
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	
	Parallelogram p;
	p.setSide(-70);
	p.setBase(-1);
	std::cout << "P = " << p.perimetr() << std::endl;
	
	return 0;
}