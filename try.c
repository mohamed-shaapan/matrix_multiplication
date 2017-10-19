// import libraries
// ********************************************
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

int main(){

	struct timeval stop, start;


	gettimeofday(&start, NULL); //start checking time
	
	printf("\nPlease Enter Your Age : \n");

	gettimeofday(&stop, NULL); //end checking time





	printf("Seconds taken %lu\n", stop.tv_sec - start.tv_sec);
	printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);

	return 0;

}



