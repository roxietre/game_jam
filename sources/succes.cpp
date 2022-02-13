/*
** EPITECH PROJECT, 2022
** jam1
** File description:
** succes
*/

#include <SFML/Graphics.hpp>
#include "GashaSmash.hpp"

void set_success(Player &player)
{
    if (player.getChampion().size() > 1) {
        player.setSuccess("invocation");
    }
    if (player.getChampion().size() > 5) {
        player.setSuccess("multi summon");
    }
    if (player.getChampion().size() > 10) {
        player.setSuccess("ultra summon");
    }
    if (player.getLevel() > 0) {
        player.setSuccess("finsih level 1");
    }
    if (player.getLevel() > 1) {
        player.setSuccess("finsih level 2");
    }
    if (player.getLevel() > 2) {
        player.setSuccess("finsih level 3");
    }
    if (player.getLevel() > 3) {
        player.setSuccess("Kill boss");
    }

}