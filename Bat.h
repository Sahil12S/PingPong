#ifndef PINGPONG_BAT_H
#define PINGPONG_BAT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
    Vector2f m_Position;
    RectangleShape m_BatShape;

    float m_BatSpeed = 5.0f;

public:
    Bat(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();
    void reset(float x, float y);
    void moveLeft();
    void moveRight();
    void update();
};


#endif //PINGPONG_BAT_H
