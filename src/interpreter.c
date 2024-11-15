#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <opcodes.h>
#include <sprites.h>
#include <memory.h>
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
		return EXIT_FAILURE;

	// open in binary mode
	FILE * chip8_file = fopen(filename, "rb");

	// get no. of characters of file
	fseek(chip8_file, SEEK_CUR, SEEK_END);	
	unsigned int FILE_MEMORY = ftell(chip8_file); 
	rewind(chip8_file);

	// check if valid
	if ( FILE_MEMORY > MEMORY_SIZE )
	{
		printf("%s\n", "File size too large! Exiting...");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%s\n", "File size: OK");
		printf("%s\n", "Starting program...");
	}

	return 0;
}
