#include<iostream>
using namespace std;

void min(int[],int,int);
void verifyDirection(int [],int,int,int);
void bitonicSort(int [],int,int,int);

int main(){
	int arr[8] = {3,7,4,8,6,2,1,5};

	//min(arr,1,2);
	
	//cout<<(arr[2]>arr[3])<<" ";
	verifyDirection(arr,1,2,1);
	/*for(int i = 0; i < 8; i++){
		cout<<arr[i]<<" ";
	}*/

	return 0;
}

void min(int arr[],int pos1,int pos2){
	if(arr[pos1]>arr[pos2]){
		int temp = arr[pos1];
		arr[pos1] = arr[pos2];
		arr[pos2] = temp;
	}
}

void verifyDirection(int arr[],int pos1,int pos2,int direction){
	if (direction==(arr[pos1]>arr[pos2]))
        min(arr,pos1,pos2);
}

void bitonicSort(int arr[],int start,int eleSize,int direction){
	
}