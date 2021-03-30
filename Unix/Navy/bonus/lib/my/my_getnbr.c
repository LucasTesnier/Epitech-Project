/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** return numbers was on the string
*/

int modif_number(char const *str, int count, int number, int is_neg)
{
    int j_count = 0;

    for (j_count = count; str[j_count] <= '9' &&
    str[j_count] >= '0'; j_count++) {
        number = number * 10 + str[j_count]-'0';
        if (number < 0 && (number != -2147483648 || is_neg % 2 != 1))
            return (0);
    }
    return (number);
}

int my_getnbr(char const *str)
{
    int number = 0;
    int count = 0;
    int is_neg = 0;
    int j_count = 0;

    while ((str[count] < '0' || str[count] > '9') && str[count] != 0)
        count++;
    for (j_count = 0; (j_count < count) && (str[j_count] == '-' ||
    str[j_count] == '+'); j_count++) {
        if (str[j_count] == '-')
            is_neg++;
    }
    number = modif_number(str, count, number, is_neg);
    if (number == 0)
        return (0);
    if (is_neg % 2 == 1 && number > 0)
        number *= -1;
    return (number);
}
