/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** main
*/
#include "my_window.h"
#include "vm.h"
#include "op.h"
#include "my.h"
#include <stdlib.h>

void champ_regs_init(champ_t *champ)
{
    if (!(champ->reg = malloc(sizeof(unsigned char *) * (REG_NUMBER + 1))))
        exit(my_error("Error Malloc.\n", 84));
    for (int j = 0; j < REG_NUMBER + 1; j++)
        champ->reg[j] = NULL;
    for (int j = 0; j < REG_NUMBER; j++)
        if (!(champ->reg[j] = my_calloc_u_char(REG_SIZE + 1, 0)))
            exit(my_error("Error Malloc.\n", 84));
}

champ_t **champs_list_init(void)
{
    champ_t **list = malloc(sizeof(champ_t *) * (MAX_CHAMPS + 1));

    if (!list)
        exit(my_error("Error Malloc.\n", 84));
    for (int i = 0; i < MAX_CHAMPS; i++) {
        list[i] = malloc(sizeof(champ_t));
        if (!list[i])
            exit(my_error("Error Malloc.\n", 84));
        list[i]->champ_nbr = -1;
        list[i]->filepath = NULL;
        list[i]->load_address = -1;
        list[i]->scheduling = -1;
        list[i]->living = true;
        list[i]->last_live_cycle = -1;
        list[i]->live_counter = 0;
        list[i]->carry = false;
        list[i]->child = NULL;
        list[i]->deep_child = 0;
        champ_regs_init(list[i]);
    }
    list[0]->color = (sfColor){59, 249, 243, 255};
    list[0]->color_id = 0;
    list[3]->color = (sfColor){0, 97, 255, 255};
    list[3]->color_id = 3;
    list[2]->color = (sfColor){255, 51, 144, 255};
    list[2]->color_id = 2;
    list[1]->color = (sfColor){245, 98, 255, 255};
    list[1]->color_id = 1;
    return (list);
}

vm_t *vm_init_machine(void)
{
    vm_t *vm = malloc(sizeof(vm_t) * 1);

    vm->dump_time = -1;
    vm->champs_number = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->max_cycle = 0;
    vm->actual_cycle = 0;
    vm->total_living_champ = 0;
    vm->winner = NULL;
    vm->graph = true;
    vm->mem = my_calloc_char(sizeof(unsigned char), MEM_SIZE + 1, 0);
    vm->colors = my_calloc_char(sizeof(unsigned char), MEM_SIZE + 1, 4);
    vm->save_colors = my_calloc_char(sizeof(unsigned char), MEM_SIZE + 1, 4);
    vm->champs = champs_list_init();
    return (vm);
}