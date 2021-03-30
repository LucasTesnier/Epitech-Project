/*
** EPITECH PROJECT, 2020
** architect.c
** File description:
** all function for architect
*/

#include "../include/proto.h"

float **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int size = 0;
    float **result;

    result = malloc(sizeof(float *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc(sizeof(float) * (nb_cols + 1));
    if (result == NULL)
        exit(84);
    return (result);
}

int is_number(char *str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '.' && str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
            return (84);
    }
}

int check_arg(int ac, char *argv[], int pos)
{
    int error = 0;

    if (pos + 3 > ac)
        return (0);
    if (argv[pos + 3][1] != 't' && argv[pos + 3][1] != 'z' && argv[pos + 3][1] != 'r' && argv[pos + 3][1] != 's') {
        printf("Invalid usage");
        exit (84);
    }
}

int check_arg_two(int ac, char *argv[], int pos)
{
    int error = 0;

    if (pos + 2 > ac)
        return (0);
    if (argv[pos + 2][1] != 't' && argv[pos + 2][1] != 'z' && argv[pos + 2][1] != 'r' && argv[pos + 2][1] != 's') {
        printf("Invalid usage");
        exit (84);
    }
}

void define_arg_t(char *argv[], int pos, int ac, float **matrice, int *first_time)
{
    float **vector = mem_alloc_2d_array(3, 3);
    float **matrice_save = mem_alloc_2d_array(3, 3);

    if (pos + 2 > ac) {
        printf("Invalid number of argument");
        exit (84);
    }
    if (is_number(argv[pos + 1]) == 84 || is_number(argv[pos + 2]) == 84) {
        printf("Invalid vector");
        exit (84);
    }
    check_arg(ac, argv, pos);
    printf("Translation along vector (%.0f, %.0f)\n", atof(argv[pos + 1]), atof(argv[pos + 2]));
    vector[0][0] = 1;
    vector[1][1] = 1;
    vector[2][2] = 1;
    vector[0][2] = atof(argv[pos + 1]);
    vector[1][2] = atof(argv[pos + 2]);
    if (*first_time != 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice_save[i][j] = vector[i][0] * matrice[0][j] + vector[i][1] * matrice[1][j] + vector[i][2] * matrice[2][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice[i][j] = matrice_save[i][j];
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice[i][j] = vector[i][j];
            }
        }
        *first_time = 1;
    }
}

void define_arg_z(char *argv[], int pos, int ac, float **matrice, int *first_time)
{
    float **vector = mem_alloc_2d_array(3, 3);
    float **matrice_save = mem_alloc_2d_array(3, 3);

    if (pos + 2 > ac) {
        printf("Invalid number of argument");
        exit (84);
    }
    if (is_number(argv[pos + 1]) == 84 || is_number(argv[pos + 2]) == 84) {
        printf("Invalid vector");
        exit (84);
    }
    check_arg(ac, argv, pos);
    printf("Scaling by factors %.0f and %.0f\n", atof(argv[pos + 1]), atof(argv[pos + 2]));
    vector[0][0] = atof(argv[pos + 1]);
    vector[1][1] = atof(argv[pos + 2]);
    vector[2][2] = 1;
    if (*first_time != 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice_save[i][j] = vector[i][0] * matrice[0][j] + vector[i][1] * matrice[1][j] + vector[i][2] * matrice[2][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice[i][j] = matrice_save[i][j];
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice[i][j] = vector[i][j];
            }
        }
        *first_time = 1;
    }
}

