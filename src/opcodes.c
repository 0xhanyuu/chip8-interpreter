#include <stdio.h>
#include <stdint.h>

extern uint16_t I;
extern uint8_t PC;
extern uint16_t STACK[16];

void SYS(uint16_t I) // 0nnn
{

}

void CLS() // 00e0
{

}

void RET(uint8_t SP, uint8_t PC) // 00ee
{
	PC = STACK[SP]; 
	SP = SP - 1;
}

void CALL(uint16_t I, uint8_t SP, uint8_t PC) // 0nnn
{
	SP = SP + 1;
	// put PC on top of stack
	// PC is then set to address
}

// // // // // // // // // // // // // // // // // // // // // // // // //

void JMP(uint16_t I, uint8_t PC) // 1nnn
{
	PC = I;
}

// // // // // // // // // // // // // // // // // // // // // // // // //

void CALL_() // 2nnn
{

}

// // // // // // // // // // // // // // // // // // // // // // // // //

void SE(uint8_t register_index, // 3xnn
		uint16_t STACK[16],
		uint8_t byte,
		uint8_t PC)
{
	if ( STACK[register_index] == byte )
		PC = PC + 2;
}

// // // // // // // // // // // // // // // // // // // // // // // // //

void SNE(uint8_t register_index, // 4xnn
		 uint16_t STACK[16],
		 uint8_t byte,
		 uint8_t PC)
{
	if ( STACK[register_index] != byte )
		PC = PC + 2;
}

// // // // // // // // // // // // // // // // // // // // // // // // //

void SE_(uint8_t register_x, // 5xy0
		 uint8_t register_y,
		 uint16_t STACK[16],
		 uint8_t PC)
{
	if ( STACK[register_x] == STACK[register_y] )
		PC = PC + 2;
}

// // // // // // // // // // // // // // // // // // // // // // // // //

void LD(uint8_t byte, // 6xnn
		uint8_t register_index,
		uint16_t STACK[16])
{
	STACK[register_index] = byte;
}

// // // // // // // // // // // // // // // // // // // // // // // // //

void ADD(uint8_t byte, // 7xnn
		uint8_t register_index,
		uint16_t STACK[16])
{
	STACK[register_index] = STACK[register_index] + byte;
}

// // // // // // // // // // // // // // // // // // // // // // // // //

void LD1(uint8_t register_x, // 8xy0
		 uint8_t register_y,
		 uint16_t STACK[16])
{
	STACK[register_x] = STACK[register_y];
}

void OR(uint8_t register_x, // 8xy1
		uint8_t register_y,
		uint16_t STACK[16])
{
	STACK[register_x] = STACK[register_x] | STACK[register_y];
}

void AND(uint8_t register_x, // 8xy2
		 uint8_t register_y,
		 uint16_t STACK[16])
{
	STACK[register_x] = STACK[register_x] & STACK[register_y];
}

void XOR(uint8_t register_x, // 8xy3
		 uint8_t register_y,
		 uint16_t STACK[16])
{
	STACK[register_x] = STACK[register_x] ^ STACK[register_y];
}

void ADD1() // 8xy4

void SUB() // 8xy5

void SHR() // 8xy6

void SUBN() // 8xy7

void SHL() // 8xye

void SNE_() // 9xy0

// // // // // // // // // // // // // // // // // // // // // // // // //

void LD2() // annn

// // // // // // // // // // // // // // // // // // // // // // // // //

void JMP_() // bnnn

// // // // // // // // // // // // // // // // // // // // // // // // //

void RND() // cxnn

// // // // // // // // // // // // // // // // // // // // // // // // //

void DRW() // dxyn

// // // // // // // // // // // // // // // // // // // // // // // // //

void SKP() // ex9e

void SKNP() // exa1

// // // // // // // // // // // // // // // // // // // // // // // // //

void LD3() // fx07

void LD4() // fx0a

void LD5() // fx15

void LD6() // fx18

void ADD2() // fx1e

void LD7() // fx29

void BCD() // fx33

void  
