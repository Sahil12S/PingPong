#include "Engine.h"
#include <sstream>

void Engine::update(float dtAsSeconds)
{
    if (m_Playing)
    {
        if(m_Ball.getPosition().top > m_ScreenSize.y)
        {
            m_Ball.hitBottom();
            m_Lives--;
            if (m_Lives < 1)
            {
                m_Score = 0;
                m_Lives = 3;
                m_Playing = false;
            }
        }

        // Handle the ball hitting top
        if (m_Ball.getPosition().top < 0)
        {
            m_Ball.reboundBarOrTop();
            // m_Score++;
        }

        // Handle the ball hitting sides
        if (m_Ball.getPosition().left < 0 || m_Ball.getPosition().left + 10 > m_ScreenSize.x)
        {
            m_Ball.reboundSides();
        }

        // Handle the ball hit the bat
        if (m_Ball.getPosition().intersects(m_Bat.getPosition()))
        {
            m_Ball.reboundBarOrTop();
            m_Score++;
        }

        // Update the HUD text
        std::stringstream ss;
        ss << "Score: " << m_Score << "   Lives: " << m_Lives;
    }
}