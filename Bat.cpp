#include "Bat.h"

Bat::Bat(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_BatShape.setSize(sf::Vector2f(40, 5));
    m_BatShape.setPosition(m_Position);
}

FloatRect Bat::getPosition()
{
    return m_BatShape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
    return m_BatShape;
}

void Bat::reset(float x, float y)
{
    Bat(x, y);
}

void Bat::moveLeft()
{
    m_Position.x -= m_BatSpeed;
}

void Bat::moveRight()
{
    m_Position.x += m_BatSpeed;
}

void Bat::update()
{
    m_BatShape.setPosition(m_Position);
}