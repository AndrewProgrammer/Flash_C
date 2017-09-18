#include <iostream>

#include "B.h"
#include "C.h"
#include "D.h"

using namespace std;

int main()
{
    D obj(10, 20, 30, 40, 50);

    cout << endl;
    cout << obj.B::GetField() << endl;
    cout << obj.C::GetField() << endl;
    cout << endl;

    return 0;
}