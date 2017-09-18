#include "Base.h"
#include "Derived.h"

int main()
{
    Base base;
    base.Set();
    base.Show(); // 10.

    Derived derived;
    // Ошибка: метод Set() замещен в классе Derived.
    //derived.Set();
    derived.Set(50);
    derived.Show(); // 50.
    derived.Base::Set();
    derived.Derived::Set(30);

    return 0;
}