/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <iostream>

sf::Sprite create_sprite(std::string img)
{
    sf::Texture texture1;

    if (!texture1.loadFromFile(img))
    {
        std::cerr << "Error while loading texture" << std::endl;
    }
    //texture1.setSmooth(true);
    sf::Sprite sprite(texture1);
    return sprite;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GashaSmash");
    sf::Sprite bg = create_sprite("Super Smash Bros Ultimate/Fighter Portraits/Zelda/chara_0_zelda_01.png");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bg);
        window.display();
    }

    return 0;
}