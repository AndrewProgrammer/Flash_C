#pragma once
#include <valarray>
#include <iostream>
using namespace std;
struct Point
{
	double x;
	double y;
};
class Figura
{
private:
	Point * Coordinates;
	int n;
public:
	virtual double Area() = 0;
	Figura(Point *xy, int size)
	{
		Coordinates = new Point[size];
		n = size;
		for (int i = 0; i < size; i++)
		{
			Coordinates[i] = xy[i];
		}
	}
	Figura()
	{
		Coordinates = nullptr;
		n = 0;
	}
	Figura(Figura & f)
	{
		Coordinates = new Point[f.n];
		n = f.n;
		for (int i = 0; i < n; i++)
		{
			Coordinates[i] = f.Coordinates[i];
		}
	}
	friend std::ostream & operator << (std::ostream& os, Figura &f)
	{
		for (int i = 0; i < f.n; i++)
		{
			os << f.Coordinates[i].x << " ";
			os << f.Coordinates[i].y;
			os << std::endl;
		}
		return os;
	}
	friend std::istream & operator >> (std::istream& is, Figura &f)
	{
		cout << "Введите кол-во точек в фигуре: ";
		is >> f.n;
		f.Coordinates = new Point[f.n];
		for (int i = 0; i < f.n; i++)
		{
			cout << "Введите " << i + 1 << " point:\n";
			cout << "x: ";
			is >> f.Coordinates[i].x;
			cout << "y: ";
			is >> f.Coordinates[i].y;
		}
		return is;
	}
	double distance(int i1, int i2)
	{
		double x1, y1, x2, y2;
		x1 = Coordinates[i1].x;
		y1 = Coordinates[i1].y;
		x2 = Coordinates[i2].x;
		y2 = Coordinates[i2].y;
		return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));//Теорема пифагора
	}
	Point & operator[](int i)
	{
		return Coordinates[i];
	}
	~Figura(void)
	{
		delete[] Coordinates;
	}
	virtual ~Figura() = default;
};
class Circle : public Figura
{
private:
	double radius;
public:
	Circle(Point&p, double rad) : Figura(&p, 1), radius(rad){};
	Circle(Figura& f) : Figura(f)
	{
		radius = f.distance(0,1);
	};
	Circle() :Figura(), radius(0){};
	virtual double Area() override
	{
		return radius*radius * 3.1459;
	}
	double Radius()
	{
		return radius;
	}
};
class Elipc : public Figura
{
private:
	double bigaxis;
	double smalaxis;
	const double pi = 3.1459;
public:
	Elipc(Point&p, double bigaxis, double smalaxis) : Figura(&p, 1), bigaxis(bigaxis), smalaxis(smalaxis){};
	Elipc(Figura& f) : Figura(f)
	{
		bigaxis = f.distance(1, 1);
		smalaxis = f.distance(2, 2);
	};
	Elipc() :Figura(), bigaxis(0), smalaxis(0){};
	virtual double Area() override
	{
		return smalaxis*bigaxis * pi;
	}
};
class Rectangle :public Figura
{
private:
	double a;
	double b;
public:
	Rectangle(Figura& f) :Figura(f)
	{
		a = f.distance(0, 1);
		b = f.distance(1, 2);
	}
	Rectangle() :Figura(), a(0), b(0){}
	virtual double Area() override
	{
		return a*b;
	}
};
class Square : public Figura
{
private:
	double a;
public:
	Square(Figura & s) : Figura(s)
	{
		a = s.distance(0, 1);
	}
	Square(): Figura(), a(0){}
	virtual double Area() override
	{
		return a*a;
	}
};