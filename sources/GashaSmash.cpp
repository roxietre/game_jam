/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/


#include <iostream>
#include "GashaSmash.hpp"

void create_sprite(std::string img, sf::RenderWindow &window, float x, float y, float new_x, float new_y)
{
    sf::Texture texture;
    sf::Sprite sprite;

    if (!texture.loadFromFile(img))
        return;

    sf::Vector2u TextureSize = texture.getSize(); //Get size of texture.

    float ScaleX = x / (float) TextureSize.x;
    float ScaleY = y / (float) TextureSize.y; 

    texture.setSmooth(true);
    sprite.setScale(ScaleX, ScaleY);
    sprite.setTexture(texture);
    sprite.setPosition(new_x, new_y);
    window.draw(sprite);
}

void mainMenu(GashaSmash &core)
{
    sf::Text text("SUMMON", core.font, 45);
    text.setFillColor(sf::Color::Black);
    sf::Text text2("BATTLE", core.font, 45);
    text2.setFillColor(sf::Color::Black);
    sf::Vector2u WindowSize = core.window->getSize();
    sf::RectangleShape rect1(sf::Vector2f((float) WindowSize.x * .35, 50));
    sf::RectangleShape rect2(sf::Vector2f((float) WindowSize.x * .35, 50));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        core.scene = MSCREEN;
    create_sprite("Super Smash Bros Ultimate/Others/Sky_Main_Menu.jpg", *core.window, (float) WindowSize.x, (float) WindowSize.y, 0, 0);
    create_sprite("Super Smash Bros Ultimate/Others/Frame.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, 0, 0);
    create_sprite("Super Smash Bros Ultimate/Others/Frame.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, (float) WindowSize.x / 2, 0);
    create_sprite("Super Smash Bros Ultimate/Others/item_0_assist.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, 0, 0);
    create_sprite("Super Smash Bros Ultimate/Others/item_0_blackball.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, (float) WindowSize.x / 2, 0);

    rect1.setPosition( ((float) WindowSize.x / 2) + 150 , (float) WindowSize.y - 100);
    core.window->draw(rect1);
    rect2.setPosition( 150 , (float) WindowSize.y - 100);
    core.window->draw(rect2);
    text.setPosition(core.window->getSize().x * .20, core.window->getSize().y - 100);
    core.window->draw(text);
    text2.setPosition(core.window->getSize().x * .73, core.window->getSize().y - 100);
    core.window->draw(text2);
}

void mainScreen(GashaSmash &core)
{
    sf::RectangleShape rectangle(sf::Vector2f(440, 45));
    if (!core.font.loadFromFile("Super Smash Bros Ultimate/Others/font.ttf"))
        return;
    sf::Text text("G  A  S  H  A", core.font, 45);
    text.setFillColor(sf::Color::Black);
    core.window->clear();
    sf::Vector2u WindowSize = core.window->getSize();
    create_sprite("Super Smash Bros Ultimate/Others/Backgroud_Smash.png", *core.window, (float) WindowSize.x, (float) WindowSize.y, 0, 0);
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
        for (int i = 0; i < TABSIZE; ++i)
            if (scene_tab[i].scene == core.scene)
                scene_tab[i].ptr_scene(core);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            core.scene = MMENU;
        core.window->display();
    }
    return 0;
}