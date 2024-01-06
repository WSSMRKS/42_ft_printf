# Directories #
SRCDIR =
HDRDIR =
OBJDIR =
LIBFTDIR = libft
# Names #
NAME = libftprintf.a
MAIN_NAME = a.out
# Compiler & COptions & CFlags #
CFLAGS = -g -Werror -Wall -Wextra
TESTFLAGS = -g
COPTIONS = -c
CC = cc
# Source Files #
SRC =  	ft_printf.c helper_functions.c ft_itoa_base.c
MAIN_SRC = 
TEST_SRC = test.c
HEADERS = ft_printf.h
LIBFT_SRC = libft.a libft.h

# Object Files #
SRC_OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

# Targets #
all : $(NAME)

$(NAME): $(SRC_OBJ)
	ar rcs $(NAME) $(SRC_OBJ)

# bonus: $(BONUS_OBJ) $(SRC_OBJ)
# 	ar rcs $(NAME) $(SRC_OBJ) $(BONUS_OBJ)

libft:
	$(MAKE) all -C libft/
	cp -rf libft/libft.h ./
	cp -rf libft/libft.a ./

test: $(MAIN_OBJ) $(NAME) $(TEST_OBJ)
	@$(CC) $(TESTFLAGS) $(MAIN_OBJ) $(SRC_OBJ) $(TEST_OBJ) -o $(MAIN_NAME)
	@echo "test command sucessfully executed. Executable is called \"$(MAIN_NAME)\"!"

test_strict: $(MAIN_OBJ) $(NAME) $(TEST_OBJ)
	@$(CC) $(CFLAGS) $(MAIN_OBJ) $(SRC_OBJ) $(TEST_OBJ) -o $(MAIN_NAME)
	@echo "test command sucessfully executed. Executable is called \"$(MAIN_NAME)\"!"

run: fclean test bonus
	@echo "\"a.out\" execution below!"
	@./a.out | cat -e

debug: fclean test bonus
	gdb ./a.out

# Compile .c to .o #
%.o: %.c
	@$(CC) $(TESTFLAGS) $(COPTIONS) $^ -o $@

clean:
	@rm -f $(SRC_OBJ)
	@rm -f $(MAIN_OBJ)
	@rm -f $(BONUS_OBJ)
	@rm -f $(TEST_OBJ)
	$(MAKE) fclean -C libft/
	@rm -f libft.a
	@rm -f libft.h
	@echo "Working folder clean."
	@echo "\"libft.a\" left if it was there before"

fclean: clean
	@rm -f $(NAME) $(MAIN_NAME)
	@echo "\"libft.a\" deleted"

re: fclean all

name:
	@echo "$(NAME)"

help:
	@echo "Possible Commands:"
	@echo "all --> Compile whole project"
	@echo "name --> Display project name"
	@echo "bonus --> Compile bonus if available project"
#	@echo "test --> Compile main if available"
#	@echo "run --> Run main if available"
#	@echo "debug --> Run GDB with a.out"
	@echo "clean --> Delete all object files"
	@echo "fclean --> Delete everything besides source files"
	@echo "re --> recompile everything (fclean, all)"

.PHONY: all name test run bonus debug fclean clean re help libft
