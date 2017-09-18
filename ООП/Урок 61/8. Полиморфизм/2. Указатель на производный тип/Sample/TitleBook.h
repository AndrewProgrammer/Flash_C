#pragma once

#include "AuthorBook.h"

class TitleBook : public AuthorBook
{
private:
    char m_title[80];

public:
    void SetTitle(const char* const title);

    void ShowTitle() const;
};