# Algorithms Project

This project implements a series of algorithms in C, focusing on tree structures, dictionaries, and other foundational data structures. It is designed to provide an educational understanding of how these algorithms work and how they are implemented in C.

---

## Project Structure

The repository contains the following files:

- **`arbre.c`**: Contains functions and implementations related to tree data structures.
- **`arbre.h`**: Header file for `arbre.c`, defining tree-related function prototypes and data structures.
- **`dico.c`**: Implements dictionary operations using appropriate data structures.
- **`dico.h`**: Header file for `dico.c`, providing dictionary function declarations and structure definitions.
- **`main.c`**: Main program file to demonstrate and test the functionality of the tree and dictionary implementations.
- **`dico.txt`**: Sample input file for testing dictionary-related operations.
- **Object Files (`*.o`)**: Compiled versions of the source files for linking into the final executable.

---

## Prerequisites

To compile and run this project, you need:

- A **C Compiler** (e.g., GCC)
- A terminal or command-line interface
- A text editor or IDE for editing C code (optional)

---

## How to Compile and Run

### Step 1: Compile the Project
Open a terminal and navigate to the project directory. Use the following commands:

```bash
# Compile individual source files
gcc -c arbre.c -o arbre.o
gcc -c dico.c -o dico.o
gcc -c main.c -o main.o

# Link the object files to create the final executable
gcc arbre.o dico.o main.o -o project_executable
