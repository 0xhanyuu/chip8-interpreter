#include <stdio.h>
#include <stdint.h>

extern uint16_t I;
extern uint8_t PC;
extern uint16_t STACK[16];

// jump to subroutine, given by address
void SYS(uint16_t I)
{

}

// clear the screen
void CLS()
{

}

// return from a subroutine

void RET(uint8_t SP, uint8_t PC)
{
	// PC = address at top of stack
 
	SP = SP - 1;
}

// jump to location address
void JP(uint16_t I, uint8_t PC)
{
	PC = I;
}

void CALL(uint16_t I, uint8_t SP, uint8_t PC)
{
	SP = SP + 1;
	// put PC on top of stack
	// PC is then set to address
}

void SE(uint16_t register_index,
		uint16_t STACK[16],
		uint8_t byte,
		uint8_t PC)
{
	if ( STACK[register_index] == byte )
		PC = PC + 2;
}