TARGET = my_printf
CFLAGS = -Wall -Wextra -Werror  # -g3 -fsanitize=address
FILES =  my_printf nondecimal_num pointer text integer format_handler # main
SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))


all: $(TARGET)

$(TARGET): $(OBJ)
	gcc -o $(TARGET) $(OBJ) 

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)

run : all
	./$(TARGET)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
