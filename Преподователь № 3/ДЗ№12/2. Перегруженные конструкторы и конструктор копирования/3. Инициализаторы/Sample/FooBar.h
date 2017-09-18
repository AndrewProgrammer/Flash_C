#pragma once

class FooBar
{
private:
    char m_characterValue;
    double m_floatingValue;
    int m_integerValue;

public:
    FooBar(const int integerValue, const double floatingValue, const char characterValue);

    void Show();
};