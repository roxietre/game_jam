/*
** EPITECH PROJECT, 2022
** jam1
** File description:
** player
*/

//class Player that contains all the information about the player like how may ivocation stone he have and also all is champion

#pragma once
#include "champion.hpp"
#include <vector>

class Player {
    public:
        Player(): _stone(10) {}
        ~Player() {}
        int getStone() {return _stone;}
        void setStone(int stone) {_stone += stone;}
        void setChampion(Champion *chap) {_champion.push_back(chap);}
        std::vector<Champion *> getChampion(Champion *chap) {return _champion;}
    private:
        int _stone;
        std::vector<Champion *> _champion;
};