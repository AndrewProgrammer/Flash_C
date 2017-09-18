#pragma once

class Sum
{
private:
    int m_first;
    int m_second;

public:
    int operator()(const int first, const int second);

    int GetFirst() const;
    int GetSecond() const;
};