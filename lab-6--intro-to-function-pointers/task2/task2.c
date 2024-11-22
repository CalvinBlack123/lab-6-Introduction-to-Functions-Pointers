#include <stdio.h>
#include <stdlib.h>

// Function pointer type for operations
typedef int (*Operation)(int, int);

// Operation functions
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main(int argc, char* argv[]) {
    // Predefined operands
    int a = 6, b = 3;
    printf("Operand 'a' : %d | Operand 'b' : %d\n", a, b);
    
    // Array of operation function pointers
    Operation ops[] = {add, subtract, multiply, divide};
    
    // Number of operations
    int num_ops = sizeof(ops) / sizeof(ops[0]);
    
    // Infinite loop for operations
    while (1) {
        int op;
        printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
        scanf("%d", &op);
        
        // Exit condition
        if (op == 4) break;
        
        // Perform operation using function pointer
        // Uses array indexing to select operation without conditionals
        int result = ops[op](a, b);
        
        // Print operation description
        const char* op_names[] = {"Adding 'a' and 'b'", 
                                  "Subtracting 'b' from 'a'", 
                                  "Multiplying 'a' and 'b'", 
                                  "Dividing 'a' by 'b'"};
        printf("%s x = %d\n", op_names[op], result);
    }
    
    return 0;
}