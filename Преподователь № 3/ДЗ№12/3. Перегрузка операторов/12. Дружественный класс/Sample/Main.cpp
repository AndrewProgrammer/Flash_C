#include "Point.h"
#include "Rectangle.h"

int main()
{
    Rectangle rectangle(Point(10, 10), Point(30, 50));
    rectangle.Show();

    rectangle(Point(5, 5), Point(30, 70));
    rectangle.Show();

    return 0;
}