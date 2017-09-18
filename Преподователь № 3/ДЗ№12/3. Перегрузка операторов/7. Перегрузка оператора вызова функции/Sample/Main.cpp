#include <iostream>

#include "Sum.h"

using namespace std;

int main()
{
    Sum obj1;

    cout << obj1(3, 3) << endl;
    cout << obj1.GetFirst() << " " << obj1.GetSecond() << endl;

    return 0;
}