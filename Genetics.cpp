#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

class Parent
{
protected:
	string f, m;
	int c[4];
public:
	void input()
	{

		std::cout << "Enter fathers' genes : " << f;
		std::cin >> f;

		std::cout << "Enter mothers' genes  : " << m;
		std::cin >> m;

		for (int i = 0; i < 4; i++)
		{
			c[i] = 0;
		}
	}
	void check(string z)
	{
		if (z == "AO" || z == "AA" || z == "OA")
			c[0]++;
		else if (z == "BO" || z == "BB" || z == "OB")
			c[1]++;
		else if (z == "AB" || z == "BA")
			c[2]++;
		else
			c[3]++;
	}
};

class offspring:public Parent
{
protected:
	string fo, mo;
public:
	void initialize()
	{
		fo = f;
		mo = m;
	}
	void assign()
	{
		int l = 1;

		if (l == 1)
			swap(f[0], m[0]);
			check(f);
			l++;
		if (l == 2)
			swap(f[0], m[1]);
			check(f);
			l++;
		f = fo;
		m = mo;
		if (l == 3)
			swap(m[0], f[0]);
			check(m);
			l++;
		if (l == 4)
			swap(m[1], f[0]);
			check(m);

	}

};

class result:public offspring
{
public:
	void finalize()
	{

		std::cout << "" << std::endl;

		std::cout << "You may have the following blood groups ";
		
		std::cout << "" << std::endl;
		
		for (int i = 0; i < 2; i++)
		{
			Sleep((i + 1) * 1000);
			for (int j = 0; j < i; j++)
			{
				std::cout << "." << std::endl;
			}
		}
		
		
		if (c[0] > 0)
			std::cout << "A Blood group" << std::endl;
		if (c[1] > 0)
			std::cout << "B Blood group" << std::endl;
		if (c[2] > 0)
			std::cout << "AB Blood group" << std::endl;
		if (c[3] > 0)
			std::cout << "O Blood group" << std::endl;
	}
};

int main()

{
	result n1;
	n1.input();
	n1.initialize();
	n1.assign();
	n1.finalize();
}
