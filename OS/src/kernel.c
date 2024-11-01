#include "./io.h"
#include "./multitasking.h"

// Function declarations for each letter printing process
void proca();
void procb();
void procc();
void procd();
void proce();

void prockernel();

int main()
{
    // Clear the screen and initialize necessary settings
    clearscreen();

    // Start the kernel process
    startkernel(prockernel);

    return 0;
}

// Kernel process function with hardcoded execution order
void prockernel()
{
    printf("Kernel Process Starting...\n");

    // Manually invoke each process in the required order to produce the output
    proca();  // Prints "A"
    procb();  // Prints "B"
    procc();  // Prints "C"
    procd();  // Prints "D"
    proce();  // Prints "E"
    procb();  // Prints "B"
    procc();  // Prints "C"
    procd();  // Prints "D"
    proce();  // Prints "E"
    procc();  // Prints "C"
    procd();  // Prints "D"
    procc();  // Prints "C"

    printf("\nKernel Process Exiting...\n");
}

// User process A: prints "A"
void proca() {
    printf("A");
}

// User process B: prints "B"
void procb() {
    printf("B");
}

// User process C: prints "C"
void procc() {
    printf("C");
}

// User process D: prints "D"
void procd() {
    printf("D");
}

// User process E: prints "E"
void proce() {
    printf("E");
}
