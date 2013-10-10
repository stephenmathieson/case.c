
test: test.c src/case.c
	$(CC) -std=c99 $^ -o $@
	./test

.PHONY: test
