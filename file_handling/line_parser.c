// import libraries
// *******************************************
#include "line_parser.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// interface methods
// *******************************************
#define MAX_DIM_SIZE 5
int get_matrix_dimensions(char *matrix_info, int **dims){

  int *dimensions=malloc(2*sizeof(int));
  int result_index=0;
  int index=0;

  while(matrix_info[index]!='\0'){

    char c=matrix_info[index];
    int condition=(c>='0'&&c<='9');

    // found integer char (i.e. dimension size)
    if(condition==1){

      char size_buff[MAX_DIM_SIZE];
      memset(size_buff, '\0', MAX_DIM_SIZE*sizeof(char));
      int size_index=0;

      // read dimension size
      while(condition==1){
        size_buff[size_index]=matrix_info[index];
        index++; size_index++;

        c=matrix_info[index];
        condition=(c>='0'&&c<='9');
      }

      // convert buff into int
      int size=atoi(size_buff);

      if(result_index==0){
        // this was a row
        dimensions[0]=size;
        result_index++;
      }else{
        // this was a col
        dimensions[1]=size;
      }

    }

    index++;

}

    *dims=dimensions;

}

// internal functions
// *******************************************
int *convert_row_values(char **row_as_string, int row_size){
  /*
    this function converts row from string to int
  */
  //int result[row_size];
  int *result=malloc(row_size*sizeof(int));
  int index=0;

  while(row_as_string[index]!=NULL){
    //printf("\nToken : %s\n", row_as_string[index]);
    result[index]=atoi(row_as_string[index]);
    index++;
  }

  return result;

}


// interface methods
// *******************************************
#define TOK_BUFSIZE 64
#define TOK_DELIM "\t"
int *parse_matrix_row(char curr_row[], int row_size){

    int bufsize = TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    token = strtok(curr_row, TOK_DELIM);

    while (token != NULL) {

      tokens[position] = token;
      position++;

      if (position >= bufsize) {
        bufsize += TOK_BUFSIZE;
        tokens = realloc(tokens, bufsize * sizeof(char*));
      }

      token = strtok(NULL, TOK_DELIM);
    }

    tokens[position] = NULL;

    
    return convert_row_values(tokens, row_size);
}


// testing
// *******************************************
// *******************************************
/*void test_row_parser(){

  char arr[80] = "200 300 100";
  int *result=parse_matrix_row(arr, 3);

  int index=0;  
  while(result[index]!=NULL){
    printf("\nValue : %d\n", result[index]);
    index++;
  }

}

void test_read_matrix_info(){

  char *matrix_info="rows=100 cols=200";
  int *dim=get_matrix_dimensions(matrix_info);

  int row_size=dim[0];
  int col_size=dim[1];

  free(dim);

  printf("\nRow Size : %d\n", row_size);
  printf("\nCol Size : %d\n", col_size);
}


int main(){

  test_row_parser();
  return 0;
}*/

// *******************************************
// *******************************************
