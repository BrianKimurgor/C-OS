\# README: Cooperative Multitasking Operating System

\## Overview

This project implements \*\*basic cooperative multitasking\*\* in a simulated operating system. Cooperative multitasking allows processes to voluntarily yield control of the CPU, enabling multiple processes (kernel and user) to share the system resources efficiently. This multitasking OS features \*\*context switching\*\*, process management, and a simple \*\*kernel-user process flow\*\*, forming the groundwork for a fully functional multitasking system.

This OS can:

1\. \*\*Switch between a kernel process and user processes\*\*.

2\. \*\*Yield control\*\* between processes to simulate multitasking.

3\. \*\*Terminate processes\*\* gracefully.

4\. \*\*Create new user processes\*\* and maintain them using a process array.

\---

\## \*\*File Descriptions\*\*

Below are the key files in the project and their responsibilities:

\### \*\*1. multitasking.h\*\*

Defines the necessary data structures and constants used in the multitasking logic:

\- \*\*Process Control Block (PCB)\*\*: Stores process state and register values.

\- \*\*\`proc\_status\_t\`\*\*: Enumerates process statuses like \`PROC\_READY\`, \`PROC\_RUNNING\`, and \`PROC\_TERMINATED\`.

\- \*\*\`proc\_type\_t\`\*\*: Defines two types of processes: \`PROC\_USER\` and \`PROC\_KERNEL\`.

\- Constants for \*\*maximum process limits\*\*: \`MAX\_USER\_PROCS\` and \`MAX\_KERN\_PROCS\`.

\### \*\*2. multitasking.c\*\*

Contains core multitasking logic such as process creation, scheduling, yielding, exiting, and context switching:

\- \*\*\`createproc()\`\*\*: Creates and initializes user processes.

\- \*\*\`schedule()\`\*\*: Selects the next process to run from the process list.

\- \*\*\`yield()\`\*\*: Switches between processes to simulate cooperative multitasking.

\- \*\*\`exit()\`\*\*: Terminates the currently running process.

\- \*\*\`switchcontext()\`\*\*: Handles the \*\*saving and restoring of process states\*\* during context switches.

\### \*\*3. kernel.c\*\*

This file defines the \*\*kernel process\*\* and the \*\*user process\*\* (proca). It controls the main execution flow:

\- \*\*\`main()\`\*\*: Clears the screen, initializes the keyboard, and starts the kernel process.

\- \*\*\`prockernel()\`\*\*: Manages the flow between the kernel and user processes.

\- \*\*\`proca()\`\*\*: A user process that prints messages, yields to the kernel, and terminates itself.

\---

\## \*\*How it Works\*\*

1\. \*\*Process Creation\*\*

\- When the OS boots, the kernel process starts (\`prockernel()\`).

\- A \*\*user process\*\* (\`proca()\`) is created using the \`createproc()\` function, initialized with a ready status and a function to execute.

2\. \*\*Process Scheduling\*\*

\- The \`schedule()\` function selects the next user process that is ready to run from the process list.

\- If there are no more user processes to run, the system continues with the kernel process or halts with an error message.

3\. \*\*Context Switching\*\*

\- \*\*\`switchcontext()\`\*\* saves the CPU state (register values, stack pointers, program counter) of the currently running process and loads the state of the next process to run. This function allows the system to seamlessly resume processes later from where they left off.

4\. \*\*Cooperative Multitasking\*\*

\- Processes \*\*voluntarily yield\*\* control using the \`yield()\` function, giving other processes a chance to execute.

\- The \*\*kernel process\*\* runs until it yields to the user process, and the user process yields back to the kernel. This cycle continues until the user process terminates.

5\. \*\*Process Termination\*\*

\- A process can \*\*terminate itself\*\* using the \`exit()\` function. When a user process terminates, control is returned to the kernel.

\---

\## \*\*Program Flow Example\*\*

1\. The OS starts and the \*\*kernel process\*\* prints:

\`\`\`

Starting Kernel Process...

\`\`\`

2\. The kernel process creates a \*\*user process\*\* (\`proca\`).

3\. The user process prints:

\`\`\`

Starting User Process A

\`\`\`

4\. The user process \*\*yields\*\* to the kernel, which resumes and prints:

\`\`\`

Resuming Kernel Process

\`\`\`

5\. The kernel yields back to the user process, which prints:

\`\`\`

Resuming User Process A

\`\`\`

6\. This back-and-forth continues until the user process prints:

\`\`\`

Exiting User Process A

\`\`\`

7\. Once the user process terminates, the kernel detects no more user processes and prints:

\`\`\`

Exiting Kernel Process...

\`\`\`

\---

\## \*\*Compilation and Execution Instructions\*\*

1\. \*\*Compile the Source Code\*\*:

Ensure that your environment supports C programming (GCC or any other compatible compiler). Use the following command to compile the code:

\`\`\`bash

gcc -o multitask\_os kernel.c multitasking.c io.c -Wall

\`\`\`

2\. \*\*Run the Program\*\*:

\`\`\`bash

./multitask\_os

\`\`\`

3\. \*\*Expected Output\*\*:

\`\`\`

Starting Kernel Process...

Starting User Process A

Resuming Kernel Process

Resuming User Process A

Exiting User Process A

Exiting Kernel Process...

\`\`\`

\---

\## \*\*Functions Implemented\*\*

\### \*\*1. createproc()\*\*

\- Initializes a new user process with a given function and stack location.

\- Adds the new process to the process array.

\### \*\*2. schedule()\*\*

\- Selects the next process to run. In this project, it always selects the single user process available.

\### \*\*3. yield()\*\*

\- Switches control between processes using the \`switchcontext()\` function.

\### \*\*4. exit()\*\*

\- Terminates the current process by setting its status to \`PROC\_TERMINATED\`.

\### \*\*5. switchcontext()\*\*

\- \*\*Saves and restores process states\*\* to ensure smooth context switching.

\---

\## \*\*Known Limitations\*\*

\- \*\*Single User Process\*\*: This implementation only supports \*\*one user process\*\* for simplicity. Future enhancements could allow multiple user processes.

\- \*\*Basic Scheduling\*\*: Currently, scheduling always selects the only available user process. In the future, more complex scheduling algorithms (e.g., round-robin or priority-based) could be introduced.

\- \*\*Cooperative Multitasking\*\*: Processes must voluntarily yield; there is no pre-emption.

\---

\## \*\*How to Extend This Project\*\*

1\. \*\*Multiple User Processes\*\*: Add support for creating and managing multiple user processes.

2\. \*\*Advanced Scheduling\*\*: Implement a round-robin or priority-based scheduling algorithm.

3\. \*\*Preemptive Multitasking\*\*: Add interrupt-driven context switching to allow processes to be preempted.

4\. \*\*More System Calls\*\*: Extend the kernel with additional system calls for inter-process communication and memory management.

\---

\## \*\*Conclusion\*\*

This project demonstrates the fundamental concepts of \*\*cooperative multitasking\*\* by implementing kernel and user processes, context switching, and process management. It lays the foundation for a more advanced operating system with multiple user processes and complex scheduling algorithms.