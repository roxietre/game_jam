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

void choseTeam(GashaSmash &core, std::vector<Champion *> &enemy, int level)
{
    createEnemy(enemy, level);
    if (core.player.getChampion().size() < 3)
        return;
}

bool makeFight(GashaSmash &core, std::vector<Champion *> &enemy)
{
    while (1) {
        std::cout << "Fight loop" << std::endl;
        std::sort(enemy.begin(), enemy.end());
        std::sort(core.player.getTeam().begin(), core.player.getTeam().end());
        if (isDead(enemy))
            return false;
        //if (isDead(core.player.getTeam()))
        //    return true;
    }
    return true;
}