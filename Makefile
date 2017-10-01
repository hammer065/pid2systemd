all:
	gcc -O9 -o pid2systemd -l systemd pid2systemd.c
install:
	cp pid2systemd /usr/local/bin
