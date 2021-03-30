/*
** EPITECH PROJECT, 2021
** shadow
** File description:
** desc
*/

#include "my_world.h"

void shadow(my_game_t *my_game, int i, int j)
{
    float progress = my_game->progress_bar->progress;
    int ratio = (progress > 0.25 && progress < 0.75) ? (progress - 0.5) *   \
2 * 200 : (0.25 - 0.5) * 2 * 200;
    float ratio_night = init_ratio_night(progress);

    ratio = (ratio >= 0) ? ratio * -1 : ratio;
    if ((progress < 0.5 && my_game->my_map.map_height[i][j] >   \
    my_game->my_map.map_height[i + 1][j]) || (progress > 0.5 && \
    my_game->my_map.map_height[i][j] >  \
    my_game->my_map.map_height[i][j + 1])) {
        sfConvexShape_setFillColor(my_game->convexShape,    \
        (sfColor){200 + ratio, 200 + ratio, 200 + ratio, 255});
    } else if (progress < 0.3 || progress > 0.7)
        sfConvexShape_setFillColor(my_game->convexShape,    \
        (sfColor){200 + ratio_night, 200 + ratio_night, 200 +   \
            ratio_night, 255});
    else
        sfConvexShape_setFillColor(my_game->convexShape,    \
        (sfColor){200, 200, 200, 255});
}