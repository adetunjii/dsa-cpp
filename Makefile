.PHONY: all clean

main: main.cc
	gcc main.cc -o main

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