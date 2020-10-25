NAME = ft_ssl

SRC =	main.c testing_main.c\
		main/init.c main/destroy.c\
		main/parser.c main/findhfunc.c\
		main/resultwriter.c main/fetchdata.c\
		utils/uints.c utils/bswaps.c \
		md5/md5.c md5/md5_private.c \
		sha2/sha256.c sha2/sha256_private.c \
		sha2/sha512.c sha2/sha512_private.c

CC = gcc

SRCDIR = src

OBJDIR = src

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

DEP = $(addprefix ${OBJDIR}/, $(SRC:.c=.d))

CFLAGS = -Wall -Wextra -Werror -g

LDFLAGS = -lm

INCLUDES = -Iincludes/

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${LDFLAGS} ${INCLUDES} -o $@ ${OBJ}

${OBJDIR}/%.o: ${SRCDIR}/%.c
	/bin/mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} ${INCLUDES} -c -o $@ $<

clean:
	@/bin/rm -Rf ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}
	@/bin/rm -Rf ${NAME}.dSYM

test: all
	@./ft_ssl

re: fclean all
