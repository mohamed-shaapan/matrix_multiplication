// import libraries
// *******************************************
#include "row_wise_multiplier.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// thread function
// *******************************************
void* calculate_row(void* args){

	struct row_thread_parms *parms=(struct row_thread_parms*) args;

	int col_index;
	for(col_index=0; col_index<parms->col_span; col_index++){

		int sum=0;
		int element_index=0;
		for(element_index=0; element_index<parms->element_span; element_index++){
			int a=parms->matrix_a[parms->row_index][element_index];
			int b=parms->matrix_b[element_index][col_index];
			sum+=a*b;
			//printf("\nMultiplying : %d,%d\n", a,b);
		}

		parms->result_matrix[parms->row_index][col_index]=sum;

	}

	pthread_exit(0);

}



// interface methods
// *******************************************
void multiply_matrices_row(int **matrix_a, int *a_dims, int **matrix_b, int *b_dims, int ***matrix_c, int **matrix_c_dims){

	// 01 - initialize result matrix
	int *result_dims=malloc(2*sizeof(int));
	result_dims[0]=a_dims[0];
	result_dims[1]=b_dims[1];
	*matrix_c_dims=result_dims;
	int **result_matrix=malloc(result_dims[0]*sizeof(int));

	// 02 - initialize threads matrix
	pthread_t tids[result_dims[0]];
	struct row_thread_parms args[result_dims[0]];
	
	// 03 - implement multiplication
	int row_index=0;
	for(row_index=0; row_index<result_dims[0]; row_index++){

		// allocate result matrix row
		result_matrix[row_index]=malloc(result_dims[1]*sizeof(int));

		// initialize arguments
		args[row_index].matrix_a=matrix_a;
		args[row_index].matrix_b=matrix_b;
		args[row_index].result_matrix=result_matrix;
		args[row_index].row_index=row_index;
		args[row_index].col_span=result_dims[1];
		args[row_index].element_span=a_dims[1];

		// launch thread
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&tids[row_index], &attr, calculate_row, &args[row_index]);

	}

	// 04 - wait on threads
	for(row_index=0; row_index<result_dims[0]; row_index++){
		// join threads
		pthread_join(tids[row_index], NULL);

	}

	// 05 - return final result
	*matrix_c=result_matrix;

}
