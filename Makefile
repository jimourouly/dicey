NAME = rdm.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = 	main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	ar -r $(NAME) $(OBJS)

comp:
	gcc -Wall -Werror -Wextra  main.c rdm.a
	make clean


clean:
	rm -f $(OBJS)
	cd $(LIBFTDIR) && make clean
	
fclean: clean
	rm -f $(NAME)
	cd $(LIBFTDIR) && make fclean
	
re: fclean all
