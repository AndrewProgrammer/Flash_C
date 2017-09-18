#pragma once

class String
{
private:
    unsigned int m_capacity = 32u;
    unsigned int m_length = 0u;
    char* m_string = nullptr;
public:
    String(const char* const string);
    String(const String& string);
    String(String&& string); // Move ctor.
    ~String();
    String& operator=(const String& right);
    String& operator=(String&& right); // Move assignment oper.

    void Swap(String& string);
};