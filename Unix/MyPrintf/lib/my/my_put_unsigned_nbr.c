/*
** EPITECH PROJECT, 2020
** my_put_unsigned_nbr.c
** File description:
** unsigned number display
*/

void my_putchar(char c);

int unsigned_check_false(unsigned int faux, int *nombre)
{
    if (faux == 4294967295) {
        (*nombre)++;
        faux == 0;
    }
    return (faux);
}

void padding_gestion(unsigned int nb, int change, int for_print)
{
    int length = 0;

    for (int i = 1; nb / i >= 10; i *= 10)
        length++;
    if (for_print != -1 && change != 2) {
        for (int j = 0; for_print - length - j > 0; j++)
            my_putchar(' ');
    }
}

void padding_gestion_right(unsigned int nb, int change, int for_print)
{
    int length = 0;

    for (int i = 1; nb / i >= 10; i *= 10)
        length++;
    if (for_print != -1 && change == 2) {
        for (int j = 0; for_print - length - j > 0; j++)
            my_putchar(' ');
    }
}

int my_put_unsigned_nbr(unsigned int nb, int change, int for_print)
{
    unsigned int faux = nb;
    int nombre;

    if (faux == 4294967295)
        nb += 1;
    padding_gestion(nb, change, for_print);
    if (nb >= 0) {
        if (nb >= 10) {
            nombre = (nb % 10);
            nb = (nb - nombre) / 10;
            my_put_unsigned_nbr(nb, change, for_print);
            faux = unsigned_check_false(faux, &nombre);
            my_putchar(nombre + '0');
        } else
            my_putchar(nb + '0');
    }
    padding_gestion_right(nb, change, for_print);
    return (0);
}
