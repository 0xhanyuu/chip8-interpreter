#pragma once

#include <stdint.h>

// constants

#define MEMORY_START 0x200ul	 				  // 512
#define ETI660_START 0x600ul	 	 			  // 1536
#define INTERPRETER_MEMORY 0x200ul				  // 512
#define MEMORY_SIZE 0xFFFul						  // 4096 
#define PROGRAM_SIZE (MEMORY_SIZE - MEMORY_START) // 4096 - 512

extern uint8_t SP;
extern uint8_t PC;
extern uint16_t I;
