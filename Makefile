TARGET=min_stack
CC=g++
CXXFLAGS=  -pedantic -Wall -Werror -Wconversion -g -ansi

SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)


.PHONY: clean run gdb
.depends:
	$(CC) -MM -I$(INC_FLAGS) $(SOURCES) > .depends


$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

include .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)

# Do not forget to add '-g' to CFLAGS
gdb: $(TARGET)
	gdb -q ./$(TARGET)
