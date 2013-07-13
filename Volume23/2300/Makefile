LD = g++
CXX = g++
CXXFLAGS = 
LDFLAGS =
TARGET = main
OBJS = main.o
SOURCE = c++.cpp

cpp: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

main.o: $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm -f *.o $(TARGET) $(SOURCE)

.PHONY: cpp clean

