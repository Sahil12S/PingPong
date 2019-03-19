#ifndef PINGPONG_ENGINE_H
#define PINGPONG_ENGINE_H

#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"

using namespace sf;

class Engine
{
private:
    // A regular RenderWindow
    RenderWindow m_Window;
    Vector2f m_ScreenSize;

    // Declare a sprite and a Texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;

    // An instance of ball and bat
    Bat m_Bat;
    Ball m_Ball;

    bool m_Playing;
    bool m_AcceptInput;

    int m_Score;
    int m_Lives;

    // Private function for internal use only.
    void input();
    void update(float dtAsSeconds);
    void draw();

public:
    // Constructor
    Engine();

    // Start will call all the private functions
    void start();
};



#endif //PINGPONG_ENGINE_H
