#include "heap.h"
#include <iostream>
#include <cmath>

// Maintains the heap property.
void Heapify(HEAP *pHeap, ELEMENT **V, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;

    if (left <= pHeap->size && V[pHeap->H[left]]->key < V[pHeap->H[smallest]]->key)
        smallest = left;

    if (right <= pHeap->size && V[pHeap->H[right]]->key < V[pHeap->H[smallest]]->key)
        smallest = right;

    if (smallest != i) {
        // Swap positions in H.
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[smallest];
        pHeap->H[smallest] = temp;

        // Update positions in ELEMENT array.
        V[pHeap->H[i]]->pos = i;
        V[pHeap->H[smallest]]->pos = smallest;

        Heapify(pHeap, V, smallest);
    }
}

// Builds a min-heap from the given ELEMENT array.
void BuildHeap(HEAP *pHeap, ELEMENT **V) {
    pHeap->size = pHeap->capacity;

    // Initialize heap indices and positions.
    for (int i = 1; i <= pHeap->size; i++) {
        pHeap->H[i] = i;
        V[i]->pos = i;
    }

    for (int i = pHeap->size / 2; i >= 1; i--) {
        Heapify(pHeap, V, i);
    }
}

// Inserts a new element into the heap.
void Insert(HEAP *pHeap, ELEMENT **V, int index) {
    if (V[index]->pos != 0) {
        std::cerr << "Error: V[" << index << "] already in the heap\n";
        return;
    }

    // Increment heap size and insert new element at the end.
    pHeap->size++;
    pHeap->H[pHeap->size] = index;
    V[index]->pos = pHeap->size;

    // Restore heap property by bubbling up.
    int i = pHeap->size;
    while (i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i / 2]]->key) {
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[i / 2];
        pHeap->H[i / 2] = temp;

        // Update positions in ELEMENT array.
        V[pHeap->H[i]]->pos = i;
        V[pHeap->H[i / 2]]->pos = i / 2;

        i /= 2;
    }
    
    std::cout << "Element V[" << index << "] inserted into the heap\n";
}

// Extracts the minimum element (the root) from the heap.
void ExtractMin(HEAP *pHeap, ELEMENT **V) {
    if (pHeap->size == 0) {
        std::cerr << "Error: heap is empty\n";
        return;
    }

    int minIndex = pHeap->H[1]; // The root holds the minimum element.

    // Replace the root with the last element and decrease heap size.
    pHeap->H[1] = pHeap->H[pHeap->size];
    V[pHeap->H[1]]->pos = 1;
    V[minIndex]->pos = 0; // Mark the extracted element as removed.
    pHeap->size--;

    // Restore the heap property.
    Heapify(pHeap, V, 1);
}

// Prints the current state of the heap.
void PrintHeap(HEAP *pHeap, ELEMENT **V) {
    if (pHeap == nullptr || pHeap->capacity == 0) {
        std::cerr << "Error: heap is NULL\n";
        return;
    }

    std::cout << "Capacity = " << pHeap->capacity << ", size = " << pHeap->size << "\n";
    for (int i = 1; i <= pHeap->size; i++) {
        std::cout << "H[" << i << "] = " << V[pHeap->H[i]]->index << "\n";
    }
}

// Decreases the key of a specified element and maintains the heap property.
void DecreaseKey(HEAP *pHeap, ELEMENT **V, int index, double newKey) {
    if (V[index]->pos == 0) {
        std::cerr << "Error: V[" << index << "] not in the heap\n";
        return;
    }

    if (newKey >= V[index]->key) {
        std::cerr << "Error: New key is not smaller than current key\n";
        return;
    }

    V[index]->key = newKey;
    int i = V[index]->pos;

    while (i > 1 && V[pHeap->H[i]]->key < V[pHeap->H[i / 2]]->key) {
        int temp = pHeap->H[i];
        pHeap->H[i] = pHeap->H[i / 2];
        pHeap->H[i / 2] = temp;

        // Update positions in ELEMENT array.
        V[pHeap->H[i]]->pos = i;
        V[pHeap->H[i / 2]]->pos = i / 2;

        i /= 2;
    }
}

// Prints the array of elements.
void PrintArray(ELEMENT **V, int n) {
    std::cout << "Instruction: PrintArray\n";
    for (int i = 1; i <= n; i++) {
        std::cout << i << " " << V[i]->key << " " << V[i]->pos << "\n";
    }
}
