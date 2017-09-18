#pragma once

#include "Base.h"

class Derived : public Base
{
private:
    char* m_bufferB;

    void Assign(const char* const string);

public:
    Derived();
    Derived(const Derived& obj);
    Derived(const char* const stringA, const char* const stringB);

    virtual ~Derived();

    Derived& operator=(const Derived& right);

    void Show() const;
};