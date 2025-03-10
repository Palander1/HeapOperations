#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

// Function declarations.
void Heapify(HEAP *pHeap, ELEMENT **V, int i);
void BuildHeap(HEAP *pHeap, ELEMENT **V);
void Insert(HEAP *pHeap, ELEMENT **V, int index);
void ExtractMin(HEAP *pHeap, ELEMENT **V);
void PrintHeap(HEAP *pHeap, ELEMENT **V);
void DecreaseKey(HEAP *pHeap, ELEMENT **V, int index, double newKey);
void PrintArray(ELEMENT **V, int n);

#endif // HEAP_H
