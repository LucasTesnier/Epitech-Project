/*
** EPITECH PROJECT, 2021
** init_sprite
** File description:
** desc
*/

#include "my_world.h"

my_sprite_t new_sprite(int sprite_name, char *pathname, sfIntRect *area)
{
    my_sprite_t sprite;

    sprite.sprite_name = sprite_name;
    sprite.area = area;
    sprite.pathname = pathname;
    sprite.image = sfImage_createFromFile(sprite.pathname);
    sprite.texture = sfTexture_createFromImage(sprite.image, sprite.area);
    sprite.sprite = sfSprite_create();
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    return (sprite);
}

my_sprite_t *sprite_init(void)
{
    my_sprite_t *sprites = malloc(sizeof(my_sprite_t) * 3);

    sprites[0] = new_sprite(1, "assets/pictures/background.png", NULL);
    sprites[1] = new_sprite(0, "assets/pictures/title1.png", NULL);
    return (sprites);
}

void display_sprites(sfRenderWindow *window, my_sprite_t *sprites)
{
    for (int i = 0; i < 2; i++) {
        sfRenderWindow_drawSprite(window, sprites[i].sprite, NULL);
    }
}

my_sprite_t *my_sprite_init(void)
{
    my_sprite_t *my_sprite;

    my_sprite = malloc(sizeof(my_sprite_t) * 5);
    my_sprite[0] = new_sprite(WATER, "assets/pictures/new_water.png", NULL);
    my_sprite[1] = new_sprite(GRASS, "assets/pictures/new_grass.png", NULL);
    my_sprite[2] = new_sprite(STONE, "assets/pictures/new_stone.png", NULL);
    my_sprite[3] = new_sprite(SAND, "assets/pictures/new_sand.png", NULL);
    my_sprite[4] = new_sprite(SNOW, "assets/pictures/new_snow.png", NULL);
    return (my_sprite);
}