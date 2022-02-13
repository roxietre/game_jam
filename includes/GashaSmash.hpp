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
#include <SFML/Window/Mouse.hpp>
#include <map>
#include <functional>

enum scene_e {MSCREEN, MMENU, MLOOT, MFIGHT, MSUMMON};

class GashaSmash {
    public:
        GashaSmash() 
        {
            window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "GashaSmash");
            scene = MSCREEN;
        };
        ~GashaSmash() {}
        sf::RenderWindow *window;
        sf::Event event;
        sf::Font font;
        sf::Mouse mouse;
        scene_e scene;
    protected:
    private:
};
void mainScreen(GashaSmash &core);
void mainMenu(GashaSmash &core);
void fightMenu(GashaSmash &core);
void summonMenu(GashaSmash &core);

typedef struct scene_s {
    scene_e scene;
    void (*ptr_scene) (GashaSmash &core);
} scene_t;

static const scene_t scene_tab[] = {
    {.scene = MSCREEN, mainScreen},
    {.scene = MMENU, mainMenu},
    {.scene = MFIGHT, fightMenu},
    {.scene = MSUMMON, summonMenu}
};

static const int TABSIZE = sizeof(scene_tab) / sizeof(scene_tab[0]);
#endif /* !GASHASMASH_HPP_ */
