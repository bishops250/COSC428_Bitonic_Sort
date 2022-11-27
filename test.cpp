#include "constants.h"
#include "test.h"
#include <iostream>
using namespace std;
bool isSorted(int arr[], int size, int direction)
{
    bool is_sorted = true;
    int index = 0;
    while (is_sorted && index < size)
    {
        if (direction == ASCENDING && arr[index] > arr[index + 1] || direction == DESCENDING && arr[index] < arr[index + 1])
        {
            is_sorted = false;
        }
        else
        {
            index++;
        }
    }
    return is_sorted;
}

void outputArr(int arr[], int size)
{
    for (int index = 0; index < size; ++index)
    {
        cout << arr[index] << " ";
        if (index % 12 == 0)
        {
            cout << endl;
        }
    }
}

int *generateArr(int size, bool max_range, int min, int max)
{
    int rand_arr[size];
    if (max_range)
    {
        for (int index = 0; index < size; ++index)
        {
            rand_arr[index] = rand();
        }
    }
    else
    {
        for (int index = 0; index < size; ++index)
        {
            rand_arr[index] = (rand() % max) + min;
        }
    }
    return rand_arr;
}