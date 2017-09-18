#include "Rectangle.h"

#include <iostream>

using namespace std;

Rectangle::Rectangle() : m_bottom(0), m_left(0), m_right(0), m_top(0)
{
}

Rectangle::Rectangle(const Point& left, const Point& right) : m_bottom(right.m_y), m_left(left.m_x), m_right(right.m_x), m_top(left.m_y)
{
}

Rectangle& Rectangle::operator()(const Point& left, const Point& right)
{
    m_bottom = right.m_y;
    m_left = left.m_x;
    m_right = right.m_x;
    m_top = left.m_y;

    return *this;
}

void Rectangle::Show()
{
    cout << "Left: " << m_left << endl;
    cout << "Top: " << m_top << endl;
    cout << "Right: " << m_right << endl;
    cout << "Bottom: " << m_bottom << endl;
    cout << endl;
}