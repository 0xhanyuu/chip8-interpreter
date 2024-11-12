# chip8-interpreter

A 'chip8' interpreter program written in C to execute binary chip8 files.

## **Setup:**

Run `make all`.

This will produce object files from the C files and produce a binary called `chip8` that you may use to run any chip8 program.

## **Uninstall:**

Run `make clean`.

This will remove all object files and remove the binary file used to run chip8 programs.

## **Notes:**

This project is a work in progress. The interpreter has not been written and some opcodes are yet to be added.

The default compiler used for this project is `gcc` and may be substituted with any other compiler, as well as other compiler information found in the `Makefile`.
