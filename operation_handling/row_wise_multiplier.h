#ifndef ROW_WISE_MULTIPLIER_H_   /* Include guard */
#define ROW_WISE_MULTIPLIER_H_


/* 
	creates a calculation thread for each row in result_matrix
*/

// global variables
// *******************************************
struct row_thread_parms{

	int **matrix_a;
	int **matrix_b;
	int **result_matrix;

	int row_index;

	int col_span;
	int element_span;

};

// interface methods
// *******************************************
void multiply_matrices_row(int **matrix_a, int *a_dims, int **matrix_b, int *b_dims, int ***matrix_c, int **matrix_c_dims);



#endif // FILE_PROCESSING_H_