# simple-ev-charging

This is a simple CPS example using a "made up" ev charging station example with a sinusoidal price curve and sinusoidal demand.

The controller has only a single output, which is to choose what the battery should do, either charge or discharge.

## Notes for WCET analysis
- Ensure all loops are bounded by constant bounds.
- Ensure no structs are passed as function parameters and accessed. Only memory may be pointed to.
- Ensure that the correct project and function are chosen in the makefile.
- No trigonometric functions from <math.h> allowed!
- No functions from <string.h> allowed!
- No FILE functions allowed!

## Usage
To start the WCET process
1) Call "make esterel" to create the .c file from the Esterel file. 
2) Ensure, in the .c file, that the char arrays have a max size of your choosing, since Esterel limits this to 81. Check STRLEN at top of <prog.c>.
3) Call "make build" to prepare the build files for a WCET analysis.
4) Call "make wcet" to start the WCET analysis.

To build and run the Esterel implementation
1) 
