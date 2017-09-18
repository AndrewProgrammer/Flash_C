#include "Foo.h"
#include "UniquePointer.h"

#include "DefaultDeleter.h"

int main()
{
    UniquePointer<Foo> p1(new Foo);
    UniquePointer<Foo[]> p2(new Foo[5]);

    p1->F();
    p2->F();

    Foo* ptr = new Foo[2];
    DefaultDeleter<Foo[]> deleter;
    ptr->F();

    deleter(ptr);

    return 0;
}