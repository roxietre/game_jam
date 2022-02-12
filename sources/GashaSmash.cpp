/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include  "Zelda.hpp"
#include <SFML/Window/Window.hpp>
#include <iostream>

void create_sprite(std::string img, sf::RenderWindow &window)
{
    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile(img))
        return;
    sprite.setTexture(texture);
    window.draw(sprite);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GashaSmash");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        create_sprite("Super Smash Bros Ultimate/Others/Backgroud_Smash.png", window);
        sf::Font font;
        if (!font.loadFromFile("Super Smash Bros Ultimate/Others/font.ttf"))
            return EXIT_FAILURE;
        sf::Text text("GASHA", font, 50);
        window.draw(text);
        window.display();
    }

    return 0;
}