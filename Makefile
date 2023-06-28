PREFIX = /usr/local
OBJS = main.o glad.o loader.o calc.o draw.o
CFLAGS = -Wall
INCLUDES = -I./include
LIBS = -lglfw
CC = g++

main:${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
