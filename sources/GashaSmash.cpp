/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <SFML/Graphics.hpp>
// #include  "Zelda.hpp"
#include <SFML/Window/Window.hpp>
#include <iostream>

void create_sprite(std::string img, sf::RenderWindow &window)
{
    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile(img))
        return;

    sf::Vector2u TextureSize = texture.getSize(); //Get size of texture.
    sf::Vector2u WindowSize = window.getSize();

    float ScaleX = (float) WindowSize.x / TextureSize.x;
    float ScaleY = (float) WindowSize.y / TextureSize.y; 

    sprite.setScale(ScaleX, ScaleY);
    sprite.setTexture(texture);
    window.draw(sprite);
}

void mainMenu(sf::RenderWindow &window, sf::Event &event)
{
    while (1) {
        window.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            break;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }
        window.display();
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GashaSmash");


    while (window.isOpen())
    {
        sf::Event event;
        sf::Font font;
        sf::RectangleShape rectangle(sf::Vector2f(440, 45));

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!font.loadFromFile("Super Smash Bros Ultimate/Others/font.ttf"))
            return EXIT_FAILURE;

        sf::Text text("G  A  S  H  A", font, 45);
        text.setFillColor(sf::Color::Black);

        window.clear();
        create_sprite("Super Smash Bros Ultimate/Others/Backgroud_Smash.png", window);
        rectangle.setPosition(window.getSize().x / 2 - 220, window.getSize().y - 100);
        window.draw(rectangle);

        text.setPosition(window.getSize().x / 2 - 150, window.getSize().y - 100);
        window.draw(text);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            mainMenu(window, event);
        window.display();
    }

    return 0;
}