#include "Engine.h"

void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            m_Window.close();
        }
        if (event.type == Event::KeyPressed)
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                m_Window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Return))
            {
                m_Playing = true;
                m_Score = 0;
                m_Lives = 3;
                m_AcceptInput = true;
                m_Bat.reset(m_ScreenSize.x / 2, m_ScreenSize.y - 40);
                m_Ball.reset(m_ScreenSize.x / 2, m_ScreenSize.y -50);
            }
        }
    }

    if (m_AcceptInput)
    {
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            m_Bat.moveLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            m_Bat.moveRight();
        }
    }
}
