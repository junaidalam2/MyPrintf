#ifndef PRINTF_H_INCLUDED
#define PRINTF_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

#define OCTAL_BASE 8
#define HEXADECIMAL_BASE 16
#define MAX_SIGNED_INT 2147483648
#define MAX_UNSIGNED_INT 4294967296

long long unsigned_int_num(long long number);
long long signed_int_num(long long number);
int stdout_int(long long number);
int print_unsigned_int(long long number);
int print_signed_int(long long number);
int print_char(int ascii_number);
int print_string(char* string);
char *create_digits_array(char case_letter);
char *convert_decimal(long long decimal_number, char case_letter);
int stdout_converted_num(char* converted_num_array, char case_letter);
int print_nondecimal(long long decimal_number, char case_letter);
int print_pointer(long long decimal_number, char case_letter);
int format_handler(char case_letter, va_list *arg);
int my_printf(char* format, ...);


#endif // PRINTF_H_INCLUDED
