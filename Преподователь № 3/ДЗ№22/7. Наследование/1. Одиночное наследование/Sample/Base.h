#pragma once

class Base
{
private:
    int m_privateBase;

protected:
    int m_protectedBase;

public:
    int m_publicBase;

    void SetBase(const int privateValue, const int protectedValue, const int publicValue);
    void ShowBase() const;
};