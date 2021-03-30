/*
** EPITECH PROJECT, 2021
** setup_plane_tower.c
** File description:
** setup plane and tower
*/

#include "proto.h"

sfCircleShape *create_circle(sfVector2f position, float radius, user_t user)
{
    sfCircleShape *shape = sfCircleShape_create();
    sfVector2f origin;
    sfColor color = user.hitbox_t;

    color.a = 0;
    origin.x = radius;
    origin.y = radius;
    sfCircleShape_setOrigin(shape, origin);
    sfCircleShape_setPosition(shape, position);
    sfCircleShape_setFillColor(shape, color);
    sfCircleShape_setOutlineColor(shape, user.hitbox_t);
    sfCircleShape_setRadius(shape, radius);
    sfCircleShape_setOutlineThickness(shape, 2);
    return (shape);
}

sfRectangleShape *create_rect(sfVector2f position, float radius, user_t user)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f origin;
    sfVector2f size;
    sfColor color = sfBlue;

    size.x = radius;
    size.y = radius;
    origin.x = 10;
    origin.y = 10;
    sfRectangleShape_setOrigin(shape, origin);
    color.a = 0;
    sfRectangleShape_setPosition(shape, position);
    sfRectangleShape_setFillColor(shape, color);
    sfRectangleShape_setOutlineColor(shape, user.hitbox_p);
    sfRectangleShape_setOutlineThickness(shape, 1);
    sfRectangleShape_setSize(shape, size);
    return (shape);
}

void setup_sprite_towers(tower_t *towers, user_t user)
{
    sfVector2f pos;

    for (int i = 0; towers[i].radius != -1; i++) {
        towers[i].screen.texture = sfTexture_createFromFile\
        ("include/pictures/control_tower.png", NULL);
        towers[i].screen.sprite = sfSprite_create();
        sfSprite_setTexture(towers[i].screen.sprite, \
        towers[i].screen.texture, sfTrue);
        pos.x = towers[i].position.x;
        pos.y = towers[i].position.y;
        towers[i].hitbox = create_circle(pos, towers[i].radius, user);
        pos.x -= 25;
        pos.y -= 25;
        sfSprite_setPosition(towers[i].screen.sprite, pos);
    }
}

void setup_sprite(tower_t *towers, plane_t *planes, user_t user)
{
    sfVector2f pos;

    for (int i = 0; planes[i].is_air != -1; i++) {
        planes[i].screen.texture = sfTexture_createFromFile\
        ("include/pictures/plane.png", NULL);
        planes[i].screen.sprite = sfSprite_create();
        sfSprite_setTexture(planes[i].screen.sprite, planes[i].screen.texture, \
        sfTrue);
        pos.x = planes[i].departure.x;
        pos.y = planes[i].departure.y;
        planes[i].hitbox = create_rect(pos, 20, user);
        pos.y -= 10;
        pos.x -= 10;
        sfSprite_setPosition(planes[i].screen.sprite, pos);
    }
    setup_sprite_towers(towers, user);
}
