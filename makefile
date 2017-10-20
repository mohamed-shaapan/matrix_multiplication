CC=gcc
CFLAGS=-c
LDFLAGS=-pthread
SOURCES=main.c file_handling/line_parser.c file_handling/file_handler.c operation_handling/element_wise_multiplier.c operation_handling/row_wise_multiplier.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=matMult

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
