#include "stdafx.h"
#include <iostream>
using namespace std;

class MyClock1    // базовый класс
{
protected:         // спецификатор доступа к элементу value
	int HH;
	int MM;
public:
	int GetHH()
	{
		return HH;
	}
	void SetHH(int h)
	{
		HH=h;
	}
	int GetMM()
	{
		return MM;
	}
	void SetMM(int m)
	{
		MM = m;
	}
	MyClock1(int h, int m)//конструктор с параметрами
	{
		HH = h;
		MM = m;
	}
	MyClock1()//конструктор по умолчанию
	{
		HH = 0;
		MM = 0;
	}

	MyClock1(MyClock1* a)//конструктор копирования
	{
		this->HH = a->HH;
		this->MM = a->MM;
	}
	void Print()
	{
		cout << HH << ":" << MM << endl;
	}
};

class MyClock2 : public MyClock1   // производный класс
{
private:
	int SS;
public:
	MyClock2(int h, int m, int s) : MyClock1(h, m)   // inputS передается в конструктор с параметром класса FirstClass
	{
		SS = s;
	}

	void Print() //полиморфизм
	{
		cout << HH << ":" << MM << ":" << SS << endl;
	}
};


int main()
{
	MyClock1 cl(12, 30);
	cl.Print();
	MyClock2 cl2(12, 30, 20);
	cl2.Print();
	system("pause");
	return 0;
}