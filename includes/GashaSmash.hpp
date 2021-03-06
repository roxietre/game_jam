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
#include <unistd.h>
#include "player.hpp"
#include <map>
#include <functional>
#include "champion.hpp"
#include <algorithm>
#include <time.h>

enum scene_e {MSCREEN, MMENU, MLOOT, MFIGHT, MSUMMON, MSELECT, STARTF, SUCCESS, SSUMMON};

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
        std::vector<Champion *> _enemy;
        int round;

        Player player;
        int actual_level;
        int _summon;
    protected:
    private:
};

//Scene Part
void mainScreen(GashaSmash &core);
void mainMenu(GashaSmash &core);
void fightMenu(GashaSmash &core);
void summonMenu(GashaSmash &core);
void SelectMenu(GashaSmash &core);
void SuccessScreen(GashaSmash &core);
void SummonScreen(GashaSmash &core);

//Fighting part
void makeFight(GashaSmash &core);
void choseTeam(GashaSmash &core);
void create_team(Player &player, int champ1, int champ2, int champ3);

//Summon part
void invocation(Player &player);
void show_champion(Player &player);

//Success part
void set_success(Player &player);
void verif_success(Player &player);

//create part
void create_sprite(std::string img, sf::RenderWindow &window, float x, float y, float new_x, float new_y, int scale = 1);

//Struct and Scene tab
typedef struct scene_s {
    scene_e scene;
    void (*ptr_scene) (GashaSmash &core);
} scene_t;

static const scene_t scene_tab[] = {
    {.scene = MSCREEN, mainScreen},
    {.scene = MMENU, mainMenu},
    {.scene = MFIGHT, fightMenu},
    {.scene = MSUMMON, summonMenu},
    {.scene = MSELECT, SelectMenu},
    {.scene = STARTF, makeFight},
    {.scene = SUCCESS, SuccessScreen},
    {.scene = SSUMMON, SummonScreen}
};

static const int TABSIZE = sizeof(scene_tab) / sizeof(scene_tab[0]);
#endif /* !GASHASMASH_HPP_ */
