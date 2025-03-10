#include <stdio.h>
#include <string.h>
#include "util.h"

// Parses the next instruction from standard input.
// Returns 1 for standard instructions, or a specific index for "DecreaseKey".
// Returns 0 on failure.
int nextInstruction(char *Word, double *Key) {
    int returnV;

    fscanf(stdin, "%s", Word);

    if (strcmp(Word, "Stop") == 0)
        return 1;
    if (strcmp(Word, "Read") == 0)
        return 1;
    if (strcmp(Word, "PrintArray") == 0)
        return 1;
    if (strcmp(Word, "PrintHeap") == 0)
        return 1;
    if (strcmp(Word, "BuildHeap") == 0)
        return 1;
    if (strcmp(Word, "ExtractMin") == 0)
        return 1;
    if (strcmp(Word, "Write") == 0)
        return 1;

    if (strcmp(Word, "Insert") == 0) {
        returnV = fscanf(stdin, "%lf", Key); // Read key for "Insert"
        if (returnV == 1)
            return 1;
        else
            return 0;
    }

    if (strcmp(Word, "DecreaseKey") == 0) {
        int index;
        double newKey;

        returnV = fscanf(stdin, "%d %lf", &index, &newKey);
        if (returnV == 2) {
            *Key = newKey;
            return index;
        } else {
            return 0;
        }
    }

    return 0;
}
