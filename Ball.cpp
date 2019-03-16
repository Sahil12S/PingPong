#include "Ball.h"

Ball::Ball(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_BallShape.setSize(Vector2f(10, 10));
    m_BallShape.setPosition(m_Position);
}

FloatRect Ball::getPosition()
{
    return m_BallShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
    return m_BallShape;
}

void Ball::reset(float x, float y)
{
    Ball(x, y);
}

float Ball::getXVelocity()
{
    return m_XVelocity;
}

void Ball::reboundSides()
{
    m_XVelocity = -m_XVelocity;
}

void Ball::reboundBarOrTop()
{
    m_Position.y -= (m_YVelocity);
    m_YVelocity = -m_YVelocity;
}

void Ball::hitBottom()
{
    m_Position.y = 1;
    m_Position.x = 500;
}

void Ball::update()
{
    m_Position.y += m_YVelocity;
    m_Position.x += m_XVelocity;

    m_BallShape.setPosition(m_Position);
}