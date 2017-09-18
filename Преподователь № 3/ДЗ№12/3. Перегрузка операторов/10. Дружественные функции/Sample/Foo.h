#pragma once

class Foo
{
private:
    int m_data;

public:
    Foo(const int data);

    friend void FriendFunction(Foo& obj);
};