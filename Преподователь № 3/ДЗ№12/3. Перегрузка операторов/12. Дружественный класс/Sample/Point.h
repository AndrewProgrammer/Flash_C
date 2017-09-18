#pragma once

class Rectangle;

class Point
{
    friend class Rectangle;

private:
    int m_x;
    int m_y;

public:
    Point();
    Point(const int x, int y);
};