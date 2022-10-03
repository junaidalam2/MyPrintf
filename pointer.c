#include "my_printf.h"


int print_pointer(long long decimal_number, char case_letter){

    int char_counter = 2;

    write(1, "0x", 2);
    char_counter += print_nondecimal(decimal_number, case_letter);

    return char_counter;

}


