/*
** EPITECH PROJECT, 2022
** jam1
** File description:
** champion
*/

#pragma once
#include <SFML/Graphics.hpp>

class Champion
{
    public:
        Champion(std::vector<std::string> sprit, int attack, int armor, int speed, int life, int spearm, int speatt) : _sprit(sprit), _attack(attack), _armor(armor), _speed(speed), _life(life), _specialArmor(spearm), _specialAttack(speatt) {_Maxhp = _life;}
        Champion(std::string);
        ~Champion() {};
        void Attack(Champion *&chap) {chap->_life -= this->_attack /*- chap->_armor*/;};
        void SpecialAttack(Champion *&chap) {chap->_life -= this->_specialAttack - chap->_specialArmor;};
        int getAttack() {return _attack;};
        int getSpeed() {return _speed;};
        int getSpecialAttack() {return _specialAttack;};
        int getLife() {return _life;};
        int getSpecialAtt() {return _specialAttack;};
        int getSpecialDef() {return _specialArmor;};
        std::vector<std::string> getSprit() {return _sprit;};
        void setSprit(std::vector<std::string> sprit) {_sprit = sprit;};
        void evolution_up(int att, int armor, int speed, int life, int spearm, int speatt) {_attack += att; _armor += armor; _speed += speed; _life += life; _specialArmor += spearm; _specialAttack += speatt;};
        void setLife(int life) {_life = life;}
        int getMax() const {return _Maxhp;}
        void setName(std::string name) {_name = name;}
        std::string getName() const {return _name;}
    protected:
        std::string _name;
        int _attack;
        int _armor;
        int _specialAttack;
        int _specialArmor;
        int _life;
        int _Maxhp;
        int _speed;
        std::vector<std::string> _sprit;
};