#include <iostream>

#include "String.h"

using namespace std;

int main()
{
    String a;
    String b;
    String c;

    cout << "Input the first part of String: ";
    cin >> a;
    cout << "Input the second part of String: ";
    cin >> b;
    // Использывались неявные вызовы функций operator>>(cin, a) и operator>>(cin, b).

    // Вызов конструктора преобразования для строки "\nThat's all!\n".
    c = a + b + "\nThat's all!\n";

    // Вывод результирующей строки. Неявный вызов функции operator<<(cout, c)
    cout << c;

    a = b = c;

    cout << a << b;

    return 0;
}