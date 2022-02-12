/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** GashaSmash
*/

#ifndef GASHASMASH_HPP_
#define GASHASMASH_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>

class GashaSmash {
    public:
        GashaSmash() 
        {
            window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "GashaSmash");
        };
        enum scene_e {MSCREEN, MMENU, MLOOT, MFIGHT};
        ~GashaSmash() {}
        sf::RenderWindow *window;
        sf::Event event;
        sf::Font font;
        scene_e scene;
    protected:
    private:
};

#endif /* !GASHASMASH_HPP_ */
