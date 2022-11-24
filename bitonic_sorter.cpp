
void swap(int * a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Determines if which direction we should swap
void verifyDirection(int * pos1, int * pos2, int direction) {
	if ( direction == (*pos1 > *pos2)) {
		swap(pos1,pos2);
	}
}

// Function to merge array after sort
void merge(int arr[],int start,int size,int direction){
	if(size > 1){
		int half = size/2;
		// For loop creates the bitonic sequence
		for(int i = start; i< start + half; i++){
			verifyDirection(&arr[i], &arr[i + half], direction);
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