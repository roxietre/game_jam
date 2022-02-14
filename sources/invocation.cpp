/*
** EPITECH PROJECT, 2022
** jam1
** File description:
** invocation
*/

#include "player.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>

Champion::Champion(std::string name)
{
    int x = rand() % 7;
    _sprit.push_back(std::string("Super Smash Bros Ultimate/Fighter Portraits/")+name+std::string("/chara_0_")+name+std::string("_0"+std::to_string(x)+".png"));
    _sprit.push_back(std::string("Super Smash Bros Ultimate/Fighter Portraits/")+name+std::string("/chara_1_")+name+std::string("_0"+std::to_string(x)+".png"));
    _sprit.push_back(std::string("Super Smash Bros Ultimate/Fighter Portraits/")+name+std::string("/chara_4_")+name+std::string("_0"+std::to_string(x)+".png"));
    _sprit.push_back(std::string("Super Smash Bros Ultimate/Fighter Portraits/")+name+std::string("/chara_6_")+name+std::string("_0"+std::to_string(x)+".png"));

    _attack = rand()%(50-5+1)+50;
    _armor = rand()%(10-5+1)+5;
    _speed = rand()%(80-5+1)+20;
    _life = rand()%(150-5+1)+100;
    _Maxhp = _life;
    _specialAttack = rand()%(10-5+1)+5;
    _specialArmor = rand()%(10-5+1)+5;
}

void show_champion(Player &player)
{
    std::cout << "heros champions : " << std::endl;
    std::vector<Champion *> champ = player.getChampion();
    for (int i = 0; i < champ.size(); i++) {
        std::cout << "Champion " << i << " : " << champ[i]->getAttack() << " " << champ[i]->getSpeed() << " " << champ[i]->getSpecialAttack() << " " << champ[i]->getLife() << " " << champ[i]->getSpecialAtt() << " " << champ[i]->getSpecialDef() << std::endl;
    }
}


void invocation(Player &player)
{
    std::vector<std::string> name_champion;

    name_champion.push_back("koopa");
    name_champion.push_back("koopajr");
    name_champion.push_back("donkey");
    name_champion.push_back("falco");
    name_champion.push_back("fox");
    name_champion.push_back("shizue");
    name_champion.push_back("link");
    name_champion.push_back("luigi");
    name_champion.push_back("mario");
    name_champion.push_back("pfushigisou");
    name_champion.push_back("pzenigame");
    name_champion.push_back("ridley");
    name_champion.push_back("sonic");
    name_champion.push_back("trail");
    name_champion.push_back("wolf");
    name_champion.push_back("zelda");
    std::cout << std::to_string(player.getStone()) << " stones left" << std::endl;
    if (player.getStone() >= 1) {
        player.setStone( -1);
        int x = rand() % 16;
        Champion *chap = new Champion(name_champion[x]);
        player.setChampion(chap);
    if (name_champion[x] == "trail")
        player.getChampion()[player.getChampion().size() - 1]->setName("Sora");
    else if (name_champion[x] ==  "pfushigisou")
        player.getChampion()[player.getChampion().size() - 1]->setName("Epizare");
    else if (name_champion[x] == "pzenigame")
        player.getChampion()[player.getChampion().size() - 1]->setName("Carapute");
    else if (name_champion[x] == "koopa")
        player.getChampion()[player.getChampion().size() - 1]->setName("Bowser");
    else if (name_champion[x] == "koopajr")
        player.getChampion()[player.getChampion().size() - 1]->setName("Bowser Jr.");
    else
        player.getChampion()[player.getChampion().size() - 1]->setName(name_champion[x]);
    }
}

void evolution(Player &player)
{
    std::vector<Champion *> champ = player.getChampion();
    int t = rand() %champ.size();

    std::vector<std::string>  old_sprite = champ[t]->getSprit();
    for (int i = 0; i < old_sprite.size(); i++) {
        std::string new_sprite = old_sprite[i];
        new_sprite.replace(new_sprite.find("_00"), 3, "_01");
        old_sprite[i] = new_sprite;
    }
    champ[t]->setSprit(old_sprite);
    champ[t]->evolution_up(rand()%(10-5+1)+5,rand()%(10-5+1)+5,rand()%(10-5+1)+5,rand()%(10-5+1)+5,rand()%(10-5+1)+5,rand()%(10-5+1)+5);
}

void create_team(Player &player, int champ1, int champ2, int champ3)
{
    std::vector<Champion *> champ = player.getChampion();
    player.addTeam(champ[champ1]);
    player.addTeam(champ[champ2]);
    player.addTeam(champ[champ3]);
}