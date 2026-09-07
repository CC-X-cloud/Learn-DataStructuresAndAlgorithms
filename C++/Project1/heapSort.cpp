#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
public:
	void heapify(vector<int>& arr, int index, int heapSize) {
		int left = 2 * index + 1;
		while (left < heapSize) {
			int largest = (left + 1 < heapSize && arr[left + 1] > arr[left]) ? left + 1 : left;
			largest = (arr[largest] > arr[index]) ? largest : index;
			if (largest == index) {
				break;
			}
			swap(arr[largest], arr[index]);
			index = largest;
			left = 2 * index + 1;
		}
	}
	void heapInsert(vector<int>& arr, int index) {
		while(arr[index] > arr[(index - 1) / 2]) {
			swap(arr[index], arr[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}
	void heapSort(vector<int>& arr) {
		int n = arr.size();
		if ( n <= 1) return;

		/*for(int i = 0; i < n ; i++) {
			heapInsert(arr, i);
		}*/

		for(int i = n - 1; i >= 0; i--) {
			heapify(arr, i, n);
		}

		int heapSize = n;
		swap(arr[0], arr[--heapSize]);
		while(heapSize > 0) {
			heapify(arr, 0, heapSize);
			swap(arr[0], arr[--heapSize]);
		}
	}
};