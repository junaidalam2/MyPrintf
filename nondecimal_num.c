#include "my_printf.h"


char *create_digits_array(char case_letter){

    int array_size = HEXADECIMAL_BASE;
    char *digits_array = malloc(sizeof(char)*array_size);

    for(int i = 0; i < array_size; i++){
        if(i > 9){
            if(case_letter == 'X'){
                digits_array[i] = 65 + (i - 10);
            } else{
                digits_array[i] = 97 + (i - 10);
            }
        } else{
            digits_array[i] = 48 + i;
        }
    }

    return digits_array;
}


char *convert_decimal(long long decimal_number, char case_letter){

    char *digits_array = create_digits_array(case_letter);

    const int array_size = 12;
    char *converted_num_array = malloc(sizeof(char)*array_size);

    char default_value = '\0';

    if(case_letter == 'p') {
        default_value = '0';
    }

    for(int i = 0; i <= array_size; i++){
        converted_num_array[i] = default_value;
    }

    int conversion_flag = 0;
    long long numerator = decimal_number;
    int quotient = '\0';
    int remainder = '\0';
    int i = '\0';
    int base = HEXADECIMAL_BASE;

    if(case_letter == 'o'){
        base = OCTAL_BASE;
    }

    while(conversion_flag == 0 && i < array_size) {

        quotient = numerator / base;
        remainder = numerator % base;
        converted_num_array[array_size - 1 - i] = digits_array[remainder];
        numerator = quotient;
        i++;

        if(remainder == 0 && quotient < 10 && i < array_size){
            converted_num_array[array_size - 1 - i] = digits_array[quotient];
            conversion_flag = 1;
        }
    }

    free(digits_array);

    return converted_num_array;
}


int stdout_converted_num(char* converted_num_array, char case_letter){

    int print_flag = '\0';
    int char_counter = '\0';

    if(case_letter == 'p'){
        print_flag = 1;
    }

    for(int i = 0; i < 12; i++){
        converted_num_array[i] = converted_num_array[i];

        if(converted_num_array[i] > '0' || i == 11){
            print_flag = 1;
        }

        if(print_flag){
            write(1, &converted_num_array[i], 1);
            char_counter++;
        }
    }

    return char_counter;
}


int print_nondecimal(long long decimal_number, char case_letter){

    int char_counter = '\0';

    decimal_number = unsigned_int_num(decimal_number);
    char *converted_num_array = convert_decimal(decimal_number, case_letter);
    char_counter = stdout_converted_num(converted_num_array, case_letter);

    free(converted_num_array);

    return char_counter;
}

