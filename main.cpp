#include "bitonic_sorter.h"
#include<iostream>
using namespace std;


int main(){
	int arr[8] = {3,7,4,8,6,2,1,5};
	
	//cout<<N<<"\n";
	bitonicSort(arr,0,8,1);

	for(int i = 0; i < 8; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
