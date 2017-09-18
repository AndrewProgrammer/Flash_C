#include "Human.h"

int main()
{
    Human humanStatic("Vasya", "Ivanov", 22U);

    Human* humanDynamic = new Human("Petya", "Sidorov", 19U);

    // Вызов деструктора для обьекта humanDynamic.
    delete humanDynamic;

    return 0;
} // Тут вызовется деструктор для обьекта humanStatic.