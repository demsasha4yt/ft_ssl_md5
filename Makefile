NAME = ft_ssl

SRC = main.c md5/md5.c

CC = gcc

SRCDIR = src

OBJDIR = src

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

DEP = $(addprefix ${OBJDIR}/, $(SRC:.c=.d))

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -lm

INCLUDES = -Iincludes/

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${LDFLAGS} ${INCLUDES} -o $@ ${OBJ}

${OBJDIR}/%.o: ${SRCDIR}/%.c
	/bin/mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} ${INCLUDES} -c -o $@ $<

clean:
	@/bin/rm -Rf ${OBJS}

fclean: clean
	@/bin/rm -f ${NAME}
	@/bin/rm -Rf ${NAME}.dSYM

test: all
	@./ft_ssl

re: fclean all
