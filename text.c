#include "my_printf.h"


int print_char(int ascii_number){

    write(1, &ascii_number, 1);

    return 1;
}


int print_string(char* string){

    int i = '\0';

    if(!string){
        char null[7] = {'(', 'n', 'u', 'l', 'l', ')', '\0'};
        for(i = 0; null[i]; i++){
            write(1, &null[i], 1);
        }
    } else {
        for(i = 0; string[i]; i++){
            write(1, &string[i], 1);
        }
    }

    return i;
}

