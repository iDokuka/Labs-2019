#include "stdafx.h"
#include <iostream>
using namespace std;

class MyClock1    // bazovyj klass
{
protected:         // specifikator dostupa k elementu value
	int HH;
	int MM;
public:
	static int CountDaysInYear()
	{
		return 365;
	}
	int GetHH()
	{
		return HH;
	}
	void SetHH(int h)
	{
		HH = h;
	}
	int GetMM()
	{
		return MM;
	}
	void SetMM(int m)
	{
		MM = m;
	}
	MyClock1(int h, int m)//konstruktor s parametrami
	{
		HH = h;
		MM = m;
	}
	MyClock1()//konstruktor po umolchaniyu
	{
		HH = 0;
		MM = 0;
	}

	MyClock1(MyClock1* a)//konstruktor kopirovaniya
	{
		this->HH = a->HH;
		this->MM = a->MM;
	}
	~MyClock1()
	{
		cout <<"Proizoshlo udalenie obekta" << endl;
	}
	virtual void Print()
	{
		cout << HH << ":" << MM << endl;
	}
	virtual void func() = 0;
	// druzhestvennost'
	friend class Display;
	friend std::ostream& operator<< (std::ostream &out, const MyClock1 &dd);
	friend std::istream& operator >> (std::istream &in, MyClock1 &dd);

	// Peregruzka operatora prisvaivaniya
	MyClock1& operator= (const MyClock1 &dd)
	{
		// vypolnyaem kopirovanie znachenij
		HH = dd.HH;
		MM = dd.MM;
		// vozvrashchaem tekushchij oekt, chtoby my mogli svyazat' v cepochku vypolnenie neskol'kih operacij prisvaivaniya
		return *this;
	}
	class InClass;
};

class MyClock1::InClass { //opisanie vlozhennogo klassa

};

ostream& operator<< (std::ostream &out, const MyClock1 &d)
{
	out << d.HH << ":" << d.MM;

	return out;
}


std::istream& operator >> (std::istream &in, MyClock1 &dd)
{
	in >> dd.HH;
	in >> dd.MM;
	return in;
}

class Display
{

public:
	static void Print(MyClock1 &v)
	{
		cout << v.HH << ":" << v.MM << endl;
	}
};
class MyClock2 : public MyClock1   // proizvodnyj klass
{
private:
	int SS;
public:
	MyClock2(int h, int m, int s) : MyClock1(h, m)   // inputS peredaetsya v konstruktor s parametrom klassa FirstClass
	{
		SS = s;
	}

	void Print() //polimorfizm
	{
		cout << HH << ":" << MM << ":" << SS << endl;
	}

	void func()
	{

	}
};


int main()
{
	MyClock2 cl(12, 30, 45);
	MyClock1 vv;
	//vvod
	cin >> vv;
	//vyvod
	cout << vv;
	Display::Print(cl);
	cl.Print();
	MyClock2 cl2(12, 30, 20);
	cl2.Print();
	system("pause");
	return 0;
}