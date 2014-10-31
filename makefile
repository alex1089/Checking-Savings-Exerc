all: main.o

main.o: 
	g++490 -std=c++11 -g -Wall Date.cpp Account.cpp Savings_Account.cpp Checking_Account.cpp main.cpp -o test
