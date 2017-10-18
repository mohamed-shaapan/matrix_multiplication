// import libraries
// ********************************************
#include <stdio.h>


// global variables
// ********************************************


// internal functions
// ********************************************



// main functions
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
    int **matrix_a;
    int **matrix_b;
    int **matrix_c;


    // 03 - operate on matrix

    // 04 - store result

    
    return 0;
  }




