CXX = g++
CFLAGS = -g -Wall -std=c++11

a.out: lab7main.o llist.o
	$(CXX) $(CFLAGS) lab7main.o llist.o -o $@

lab7main.o: lab7main.cc llist.h
	$(CXX) $(CFLAGS) -c lab7main.cc -o $@

llist.o: llist.cc llist.h
	$(CXX) $(CFLAGS) -c llist.cc -o $@

clean:
	rm -rf *.o a.out
