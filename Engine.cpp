#include "Engine.h"

Engine::Engine()
{
    // Get the screen resolution and create an SFML window and view
    // Vector2f resolution;
    // resolution.x = VideoMode::getDesktopMode().width;
    // resolution.y = VideoMode::getDesktopMode().height;
    // resolution.x = 400;
    // resolution.y = 600;

    m_ScreenSize.x = 1280;
    m_ScreenSize.y = 720;

    m_Window.create(VideoMode(m_ScreenSize.x, m_ScreenSize.y),
                    "Ping Pong",
                    Style::Default);

    // Load the background into the texture
    // Be sure to scale this image to your screen size
    m_BackgroundTexture.loadFromFile("../background.png");

    // Associate the sprite with the texture
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void Engine::start()
{
    // Timing
    Clock clock;

    while (m_Window.isOpen())
    {
        // Restart the clock and save the elapsed time into dt
        Time dt = clock.restart();

        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}