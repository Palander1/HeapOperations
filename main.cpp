#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "main.h"

int main(int argc, char **argv) {
    FILE *inputFile, *outputFile;
    HEAP *pHeap;
    ELEMENT **V;
    double key;
    int n, returnV;
    char instruction[100];

    // Check command-line arguments.
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <I-File> <O-File>\n", argv[0]);
        exit(0);
    }

    // Open the output file.
    outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        fprintf(stderr, "Error: cannot open file %s\n", argv[2]);
        exit(0);
    }

    pHeap = NULL;
    V = NULL;

    // Loop over instructions.
    while (1) {
        returnV = nextInstruction(instruction, &key);
        if (returnV == 0) {
            fprintf(stderr, "Warning: Invalid instruction: %s\n", instruction);
            continue;
        }

        // Handle "Stop" instruction.
        if (strcmp(instruction, "Stop") == 0) {
            printf("Instruction: Stop\n");
            if (outputFile) {
                fclose(outputFile);
            }
            return 0;
        }

        // Handle "Read" instruction.
        if (strcmp(instruction, "Read") == 0) {
            // Open the input file and initialize the heap.
            inputFile = fopen(argv[1], "r");
            if (!inputFile) {
                fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
                exit(0);
            }
            fscanf(inputFile, "%d", &n);

            // Allocate memory for the ELEMENT array.
            V = (ELEMENT **) malloc((n + 1) * sizeof(ELEMENT *));
            for (int i = 1; i <= n; i++) {
                V[i] = (ELEMENT *) malloc(sizeof(ELEMENT));
                fscanf(inputFile, "%lf", &V[i]->key);
                V[i]->index = i;
                V[i]->pos = 0;
            }
            fclose(inputFile);

            // Allocate memory for the heap.
            pHeap = (HEAP *) malloc(sizeof(HEAP));
            pHeap->capacity = n;
            pHeap->size = 0;
            pHeap->H = (int *) malloc((n + 1) * sizeof(int));

            printf("Instruction: Read\n");
            continue;
        }

        // Handle "PrintArray" instruction.
        if (strcmp(instruction, "PrintArray") == 0) {
            printf("Instruction: PrintArray\n");
            for (int i = 1; i <= n; i++) {
                printf("%d %lf %d\n", V[i]->index, V[i]->key, V[i]->pos);
            }
            continue;
        }

        // Handle "BuildHeap" instruction.
        if (strcmp(instruction, "BuildHeap") == 0) {
            printf("Instruction: BuildHeap\n");
            BuildHeap(pHeap, V);
            continue;
        }

        // Handle "Insert" instruction.
        if (strcmp(instruction, "Insert") == 0) {
            printf("Instruction: Insert %d\n", (int) key);
            if ((int) key >= 1 && (int) key <= n) {
                Insert(pHeap, V, (int) key);
            } else {
                fprintf(stderr, "Error: index out of bound\n");
            }
            continue;
        }

        // Handle "ExtractMin" instruction.
        if (strcmp(instruction, "ExtractMin") == 0) {
            printf("Instruction: ExtractMin\n");
            ExtractMin(pHeap, V);
            continue;
        }

        // Handle "PrintHeap" instruction.
        if (strcmp(instruction, "PrintHeap") == 0) {
            printf("Instruction: PrintHeap\n");
            if (pHeap == NULL) {
                fprintf(stderr, "Error: heap is NULL\n");
            } else {
                PrintHeap(pHeap, V);
            }
            continue;
        }

        // Handle "DecreaseKey" instruction.
        if (strcmp(instruction, "DecreaseKey") == 0) {
            int index = returnV;
            printf("Instruction: DecreaseKey %d %lf\n", index, key);
            DecreaseKey(pHeap, V, index, key);
            continue;
        }

        // Handle "Write" instruction.
        if (strcmp(instruction, "Write") == 0) {
            printf("Instruction: Write\n");
            if (outputFile) {
                for (int i = 1; i <= n; i++) {
                    fprintf(outputFile, "%d %lf %d\n", V[i]->index, V[i]->key, V[i]->pos);
                }
            }
            continue;
        }
    }

    return 1;
}
