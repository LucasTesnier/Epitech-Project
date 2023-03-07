#include <stdio.h>
#include "dissas.h"

int main(int ac, char **av) {
    dissas_t *dump;

    if (ac != 2 || !(dump = init_dissas()))
        return (84);
    if(!get_cor_file(dump, av[1]))
        return (84);
    write_meta_data(dump);
    write_instructions_from_bytecode(dump);
    fclose(dump->asm_fp);
    return (0);
}
