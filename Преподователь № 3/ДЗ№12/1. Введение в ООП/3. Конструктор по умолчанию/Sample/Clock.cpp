#include "Clock.h"

Clock::Clock()
{
    m_hours = 0U;
    m_minutes = 0U;
    m_seconds = 0U;
}

unsigned int Clock::GetHours()
{
    return m_hours;
}

unsigned int Clock::GetMinutes()
{
    return m_minutes;
}

unsigned int Clock::GetSeconds()
{
    return m_seconds;
}

void Clock::SetHours(const unsigned int hours)
{
    m_hours = hours % 24U;
}

void Clock::SetMinutes(const unsigned int minutes)
{
    m_minutes = minutes % 60U;
}

void Clock::SetSeconds(const unsigned int seconds)
{
    m_seconds = seconds % 60U;
}

void Clock::Tick()
{
    ++m_seconds;

    if (m_seconds > 59U)
    {
        m_seconds = 0U;
        ++m_minutes;

        if (m_minutes > 59U)
        {
            m_minutes = 0U;
            ++m_hours;

            if (m_hours > 23U)
            {
                m_hours = 0U;
            }
        }
    }
}