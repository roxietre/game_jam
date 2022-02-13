/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/


#include <iostream>
#include "GashaSmash.hpp"

void create_sprite(std::string img, sf::RenderWindow &window, float x, float y, float new_x, float new_y )
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


void fightMenu(GashaSmash &core)
{
    core.window->clear();
    std::vector<Champion *> enemy;
    std::cout << "Making team" << std::endl;
    choseTeam(core, enemy, 0);
    std::cout << "Making fight" << std::endl;
    makeFight(core, enemy);
}

void summonMenu(GashaSmash &core)
{
    sf::Vector2u WindowSize = core.window->getSize();

    sf::Text text("SINGLE SUMMON", core.font, 45);
    text.setFillColor(sf::Color::Black);
    sf::Text text2("MULTI SUMMON", core.font, 45);
    text2.setFillColor(sf::Color::Black);
    
    sf::RectangleShape rect1(sf::Vector2f((float) WindowSize.x * .35, 50));
    sf::RectangleShape rect2(sf::Vector2f((float) WindowSize.x * .35, 50));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        core.scene = MMENU;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        invocation(core.player);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        show_champion(core.player);
    core.window->clear();
    create_sprite("Super Smash Bros Ultimate/Others/Sky_Main_Menu.jpg", *core.window, (float) WindowSize.x, (float) WindowSize.y, 0, 0);
    create_sprite("Super Smash Bros Ultimate/Others/Frame.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, 0, 0);
    create_sprite("Super Smash Bros Ultimate/Others/Frame.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, (float) WindowSize.x / 2, 0);
    create_sprite("Super Smash Bros Ultimate/Others/item_0_pokeball.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, 0, 0);
    create_sprite("Super Smash Bros Ultimate/Others/item_0_masterball.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, (float) WindowSize.x / 2, 0);

    rect1.setPosition( ((float) WindowSize.x / 2) + 150 , (float) WindowSize.y - 100);
    rect2.setPosition( 150 , (float) WindowSize.y - 100);
    core.window->draw(rect1);
    core.window->draw(rect2);
    text.setPosition(core.window->getSize().x * .10, core.window->getSize().y - 100);
    core.window->draw(text);
    text2.setPosition(core.window->getSize().x * .60, core.window->getSize().y - 100);
    core.window->draw(text2);
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
    rect2.setPosition( 150 , (float) WindowSize.y - 100);
    sf::Vector2i m = core.mouse.getPosition(*core.window);
    if (m.x >= WindowSize.x/2 + 150 && m.x <= WindowSize.x/2 + 150 + WindowSize.x * .35 && m.y >= WindowSize.y - 100 && m.y <= WindowSize.y - 100 + 50) {
        rect1.setPosition(sf::Vector2f(rect1.getPosition().x - 50, rect1.getPosition().y - 20));
        rect1.setScale(sf::Vector2f(rect1.getScale().x * 1.2, rect1.getScale().y * 1.5));
        if (core.mouse.isButtonPressed(sf::Mouse::Left)) {
            core.scene = MFIGHT;
        }
    }
    if (m.x >= 150 && m.x <= WindowSize.x/2 && m.y >= WindowSize.y - 100 && m.y <= WindowSize.y - 100 + 50) {
        rect2.setPosition(sf::Vector2f(rect2.getPosition().x - 50, rect2.getPosition().y - 20));
        rect2.setScale(sf::Vector2f(rect2.getScale().x * 1.2, rect2.getScale().y * 1.5));
        if (core.mouse.isButtonPressed(sf::Mouse::Left)) {
            core.scene = MSUMMON;
        }
    }
    core.window->draw(rect1);
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