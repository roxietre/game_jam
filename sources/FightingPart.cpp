/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** FightingPart
*/

#include "GashaSmash.hpp"
#include <iostream>


static bool isDead(std::vector<Champion *> team)
{
    if (team[0]->getLife() <= 0 && team[1]->getLife() <= 0 && team[2]->getLife() <= 0)
        return 0;
    return 1;
}

void createEnemy(std::vector<Champion *> &enemy, int level)
{
    switch (level) {
        case 0:
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_wooper.png"}, 10, 10, 10, 100, 10, 10));
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_tatanga.png"}, 20, 20, 20, 200, 20, 20));
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_viruses.png"}, 10, 10, 10, 100, 10, 10));
            break;
        case 1:
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_vaati.png"}, 20, 20, 20, 200, 20, 20));
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_twinrova.png"}, 40, 40, 40, 400, 40, 40));
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_thundurus.png"}, 20, 20, 20, 200, 20, 20));
            break;
        case 2:
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_tingle.png"}, 40, 40, 40, 400, 40, 40));
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_valoo.png"}, 80, 80, 80, 800, 80, 80));
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_walker.png"}, 40, 40, 40, 400, 40, 40));
            break;
        default:
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_t_rex.png"}, 80, 80, 80, 800, 80, 80));
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_tom_nook_nookingtons.png"}, 160, 160, 160, 1600, 160, 160));
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighters/Spirits/spirits_0_zygarde_complete.png"}, 80, 80, 80, 800, 80, 80));
            break;
    }
}

void choseTeam(GashaSmash &core)
{
    if (core.player.getChampion().size() < 3)
        return;
    createEnemy(core._enemy, core.actual_level);
    create_team(core.player, 0, 1, 2);
}

void sort( std::vector<Champion *> &list) {
	int i = 0;
    Champion *temp;

    for(i = 0; i < list.size(); i++) {
        for(int j = i+1; j < list.size(); j++)
        {
            if(list[j]->getSpeed() < list[i]->getSpeed()) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void makeFight(GashaSmash &core)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        core.scene = MFIGHT;
    sort(core._enemy);
    sort(core.player._team);



    if (isDead(core._enemy) == 0) {
        core.scene = MFIGHT;
        core.player.setStone(core.player.getStone() + 10);
        if (core.actual_level == core.player.getLevel())
            core.player.setLevel(core.player.getLevel() + 1);
    }
    if (isDead(core.player.getTeam()) == 0)
        core.scene = MFIGHT;
}