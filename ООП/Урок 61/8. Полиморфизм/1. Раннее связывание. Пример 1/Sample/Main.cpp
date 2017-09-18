#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main()
{
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;

    circle.SetDimension(10.0);
    circle.ShowArea();

    rectangle.SetDimension(5.5, 10.0);
    rectangle.ShowArea();

    triangle.SetDimension(5.5, 10.0);
    triangle.ShowArea();

    return 0;
}