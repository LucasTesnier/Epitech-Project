/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** recursive function that return a number shaft to the power
*/

void my_putchar(char c);

int my_compute_power_rec(int nb, int p);

int my_compute_power_rec(int nb, int p)
{
    int result;

    result = nb;
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (result);
    result = result * my_compute_power_rec(result, p - 1);
    return (result);
}
