PREFIX = /usr/local
OBJS = main.o
CFLAGS = -Wall
INCLUDES = -I./include
LIBS = -lglfw -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl 
CC = g++

main:${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core

.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $< ${LIBS}

