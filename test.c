#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int test(){
	generate_array(5,5);
	parse_commands("ls -l");
	parse_inputs("ls -l");
	count_tokens("hello i am derrick", " ");
	trim("      test      ");

	//parse commands
	//parse input
	//count_tokens
	//trim
	//parse_all
	}
