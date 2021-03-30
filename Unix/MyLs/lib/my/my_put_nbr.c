/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Desc
*/

void my_putchar(char c);

int check_false(int faux, int *nombre)
{
    if (faux == -2147483648) {
        (*nombre)++;
        faux == 0;
    }
    return (faux);
}

int my_put_nbr(int nb)
{
    int faux = nb;
    int nombre;

    if (faux == -2147483648)
        nb += 1;
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb >= 0) {
        if (nb >= 10) {
            nombre = (nb % 10);
            nb = (nb - nombre) / 10;
            my_put_nbr(nb);
            faux = check_false(faux, &nombre);
            my_putchar(nombre + '0');
        } else
            my_putchar(nb + '0');
    }
    return (0);
}
