/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/


#include <iostream>
#include "GashaSmash.hpp"

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

void mainMenu(GashaSmash &core)
{
    while (1) {
        core.window->clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            break;
        while (core.window->pollEvent(core.event))
        {
            if (core.event.type == sf::Event::Closed) {
                core.window->close();
                return;
            }
        }
        core.window->display();
    }
}

void mainScreen(GashaSmash &core)
{
    sf::RectangleShape rectangle(sf::Vector2f(440, 45));
    if (!core.font.loadFromFile("Super Smash Bros Ultimate/Others/font.ttf"))
        return;
    sf::Text text("G  A  S  H  A", core.font, 45);
    text.setFillColor(sf::Color::Black);
    core.window->clear();
    create_sprite("Super Smash Bros Ultimate/Others/Backgroud_Smash.png", *core.window);
    rectangle.setPosition(core.window->getSize().x / 2 - 220, core.window->getSize().y - 100);
    core.window->draw(rectangle);
    text.setPosition(core.window->getSize().x / 2 - 150, core.window->getSize().y - 100);
    core.window->draw(text);
}

int main()
{
    
    GashaSmash core;

    while (core.window->isOpen())
    {
        while (core.window->pollEvent(core.event))
        {
            if (core.event.type == sf::Event::Closed)
                core.window->close();
        }
        mainScreen(core);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            mainMenu(core);
        core.window->display();
    }

    return 0;
}