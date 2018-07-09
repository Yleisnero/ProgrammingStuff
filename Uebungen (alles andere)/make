CXX = g++ -std=c++17
CXXFLAGS = -g -o

all: hello test

clean:
	rm -f hello *.o

hello: hello.o
	$(CXX) $(CXXFLAGS) -o $@ %^

.PHONY: all clean

test: test.o
	$(CXX) $(CXXFLAGS) -o $@ $^

servus: servus.o
	$(CXX) $(CXXFLAGS) -o $@ $^

hallo: hallo.o
	$(CXX) $(CXXFLAGS) -o $@ $^

