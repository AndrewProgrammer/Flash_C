#pragma once

class Base
{
private:
    int m_privateBase;

public:
    int m_publicBase;

    Base();
    void SetBase(const int privateValue, const int publicValue);
    void ShowBase() const;
};