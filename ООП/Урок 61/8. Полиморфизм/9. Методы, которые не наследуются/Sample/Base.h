#pragma once

class Base
{
private:
    char* m_bufferA;

    void Assign(const char* const string);

public:
    Base();
    Base(const Base& obj);
    Base(const char* const string);

    virtual ~Base();

    Base& operator=(const Base& right);

    void Show() const;
};