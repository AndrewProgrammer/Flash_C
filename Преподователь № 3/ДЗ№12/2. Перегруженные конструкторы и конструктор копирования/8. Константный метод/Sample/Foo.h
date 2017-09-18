#pragma once

class Foo
{
private:
    int m_value;

public:
    Foo();

    int GetValue() const;
    void SetValue(const int value);
    void Show() const;
};