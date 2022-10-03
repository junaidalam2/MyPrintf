#include "my_printf.h"

int format_handler(char case_letter, va_list *arg){

    int char_counter = '\0';

    switch(case_letter){
            case 'u':
                    char_counter = print_unsigned_int(va_arg(*arg, long long));
                    break;
            case 'd':
                    char_counter = print_signed_int(va_arg(*arg, long long));
                    break;
            case 'c':
                    char_counter = print_char(va_arg(*arg, int));
                    break;
            case 's':
                    char_counter = print_string(va_arg(*arg, char*));
                    break;
            case 'o':
            case 'X':
            case 'x':
                    char_counter = print_nondecimal(va_arg(*arg, long long), case_letter);
                    break;
            case 'p':
                    char_counter = print_pointer(va_arg(*arg, long long), case_letter);
                    break;
            case '%':
                    write(1, "%", 1);
                    char_counter++;
                    break;
            default:
                    break;
        }

    return char_counter;

}

