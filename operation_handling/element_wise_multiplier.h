#ifndef ELEMENT_WISE_MULTIPLIER_H_   /* Include guard */
#define ELEMENT_WISE_MULTIPLIER_H_


/* 
	creates a calculation thread for each element in result_matrix
*/

// global variables
// *******************************************
struct element_thread_parms{

	int **matrix_a;
	int **matrix_b;
	int **result_matrix;

	int row_index;
	int col_index;

	int element_span;

};

// interface methods
// *******************************************
void multiply_matrices_element(int **matrix_a, int *a_dims, int **matrix_b, int *b_dims, int ***matrix_c, int **matrix_c_dims);



#endif // FILE_PROCESSING_H_