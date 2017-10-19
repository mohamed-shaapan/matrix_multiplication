// import libraries
// *******************************************
#include "line_parser.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// REPLACE VARIABLE WITH ACTUAL VALUE
// **********************************************************************
// **********************************************************************
int get_strlen(char *string){

  int index=0;

  while(string[index]!='\0'){
    index++;
  }

  return index;


}

// **********************************************************************
char *replace_variables(char *command){

  char *result=malloc(512*sizeof(char));
  memset(result, '\0', 512*sizeof(char));
  
  int result_index=0;
  int command_index=0;
  int var_start_index=-1;
  //int var_end_index=-1;

  while(command[command_index]!='\0'){



    if(command[command_index]!='$'){
        result[result_index]=command[command_index];
        result_index++; command_index++;

    }else{
      //if(command[command_index]=='$')

      // 01_identify variable name
      command_index++;
        
      char arg_buff[100];
      int buff_index=0;

      while(1){

        char c=command[command_index];
        int condition=(c>='A'&&c<='Z')||(c>='a'&&c<='z');

        if(condition==1){
          //printf("\nENTERED******************\n");
          arg_buff[buff_index]=command[command_index];
          command_index++; buff_index++;
        }else{

          break;
        }

      }

      // get variable from list
      //printf("\nvar.name = %s", arg_buff);
      char *value=get_variable(arg_buff).value;
      //char *value="ALOHA";
      strcat(result, value);
      //printf("\nNew Command So Far : %s\n", result);

      result_index+=get_strlen(value);

    }


  }

  result[result_index]='\0';
  return result;
  
}


// IDENTIFY BACKGROUND PROCESS FLAG
// **********************************************************************
// **********************************************************************
int background_flag(char *command){
  
  int ampersand_found=0;
  int ampersand_index=-1;
  int index=0;

  while(command[index]!='\0'){

    if(command[index]=='&'){
      ampersand_found=1;
      ampersand_index=index;

    }else if(ampersand_found==1){
      if(!(command[index]==' '||command[index]==10)){
        ampersand_found=0;
      }

    }

    index++;

  }

  if(ampersand_found==1){
    command[ampersand_index]=' ';
    return 1;
  }

  return 0;

}



// INTERFACE FUNCTION
// **********************************************************************
// **********************************************************************
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"


char **parse_command(char *command, int *background_process_flag){

    // 01_indentify background processes
    *background_process_flag=background_flag(command);

    // 02_substitute variables with values if found
    command=replace_variables(command);

    //printf("\nCommand : %sEND\n", command);//***********************************

    // 03_parse arguments
    int bufsize = LSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
      fprintf(stderr, "lsh: allocation error\n");
      exit(EXIT_FAILURE);
    }

    token = strtok(command, LSH_TOK_DELIM);
    while (token != NULL) {
      tokens[position] = token;
      position++;

      if (position >= bufsize) {
        bufsize += LSH_TOK_BUFSIZE;
        tokens = realloc(tokens, bufsize * sizeof(char*));
        if (!tokens) {
          fprintf(stderr, "lsh: allocation error\n");
          exit(EXIT_FAILURE);
        }
      }

      token = strtok(NULL, LSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}
