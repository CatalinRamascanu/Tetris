# Completati va rog urmatoarele 3 linii cu informatiile voastre personale.
# Daca aveti mai multe prenume, alegeti doar unul dintre ele.
NUME=Ramascanu
PRENUME=Catalin
GRUPA=314CC
# ^ Doar cele trei de sus.

CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lcurses

.PHONY: build run examples pack clean

build:
  $(CC) $(CFLAGS) src/*.c -o bin/Tetris $(LDFLAGS) 

run: build
	./bin/Tetris

examples:
	$(CC) $(CFLAGS) example/exemplu1.c -o bin/exemplu1 $(LDFLAGS)
	$(CC) $(CFLAGS) example/exemplu2.c -o bin/exemplu2 $(LDFLAGS)
pack: clean
	zip -r $(GRUPA)_$(NUME)_$(PRENUME)_tema3.zip *

clean:
	rm -rf bin/* *.zip
	clear
