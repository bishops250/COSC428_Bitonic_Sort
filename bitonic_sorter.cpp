#include<iostream>
using namespace std;

void min(int[],int,int);
void verifyDirection(int [],int,int,int);
void merge(int[],int,int,int);
void bitonicSort(int [],int,int,int);

int main(){
	int arr[8] = {3,7,4,8,6,2,1,5};
	
	//cout<<N<<"\n";
	bitonicSort(arr,0,8,1);

	for(int i = 0; i < 8; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}

// Function to swap two elements if the first position is minimum
void swap(int arr[],int pos1,int pos2){
		int temp = arr[pos1];
		arr[pos1] = arr[pos2];
		arr[pos2] = temp;
}

// Determines if which direction we should swap
void verifyDirection(int arr[],int pos1,int pos2,int direction){
	if (direction==(arr[pos1]>arr[pos2])) //if direction is 1 and (arr[pos1]>arr[pos2]) = 1 then swap
        swap(arr,pos1,pos2);
}

// Function to merge array after sort
void merge(int arr[],int start,int size,int direction){
	if(size > 1){
		int half = size/2;
		// For loop creates the bitonic sequence
		for(int i = start; i< start + half; i++){ 
			verifyDirection(arr, i, i + half, direction); 
		}
			merge(arr, start, half, direction); // Merges the first half of the list
			merge(arr, start + half, half, direction); // Merges the second half of the list
	}
}

// function to sort array
void bitonicSort(int arr[],int start,int size,int direction){
	if(size>1){
		int half = size/2;
		bitonicSort(arr, start, half, 1); 
		bitonicSort(arr, start + half, half, 0);
		merge(arr, start, size, direction);
	}
}