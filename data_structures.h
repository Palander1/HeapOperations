#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

// Structure representing an element.
typedef struct TAG_ELEMENT {
    int index;    // Element index.
    double key;   // Key value.
    int pos;      // Position.
} ELEMENT;

// Structure representing a heap.
typedef struct TAG_HEAP {
    int capacity; // Maximum capacity.
    int size;     // Current size.
    int *H;       // Array of indices.
} HEAP;

#endif // DATA_STRUCTURES_H
