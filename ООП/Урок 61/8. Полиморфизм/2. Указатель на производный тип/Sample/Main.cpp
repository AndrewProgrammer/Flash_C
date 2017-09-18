#include <iostream>

#include "AuthorBook.h"
#include "TitleBook.h"

int main()
{
    AuthorBook* ptr1 = nullptr;
    TitleBook* ptr2 = nullptr;

    AuthorBook obj1;
    TitleBook obj2;

    ptr1 = &obj1;
    ptr1->SetAuthor("Ira Pohl");

    ptr1 = &obj2;
    ptr1->SetAuthor("Herbert Shildt");

    obj1.ShowAuthor();
    obj2.ShowAuthor();

    ptr2 = &obj2;
    ptr2->SetTitle("C++ from the Ground Up");
    ptr2->ShowAuthor();

    ((TitleBook*)ptr1)->ShowTitle();
    ptr2->ShowTitle();

    return 0;
}