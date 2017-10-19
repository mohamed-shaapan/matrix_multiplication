// import libraries
// *******************************************
#include "file_handling/file_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



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

    printf("\n\n");
}



// main function
// *******************************************
int main(){

	// load matrix into memory
	// ******************************************
	char *matrix_a_dir="io_matrices/a.txt";
	char *matrix_b_dir="io_matrices/b.txt";
	char *matrix_c_dir="io_matrices/c.txt";

	int **matrix_a; int *matrix_a_dims;
    load_matrix(matrix_a_dir, &matrix_a_dims, &matrix_a);
    //print_matrix(matrix_a_dims, matrix_a);

    int **matrix_b; int *matrix_b_dims;
    load_matrix(matrix_b_dir, &matrix_b_dims, &matrix_b);
    //print_matrix(matrix_b_dims, matrix_b);

    // operate on matrix
	// ******************************************
	int **matrix_c;
	int *matrix_c_dims;
	multiply_matrices(matrix_a, matrix_a_dims, matrix_b, matrix_b_dims, &matrix_c, &matrix_c_dims);

	print_matrix(matrix_c_dims, matrix_c);
	/*free(matrix_a); free(matrix_b); free(matrix_a_dims); free(matrix_b_dims);
	store_matrix(matrix_c_dims, matrix_c, matrix_c_dir);*/

	



}

