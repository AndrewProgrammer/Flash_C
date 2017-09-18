#include "Derived.h"

int main()
{
    Derived obj;

    // Ошибка: нет прав доступа.
    //obj.SetBase(10, 20);

    obj.SetDerived(30);
    obj.ShowBase();
    obj.ShowDerived();

    obj.m_publicBase = 20;

    return 0;
}