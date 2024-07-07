OS = $(shell uname)
ifeq ("$(OS)","Linux")
	CC = gcc
	GCOV = gcovr 
	LEAKS_RUN_TEST = valgrind --tool=memcheck --leak-check=yes --log-file=1.txt ./test
else
	CC = gcc-14 
	GCOV = gcov-14
	LEAKS_RUN_TEST = leaks -atExit -- ./test
endif

CFLAGS = -std=c11 -Wall -Werror -Wextra -pedantic
CFLAGS_TEST = -std=c11 -Wall -Werror -Wextra -pedantic 
GCOVFLAGS = --coverage

CLANG_FORMAT = ../materials/linters/.clang-format


SRC=s21_eq_matrix.c s21_extra_func.c s21_create_matrix.c s21_remove_matrix.c s21_sum_matrix.c s21_sub_matrix.c $\
s21_mult_number.c s21_determinant.c s21_calc_complements.c s21_mult_matrix.c s21_transpose.c s21_inverse_matrix.c

OBJECTS = $(addprefix obj/,$(SRC:.c=.o))
OBJECTS_GCOV = $(addprefix gcov_obj/,$(SRC:.c=.o))

CHECK_FILE = ./tests/*.check


FREE_TEST = rm -rf test.c test.o

all: s21_matrix.a
	
clean:
	rm -rf *.o *.so *.a *.out *.gcda *.gcno *.info test test.c test_gcov report obj gcov_obj

rebuild: clean all

s21_matrix.a: $(OBJECTS) s21_matrix.h s21_extra_func.h
	ar rc s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a

s21_matrix_gcov.a: $(OBJECTS_GCOV)
	ar rc s21_matrix_gcov.a $(OBJECTS_GCOV)
	ranlib s21_matrix_gcov.a

test.c:
	checkmk clean_mode=1 $(CHECK_FILE) > test.c	

test.o: test.c s21_matrix.h
	$(CC) $(CFLAGS_TEST) -g -c test.c	

test: clean test.o s21_matrix.a	
	$(CC) $(CFLAGS) -g test.o -o test `pkg-config --cflags --libs check` -L. s21_matrix.a -lm
	./test
	$(FREE_TEST)

leak_test: clean test.o s21_matrix.a
	$(CC) $(CFLAGS) -g test.o -o test `pkg-config --cflags --libs check` -L. s21_matrix.a -lm
	$(LEAKS_RUN_TEST)
	$(FREE_TEST)	

gcov_report: clean test.o s21_matrix_gcov.a
ifeq ("$(OS)", "Linux")
	$(CC) $(CFLAGS) test.o -o gcov_obj/test_gcov `pkg-config --cflags --libs check` -L. s21_matrix.a $(GCOVFLAGS) -lm
	gcov_obj/test_gcov
	mkdir -p report
	$(GCOV) --html-details report/index.html --html-medium-threshold 80 --html-high-threshold 100 --html-title "Coverage s21_matrix report"
	$(FREE_TEST)
else
	$(CC) $(CFLAGS) test.o -o gcov_obj/test_gcov `pkg-config --cflags --libs check` -L. s21_matrix_gcov.a $(GCOVFLAGS) -lm
	gcov_obj/test_gcov
	mkdir -p report
	lcov -t "Report" -c -d ./gcov_obj --output-file ./report/coverage.info --gcov-tool $(GCOV) --rc branch_coverage=1
	genhtml ./report/coverage.info --output-directory ./report/ --rc branch_coverage=1
endif

obj/%.o: %.c
	mkdir -p obj/
	$(CC) $(CFLAGS) -g -c $< -o $@

gcov_obj/%.o: %.c
	mkdir -p gcov_obj
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

clang:
	clang-format --style=file:$(CLANG_FORMAT) -i *.c *.h
	clang-format --style=file:$(CLANG_FORMAT) -n *.c *.h

check:
	cppcheck -q --enable=warning,portability --inconclusive ./

.PHONY: all clean rebuild clang check
