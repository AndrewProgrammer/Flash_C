#pragma once

class AuthorBook
{
private:
    char m_author[80];

public:
    void SetAuthor(const char* const author);

    void ShowAuthor() const;
};