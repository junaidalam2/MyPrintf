#include "my_printf.h"


long long unsigned_int_num(long long number){

    long long max_number = MAX_UNSIGNED_INT;
    int is_negative = '\0';

    if(number < 0){
        number *= -1;
        is_negative = 1;
    }

    if(number >= max_number){
        number %= max_number;
    }

    if(is_negative && number){
        number = max_number - number;
    }

    return number;
}


long long signed_int_num(long long number){

    long long max_number = MAX_SIGNED_INT;
    int multiple_of_max = '\0';
    int is_original_num_negative = '\0';
    int print_negative_symbol = '\0';

    if(number < 0){
        number *= -1;
        is_original_num_negative = 1;
        print_negative_symbol = is_original_num_negative;
    }

    if(number >= max_number){
        multiple_of_max = number / max_number;
        number %= max_number;
    }

    if(multiple_of_max && multiple_of_max%2) {
        number = max_number - number;
        print_negative_symbol = 1;

        if(is_original_num_negative){
            print_negative_symbol = 0;
        }
    }

    if(print_negative_symbol){
        number *= -1;

    }
        return number;
}


int stdout_int(long long number){

    int number_of_digits = '\0';
    long long power_of_ten = 1;
    int digit = '\0';
    long long number_for_digit_count = number;
    int digit_to_print = '\0';
    int print_negative_symbol = '\0';
    int char_counter = '\0';

    if(number < 0){
        print_negative_symbol = 1;
        number *= -1;
    }

    while(number_for_digit_count){
        number_for_digit_count /= 10;
        number_of_digits++;
        power_of_ten *= 10;
    }

    if(number == 0){
        number_of_digits++;
    }

    if(print_negative_symbol && number){
        write(1, "-", 1);
        char_counter++;
    }

    for(int i = 0; i < number_of_digits; i++){

        power_of_ten /= 10;

        if( power_of_ten == 0 ){
            power_of_ten = 1;
        }

        digit = number / power_of_ten;
        digit_to_print = digit + '0';
        write(1, &digit_to_print, 1);
        char_counter++;
        number = number - digit * power_of_ten;
    }

    return char_counter;
}


int print_unsigned_int(long long number){

    int char_counter = '\0';

    number = unsigned_int_num(number);
    char_counter = stdout_int(number);

    return char_counter;

}


int print_signed_int(long long number){

    int char_counter = '\0';

    number = signed_int_num(number);
    char_counter = stdout_int(number);

    return char_counter;

}


