/*
** EPITECH PROJECT, 2022
** jam1
** File description:
** succes
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GashaSmash.hpp"

void verif_success(Player &player)
{
    if (player.getChampion().size() >= 1) {
        player.setTrueSuccess(1);
    }
    if (player.getChampion().size() >= 5) {
        player.setTrueSuccess(2);
    }
    if (player.getChampion().size() >= 10) {
        player.setTrueSuccess(3);
    }
    if (player.getLevel() > 0) {
        player.setTrueSuccess(4);
    }
    if (player.getLevel() > 1) {
        player.setTrueSuccess(5);
    }
    if (player.getLevel() > 2) {
        player.setTrueSuccess(6);
    }
    if (player.getLevel() > 3) {
        player.setTrueSuccess(7);
    }

}

void set_success(Player &player)
{
    player.setSuccess("invocation");
    player.setSuccess("multi summon");
    player.setSuccess("ultra summon");
    player.setSuccess("finsih level 1");
    player.setSuccess("finsih level 2");
    player.setSuccess("finsih level 3");
    player.setSuccess("Kill boss");
}