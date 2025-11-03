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
        weightArr[++size] = idx;            // insert at the end of heap
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
        while ((2 * pos) + 1 < size) { // while left child exists
            int left = (2 * pos) + 1;   // left child
            int right = (2 * pos) + 2;  // right child
            int min = left;             // smallest child
            if (right < size && weightArr[right] < weightArr[left]) {   // if-statement to check if right child is less that the size of the heap and if the value
                min = right;                                            //  of right child is smaller than the value of the left child find smaller child
            }
            if (weightArr[pos] <= weightArr[min]) {     // if-statement to check if child is less than or
                break;                                  //  equal to parent in order to hold heap property
            }
            pos = min;  // move down the heap tree
        }
    }
};

#endif