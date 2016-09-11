# Patrick Anderson psa5dg Lab 105
CXXFLAGS = -Wall -O2
CXX = clang++ $(CXXFLAGS)
OFILES=wordPuzzle.o timer.o hashTable.o
.SUFFIXES: .o .cpp

make: $(OFILES)
	$(CXX) $(OFILES)

hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h

clean:
	-rm -f *.o *~ outputfile