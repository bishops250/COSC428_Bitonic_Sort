#include <iostream>
#include "constants.h"
#include "helper.h"
#include "bitonic_sorter.h"
#include <thread>
#include <chrono>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Determines if which direction we should swap
void verifyDirection(int *pos1, int *pos2, int direction)
{
	if (direction == (*pos1 > *pos2))
	{
		swap(pos1, pos2);
	}
}

// Function to merge array after sort
void merge(int arr[], unsigned int start, unsigned int size, unsigned int direction, unsigned int *num_threads)
{
	if (size > 1)
	{
		int half = size / REQ_POW;
		// For loop creates the bitonic sequence
		for (int unsigned i = start; i < start + half; i++)
		{
			verifyDirection(&arr[i], &arr[i + half], direction);
		}
		if (*num_threads > MIN_THREADS)
		{
			std::thread left(merge, arr, start, half, direction, num_threads);		   // Merges the first half of the list
			std::thread right(merge, arr, start + half, half, direction, num_threads); // Merges the second half of the list
			left.join();
			right.join();
		}
		else
		{
			merge(arr, start, half, direction, num_threads);		// Merges the first half of the list
			merge(arr, start + half, half, direction, num_threads); // Merges the second half of the list
		}
	}
}

// function to sort array
void bitonicSort(int arr[], int size, int direction, int num_thread)
{
	if (!isValidSize(size))
	{
		std::cout << "Number of elements, must be a power of " << REQ_POW << std::endl;
	}
	else
	{
		unsigned int threads = setThreads(num_thread);
		unsigned int dir = setDirection(direction);
		auto start_time = std::chrono::high_resolution_clock::now();
		bitonicSortWrapper(arr, 0, size, dir, &threads);
		auto end_time = std::chrono::high_resolution_clock::now();
		auto elapsed_time = end_time - start_time;
		std::cout << "Nano-seconds Elapsed Time: " << elapsed_time.count() << endl;
	}
}

void bitonicSortWrapper(int arr[], unsigned int start, unsigned int size, unsigned int direction, unsigned int *num_threads)
{
	if (size > 1)
	{
		int half = size / REQ_POW;
		if (*num_threads > MIN_THREADS)
		{
			*num_threads -= 2;
			std::thread left(bitonicSortWrapper, arr, start, half, 1, num_threads);
			std::thread right(bitonicSortWrapper, arr, start + half, half, 0, num_threads);
			left.join();
			right.join();
			*num_threads += 2;
		}
		else
		{
			bitonicSortWrapper(arr, start, half, 1, num_threads);
			bitonicSortWrapper(arr, start + half, half, 0, num_threads);
		}
		merge(arr, start, size, direction, num_threads);
	}
}
