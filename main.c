// import libraries
// ********************************************
#include "file_handling/file_handler.h"
#include "operation_handling/element_wise_multiplier.h"
#include "operation_handling/row_wise_multiplier.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>


// main function
// *******************************************
int main(int argc, char *argv[]){

    // declare variables *************************************
    char matrix_a_dir[100]="io_matrices/";
    char matrix_b_dir[100]="io_matrices/";
    char matrix_c_dir[100]="io_matrices/";
    int **matrix_a; int **matrix_b; int **element_wise_result; int **row_wise_result;
    int *matrix_a_dims; int *matrix_b_dims; int *element_wise_dims; int *row_wise_dims;
    struct timeval element_start, element_stop;
    struct timeval row_start, row_stop;
    int element_num_threads; int row_num_threads;

    // 01 - get matrix file names
    if( argc > 1 ){
    	// use given file names
        strcat(matrix_a_dir, argv[1]);
        strcat(matrix_b_dir, argv[2]);
        strcat(matrix_c_dir, argv[3]);
    }
    else{
        // use default file names
    	strcat(matrix_a_dir, "a.txt");
        strcat(matrix_b_dir, "b.txt");
        strcat(matrix_c_dir, "c.txt");
    }
 
    // 02 - load matrix into memory **************************
    load_matrix(matrix_a_dir, &matrix_a_dims, &matrix_a);
    load_matrix(matrix_b_dir, &matrix_b_dims, &matrix_b);

    // 03 - apply multiplication algorithm *******************
    //element-wise threading
    gettimeofday(&element_start, NULL); // start checking time
    multiply_matrices_element(matrix_a, matrix_a_dims, matrix_b, matrix_b_dims, &element_wise_result, &element_wise_dims);
    gettimeofday(&element_stop, NULL); // stop checking time
    element_num_threads=element_wise_dims[0]*element_wise_dims[1];
    // row-wise threading
    gettimeofday(&row_start, NULL); // start checking time
    multiply_matrices_row(matrix_a, matrix_a_dims, matrix_b, matrix_b_dims, &row_wise_result, &row_wise_dims);
    gettimeofday(&row_stop, NULL); // start checking time
    row_num_threads=row_wise_dims[0];

    // 04 - store result ************************************
    store_matrix(element_wise_dims, element_wise_result, matrix_c_dir);

    // 05 - display compare result **************************
    printf("\nElement-Wise Method *******************\n");
    printf("Threads Created:\t%d\n", element_num_threads);
    printf("Time Taken (Micro): \t%lu", element_stop.tv_usec - element_start.tv_usec);

    printf("\n\nRow-Wise Method ***********************\n");
    printf("Threads Created :\t%d\n", row_num_threads);
    printf("Time Taken (Micro): %lu\n", row_stop.tv_usec - row_start.tv_usec);

    
    return 0;
  }




