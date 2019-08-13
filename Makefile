# all: hw7.o

test: test.cc
	g++ -std=c++11 test.cc
# hw7.o: hw7_matrix.cc
# 	g++ -std=c++11 -O2 hw7_matrix.cc