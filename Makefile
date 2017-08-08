#Docs : http://aggregate.org/rfisher/Tutorials/Make/make6.html

GCCPARAMS = -Iinclude 

CFLAGS=-I/include
OBJ=main

SRC= libs/libjalali/jalali.c \
	 libs/libbase64/encode.c \
	 libs/libbase64/decode.c \
	 util/utility.c \
	 libs/libbase64/main.c

all:
	
	gcc -fsanitize=address $(GCCPARAMS) $(SRC) -o $(OBJ)
	cd python; make


.PHONY: clean
clean:
	rm -rf *.o
