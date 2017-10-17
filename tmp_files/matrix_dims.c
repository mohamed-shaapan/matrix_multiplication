// import libraries
// *******************************************
//#include "line_parser.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>




#define MAX_DIM_SIZE 5

int *get_matrix_dimensions(char *matrix_info){

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

    return dimensions;

}




int main(){

  test_read_matrix_info();
  return 0;
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