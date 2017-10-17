// import libraries
// *******************************************
#include "file_handler.h"
#include "line_parser.h"

#include <stdio.h>
#include <stdlib.h>


// read matrix from file
// *******************************************
int **load_matrix(char *file_directory);{

  // result
  //char **lines_as_list=malloc(200*512*sizeof(char));

  // 01_open file
  FILE *pointer;
  pointer=fopen(file_directory, "r");


  // 02_read matrix size
  char matrix_info[20];
  fgets(matrix_info, 20, pointer);


  int *dims=get_matrix_dimensions(matrix_info);
  int row_size=dims[0]; int col_size=dims[1];

  /*char **result_matrix=malloc(rows*cols*sizeof(int));

  // 02_read from file
  int curr_row=0;
  int curr_col=0;

  while(!feof(pointer)){

    char *current_line=malloc(512*sizeof(char));

    fgets(current_line, 512, pointer);
    lines_as_list[curr_row]=current_line;

    curr_row++;

  }

  // 03_close file
  fclose(pointer);

  // return alue
  return lines_as_list;*/

}


