all: test #hw3a #hw3b

# hw3a: hw3a.cc
# 	g++ -std=c++11 -O2 hw3a.cc
# hw3b: hw3b.cc
# 	g++ -std=c++11 -O2 hw3b.cc
test: hw4a_GrowArray.cc
	g++ -std=c++11 -O2 hw4a_GrowArray.cc