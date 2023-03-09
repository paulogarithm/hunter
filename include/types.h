/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** types
*/

#ifndef TYPES_H_
    #define TYPES_H_

    #include "../include/hunter.h"

/*
**  type, id, name, path, NULL, NULL, NULL
**  size, raws, orientation, speed, priority, isattack
*/

static const hunt_object hunt_typeEMPTY = {
    -1, 0, "Empty", NULL, NULL, NULL, NULL,
    0, 0, 0, 0, 0, 0
};
static const hunt_object hunt_typeENNEMY = {
    1, 0, "[Ennemy]", "assets/ennemy_sprite.png", NULL, NULL, NULL,
    32, 4, 1, 0, 2, 0
};
static const hunt_object hunt_typeBRIDGE = {
    2, 0, "[Bridge]", "assets/bridge.png", NULL, NULL, NULL,
    300, 1, 0, 0, 1, 0
};
static const hunt_object hunt_typeHAND = {
    3, 0, "[Hand]", "assets/hand.png", NULL, NULL, NULL,
    32, 1, 0, 0, 3, 0
};
static const hunt_object hunt_typeCLOUD = {
    4, 0, "[Cloud Top]", "assets/cloud.png", NULL, NULL, NULL,
    64, 1, 1, 0, 0, 0
};
static const hunt_object hunt_typeCLOUD2 = {
    4, 0, "[Cloud Behind]", "assets/cloud.png", NULL, NULL, NULL,
    64, 1, 1, 0, -1000, 0
};
static const hunt_object hunt_typeWINDOW = {
    5, 0, "[Window]", "", NULL, NULL, NULL,
    0, 0, 0, 0, 0, 0
};
static const hunt_object hunt_typePLAYBTN = {
    6, 0, "Play", "", NULL, NULL, NULL,
    64, 0, 0, 0, 0, 0
};
static const hunt_object hunt_typeHEALTH = {
    7, 0, "[Health]", "assets/health.png", NULL, NULL, NULL,
    64, 0, 0, 0, 100, 0
};

#endif /* !TYPES_H_ */
