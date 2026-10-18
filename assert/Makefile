CC = gcc
CFLAGS = -Wall -g

assert_test: assert_test.c my_assert.c my_assert.h
	$(CC) $(CFLAGS) -o $@ assert_test.c my_assert.c

assert_test_ndebug: assert_test.c my_assert.c my_assert.h
	$(CC) $(CFLAGS) -DNDEBUG -o $@ assert_test.c my_assert.c

clean:
	rm -f assert_test assert_test_ndebug

.PHONY: clean
