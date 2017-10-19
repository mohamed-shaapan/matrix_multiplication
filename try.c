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

// read matrix from file
// *******************************************
int load_matrix(char *file_directory, int **dims, int ***matrix){

  // 01 - open file
  FILE *file_pointer;
  file_pointer=fopen(file_directory, "r");

  // 02 - read matrix size
  char *matrix_info=read_input_line(file_pointer);
  int *tmp_dims;
  get_matrix_dimensions(matrix_info, &tmp_dims);
  int row_size=tmp_dims[0]; int col_size=tmp_dims[1];
  *dims=tmp_dims;
  free(matrix_info);

  // 02_read from file
  int **result_matrix=malloc(row_size*sizeof(int));
  //memset(result_matrix, -1, row_size*col_size*sizeof(int));
  int row_index=0;
  int col_index=0;
  char *curr_line=NULL;

  while(!feof(file_pointer)){

    curr_line=NULL;
    curr_line=read_input_line(file_pointer);
    int *row_as_int=parse_matrix_row(curr_line, col_size);

    result_matrix[row_index]=malloc(col_size*sizeof(int));
    for(col_index=0; col_index<col_size; col_index++){
      result_matrix[row_index][col_index]=row_as_int[col_index];
    }

    row_index++;

  }

  // 03_close file
  fclose(file_pointer);

  *matrix=result_matrix;

}


int main(){

  int *dims;
  int **matrix;
  load_matrix("io_matrices/a.txt", &dims, &matrix);

  printf("\nRows = %d,\tCols = %d\n\n", dims[0], dims[1]);

  int row_index;
  int col_index;
  for(row_index=0; row_index<dims[0]; row_index++){
    for(col_index=0; col_index<dims[1]; col_index++){
      printf("%d\t", matrix[row_index][col_index]);
    }
    printf("\n");
  }



  return 0;
}



void store_matrix(int **matrix, char *file_directory){

  // 01 - open file
  FILE *file_pointer;
  file_pointer=fopen(file_directory, "w");
   
  // 02 - write to file
  int row_index; int row_size;
  int col_index; int col_size;

  for(row_index=0; row_index<row_size; row_size++){
    
    for(col_index=0; col_index<col_size; col_index++){

      if(col_index==col_size-1){
        fprintf(file_pointer, "%d", matrix[row_index][col_index]);
      }else{
        fprintf(file_pointer, "%d\t", matrix[row_index][col_index]);
      }
      
    }

    fprintf(file_pointer, "\n");

  }

  // 03 - close file
  fclose(file_pointer);

}




