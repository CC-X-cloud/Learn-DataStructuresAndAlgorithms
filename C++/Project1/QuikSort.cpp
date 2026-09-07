#include <iostream>
#include <vector>
using namespace std;

class QuickSort {
public:
	void quickSort_v1(vector<int>& arr, int left, int right) {
		if (left > right) return;

		int index = partition_v1(arr, left, right);

		quickSort_v1(arr, left, index);
		quickSort_v1(arr, index + 1, right);

	}
	int partition_v1(vector<int>& arr, int left, int right) {
		int pivot = arr[left];
		int i = left + 1;
		int j = right;
		int temp;
		while (i <= j) {
			while (i <= j && arr[i] <= pivot) {
				i++;
			}
			while (i <= j && arr[j] >= pivot) {
				j--;
			}
			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++;
				j--;
			}
		}
		temp = arr[left];
		arr[left] = arr[j];
		arr[j] = temp;

		return j;
	}
	void quickSort_v2(vector<int>& arr, int left, int right) {
		if (left > right) return;
		srand((unsigned)time(NULL));
		int pivotIndex = left + rand() % (right - left + 1);
		swap(arr[left], arr[pivotIndex]);
		int pivot = arr[left];

		int index = partition_v2(arr, left, right, pivot);

		quickSort_v2(arr, left, index);
		quickSort_v2(arr, index + 1, right);

	}
	int partition_v2(vector<int>& arr, int left, int right, int pivot) {
		int i = left + 1;
		int j = right;
		int cur = left+1;

		while(cur <= j) {
			if (arr[cur] < pivot) {
				swap(arr[cur], arr[i]);
				i++;
				cur++;
			}
			else if (arr[cur] > pivot) {
				swap(arr[cur], arr[j]);
				j--;
			}
			else {
				cur++;
			}
		}
		swap(arr[left], arr[i - 1]);
		return j;
	}
};