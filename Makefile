CC = gcc
CFLAGS = -march=native -O2
LIBS = -lncurses
PREFIX = /usr/local
NAME = dictator

HEADERS = curses.h data.h
CFILES = main.c data.c curses.c key.c intro.c title.c bankrupt.c \
	save.c advice.c cash_advice.c audience.c assasination.c \
	end.c aid.c news.c revolution.c transfer.c plot.c \
	police_report.c account.c war.c decision.c welcome.c restore.c

all: ${HEADERS} ${CFILES}
	${CC} ${CFLAGS} ${CFILES} ${LIBS} -o ${NAME}

warnings: ${HEADERS} ${CFILES}
	${CC} ${CFLAGS} -g -Wall ${CFILES} ${LIBS} -o ${NAME}

install: all
	@echo installing executable file to ${PREFIX}/bin
	@mkdir -p ${PREFIX}/bin
	@cp -f ${NAME} ${PREFIX}/bin
	@chmod 755 ${PREFIX}/bin/${NAME}

uninstall:
	@echo removing executable file from ${PREFIX}/bin
	@rm -f ${PREFIX}/bin/${NAME}
