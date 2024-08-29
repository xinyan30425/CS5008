
// Xinyan Liu
// March 22,2023
// CS5008 Lab07
//
// Implement your cycle count tool here.

#include <stdio.h>
#include <string.h>


int main(int argc, char** argv) {
    // Open the assembly file for reading
    FILE* input = fopen(argv[1],"r");
    // FILE* file = fopen("barebones.s", "r");
    if (input == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    //Initialize instruction and cycle counts to 0
    
    int cycles=0, add = 0, sub = 0, mul = 0, div = 0, mov = 0, lea = 0, push = 0, pop = 0, ret = 0;

    //read characters from the inputfile into the buffer array
    char buffer[256];

    // Loop through each line of the file
    while (fgets(buffer, 256, input)) {
        char instruction[4];
        sscanf(buffer, "%3s", instruction);//read the first three characters of each line into a "char" array of size 4
        // Count the number of cycles for each instruction type
        if (strstr(instruction, "ADD") != NULL) {
            cycles += 1;
            add += 1;
        } else if (strstr(instruction, "SUB") != NULL) {
            cycles += 1;
            sub += 1;
        } else if (strstr(instruction, "MUL") != NULL) {
            cycles += 1;
            mul += 1;
        } else if (strstr(instruction, "DIV") != NULL) {
            cycles += 1;
            div += 1;
        } else if (strstr(instruction, "mov") != NULL) {
            cycles += 1;
            mov += 1;
        } else if (strstr(instruction, "lea") != NULL) {
            cycles += 1;
            lea += 1;
        } else if (strstr(instruction, "pus") != NULL) {
            cycles += 1;
            push += 1;
        } else if (strstr(instruction, "pop") != NULL) {
            cycles += 1;
            pop += 1;
        } else if (strstr(instruction, "RET") != NULL) {
            cycles += 1;
            ret += 1;
        }
    }

// Print the results
    printf("ADD counts as %d cycle\n", add);
    printf("SUB counts as %d cycle\n", sub);
    printf("MUL counts as %d cycles\n", mul);
    printf("DIV counts as %d cycles\n", div);
    printf("MOV counts as %d cycle\n", mov);
    printf("LEA counts as %d cycles\n", lea);
    printf("PUSH counts as %d cycle\n", push);
    printf("POP counts as %d cycle\n", pop);
    printf("RET counts as %d cycle\n", ret);
    printf("Total instructions: %d\n", add + sub + mul + div + mov + lea + push + pop + ret);
    printf("Total cycles: %d\n", cycles);

    // Close the file
    fclose(input);

    return 0;

}
