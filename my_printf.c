#include "my_printf.h"


int my_printf(char* restrict format, ...)
{

    va_list arg;
    va_start(arg, format);

    char case_letter_array[10] = {'u', 'd', 'c', 's', 'o', 'X', 'x', 'p', '%', '\0'};
    char case_letter = '\0';
    int format_handler_flag = '\0';
    int char_counter = '\0';


    for(int i = 0; format[i]; i++) {

        if(format[i] == '%' && format[i + 1]){

            for(int j = 0; j < 9 ; j++){
                if(format[i + 1] == case_letter_array[j]){
                   format_handler_flag = 1;
                }
            }
        }

        if(format_handler_flag){

            case_letter = format[i + 1];
            char_counter += format_handler(case_letter, &arg);
            i++;
            case_letter = '\0';
            format_handler_flag = 0;

        } else if (format[i] == '\\' && format[i + 1] == 'n') {

            write(1, &"\n", 1);
            char_counter++;
            i++;

        } else {

            write(1, &format[i], 1);
            char_counter++;

        }
    }

    va_end(arg);

    return char_counter;
}
