NAME = ft_ssl

SRC = main.c

CC = gcc

SRCDIR = src

OBJDIR = obj

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
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@/bin/rm -f ${NAME}
	@/bin/rm -Rf ${NAME}.dSYM

test:
	@${CC} -g ${INCLUDES} -I. -o ${NAME} $(addprefix src/, ${SRC})

re: fclean all
