/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** all function for main
*/

#include "../include/proto.h"

float **mem_alloc_2d_array_f(int nb_rows, int nb_cols)
{
    int size = 0;
    float **result;

    result = malloc(sizeof(float *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc(sizeof(float) * (nb_cols + 1));
    return (result);
}

int **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int size = 0;
    int **result;

    result = malloc(sizeof(int *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        result[i] = malloc(sizeof(int) * (nb_cols + 1));
    return (result);
}

float calc_delt(float **matrice)
{
    float res = 0;
    float **copy = mem_alloc_2d_array_f(3, 5);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            copy[i][j] = matrice[i][j];
        }
    }
    copy[0][3] = matrice[0][0];
    copy[0][4] = matrice[0][1];
    copy[1][3] = matrice[1][0];
    copy[1][4] = matrice[1][1];
    copy[2][3] = matrice[2][0];
    copy[2][4] = matrice[2][1];
    res = (copy[0][0] * copy[1][1] * copy[2][2] + copy[0][1] * copy[1][2] * copy[2][3] + copy[0][2] * copy[1][3] * copy[2][4]) - (copy[0][4] * copy[1][3] * copy[2][2] + copy[0][3] * copy[1][2] * copy[2][1] + copy[0][2] * copy[1][1] * copy[2][0]);
    return (res);
}

int **inverse_matrice(float **matrice)
{
    int **inverse = mem_alloc_2d_array(3, 3);

    inverse[0][0] = matrice[1][1] * matrice[2][2] - matrice[2][1] * matrice[1][2];
    inverse[0][1] = -1  * (matrice[1][0] * matrice[2][2] - matrice[2][0] * matrice[1][2]);
    inverse[0][2] = matrice[1][0] * matrice[2][1] - matrice[2][0] * matrice[1][1];
    inverse[1][0] = -1 * (matrice[0][1] * matrice[2][2] - matrice[2][1] * matrice[0][2]);
    inverse[1][1] = matrice[0][0] * matrice[2][2] - matrice[2][0] * matrice[0][2];
    inverse[1][2] = -1 * (matrice[0][0] * matrice[2][1] - matrice[2][0] * matrice[0][1]);
    inverse[2][0] = matrice[0][1] * matrice[1][2] - matrice[1][1] * matrice[0][2];
    inverse[2][1] = -1 * (matrice[0][0] * matrice[1][2] - matrice[1][0] * matrice[0][2]);
    inverse[2][2] = matrice[0][0] * matrice[1][1] - matrice[1][0] * matrice[0][1];
//    display_matrix(3, 3, inverse, 1, 1);
    return (inverse);
}

void display_message(int a, int b, int **matrix)
{
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d", matrix[i][j]);
            if (i != a - 1 || j != b - 1)
                printf(" ");
        }
    }
    printf("\n");
}

void display_matrix(int a, int b, float **matrix, int w)
{
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (w == 1)
                printf("%.3f", matrix[i][j]);
            if (w == 0)
                printf("%.0f", matrix[i][j]);
            if (j != b - 1)
                printf("\t");
        }
        printf("\n");
    }
}

int arrondi(float nbr)
{
    return (floor(nbr + 0.5));
}

int main(int ac, char *argv[])
{
    float **key;
    float **message;
    int **res;
    int n = 0;

    if (ac != 4) {
        if (ac == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
            printf("USAGE\n   ./103cipher message key flag\n\nDESCRIPTION\n   message    a message, made of ASCII characters\n   key        the encryption key, made of ASCII characters\n   flag       0 for the message to be encrypted, 1 to be decrypted\n");
            return (0);
        }
        printf("Invalid arguments, try with -h\n");
        return (84);
    }
    if (atoi(argv[3]) != 0 && atoi(argv[3]) != 1)
        return (84);
    for (; pow(n, 2) < strlen(argv[2]); n++);
    key = mem_alloc_2d_array_f(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            key[i][j] = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (count < strlen(argv[2])) {
                key[i][j] = argv[2][count];
            }
            count++;
        }
    }
    if (atoi(argv[3]) == 1) {
        float **inverse;
        if (n != 1) {
            if (!test_inverse(key, n)) {
                printf("Invalid Key\n");
                exit (84);
            }
            inverse = new_inverse_matrice(key, n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    key[i][j] = inverse[i][j];  
                    /*if (key[i][j] <= -0.000 && key[i][j] >= -0.001)
                        key[i][j] = 0;*/
                }
            }
        }
    }
    printf("Key matrix:\n");
    display_matrix(n, n, key, atoi(argv[3]));
    if (atoi(argv[3]) == 0) {
        int x = 0;
        for (; n * x < strlen(argv[1]); x++);
        message = mem_alloc_2d_array_f(x, n);
        count = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < n; j++) {
                if (count < strlen(argv[1])) {
                    message[i][j] = argv[1][count];
                } else
                    message[i][j] = 0;
                count++;
            }
        }
        int save = 0;
        res = mem_alloc_2d_array(x, n);
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < n; j++) {
                save = 0;
                for (int k = 0; k < n; k++)
                    save += message[i][k] * key[k][j];
                res[i][j] = save;
                //res[i][j] = message[i][0] * key[0][j] + message[i][1] * key[1][j] + message[i][2] * key[2][j];
            }
        }
        printf("\nEncrypted message:\n");
        display_message(x, n, res);
    }
    if (atoi(argv[3]) == 1) {
        int m = 0;
        int mm = 0;
        int cnt = 0;
        for (int i = 0; i < strlen(argv[1]); i++) {
            if (argv[1][i] == ' ' || i == 0)
                m++;
        }
        int *mes = malloc(sizeof(int) * m + 1);
        for (int i = 0; i < strlen(argv[1]); i++) {
            if (argv[1][i] == ' ' || i == 0) {
                mes[cnt] = atoi(argv[1] + i);
                cnt++;
            }
        }
        cnt = 0;
        for (; mm * n < m; mm++);
        float **mes_m = mem_alloc_2d_array_f(mm, n);
        for (int i = 0; i < mm; i++) {
            for (int j = 0; j < n; j++) {
                if (cnt < m) {
                    mes_m[i][j] = mes[cnt];
                } else
                    mes_m[i][j] = 0;
                cnt++;
            }
        }
        float save = 0;
        int **ress = mem_alloc_2d_array(mm, n);
        printf("\nDecrypted message:\n");
        if (n != 1) {
            for (int i = 0; i < mm; i++) {
                for (int j = 0; j < n; j++) {
                    save = 0;
                    for (int k = 0; k < n; k++)
                        save += mes_m[i][k] * key[k][j];
                    //save = arrondi(mes_m[i][0] * key[0][j] + mes_m[i][1] * key[1][j] + mes_m[i][2] * key[2][j]);
                    save = arrondi(save);
                    ress[i][j] = save;
                    if (ress[i][j] != 0)
                        printf("%c", ress[i][j]);
                }
            }
        } else {
            for (int i = 0; i < mm; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%c", arrondi(mes_m[i][j]/key[0][0]));
                }
            }
        }
        printf("\n");
    }
}