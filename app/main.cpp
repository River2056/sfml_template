#include <cstdlib>
#include <ctime>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


void CheckForExit(sf::Window& window, sf::Event& event) {
    if (event.type == sf::Event::Closed)
            window.close();

    if (event.type == event.KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
    }
}


int main() {
    // window
    std::srand(std::time(NULL));
    sf::RenderWindow window(sf::VideoMode(1280, 960), "DVD Screen Saver", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    sf::Event event;
    int circle_radius = 90;
    int text_size = 56;
    float x_speed = std::rand() % 5 + 5;
    float y_speed = std::rand() % 2 + 3;
    float x = (window.getSize().x / 2.0) - circle_radius;
    float y = (window.getSize().y / 2.0) - circle_radius;
    sf::Font font;
    if (!font.loadFromFile("./fonts/Roboto-Regular.ttf"))
        return EXIT_FAILURE;

    sf::Text text("DVD", font, text_size);
    text.setFillColor(sf::Color(0, 0, 0));
    sf::Clock deltaClock;

    // game loop
    while (window.isOpen()) {
        sf::Time dt = deltaClock.restart();
        while (window.pollEvent(event)) {
            // check for exit event
            CheckForExit(window, event);
        }

        // clear old frame
        window.clear();

        // draw game
        sf::CircleShape ball(circle_radius);
        ball.setFillColor(sf::Color(255, 255, 255));

        // move ball
        if (x + (2 * circle_radius) >= window.getSize().x || x < 0) {
            x_speed *= -1;
            text.setFillColor(sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255));
        }
        if (y + (2 * circle_radius) >= window.getSize().y || y < 0) {
            y_speed *= -1;
            text.setFillColor(sf::Color(std::rand() % 255, std::rand() % 255, std::rand() % 255));
        }

        x += x_speed * (60 * dt.asSeconds()); // 60fps
        y += y_speed * (60 * dt.asSeconds()); // 60fps
        ball.setPosition(x, y);
        text.setPosition(x + circle_radius - text_size, y + text_size);
        window.draw(ball);
        window.draw(text);

        // tell game done drawing and display results
        window.display();
    }
    
    return EXIT_SUCCESS; // 0
}
