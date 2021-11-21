# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abeznik <abeznik@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/08 18:26:29 by abeznik       #+#    #+#                  #
#    Updated: 2021/11/19 13:28:34 by abeznik       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c \
			get_next_line_utils.c \

MAINS	=	main.c \

OBJS	=	$(SRCS:.c=.o)

MAIN	=	$(MAINS:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=42
# CFLAGS	=	-D BUFFER_SIZE=29

NAME	=	get_next_line.a

all:		$(NAME)

$(NAME): 	$(OBJS)
	ar cr $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	
fclean:		clean
	$(RM) $(NAME)

mclean:
	$(RM) $(MAIN)

oclean:
	$(RM) *.out
	rm -rf *.dSYM

test:	$(OBJS) $(MAIN)
	$(CC) $(CFLAGS) -o test.out $(OBJS) $(MAIN)
	./test.out

gnl:		$(OBJS) $(MAIN)
	$(CC) $(CFLAGS) -o gnl.out $(OBJS) $(MAIN)
	./gnl.out

leaks:
	leaks test.out

debug:
	$(CC) $(CFLAGS) -g3 $(SRCS) $(MAINS)
	lldb a.out

del:		mclean oclean fclean

re:			fclean all

.PHONY:		all clean fclean mclean re