CC = gcc
CFLAGS = -Wall -g
LIB = lib

OBJS = $(LIB)/add.o $(LIB)/subtract.o $(LIB)/multiply.o $(LIB)/divide.o
PIC_OBJS = $(LIB)/add.pic.o $(LIB)/subtract.pic.o $(LIB)/multiply.pic.o $(LIB)/divide.pic.o

all: calc_static calc_shared calc_dynamic

# 목적 파일
$(LIB)/%.o: $(LIB)/%.c $(LIB)/calc.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB)/%.pic.o: $(LIB)/%.c $(LIB)/calc.h
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# 라이브러리
$(LIB)/libcalc.a: $(OBJS)
	ar rcs $@ $^

$(LIB)/libcalc.so: $(PIC_OBJS)
	$(CC) -shared -o $@ $^

# 실행 파일
calc_static: main.c $(LIB)/libcalc.a
	$(CC) $(CFLAGS) -I$(LIB) -o $@ main.c -L$(LIB) -l:libcalc.a

calc_shared: main.c $(LIB)/libcalc.so
	$(CC) $(CFLAGS) -I$(LIB) -o $@ main.c -L$(LIB) -lcalc

calc_dynamic: main_dl.c $(LIB)/libcalc.so
	$(CC) $(CFLAGS) -o $@ main_dl.c -ldl

run: all
	./calc_static 20 4
	LD_LIBRARY_PATH=$(LIB) ./calc_shared 20 4
	./calc_dynamic 20 4

prof: main.c
	$(CC) -pg -g -I$(LIB) -o calc_prof main.c $(LIB)/add.c $(LIB)/subtract.c $(LIB)/multiply.c $(LIB)/divide.c

clean:
	rm -f $(LIB)/*.o $(LIB)/libcalc.a $(LIB)/libcalc.so calc_static calc_shared calc_dynamic calc_prof gmon.out

.PHONY: all run prof clean
