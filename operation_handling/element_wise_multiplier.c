// import libraries
// *******************************************
#include "file_handling/file_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// global variables
// *******************************************
struct thread_parms{

	int **matrix_a;
	int **matrix_b;
	int **result_matrix;

	int row_index;
	int col_index;

	int element_span;

};

// thread functions
// *******************************************
void* calculate_element(void* args){

	struct thread_parms *parms=(struct thread_parms*) args;

	int sum=0;
	int element_index=0;
	for(element_index=0; element_index<parms->element_span; element_index++){
		int a=parms->matrix_a[parms->row_index][element_index];
		int b=parms->matrix_b[element_index][parms->col_index];
		sum+=a*b;
		//printf("\nMultiplying : %d,%d\n", a,b);
	}
	parms->result_matrix[parms->row_index][parms->col_index]=sum;

	pthread_exit(0);

}



// interface methods
// *******************************************
void multiply_matrices(int **matrix_a, int *a_dims, int **matrix_b, int *b_dims, int ***matrix_c, int **matrix_c_dims){

	// initialize result matrix
	int *result_dims=malloc(2*sizeof(int));
	result_dims[0]=a_dims[0];
	result_dims[1]=b_dims[1];
	*matrix_c_dims=result_dims;
	int **result_matrix=malloc(result_dims[0]*sizeof(int));

	// initialize threads matrix
	pthread_t tids[result_dims[0]][result_dims[1]];
	struct thread_parms args[result_dims[0]][result_dims[1]];
	
	// implement multiplication
	int row_index=0;
	int col_index=0;
	for(row_index=0; row_index<result_dims[0]; row_index++){

		result_matrix[row_index]=malloc(result_dims[1]*sizeof(int));

		for(col_index=0; col_index<result_dims[1]; col_index++){

			// initialize arguments
			args[row_index][col_index].matrix_a=matrix_a;
			args[row_index][col_index].matrix_b=matrix_b;
			args[row_index][col_index].result_matrix=result_matrix;
			args[row_index][col_index].row_index=row_index;
			args[row_index][col_index].col_index=col_index;
			args[row_index][col_index].element_span=a_dims[1];

			// launch thread
			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_create(&tids[row_index][col_index], &attr, calculate_element, &args[row_index][col_index]);

			//pthread_join(tids[row_index][col_index], NULL);

		}

	}


	// wait on threads
	for(row_index=0; row_index<result_dims[0]; row_index++){

		for(col_index=0; col_index<result_dims[1]; col_index++){
			// join threads
			pthread_join(tids[row_index][col_index], NULL);

		}

	}

	// return final result
	*matrix_c=result_matrix;

}


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

