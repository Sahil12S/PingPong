#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"

using namespace sf;

int main()
{
    Vector2f windowSize = {1024, 768};

    RenderWindow window(VideoMode(windowSize.x, windowSize.y), "Ping Pong");
    int score = 0;
    int lives = 3;

    Bat bat (windowSize.x / 2, windowSize.y - 20);

    Ball ball(windowSize.x / 2, 1);

    Text hud;

    Font font;

    font.loadFromFile("../mytype.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        /*
         * Handle player input
         */
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        /*
         * Update the frame
         */
        // Handle ball hitting the bottom
        if (ball.getPosition().top > windowSize.y)
        {
            ball.hitBottom();
            lives--;
            if (lives < 1)
            {
                score = 0;
                lives = 3;
            }
        }

        // Handle ball hitting top
        if (ball.getPosition().top < 0)
        {
            ball.reboundBarOrTop();
            score++;
        }

        // Handle ball hitting sides
        if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowSize.x)
        {
            ball.reboundSides();
        }

        // Has the ball hit the bat
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundBarOrTop();
        }

        ball.update();
        bat.update();

        // Update the HUD text
        std::stringstream ss;
        ss << "Score: " << score << "   Lives: " << lives;
        hud.setString(ss.str());

        /*
         * Draw the frame
         */
        window.clear(Color(26, 128, 182, 255));
        window.draw(bat.getShape());
        window.draw(ball.getShape());

        window.draw(hud);
        window.display();
    }
    return 0;
}