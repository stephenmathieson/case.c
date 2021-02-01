.POSIX:

test: test.c src/case.c
	$(CC) -std=c99 test.c src/case.c -o $@
	./test

.PHONY: test
