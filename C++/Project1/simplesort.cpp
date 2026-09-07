#include "simplesort.h"
using namespace std;

int* simplesort::BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size -1; i++) {
		bool isSwapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				simplesort::swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}
		if (!isSwapped) {
			break;
		}
	}
	return arr;
};
int* simplesort::SelectionSort(int arr[], int size) 
{
	for (int i = 0; i < size; i++) {
		int* min = &arr[i];
		for (int j = i+1; j < size ; j++) {
			if(arr[j] < *min) {
				min = &arr[j];
			}
		}
		simplesort::swap(arr[size - i -1], *min);
	}
	return arr;
}
int* simplesort::InsertionSort(int arr[], int size) 
{
	for (int i = 1; i < size; i++) 
	{
		for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--) 
		{
			simplesort::swap(arr[j], arr[j - 1]);
		}
	}
	return arr;
}