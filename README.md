# Tower-of-Hanoi-Problem-Solver
This program solves the Tower of Hanoi problem using recursion.

The Tower of Hanoi is a classic mathematical puzzle involving three rods and a number of disks (N) of different sizes, with the goal of moving all disks from one rod to another, following specific rules: only one disk (the disk at the top of a rod) can be moved at a time, and a larger disk cannot be placed on top of a smaller one. 

How to run/execute the program

Files needed:
1. main.cpp

Compilation & Execution:
1. While in the directory containing the main.cpp file, type and enter in Terminal, the command: g++ -std=c++11 main.cpp
2. To run the program, type and enter the command: ./a.out

Using the running program:
1. The program first prompts for a number greater than 2 to use as the number of rings to initially place on 1st of the 3 rods (N)
2. Once a number is entered, the program prints a visualization of the status of the 3 rods (A, B and C) before any movement (all N rings are on rod A; The bigger the number, the larger the ring)
3. For each movement of a ring from one rod to another, the program details which ring was moved to which rod and prints a visualization of the status of all rods after the move. 
4. The program ends with all rings in the correct order (decreasing diameter from bottom to top) on a rod that is not rod A. 

Other notes:
1. make sure when compiling the program, that the "-std=c++11" flag is in the command as my code may not properly compile with older compilers without the specified flag.
