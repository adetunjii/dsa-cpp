.PHONY: all clean main one

main: main.cc
	g++ main.cc -o main -g --std=c++23 && ./main
.PHONY: main

hey:
	echo $@

one:
	touch one

two:
	touch two

print_test:
	echo "print test"

print_silent:
	@echo "print silent"