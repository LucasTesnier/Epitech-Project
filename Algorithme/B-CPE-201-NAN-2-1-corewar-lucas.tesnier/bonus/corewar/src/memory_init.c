/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** memory_init
*/

#include "my.h"
#include "vm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void check_ext(char *path, vm_t *machine)
{
    if (my_strcmp(".cor", path + my_strlen(path) - 4) != 0) {
        destroy_graph(machine);
        exit(my_error("Please select a good champion extension.\n", 84));
    }
}

void write_champ_in_memory(unsigned char *instruction_list, champ_t *champ, \
vm_t *machine)
{
    int count = 0;
    int prog_size = champ->header.prog_size;
    int load_address = champ->load_address;

    for (int i = load_address; i < prog_size + load_address; i++) {
        if (machine->mem[i % MEM_SIZE] != 0) {
            destroy_graph(machine);
            exit(my_error("Program is writing on another.\n", 84));
        }
        machine->mem[i % MEM_SIZE] = instruction_list[count];
        machine->colors[i % MEM_SIZE] = champ->color_id;
        count++;
        if (i % 2)
            draw_graph(machine, true);
    }
    text_change_buffer(&(machine->window->texts[champ->champ_nbr - 1]), champ->header.prog_name);
    text_change_is_display(&(machine->window->texts[champ->champ_nbr - 1]), true);
}

void get_champion_content(int fd, champ_t *champ, vm_t *machine)
{
    unsigned char *instruction_list = NULL;

    read(fd, &champ->header, sizeof(header_t));
    champ->header.magic = UINT32(champ->header.magic);
    champ->header.prog_size = UINT32(champ->header.prog_size);
    if (champ->header.magic != COREWAR_EXEC_MAGIC) {
        destroy_graph(machine);
        exit(my_error("Invalid Magic Number.\n", 84));
    }
    instruction_list = my_calloc_char(sizeof(unsigned char), \
    champ->header.prog_size + 1, 0);
    read(fd, instruction_list, champ->header.prog_size);
    write_champ_in_memory(instruction_list, champ, machine);
    free(instruction_list);
}

void memory_initialisation(vm_t *machine)
{
    int fd;

    for (int i = 0; i < machine->champs_number; i++) {
        check_ext(machine->champs[i]->filepath, machine);
        fd = open(machine->champs[i]->filepath, O_RDONLY);
        if (fd < 0) {
            destroy_graph(machine);
            exit(my_error("The Champion cannot be open.\n", 84));
        }
        get_champion_content(fd, machine->champs[i], machine);
    }
}