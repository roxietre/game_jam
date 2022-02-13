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

    _sprit.push_back(std::string("Super Smash Bros Ultimate/Fighters/")+name+std::string("/chara_0")+name+std::string("_00.png"));
    _sprit.push_back(std::string("Super Smash Bros Ultimate/Fighters/")+name+std::string("/chara_1")+name+std::string("_00.png"));
    _sprit.push_back(std::string("Super Smash Bros Ultimate/Fighters/")+name+std::string("/chara_4")+name+std::string("_00.png"));
    _sprit.push_back(std::string("Super Smash Bros Ultimate/Fighters/")+name+std::string("/chara_6")+name+std::string("_00.png"));

    _attack = rand()%(10-5+1)+5;
    _armor = rand()%(10-5+1)+5;
    _speed = rand()%(10-5+1)+5;
    _life = rand()%(10-5+1)+5;
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
        int x = rand() % 10;
        Champion *chap = new Champion(name_champion[x]);
        player.setChampion(chap);
    }
}