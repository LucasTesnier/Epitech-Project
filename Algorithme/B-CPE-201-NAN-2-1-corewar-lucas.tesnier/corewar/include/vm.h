/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-corewar-lucas.tesnier
** File description:
** struct
*/

#ifndef VM_H_
#define VM_H_

#include <stdbool.h>
#include "op.h"

#define MAX_CHAMPS 4
#define UINT32(x) ((x>>24)&0xff) | ((x<<8)&0xff0000) | ((x>>8)&0xff00) |\
((x<<24)&0xff000000)

#define USAGE "USAGE\n\
\t.corewar [-dump nbr_cycle] [[-n proh_number] [-a laod_address] prog_name] ...\
\nDESCRIPTION\n\
\t-dump nbr_cycle dumps the memory after the nbr_cycle execution (if the round \
isn't already over) with the following format: 32bytes/line\n\t\t in \
hexadecimal (A0BCDEFE1DD3...)\n\
\t-n prog_number sets the next programs's number. By default, the first free \
number in the parameter order\n\
\t-a load_address sets the next program's loading address. When no address is \
specified, optimize the addresses so that the processes are as far away from \
each other possible. The addresses are MEM_SIZE modulo.\n"

typedef struct champ_s
{
    char *filepath;
    bool living;
    int scheduling;
    int champ_nbr;
    int load_address;
    int prog_count;
    int live_counter;
    int last_live_cycle;
    bool carry;
    unsigned char **reg;
    int deep_child;
    struct champ_s *child;
    header_t header;
} champ_t;

typedef struct vm_s
{
    champ_t **champs;
    champ_t *winner;
    int dump_time;
    int champs_number;
    int actual_cycle;
    int max_cycle;
    int cycle_to_die;
    int total_living_champ;
    unsigned char *mem;
} vm_t;


//flag_handling.c
void champion_list_handling(int ac, char **av, vm_t *machine, int i);
void flags_management(int ac, char **av, vm_t *machine);

//corewar_loop.c
void corewar_loop(vm_t *machine);

//struc_init.c
vm_t *vm_init_machine(void);
void champ_regs_init(champ_t *champ);

//champ_flags_handling.c
void champ_flag_handling(int *number_champs, int *i, vm_t *machine, char **av);

//champ_mem_init.c
void champs_set_adress(vm_t *machine);
void init_champ_register(vm_t *machine);

//memory_init.c
void memory_initialisation(vm_t *machine);

//unsigned_operations.c
unsigned char *unsigned_ncopy(unsigned char *dest, unsigned char *str, \
int size);
unsigned char *my_calloc_u_char(int size, unsigned char c);

//hexdump_display.c
void hexdump_display(vm_t *machine);
void launch_virtual_machine(int ac, char **av);

//---INSTRUCTIONS---
//inst-scheduling.c
bool scheduling_check(vm_t *machine, champ_t *champ, int nb_cycle);
//inst-params.c
int *get_inst_parameters(vm_t *machine, champ_t *champ, op_t op);
bool inst_parms_verif(op_t op, int *params);
//inst-convert_values.c
short hex_to_short(vm_t *machine, int start);
int reg_to_int(unsigned char *reg);
//inst-live.c
bool inst_live(vm_t *machine, champ_t *champ);
//inst-ld.c
bool inst_ld(vm_t *machine, champ_t *champ);
//inst-change_pc.c
void inst_change_pc(champ_t *champ, int *params, op_t op);
//inst-mem_write.c
void write_a_reg(vm_t *machine, int val, unsigned char *reg);
void write_reg_in_mem(vm_t *machine, unsigned char *str, int start, \
champ_t *champ);
//inst-st.c
bool inst_st(vm_t *machine, champ_t *champ);
//inst-add.c
bool inst_add(vm_t *machine, champ_t *champ);
//inst-sub.c
bool inst_sub(vm_t *machine, champ_t *champ);
//inst-and.c
bool inst_and(vm_t *machine, champ_t *champ);
void set_start_from_param(vm_t *machine, int param, unsigned char *val, \
int *start);
//inst-or.c
bool inst_or(vm_t *machine, champ_t *champ);
//inst-xor.c
bool inst_xor(vm_t *machine, champ_t *champ);
//inst-zjmp.c
bool inst_zjmp(vm_t *machine, champ_t *champ);
//inst-ldi.c
bool inst_ldi(vm_t *machine, champ_t *champ);
//inst-sti.c
bool inst_sti(vm_t *machine, champ_t *champ);
//inst-fork.c
bool inst_fork(vm_t *machine, champ_t *champ);
//inst-lld.c
bool inst_lld(vm_t *machine, champ_t *champ);
//inst-lldi.c
bool inst_lldi(vm_t *machine, champ_t *champ);
//inst-lfork.c
bool inst_lfork(vm_t *machine, champ_t *champ);
//inst-aff.c
bool inst_aff(vm_t *machine, champ_t *champ);
#endif /* !STRUCT_H_ */
