#ifndef PINGPONG_HUD_H
#define PINGPONG_HUD_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Hud
{
private:
    Font m_Font;

    Text m_StartText;
    Text m_LivesText;
    Text m_ScoreText;
    // Text m_StartScreenText;

public:
    Hud();

    Text getMessage();
    Text getLives();
    Text getScore();
};

#endif //PINGPONG_HUD_H
