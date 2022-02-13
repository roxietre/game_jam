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

void SelectMenu(GashaSmash &core)
{
    sf::Vector2u WindowSize = core.window->getSize();
    core.window->clear();
    create_sprite("Super Smash Bros Ultimate/Others/sky.png", *core.window, (float) WindowSize.x, (float) WindowSize.y, 0, 0);
}


void fightMenu(GashaSmash &core)
{
    sf::Vector2u WindowSize = core.window->getSize();
    sf::Text text("1", core.font, 100);
    sf::Text text1("2", core.font, 100);
    sf::Text text2("3", core.font, 100);
    sf::Text textBoss("BOSS", core.font, 100);
    
    sf::RectangleShape rect(sf::Vector2f((float) WindowSize.x * .1, WindowSize.y * .1));
    sf::RectangleShape rect1(sf::Vector2f((float) WindowSize.x * .1, WindowSize.y * .1));
    sf::RectangleShape rect2(sf::Vector2f((float) WindowSize.x * .1, WindowSize.y * .1));
    sf::RectangleShape rectBoss(sf::Vector2f((float) WindowSize.x * .1, WindowSize.y * .1));


    text.setFillColor(sf::Color::Black);
    text1.setFillColor(sf::Color::Black);
    text2.setFillColor(sf::Color::Black);
    textBoss.setFillColor(sf::Color::Black);


    sf::RectangleShape line(sf::Vector2f(WindowSize.x * .33, WindowSize.y * .018));
    line.rotate(45);
    line.setFillColor(sf::Color(220,220,220));

    sf::RectangleShape line2(sf::Vector2f(WindowSize.x * .4, WindowSize.y * .018));
    line2.rotate(-40);
    line2.setFillColor(sf::Color(220,220,220));

    sf::RectangleShape line3(sf::Vector2f(WindowSize.x * .36, WindowSize.y * .018));
    line3.rotate(45);
    line3.setFillColor(sf::Color(220,220,220));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        core.scene = MMENU;

    core.window->clear();
    std::vector<Champion *> enemy;
    std::cout << "Making team" << std::endl;
    choseTeam(core, enemy, 0);
    std::cout << "Making fight" << std::endl;
    makeFight(core, enemy);

    create_sprite("Super Smash Bros Ultimate/Others/Backgroun.png", *core.window, (float) WindowSize.x, (float) WindowSize.y, 0, 0);
    text.setPosition(WindowSize.x * 0.031, 0);
    rect.setPosition(WindowSize.x * 0.025, 0);
    rect.scale(.5, 1);

    line.setPosition(WindowSize.x * 0.032, 0);
    text1.setPosition(WindowSize.x * .25, WindowSize.y * .4);
    rect1.setPosition(WindowSize.x * .245, WindowSize.y * .4);
    rect1.scale(.5, 1);

    line2.setPosition(WindowSize.x * 0.25, WindowSize.y * .42);
    text2.setPosition(WindowSize.x * .5, 0);
    rect2.setPosition(WindowSize.x * .495, 0);
    rect2.scale(.5, 1);

    line3.setPosition(WindowSize.x * 0.52, WindowSize.y * 0);
    textBoss.setPosition(WindowSize.x * .75, WindowSize.y * .4);
    rectBoss.setPosition(WindowSize.x * .74, WindowSize.y * .4);
    rectBoss.scale(1.6, 1);

    rect.setFillColor(sf::Color::Green);

    if (core.player.getLevel() >= 1)
        rect1.setFillColor(sf::Color::Green);
    else
        rect1.setFillColor(sf::Color::Red);

    if (core.player.getLevel() >= 2)
        rect2.setFillColor(sf::Color::Green);
    else
        rect2.setFillColor(sf::Color::Red);

    if (core.player.getLevel() == 3)
        rectBoss.setFillColor(sf::Color::Green);
    else
        rectBoss.setFillColor(sf::Color::Red);


    sf::Vector2i m = core.mouse.getPosition(*core.window);
    if (m.x >= rect.getPosition().x && m.x <= rect.getPosition().x + rect.getSize().x && m.y >= rect.getPosition().y && m.y <= rect.getPosition().y + rect.getSize().y) 
    {
        text.scale(2, 2);
        rect.scale(1, 2);
        if (core.mouse.isButtonPressed(sf::Mouse::Left)) {
            core.scene = MSELECT;
        }
    }

    core.window->draw(line);
    core.window->draw(rect);
    core.window->draw(text);
    core.window->draw(line2);
    core.window->draw(rect1);
    core.window->draw(text1);
    core.window->draw(line3);
    core.window->draw(rect2);
    core.window->draw(text2);
    core.window->draw(rectBoss);
    core.window->draw(textBoss);

}

void summonMenu(GashaSmash &core)
{
    sf::Vector2u WindowSize = core.window->getSize();

    sf::Text text("SINGLE SUMMON press I", core.font, 45);
    text.setFillColor(sf::Color::Black);
    sf::Text text2("MULTI SUMMON press I", core.font, 45);
    text2.setFillColor(sf::Color::Black);

    sf::RectangleShape rect1(sf::Vector2f((float) WindowSize.x * .35, 50));
    sf::RectangleShape rect2(sf::Vector2f((float) WindowSize.x * .35, 50));
    core.window->clear();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        core.scene = MMENU;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        show_champion(core.player);

    create_sprite("Super Smash Bros Ultimate/Others/Sky_Main_Menu.jpg", *core.window, (float) WindowSize.x, (float) WindowSize.y, 0, 0);
    create_sprite("Super Smash Bros Ultimate/Others/Frame.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, 0, 0);
    create_sprite("Super Smash Bros Ultimate/Others/Frame.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, (float) WindowSize.x / 2, 0);
    create_sprite("Super Smash Bros Ultimate/Others/item_0_pokeball.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, 0, 0);
    create_sprite("Super Smash Bros Ultimate/Others/item_0_masterball.png", *core.window, (float) WindowSize.x / 2, (float) WindowSize.y, (float) WindowSize.x / 2, 0);

    rect1.setPosition( ((float) WindowSize.x / 2) + 150 , (float) WindowSize.y - 100);
    rect2.setPosition( 150 , (float) WindowSize.y - 100);
    text.setPosition(core.window->getSize().x * .10, core.window->getSize().y - 100);
    text2.setPosition(core.window->getSize().x * .60, core.window->getSize().y - 100);

    core.window->draw(rect1);
    core.window->draw(rect2);
    core.window->draw(text);
    core.window->draw(text2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
        invocation(core.player);
        std::vector<Champion *>champ = core.player.getChampion();
        create_sprite(champ[champ.size()- 1]->getSprit()[2], *core.window, 10, 15, 25, 25);
    }
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
    text.setPosition(core.window->getSize().x * .20, core.window->getSize().y - 100);
    text2.setPosition(core.window->getSize().x * .73, core.window->getSize().y - 100);


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
    core.window->draw(text);
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