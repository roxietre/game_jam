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

typedef struct  success_s
{
    bool _is;
    std::string _message;
}success_t;

class Player {
    public:
        Player(): _stone(10000),_level(0) {}
        ~Player() {}
        int getStone() {return _stone;}
        void setStone(int stone) {_stone += stone;}
        void setChampion(Champion *chap) {_champion.push_back(chap);}
        std::vector<Champion *> getChampion() {return _champion;}
        std::vector<Champion *> getTeam() {return _team;}
        void addTeam(Champion *chap) {_team.push_back(chap);}

        std::vector<Champion *> _team;
        int getLevel() const {return _level;}
        void setLevel(int level) {_level = level;}
        void setSuccess(std::string message) {success_t success; success._is = false; success._message = message; _success.push_back(success);}
        void setTrueSuccess(int n) { _success[n -1]._is = true;};
        std::vector<success_t> getSuccess() const {return _success;}
    private:
        int _stone;
        int _level;
        std::vector<Champion *> _champion;
        std::vector<success_t> _success;
};

