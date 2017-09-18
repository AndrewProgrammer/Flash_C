#pragma once

class Integer
{
private:
    int m_number;

public:
    Integer();
    Integer(const int number);

    bool operator==(const Integer& right) const;
    bool operator!=(const Integer& right) const;
    bool operator>(const Integer& right) const;
    bool operator<(const Integer& right) const;
    bool operator>=(const Integer& right) const;
    bool operator<=(const Integer& right) const;

    int GetValue() const;
    void SetValue(const int number);
};