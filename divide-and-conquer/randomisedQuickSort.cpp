#include <iostream>
#include <cstdlib>

using namespace std;


int _partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low-1;
	for(int j=low; j<=high-1; j++){
		if (arr[j]<=pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return (i+1);
}

int partition(int arr[], int low, int high){
	srand(time(NULL));
	int random = low + rand() % (high-low);
	swap(arr[random], arr[high]);
	return _partition(arr, high, low);
}

// Divide and Conquer - QuickSort
void quickSort(int arr[], int low, int high){
	if(low < high){
		int pval = partition(arr, low, high);
		quickSort(arr, low, pval-1);
		quickSort(arr, pval+1, high);
	}
}

int main(){
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n-1);
	cout << "Sorted Array: ";
	for(int i=0; i<n; i++){
		cout << arr[i] << endl;
	}
	return 0;
}