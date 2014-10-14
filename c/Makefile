all: weakfunc func hmac_strcmp

comp:
	gcc -c a_func.c
	gcc -c main.c

weakfunc: comp
	gcc main.o -o weakfunc

func: comp
	gcc main.o a_func.o -o func

hmac_strcmp:
	gcc -Wall hmac_strcmp.c -lssl -lcrypto -o hmac_strcmp

clean:
	rm -rf weakfunc func main.o a_func.o hmac_strcmp

test: all
	./func
	./weakfunc
	./hmac_strcmp 1 1
