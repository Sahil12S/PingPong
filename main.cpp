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
    window.setFramerateLimit(60);

    Clock clock;

    bool paused = true;
    int score = 0;
    int lives = 3;

    bool acceptInput = false;

    Bat bat (windowSize.x / 2, windowSize.y - 20);

    Ball ball(windowSize.x / 2, 1);

    Text hud;
    Text message;

    Font font;

    font.loadFromFile("../mytype.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(sf::Color::White);
    message.setFont(font);
    message.setCharacterSize(75);
    message.setFillColor(sf::Color::White);

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
            if (event.type == Event::KeyReleased && !paused)
            {
                acceptInput = true;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = false;
            score = 0;
            acceptInput = true;
            bat.reset(windowSize.x / 2, windowSize.y - 20);
            ball.reset(windowSize.x / 2, 1);
        }

        if (acceptInput)
        {
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
        }

        /*
         * Update the frame
         */
        if (!paused)
        {
            // Handle ball hitting the bottom
            if (ball.getPosition().top > windowSize.y)
            {
                ball.hitBottom();
                lives--;
                if (lives < 1)
                {
                    score = 0;
                    lives = 3;
                    paused = true;
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
        }



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