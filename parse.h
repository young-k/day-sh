#ifndef PARSE_H
#define PARSE_H 

/*
 * Function Description:
 *   parse_commands() takes in a string of a single command with command line
 *   arguments and puts it in a char * array with the first element being the
 *   command and the following elements are the arguments. The last element
 *   of the array is NULL
 *
 * Arguments:
 *   char * of a single command line
 *
 * Return Value:
 *   char** of command and arguments
 *
 */
char** parse_commands (char *);



/*
 * Function Description:
 *   parse_inputs() takes in the raw input string from stdin and puts each
 *   command separated by a semicolon in to an array of commands
 *
 * Arguments:
 *   char * of the raw input
 *
 * Return:
 *   char ** of commands
 *
 */
char** parse_inputs (char *);



/*
 * Function Description:
 *   count_tokens() returns the number of times the character delimiter appears  
 *   in the string line
 *
 * Arguments:
 *   char * string 
 *   char * delimiter
 *
 * Return:
 *   number of tokens in line separated by delim
 *
 */
int count_tokens(char *, char*);



/*
 * Function Description:
 *   trim() removes leading and trailing whitespace of the string
 *
 * Arguments:
 *   char *string
 *
 * Returns:
 *   string without leading and trailing whitespace
 *
 */
char *trim(char *);
 

/*
 * Function Description:
 *   generate() creates an char ** or a two dimensional array of characters    
 *
 * Arguments:
 *   int a
 *   int b
 *
 * Return:
 *   an array that is a by b
 *
 */
char **generate_array(int, int);


/*
 * Function Description:
 *    master parse function  
 *
 * Arguments:
 *   char * rawinput
 *
 * Return:
 *   array of arrays that are formatted for exevp
 *
 */
char **parse_all(char*);
#endif
