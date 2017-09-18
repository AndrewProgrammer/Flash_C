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
	virtual double Area() = 0;//Работаем только через указатель так как абстрактный метод
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
	Circle(double rad)
	{
		radius = rad;
	}
	Circle() : Figura(), radius(0){};
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
	Elipc(double  BigAxis, double SmalAxis)
	{
		bigaxis = BigAxis;
		smalaxis = SmalAxis;
	}
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
	Rectangle(double Aside, double Bside)
	{
		a = Aside;
		b = Bside;
	}
	Rectangle() :Figura(), a(0), b(0){};
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
	Square() : Figura(), a(0){};
	Square(double lenght)
	{
		a = lenght;
	}
	virtual double Area() override
	{
		return a*a;
	}
};
class Triangle: public Figura
{
private:
	double a, b, c, S;
public:
	Triangle(Figura & t) : Figura(t)
	{
		a = t.distance(0, 1);
		b = t.distance(1, 2);
		c = t.distance(2, 3);
	}
	Triangle(double Aside , double Bside, double Cside)
	{
		a = Aside;
		b = Bside;
		c = Cside;
	}
	Triangle() : Figura(), a(0), b(0), c(0),S(0){};
	virtual double Area() override
	{
		const double p = (a + b + c) / 2.0;
		return S = sqrt(p*(p - a)*(p - b)*(p - c));
	}
};
class RectangularTriangle : public Figura
{
private :
	double a, b, c, S;
public:
	RectangularTriangle(Figura& rt) : Figura(rt)
	{
		a = rt.distance(0, 1);
		b = rt.distance(2, 2);
		c = rt.distance(3, 3);
	}
	RectangularTriangle(double Aside, double Bside, double Cside)
	{
		a = Aside;
		b = Bside;
		c = Cside;
	}
	RectangularTriangle() : Figura(), a(0), b(0), c(0), S(0){};
	virtual double Area() override
	{
		return S = a*b / 2;
	}
};
