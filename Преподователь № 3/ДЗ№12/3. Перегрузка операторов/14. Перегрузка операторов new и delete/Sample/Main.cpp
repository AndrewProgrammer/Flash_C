#include "Foo.h"

int main()
{
    Foo* obj = new Foo;
    Foo* array = new Foo[5];

    array[2].Show();

    delete[] array;
    delete obj;

    return 0;
}