NAME			= 	philo
HEADER			= 	philo.h
SOURCE			=	arrays.c \
					death_timers.c \
					forks.c \
					ft_atoi.c \
					life_of_phil.c \
					main.c \
					printing.c \
					put_int_nbr.c \
					put_long_nbr.c \
					threads_starting.c \
					utils.c \
					utils_2.c

OBJS			= $(SOURCE:.c=.o)
RM				= rm -f
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I $(HEADER)

%.o:			%.c ${HEADER}
				$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):		$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all
				
.PHONY:			all clean fclean re
