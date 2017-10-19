// import libraries
// *******************************************
#include "file_handling/file_handler.h"

#include <stdio.h>
#include <stdlib.h>


// interface methods
// *******************************************
int **multiply_matrices(int **matrix_a, int *a_dims, int **matrix_b, int *b_dims, int ***matrix_c, int **matrix_c_dims){

	int *result_dims=malloc(2*sizeof(int));
	result_dims[0]=a_dims[0];
	result_dims[1]=b_dims[1];
	*matrix_c_dims=result_dims;
	int **result_matrix=malloc(result_dims[0]*sizeof(int));
	
	int row_index=0;
	int col_index=0;
	for(row_index=0; row_index<result_dims[0]; row_index++){

		result_matrix[row_index]=malloc(result_dims[1]*sizeof(int));

		for(col_index=0; col_index<result_dims[1]; col_index++){

			int sum=0;
			int element_index=0;
			for(element_index=0; element_index<a_dims[1]; element_index++){
				int a=matrix_a[row_index][element_index];
				int b=matrix_b[element_index][col_index];
				sum+=a*b;
				//printf("\nMultiplying : %d,%d\n", a,b);
			}
			result_matrix[row_index][col_index]=sum;

		}

	}

	*matrix_c=result_matrix;

}




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

	



}

