
matMult: main.o file_handler.o line_parser.o element_wise_multiplier.o row_wise_multiplier.o
	gcc main.o file_handler.o line_parser.o element_wise_multiplier.o row_wise_multiplier.o

main.o: main.c
	gcc -c main.c

file_handler.o: file_handling/file_handler.c
	gcc -c file_handling/file_handler.c

line_parser.o: file_handling/line_parser.c
	gcc -c file_handling/line_parser.c

element_wise_multiplier.o: operation_handling/element_wise_multiplier.c
	gcc -c operation_handling/element_wise_multiplier.c

row_wise_multiplier.o: operation_handling/row_wise_multiplier.c
	gcc -c operation_handling/row_wise_multiplier.c

clean:
	rm *.o matMult