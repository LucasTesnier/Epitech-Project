/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** hexdump_display
*/

#include "my.h"
#include "vm.h"
#include "op.h"

void hexa_value_display(vm_t *machine, unsigned char val)
{
    char *hexa = "0123456789ABCDEF";
    char res[3];
    int temp = 0;

    if (val == 0) {
        my_putstr("00");
        return;
    }
    res[0] = '0';
    res[1] = '0';
    res[2] = '\0';
    for (int i = 1; i >= 0 && val > 0; i--) {
        temp = val % 16;
        res[i] = hexa[temp];
        val /= 16;
    }
    my_putstr(res);
}

void hexdump_display(vm_t *machine)
{
    int start = 0;

    my_putchar('0');
    for (int i = 0; i < MEM_SIZE / 32; i++) {
        my_printf("%X\t: ", i * 32);
        hexa_value_display(machine, machine->mem[start]);
        for (int j = 1; j < 32; j++) {
            my_putchar(' ');
            hexa_value_display(machine, machine->mem[j + start]);
        }
        my_putchar('\n');
        start += 32;
    }
}