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
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_wooper.png"}, 10, 10, 10, 100, 10, 10));
            enemy[0]->setName("Wooper");
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_tatanga.png"}, 20, 20, 20, 200, 20, 20));
            enemy[1]->setName("Tatanga");
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_viruses.png"}, 10, 10, 10, 100, 10, 10));
            enemy[2]->setName("Virtuses");
            break;
        case 1:
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_vaati.png"}, 20, 20, 20, 200, 20, 20));
            enemy[0]->setName("Vaati");
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_twinrova.png"}, 40, 40, 40, 400, 40, 40));
            enemy[1]->setName("Twinrova");
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_thundurus.png"}, 20, 20, 20, 200, 20, 20));
            enemy[2]->setName("Thundurus");
            break;
        case 2:
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_tingle.png"}, 40, 40, 40, 400, 40, 40));
            enemy[0]->setName("Tingle");
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_valoo.png"}, 80, 80, 80, 800, 80, 80));
            enemy[1]->setName("Valoo");
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_walker.png"}, 40, 40, 40, 400, 40, 40));
            enemy[2]->setName("Walker");
            break;
        default:
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_t_rex.png"}, 80, 80, 80, 800, 80, 80));
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_tom_nook_nookingtons.png"}, 160, 160, 160, 1600, 160, 160));
            enemy.push_back(new Champion(std::vector<std::string>{"Super Smash Bros Ultimate/Fighter Portraits/Spirits/spirits_0_zygarde_complete.png"}, 80, 80, 80, 800, 80, 80));
            break;
    }
}

void choseTeam(GashaSmash &core)
{
    core.round = 0;
    createEnemy(core._enemy, core.actual_level);
    int i = rand() % core.player.getChampion().size();
    int j = rand() % core.player.getChampion().size();
    if (j == i) {
        if (j == core.player.getChampion().size() - 1)
            j--;
        else
            j++;
    }
    int k = rand() % core.player.getChampion().size();
    if (k == i || k == j) {
        if (k == core.player.getChampion().size() - 1)
            k--;
        else
            k++;
    }
    create_team(core.player, i, j, k);    
    for (int i = 0; i < core.player._team.size(); ++i) {
        core.player._team[i]->setLife(core.player._team[i]->getMax());
    }
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
    sf::Vector2u WindowSize = core.window->getSize();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        core.scene = MFIGHT;
    sort(core._enemy);
    sort(core.player._team);

    core.window->clear();
    create_sprite("Super Smash Bros Ultimate/Others/Backgroun.png", *core.window, (float) WindowSize.x, (float) WindowSize.y, 0, 0);

    sf::Text champ1_name(core.player._team[0]->getName(), core.font, 50);
    sf::Text champ2_name(core.player._team[1]->getName(), core.font, 50);
    sf::Text champ3_name(core.player._team[2]->getName(), core.font, 50);
    sf::Text en1_name(core._enemy[0]->getName(), core.font, 50);
    sf::Text en2_name(core._enemy[1]->getName(), core.font, 50);
    sf::Text en3_name(core._enemy[2]->getName(), core.font, 50);


    champ1_name.setFillColor(sf::Color::Black);
    champ2_name.setFillColor(sf::Color::Black);
    champ3_name.setFillColor(sf::Color::Black);
    en1_name.setFillColor(sf::Color::Black);
    en2_name.setFillColor(sf::Color::Black);
    en3_name.setFillColor(sf::Color::Black);
    
    create_sprite(core.player._team[0]->getSprit()[0], *core.window, WindowSize.x * .25, WindowSize.y * .25, WindowSize.x * 0, WindowSize.y * .6);
    create_sprite(core.player._team[1]->getSprit()[0], *core.window, WindowSize.x * .25, WindowSize.y * .25, WindowSize.x * .33, WindowSize.y * .6);
    create_sprite(core.player._team[2]->getSprit()[0], *core.window, WindowSize.x * .25, WindowSize.y * .25, WindowSize.x * .66, WindowSize.y * .6);
    create_sprite(core._enemy[0]->getSprit()[0], *core.window, WindowSize.x * .25, WindowSize.y * .25, WindowSize.x * 0, WindowSize.y * 0);
    create_sprite(core._enemy[1]->getSprit()[0], *core.window, WindowSize.x * .25, WindowSize.y * .25, WindowSize.x * .33, WindowSize.y * 0);
    create_sprite(core._enemy[2]->getSprit()[0], *core.window, WindowSize.x * .25, WindowSize.y * .25, WindowSize.x * .66, WindowSize.y * 0);

    champ1_name.setPosition(WindowSize.x * 0, WindowSize.y * .86);
    champ2_name.setPosition(WindowSize.x * .33, WindowSize.y * .86);
    champ3_name.setPosition(WindowSize.x * .66, WindowSize.y * .86);
    en1_name.setPosition(WindowSize.x * 0, WindowSize.y * .26);
    en2_name.setPosition(WindowSize.x * .33, WindowSize.y * .26);
    en3_name.setPosition(WindowSize.x * .66, WindowSize.y * .26);

    core.window->draw(champ1_name);
    core.window->draw(champ2_name);
    core.window->draw(champ3_name);
    core.window->draw(en1_name);
    core.window->draw(en2_name);
    core.window->draw(en3_name);
    sleep(2);
    if (core._enemy[core.round]->getSpeed() > core.player._team[core.round]->getSpeed()) {
        std::cout << "enemy attack player" << std::endl;
        core._enemy[core.round]->Attack(core.player._team[core.round]);
    } else {
        std::cout << "player attack enemy" << std::endl;
        core.player._team[core.round]->Attack(core._enemy[core.round]);
    }
    if (core._enemy[core.round]->getSpeed() > core.player._team[core.round]->getSpeed()) {
        std::cout << "player attack enemy" << std::endl;
        core.player._team[core.round]->Attack(core._enemy[core.round]);
    } else {
        std::cout << "enemy attack player" << std::endl;
        core._enemy[core.round]->Attack(core.player._team[core.round]);
    }
    if (isDead(core._enemy) == 0) {
        sf::Text t("WIN !", core.font, 40);
        t.setFillColor(sf::Color::Black);
        t.setPosition(WindowSize.x * .25, WindowSize.y * .5);
        core.window->draw(t);
        std::cout << "Player win" << std::endl;
        core.scene = MFIGHT;
        core.player.setStone(core.player.getStone() + 10);
        if (core.actual_level == core.player.getLevel())
            core.player.setLevel(core.player.getLevel() + 1);
    }
    if (isDead(core.player.getTeam()) == 0) {
        sf::Text t("LOOSE !", core.font, 40);
        t.setFillColor(sf::Color::Black);
        t.setPosition(WindowSize.x * .25, WindowSize.y * .5);
        core.window->draw(t);
        std::cout << "Enemy win" << std::endl;
        core.scene = MFIGHT;
    }
    core.round++;
    if (core.round >= 3)
        core.round = 0;
}