COMPILER = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra
SANITIZE = -fsanitize=address -pedantic
TARGETS = tests.cc
GCOV = -fprofile-arcs -ftest-coverage -fPIC -pthread
GTEST = -lgtest -lgtest_main

.PHONY: all clean rebuild check gcov_report test style_check style_make leaks

all: gcov_report

gcov_report: test
	lcov --ignore-errors mismatch -t "containers" -o containers.info -c -d .
	genhtml -o report containers.info
	open report/index.html

test: clean
	${COMPILER} ${FLAGS} ${GCOV} ${TARGETS} -o test ${GTEST}
	./test

style_check:
	cp ./../materials/linters/.clang-format ./
	clang-format -n ./containers/*.h *.cc *.h
	rm .clang-format

style_make:
	cp ./../materials/linters/.clang-format ./
	clang-format -i ./containers/*.h *.cc *.h
	rm .clang-format

leaks:
	make test
	CK_FORK=no leaks --atExit --  ./test

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a tests_s21_matrix *.css *.html vgcore* report *.info *.gz *.log test

rebuild: all


#forleaks
# 1) open docker: run docker run -tiv $PWD/:/valgrind karek/valgrind:latest
# 2) run sudo apt-get install libgtest-dev
# 3) run make test
# 4) run valgrind --leak-check=full ./test
