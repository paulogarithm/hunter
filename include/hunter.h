/*
** EPITECH PROJECT, 2022
** hunter_final
** File description:
** hunter
*/

#ifndef HUNTER_H_
    #define HUNTER_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <time.h>

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>

    #include "../include/statics.h"


typedef struct {
    int type;
    int id;

    char *name;
    char *texture;
    sfClock *clock;
    sfSprite *sprite;
    sfText *text;
    int size;
    int raws;
    int orientation;
    int speed;
    int priority;
    int attack;

} hunt_object;


typedef struct {
    int mode;
    int level;
    hunt_object *menu;
    hunt_object *game;

} hunt_instances;

#endif /* !HUNTER_H_ */
