#pragma once
#include <iostream>
using namespace std;
struct Point
{
	double x;
	double y;
};
class Rectangle
{
private:
	Point * Coordinates;
	int n;
	int m_height;
	int m_width;
public:
	Rectangle(Point *xy, int size) 
	{
		Coordinates = new Point[size];
		n = size;
		for (int i = 0; i < size; i++)
		{
			Coordinates[i] = xy[i];
		}
	}
	Rectangle()
	{
		Coordinates = nullptr;
		n = 0;
	}
	Rectangle(Rectangle & f)
	{
		Coordinates = new Point[f.n];
		n = f.n;
		for (int i = 0; i < n; i++)
		{
			Coordinates[i] = f.Coordinates[i];
		}
	}
	friend std::ostream & operator << (std::ostream& os, Rectangle &f)
	{
		for (int i = 0; i < f.n; i++)
		{
			os << f.Coordinates[i].x << " ";
			os << f.Coordinates[i].y;
			os << std::endl;
		}
		return os;
	}
	friend std::istream & operator >> (std::istream& is, Rectangle &f)
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
	virtual ~Rectangle() = default;
	virtual void SetHeight(int h)
	{
		m_height = h;
	}
	virtual void SetWidth(int w)
	{
		m_width = w;
	}
};
class Square : public Rectangle
{
public:
	virtual	void SetHeight(int h)//Позднее связывание.Сигнатура метода( это часть интерфейса).
	{
		Rectangle::SetHeight(h);
		Rectangle::SetHeight(h);
	}
};		
