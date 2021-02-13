CXX=g++
CFLAGS=-Wall -Wextra -O3

TARGET=main
OBJS=(roster.o student.o)

# https://stackoverflow.com/a/3220288
#
# all: library.cpp main.cpp
#
#	$@ evaluates to "all"
#	$< evaluates to "library.cpp"
#	$^ evaluates to "library.cpp main.cpp"
#

all: $(TARGET)

$(TARGET): main.o roster.o student.o
	$(CXX) -o $@ $^

main.o: main.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^

student.o: student.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^

roster.o: roster.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^

clean:
	rm -f *.o $(TARGET)
