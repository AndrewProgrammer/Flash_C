#include <iostream>

#include "Base.h"
#include "Derived.h"

using namespace std;

int main()
{
    Base base;
    base.m_privateBase = 1;
    base.m_protectedBase = 2;
    base.m_publicBase = 3;
    base.SetBase(10, 20, 30);
    base.ShowBase();

    Derived derived;
    derived.m_privateBase = 1;
    derived.m_protectedBase = 2;
    derived.m_publicBase = 3;
    derived.m_privateBase = 4;
    derived.SetBase(10, 20, 30);
    derived.SetDerived(40);
    derived.ShowDerived();

    return 0;
}