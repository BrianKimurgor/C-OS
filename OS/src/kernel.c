#include "./io.h"
#include "./multitasking.h"
#include "./irq.h"
#include "./isr.h"
#include "./fdc.h"

void prockernel();
void proca();

int main() 
{
	// Clear the screen
	clearscreen();

	// Initialize our keyboard
	initkeymap();

	startkernel(prockernel);
	
	return 0;
}

void prockernel() {
    printf("Starting Kernel Process...\n");
    
    createproc(proca, (void *)0x10000);  // Create user process A

    while (schedule()) {  // While there are user processes to run
        yield();
        printf("Resuming Kernel Process\n");
    }

    printf("Exiting Kernel Process...\n");
}


// The user processes

void proca() {
    printf("Starting User Process A\n");
    yield();  // Yield back to kernel

    printf("Resuming User Process A\n");
    yield();  // Yield back to kernel

    printf("Exiting User Process A\n");
    exit();  // Terminate process A
}
