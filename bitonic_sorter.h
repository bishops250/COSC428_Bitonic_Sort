#ifndef bitonic_sorter_H
#define bitonic_sorter_H

void swap(int *a, int *b);

// Determines if which direction we should swap
void verifyDirection(int *pos1, int *pos2, int direction);

// Function to merge array after sort
void merge(int arr[], unsigned int start, unsigned int size, unsigned int direction, unsigned int *num_threads);

// function to sort array
void bitonicSort(int arr[], int size, int direction, int num_thread);

void bitonicSortWrapper(int arr[], unsigned int start, unsigned int size, unsigned int direction, unsigned int *num_threads);

#endif
