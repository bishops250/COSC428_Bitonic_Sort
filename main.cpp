#include "bitonic_sorter.h"
#include <iostream>
using namespace std;

int main()
{
	int arr[8] = {3, 7, 4, 8, 6, 2, 1, 5};

	// cout<<N<<"\n";
	bitonicSort(arr, 8, 1, 1);

	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