void define_arg_r(char *argv[], int pos, int ac, float **matrice, int *first_time)
{
    float **vector = mem_alloc_2d_array(3, 3);
    float **matrice_save = mem_alloc_2d_array(3, 3);

    if (pos + 1 > ac) {
        printf("Invalid number of argument");
        exit (84);
    }
    if (is_number(argv[pos + 1]) == 84) {
        printf("Invalid vector");
        exit (84);
    }
    check_arg_two(ac, argv, pos);
    printf("Rotation by a %.0f degree angle\n", atof(argv[pos + 1]));
    vector[0][0] = cos(atof(argv[pos + 1]) * M_PI / 180);
    vector[1][1] = cos(atof(argv[pos + 1]) * M_PI / 180);
    vector[2][2] = 1;
    vector[0][1] = -sin(atof(argv[pos + 1]) * M_PI / 180);
    vector[1][0] = sin(atof(argv[pos + 1]) * M_PI / 180);
    if (*first_time != 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice_save[i][j] = vector[i][0] * matrice[0][j] + vector[i][1] * matrice[1][j] + vector[i][2] * matrice[2][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice[i][j] = matrice_save[i][j];
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice[i][j] = vector[i][j];
            }
        }
        *first_time = 1;
    }
}

void define_arg_s(char *argv[], int pos, int ac, float **matrice, int *first_time)
{
    float **vector = mem_alloc_2d_array(3, 3);
    float **matrice_save = mem_alloc_2d_array(3, 3);

    if (pos + 1 > ac) {
        printf("Invalid number of argument");
        exit (84);
    }
    if (is_number(argv[pos + 1]) == 84) {
        printf("Invalid vector");
        exit (84);
    }
    check_arg_two(ac, argv, pos);
    printf("Reflection over an axis with an inclination angle of %.0f degrees\n", atof(argv[pos + 1]));
    vector[0][0] = cos(2 * atof(argv[pos + 1]) * M_PI / 180);
    vector[1][1] = -cos(2 * atof(argv[pos + 1]) * M_PI / 180);
    if (vector[1][1] < 0 && vector[1][1] > -0.01)
        vector[1][1] = vector[1][1] * -1;
    vector[2][2] = 1;
    vector[0][1] = sin(2 * atof(argv[pos + 1]) * M_PI / 180);
    vector[1][0] = sin(2 * atof(argv[pos + 1]) * M_PI / 180);
    if (*first_time != 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice_save[i][j] = vector[i][0] * matrice[0][j] + vector[i][1] * matrice[1][j] + vector[i][2] * matrice[2][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice[i][j] = matrice_save[i][j];
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrice[i][j] = vector[i][j];
            }
        }
        *first_time = 1;
    }
}

float *architect_receiver(int ac, char *argv[])
{
    int count = 0;
    int nb_count = 0;
    int pos = 1;
    float **matrice = mem_alloc_2d_array(3, 3);
    int first_time = 0;
    int last = 0;
    float *coords = malloc(sizeof(float) * 5);

    for (int i = 1; i < ac; i++) {
        if (argv[i][1] ==  't' || argv[i][1] ==  'z' || argv[i][1] ==  'r' || argv[i][1] ==  's')
            count++;
    }
    if (is_number(argv[1]) == 84 || is_number(argv[2]) == 84) {
        printf("Invalid usage");
        exit (84);
    }
    check_arg(ac, argv, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            matrice[i][j] = 0;
    }
    while (nb_count != count) {
        for (; argv[pos][1] !=  't' && argv[pos][1] !=  'z' && argv[pos][1] !=  'r' && argv[pos][1] !=  's'; pos++);
        if (argv[pos][1] == 't')
            define_arg_t(argv, pos, ac - 1, matrice, &first_time);
        if (argv[pos][1] == 'z')
            define_arg_z(argv, pos, ac - 1, matrice, &first_time);
        if (argv[pos][1] == 'r')
            define_arg_r(argv, pos, ac - 1, matrice, &first_time);
        if (argv[pos][1] == 's')
            define_arg_s(argv, pos, ac - 1, matrice, &first_time);
        nb_count++;
        pos++;
    }
    for (int i = 0; i < 3; i++) {
        last = 1;
        for (int j = 0; j < 3; j++) {
            if (matrice[i][j] < 0 && matrice[i][j] > -0.01)
                matrice[i][j] = matrice[i][j] * -1;
            printf("%.2f", matrice[i][j]);
            if (last != 3)
                printf("\t");
            last++;
        }
        printf("\n");
    }
    printf("(%.2f, %.2f) => (", atof(argv[1]), atof(argv[2]));
    printf("%.2f", matrice[0][0] * atof(argv[1]) + matrice[0][1] * atof(argv[2]) + matrice[0][2] * 1);
    printf(", ");
    printf("%.2f)\n", matrice[1][0] * atof(argv[1]) + matrice[1][1] * atof(argv[2]) + matrice[1][2] * 1);
    coords[0] = atof(argv[1]);
    coords[1] = atof(argv[2]);
    coords[2] = matrice[0][0] * atof(argv[1]) + matrice[0][1] * atof(argv[2]) + matrice[0][2] * 1;
    coords[3] = matrice[1][0] * atof(argv[1]) + matrice[1][1] * atof(argv[2]) + matrice[1][2] * 1;
    return (coords);
}

