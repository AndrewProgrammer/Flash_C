#include <iostream>

#include "Foo.h"

using namespace std;

int main()
{
    Foo obj;
    obj.SetValue(100);
    obj.Show();

    cout << obj.GetMutableValue() << endl;

    return 0;
}