/*
** EPITECH PROJECT, 2020
** push_swap_bis.c
** File description:
** all function for pushswap
*/

#include "../include/proto.h"

linked_list_t *get_nbr(int ac, char *argv[])
{
    linked_list_t *list_last;
    linked_list_t *list_first;
    linked_list_t *list = malloc(sizeof(linked_list_t));

    list->data = my_getnbr(argv[1]);
    list->prev = list;
    list->next = list;
    list_first = list;
    for (int i = 2; i < ac; i++) {
        linked_list_t *list_next = malloc(sizeof(linked_list_t));
        list_next->data = my_getnbr(argv[i]);
        list_next->next = list_first;
        list->next = list_next;
        list_last = list;
        list = list->next;
        list->prev = list_last;
    }
    list_last = list;
    list = list->next;
    list->prev = list_last;
    return (list);
}

void display_res_bis(int *res, int size, int i, char *display)
{
    if (res[i] == 5)
        display = my_strcat(display, "pb");
    if (res[i] == 6)
        display = my_strcat(display, "ra");
    if (res[i] == 7)
        display = my_strcat(display, "rb");
    if (res[i] == 8)
        display = my_strcat(display, "rr");
    if (res[i] == 9)
        display = my_strcat(display, "rra");
    if (res[i] == 10)
        display = my_strcat(display, "rrb");
    if (res[i] == 11)
        display = my_strcat(display, "rrr");
    if (i < size - 1)
        display = my_strcat(display, " ");
}

void display_res(int *res, int size)
{
    char *display = malloc(sizeof(char) * 50);

    for (int i = 0; i < size; i++) {
        if (res[i] == 1)
            display = my_strcat(display, "sa");
        if (res[i] == 2)
            display = my_strcat(display, "sb");
        if (res[i] == 3)
            display = my_strcat(display, "sc");
        if (res[i] == 4)
            display = my_strcat(display, "pa");
        display_res_bis(res, size, i, display);
        if (i % 12 == 0) {
            write(1, display, my_strlen(display));
            free(display);
            display = malloc(sizeof(char) * 50);
        }
    }
    write(1, display, my_strlen(display));
    my_putchar('\n');
}

int verif_sort(linked_list_t *lista, int sizea)
{
    linked_list_t *save_l = lista;
    linked_list_t *save_m = lista;

    for (int i = 0; i <= sizea; i++) {
        for (int j = i + 1; j <= sizea; j++) {
            if (save_l->data > save_m->data)
                return (84);
            save_m = save_m->next;
        }
        save_l = save_l->next;
        save_m = save_l;
    }
    return (0);
}

int setup(int ac, linked_list_t **lista, int sizea, char *argv[])
{
    *lista = get_nbr(ac, argv);
    if (ac > 20000) {
        my_putstr("To long list");
        return (0);
    }
    if (verif_sort(*lista, sizea) == 0) {
        my_putchar('\n');
        return (0);
    }
    return (1);
}
