// import libraries
// *******************************************
#include "file_handling/line_parser.h"

#include <stdio.h>
#include <stdlib.h>

void get_dims(int **dims){

  int *tmp=malloc(2*sizeof(int));
  tmp[0]=3; tmp[1]=5;

  *dims=tmp;

}


int main(){

  int *dims;
  get_dims(&dims);

  printf("\nRows : %d,\tCols : %d\n", dims[0], dims[1]);

  return 0;
}



