//
// Created by Fabian Llamas on 11/2/25.
//
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // DONE: insert index at end of heap, restore order using upheap()
        data[++size] = idx;                 // insert at the end of heap
        upheap(size - 1, weightArr);    // restore heap priority
    }

    int pop(int weightArr[]) {
        // DONE: remove and return smallest index
        // Replace root with last element, then call downheap()
        int minIdx = weightArr[0];          // root
        weightArr[0] = weightArr[size - 1]; // shift last to root
        size--;                             // remove the last element
        downheap(0, weightArr);         // restore heap priority
        return minIdx;                      // return the smallest index
    }

    void upheap(int pos, int weightArr[]) {
        // DONE: swap child upward while smaller than parent
        int parent = (pos - 1) / 2;     // parent
        while (pos > 0 && weightArr[pos] < weightArr[parent]) {
            if (weightArr[pos] >= weightArr[parent]) {  // if-statement to check if child is greater than or
                break;                                  //  equal to parent in order to hold heap property
            }
            swap(weightArr[pos], weightArr[parent]);    // swap child upward
            pos = parent; // move up the heap tree
        }
    }

    void downheap(int pos, int weightArr[]) {
        // DONE: swap parent downward while larger than any child
        int min = pos;
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;

        if (left < size && weightArr[left] < weightArr[min]) {
            min = left;
        }
        if (right < size && weightArr[right] < weightArr[min]) {
            min = right;
        }
        if (min != pos) {
            swap(weightArr[min], weightArr[pos]);
            downheap(min, weightArr);
        }
    }
};

#endif