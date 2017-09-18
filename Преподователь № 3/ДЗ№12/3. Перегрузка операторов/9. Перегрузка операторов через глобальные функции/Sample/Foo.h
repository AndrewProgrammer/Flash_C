#pragma once

class Foo
{
private:
    int m_data;

public:
    Foo(const int data);

    //Foo operator+(Foo obj) const;

    int GetData() const;
    void Show();
};

Foo operator+(const Foo obj1, const Foo obj2);