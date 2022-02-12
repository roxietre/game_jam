/*
** EPITECH PROJECT, 2022
** jam1
** File description:
** champion
*/

#pragma once

class Champion
{
    public:
        virtual ~Champion();
        virtual void Attack(Champion *chap) {chap->_life -= this->_attack - chap->_armor;};
        virtual void SpecialAttack(Champion *chap) {chap->_life -= this->_specialAttack - chap->_specialArmor;};

        virtual int getAttack() {return _attack;};
        virtual int getSpeed() {return _speed;};
        virtual int getSpecialAttack() {return _specialAttack;};
        virtual int getLife() {return _life;};
        virtual int getSpecialAtt() {return _specialAttack;};
        virtual int getSpecialDef() {return _specialArmor;};

    protected:
        int _attack;
        int _armor;
        int _specialAttack;
        int _specialArmor;
        int _life;
        int _speed;
};