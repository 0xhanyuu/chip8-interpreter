#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <opcodes.h>
#include <sprites.h>
//#include <display.h>
//#include <timers.h>
//#include <input.h>
//#include <sound.h>

void print_usage_error()
{
	fprintf(stderr, "Usage: chip8 <filename>\n");
}

signed int file_handling(int argc, char **argv, char filename[])
{
	//handle no args
	if ( argc < 2 || argc > 2 )
	{
		print_usage_error();
		exit(EXIT_FAILURE);
	}

	//open file, if file does not exist, return error
	FILE * f_filename = fopen(argv[1], "r");

	if ( f_filename == NULL )
	{
		perror(argv[1]);
		fclose(f_filename);
		return EXIT_FAILURE;
	}

	//if file exists, strcpy
	strcpy(filename, argv[1]);
	//null terminate string
	filename[strlen(argv[1])] = '\x00';

	return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
	char filename[128];
	signed int file_handling_code = file_handling(argc, argv, filename);	
	if ( file_handling_code == EXIT_FAILURE )
		exit(EXIT_FAILURE);

//	FILE * chip8_file = fopen(filename, "r");

	return 0;
}
