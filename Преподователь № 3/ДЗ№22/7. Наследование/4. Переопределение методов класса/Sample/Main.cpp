#include "Base.h"
#include "Derived.h"

int main()
{
    Base base;
    base.SetBase(10);
    base.Show(); // 10.

    Derived derived;
    derived.SetBase(20);
    derived.SetDerived(30);
    derived.Show(); // 20, 30.
    derived.Base::Show(); // 20.
    derived.Derived::Show(); // 20, 30.

    return 0;
}