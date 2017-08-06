#Docs : http://aggregate.org/rfisher/Tutorials/Make/make6.html

GCCPARAMS = -Iinclude 

CFLAGS=-I/include
OBJ=main

SRC= libjalali/jalali.c \
	 libbase64/encode.c \
	 libbase64/decode.c \
	 util/utility.c \
	 libbase64/main.c

all:
	
	gcc -fsanitize=address $(GCCPARAMS) $(SRC) -o $(OBJ)
	cd python; make


.PHONY: clean
clean:
	rm -rf *.o
