#include "AuthorBook.h"

#include <iostream>

using namespace std;

void AuthorBook::SetAuthor(const char* const author)
{
    strcpy_s(m_author, author);
}

void AuthorBook::ShowAuthor() const
{
    cout << "Author: " << m_author << endl;
}