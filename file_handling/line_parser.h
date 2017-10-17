#ifndef LINE_PARSER_H_   /* Include guard */
#define LINE_PARSER_H_


/* 
	CommandsBatch file basic functions' prototypes
*/
int *get_matrix_dimensions(char *matrix_info);

int *parse_matrix_row(char *curr_row, int row_size);



#endif // FILE_PROCESSING_H_