#include "A.h"
#include "B.h"
#include "C.h"

int main()
{
    C obj(10, 20, 30);

    obj.Show();
    obj.A::Show();
    obj.B::Show();

    return 0;
}