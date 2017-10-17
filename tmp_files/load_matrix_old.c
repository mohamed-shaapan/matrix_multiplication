// import libraries
// *******************************************
#include "file_handling/line_parser.h"

#include <stdio.h>
#include <stdlib.h>


#define MAX_ROW_SIZE 512

// read matrix from file
// *******************************************
void load_matrix_file(char *file_directory){

  // result
  //char **lines_as_list=malloc(200*512*sizeof(char));

  // 01_open file
  FILE *pointer;
  pointer=fopen(file_directory, "r");


  // 02_read matrix size
  char matrix_info[MAX_ROW_SIZE];
  fgets(matrix_info, MAX_ROW_SIZE, pointer);


  int *dims=get_matrix_dimensions(matrix_info);
  int row_size=dims[0]; int col_size=dims[1];

  //printf("\nRows : %d\n", row_size);
  //printf("\nCols : %d\n", col_size);

  int **result_matrix=malloc(row_size*col_size*sizeof(int));

  // 02_read from file

  int row_index=0; int col_index=0;
  while(!feof(pointer)){

    char *curr_row=malloc(MAX_ROW_SIZE*sizeof(char));

    fgets(curr_row, MAX_ROW_SIZE, pointer);
    int *row_as_int=parse_matrix_row(curr_row, row_size);

    for()

  }

  // 03_close file
  fclose(pointer);

  // return alue
  return lines_as_list;

}




int main(){

	char *dir="io_matrices/a.txt";
	load_matrix(dir);

	return 0;
}