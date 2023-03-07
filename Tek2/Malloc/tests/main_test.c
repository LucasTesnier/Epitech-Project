/*
** EPITECH PROJECT, 2022
** Malloc
** File description:
** main_test
*/

int main(int ac, char **av)
{
    char *temp = malloc(sizeof(char) * 5);

    temp[0] = 'A';
    temp[1] = 'B';
    temp[2] = 'C';
    temp[3] = 'D';
    temp[4] = '\0';

    write(1, temp, 5);
    temp = realloc(temp, sizeof(char) * 6);
    temp[0] = 'A';
    temp[1] = 'B';
    temp[2] = 'C';
    temp[3] = 'D';
    temp[4] = 'E';
    temp[5] = '\0';
    write(1, temp, 6);
    temp = calloc(6, char);
    write(1, temp, 6);
    free(temp);
    return 0;
}