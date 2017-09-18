#include "TitleBook.h"

#include <iostream>

using namespace std;

void TitleBook::SetTitle(const char* const title)
{
    strcpy_s(m_title, title);
}

void TitleBook::ShowTitle() const
{
    cout << "Title: " << m_title << endl;
}