#ifndef FILE_HANDLER_H_   /* Include guard */
#define FILE_HANDLER_H_


/* 
	CommandsBatch file basic functions' prototypes
*/
int load_matrix(char *file_directory, int **dims, int ***matrix);

void store_matrix(int *dims, int **matrix, char *file_directory);



#endif // FILE_PROCESSING_H_