#pragma once

class Clock
{
private:
    unsigned int m_hours;
    unsigned int m_minutes;
    unsigned int m_seconds;

public:
    Clock();

    unsigned int GetHours();
    unsigned int GetMinutes();
    unsigned int GetSeconds();
    void SetHours(const unsigned int hours);
    void SetMinutes(const unsigned int minutes);
    void SetSeconds(const unsigned int seconds);
    void Tick();
};