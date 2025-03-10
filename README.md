# Heap Operations Project

A C++ project demonstrating custom min-heap operations.

## File Structure

- **data_structures.h**: Data type definitions for ELEMENT and HEAP.
- **heap.h / heap.cpp**: Implementation of min-heap operations.
- **util.h / util.cpp**: Utility functions for reading instructions.
- **main.h / main.cpp**: Main program that processes heap commands.
- **Makefile**: Build instructions.

## Compilation

To compile the project, run:
```bash
make
This produces an executable named PJ2.

Usage
Run the executable as follows:

bash
Copy
./PJ2 INPUT_FILE OUTPUT_FILE
Where:

INPUT_FILE is the path to the input file containing heap data.
OUTPUT_FILE is the path to the file where results will be written.
Input File Format
First line: An integer n representing the number of elements.
Each subsequent line: A floating-point number representing an element's key.
Example:

Copy
5
3.2
1.5
4.8
2.9
0.7
Available Commands
The program reads commands from standard input. Available commands include:

Stop: Terminates the program.
Read: Reads heap data from the input file and initializes the heap.
PrintArray: Prints the array of heap elements.
PrintHeap: Prints the current state of the heap.
BuildHeap: Constructs the heap from the array.
ExtractMin: Extracts the minimum element from the heap.
Insert: Inserts a new element into the heap.
DecreaseKey: Decreases the key of a specified element.
Write: Writes the heap data to the output file.
Copy
