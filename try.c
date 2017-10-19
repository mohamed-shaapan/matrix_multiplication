// import libraries
// ********************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// main function
// *******************************************
int main(int argc, char *argv[]){

    // declare variables *************************************
    char matrix_a_dir[100]="io_matrices/";
    char matrix_b_dir[100]="io_matrices/";
    char matrix_c_dir[100]="io_matrices/";

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

    printf("\nFile A : %s", matrix_a_dir);
    printf("\nFile B : %s", matrix_b_dir);
    printf("\nFile C : %s", matrix_c_dir);
    printf("\n");


    
    return 0;
  }




