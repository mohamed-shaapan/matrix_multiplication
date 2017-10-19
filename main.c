// import libraries
// ********************************************
#include "file_handling/file_handler.h"
#include "operation_handling/element_wise_multiplier.h"
#include "operation_handling/row_wise_multiplier.h"

#include <stdio.h>
#include <stdlib.h>


// internal functions
// *******************************************
void print_matrix(int *dims, int **matrix){
    
    int row_index;
    int col_index;

    for(row_index=0; row_index<dims[0]; row_index++){

        for(col_index=0; col_index<dims[1]; col_index++){
            printf("%d\t", matrix[row_index][col_index]);
        }

        printf("\n");
    }
}


// main function
// *******************************************
int main(int argc, char *argv[]){

    // 01 - get matrix file names
    char *matrix_a_dir; char *matrix_b_dir; char *matrix_c_dir;
    if( argc > 1 ){
    	// use given file names
    	matrix_a_dir=argv[0];
    	matrix_b_dir=argv[1];
    	matrix_c_dir=argv[2];
    }
    else{
      // use default file names
    	matrix_a_dir="io_matrices/a.txt";
      	matrix_b_dir="io_matrices/b.txt";
      	matrix_c_dir="io_matrices/c.txt";
    }
 
    // 02 - load matrix into memory
    int **matrix_a; int *matrix_a_dims;
    load_matrix(matrix_a_dir, &matrix_a_dims, &matrix_a);
    //print_matrix(matrix_a_dims, matrix_a);

    int **matrix_b; int *matrix_b_dims;
    load_matrix(matrix_b_dir, &matrix_b_dims, &matrix_b);
    //print_matrix(matrix_b_dims, matrix_b);

    // apply multiplication algorithm

    //element-wise threading
    int **element_wise_result;
    int *element_wise_dims;
    multiply_matrices_element(matrix_a, matrix_a_dims, matrix_b, matrix_b_dims, &element_wise_result, &element_wise_dims);
    
    // row-wise threading
    int **row_wise_result;
    int *row_wise_dims;
    multiply_matrices_row(matrix_a, matrix_a_dims, matrix_b, matrix_b_dims, &row_wise_result, &row_wise_dims);
    
    // 04 - store result
    store_matrix(element_wise_dims, element_wise_result, matrix_c_dir);

    
    return 0;
  }




