NAME = push_swap

C_FILES = stack_operations/swap_operations.c stack_operations/push_operations.c \
	stack_operations/reverse_rotate_operations.c stack_operations/rotate_operations.c\
	push_swap.c \
	set_up/tab_creation.c set_up/cheakers.c \
	radix/radix.c radix/small_sort.c

OBJECT_FILES = swap_operations.o push_operations.o \
	reverse_rotate_operations.o rotate_operations.o push_swap.o \
	tab_creation.o cheakers.o radix.o small_sort.o

all : $(NAME)

$(NAME) : $(OBJECT_FILES)
# 	make bonus -C libft
	cc -Wall -Wextra -Werror -o $(NAME) $(OBJECT_FILES) libft/libft.a

$(OBJECT_FILES) : $(C_FILES)
	cc -c -Wall -Wextra -Werror -g3 $(C_FILES) 


clean :
	rm -f $(OBJECT_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re Makefile