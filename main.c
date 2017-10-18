// import libraries
// ********************************************
#include <stdio.h>



// main function
// *******************************************
int main(int argc, char *argv[]){

    // 01 - get matrix file names
    if( argc > 1 ){
    	// use given file names
    	char *matrix_a_dir=argv[0];
    	char *matrix_b_dir=argv[1];
    	char *matrix_c_dir=argv[2];
    }
    else{
      // use default file names
    	char *matrix_a_dir="a.txt";
      	char *matrix_b_dir="b.txt";
      	char *matrix_c_dir="c.txt";
    }
 
    // 02 - load matrix into memory
    int **matrix_a=load_matrix(matrix_a_dir);
    int **matrix_b=load_matrix(matrix_b_dir);

    // 03 - operate on matrix
    int **matrix_c=multiply_matrices_element_wise(matrix_a, matrix_b);

    // 04 - store result
    store_matrix(matrix_c, matrix_c_dir);

    
    return 0;
  }




