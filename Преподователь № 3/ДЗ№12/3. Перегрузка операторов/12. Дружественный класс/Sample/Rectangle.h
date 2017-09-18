#pragma once

#include "Point.h"

class Rectangle
{
private:
    int m_bottom;
    int m_left;
    int m_right;
    int m_top;

public:
    Rectangle();
    Rectangle(const Point& left, const Point& right);

    Rectangle& operator()(const Point& left, const Point& right);

    void Show();
};