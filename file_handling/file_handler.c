// import libraries
// *******************************************
#include "file_handling/line_parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *read_input_line(FILE *file_pointer){

    char *line = NULL;
    ssize_t bufsize = 0; // have getline allocate a buffer for us
    //getline(&line, &bufsize, stdin);
    getline(&line, &bufsize, file_pointer);
    
    return line;
}


/*void print_matrix(int **matrix, int row_size, int col_size){

  int curr_row;
  int curr_col;

  for(curr_row=0; curr_row<row_size; curr_row++){

    for(curr_col=0; curr_col<col_size; curr_col++){
      printf("%d\t", matrix[curr_row][curr_col]);
    }

    printf("\n");

  }

}*/



// read matrix from file
// *******************************************
int **load_matrix(char *file_directory){

  // 01 - open file
  FILE *file_pointer;
  file_pointer=fopen(file_directory, "r");

  // 02 - read matrix size
  char *matrix_info=read_input_line(file_pointer);
  int *dims=get_matrix_dimensions(matrix_info);
  int row_size=dims[0]; int col_size=dims[1];
  //free(dims);
  //free(matrix_info);

  // 02_read from file
  //int **result_matrix=malloc(row_size*col_size*sizeof(int));
  int result_matrix[row_size][col_size];
  memset(result_matrix, -1, row_size*col_size*sizeof(int));
  int curr_row=0;
  int curr_col=0;
  char *curr_line=NULL;

  while(!feof(file_pointer)){

    curr_line=NULL;
    curr_line=read_input_line(file_pointer);
    printf("\nLINE : %s\n", curr_line);
    int *row_as_int=parse_matrix_row(curr_line, row_size);

    

    int col_index;
    for(col_index=1; col_index<=row_size; col_index++){
      result_matrix[curr_row][curr_col]=row_as_int[col_index-1];
      //printf("%d\t", row_as_int[col_index-1]);
      //printf("\nGOT HERE *************\n");
      col_index++; curr_col++;
    }

    printf("\n");

    curr_row++;
    curr_col=0;

  }

  // 03_close file
  fclose(file_pointer);

  //int curr_row;
  //int curr_col;

  for(curr_row=0; curr_row<row_size; curr_row++){
    for(curr_col=0; curr_col<col_size; curr_col++){
      printf("%d\t", result_matrix[curr_row][curr_col]);
    }
    printf("\n");
  }

  //return result_matrix;

}


int main(){

  load_matrix("io_matrices/a.txt");

  return 0;
}