t_my_framebuffer *framebuffer_create(unsigned int width, unsigned int height)
{
    t_my_framebuffer *framebuffer;

    framebuffer = malloc(sizeof(t_my_framebuffer));
    framebuffer->pixels = malloc(width * height * 32 / 8);
    framebuffer->width = width;
    framebuffer->height = height;
    return (framebuffer);
}

void my_put_pixel(t_my_framebuffer *framebuffer, unsigned int x,
                  unsigned int y, sfColor color)
{
    framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
    framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
    framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
    framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
}

void event_detection(sfRenderWindow *window)
{
    sfEvent event;
    
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void my_put_square(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
    for (int i = x; i < x + 10; i++) {
        for (int j = y; j < y + 10; j++)
            my_put_pixel(framebuffer, i, j, color);
    }
}

void window(int ac, char *argv[])
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    t_my_framebuffer *framebuffer = framebuffer_create(800, 600);
    sfTexture* texture = sfTexture_create(800, 600);
    sfSprite* sprite = sfSprite_create();
    float *coords = architect_receiver(ac, argv);
    int *new_cord = malloc(sizeof(int) * 5);

    window = sfRenderWindow_create(mode, "102 architect", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfSprite_setTexture(sprite, texture, sfTrue);
    for (int i = 0; i < 800; i++) {
        for (int j = 0; j < 600; j++)
            my_put_pixel(framebuffer, i, j, sfWhite);
    }
    for (int i = 0; i < 600; i++)
        my_put_pixel(framebuffer, 400, i, sfBlue);
    for (int i = 0; i < 800; i++)
        my_put_pixel(framebuffer, i, 300, sfBlue);
    new_cord[0] = 400 + ((int) coords[0] * 10);
    new_cord[1] = 300 + ((int) coords[1] * -10);
    new_cord[2] = 400 + ((int) coords[2] * 10);
    new_cord[3] = 300 + ((int) coords[3] * -10);
    if (coords[0] >= 39 || coords[0] <= -39) {
        printf("For graphical please put a value between -39 and 39");
        exit (84);
    }
    if (coords[2] >= 39 || coords[2] <= -39) {
        printf("For graphical please put a value between -39 and 39");
        exit (84);
    }
    if (coords[1] >= 29 || coords[1] <= -29) {
        printf("For graphical please put a value between -29 and 29");
        exit (84);
    }
    if (coords[3] >= 29 || coords[3] <= -29) {
        printf("For graphical please put a value between -29 and 29");
        exit (84);
    }
    my_put_square(framebuffer, new_cord[0], new_cord[1], sfRed);
    my_put_square(framebuffer, new_cord[2], new_cord[3], sfGreen);
    while (sfRenderWindow_isOpen(window)) {
        event_detection(window);
        sfTexture_updateFromPixels(texture, framebuffer->pixels, \
        framebuffer->width, framebuffer->height, 0, 0);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
