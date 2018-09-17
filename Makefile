CC=gcc
CFLAGS=-Wall -Wextra --pedantic --pedantic-errors
PROGRAMS=pid2systemd

all: $(PROGRAMS)

.PHONY: all clean install

clean:
	rm -f $(PROGRAMS)

pid2systemd: pid2systemd.c
	$(CC) -o $@ -l systemd $(CFLAGS) $^

install: pid2systemd
	cp pid2systemd /usr/local/bin/
