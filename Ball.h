#ifndef PINGPONG_BALL_H
#define PINGPONG_BALL_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
    Vector2f m_Position;
    RectangleShape m_BallShape;

    float m_XVelocity = 4.0f;
    float m_YVelocity = 4.0f;

public:
    Ball(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();

    void reset(float x, float y);

    float getXVelocity();
    void reboundSides();
    void reboundBarOrTop();
    void hitBottom();
    void update();
};

#endif //PINGPONG_BALL_H
