# Welcome to My Printf
***

## Task
my_printf replicates certain print modifiers of the 'printf' function within C. The print modifiers replicated are:

* '%d', '%u', '%X', '%x', '%o', '%p', '%c', '%s', '%%'

Furthermore, '\n' can be applied to create a new line.

## Description
my_printf takes inputs in the same manner as the 'printf' function within C. 

my_printf uses variable length arguments to obtain inputs. The relevant function is called by my_printf based on the print modifier provided by the user. 

The output of my_printf is via stdout in the same format as 'printf' for the relevant print modifiers. 


## Screenshot
Example input and output:

Input:
![Screenshot](https://github.com/junaidalam2/MyPrintf/blob/main/screenshot_input.jpg?raw=true)

Output:
![Screenshot](https://github.com/junaidalam2/MyPrintf/blob/main/screenshot_output.jpg?raw=true)

## Installation
The application uses a GCC compiler for C. 

## Usage
main() or another function can call *int* my_printf(*char* * *restrict* format, ...).

 
### Compiling

Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and binary file (program):
	- `make fclean`
* To re-compile:
	- `make re`


## Author

- [@junaidalam2](https://github.com/junaidalam2)


## Support

For support, email junaid.alam2@gmail.com.