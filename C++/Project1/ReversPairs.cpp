#include <iostream>
#include <vector>
using namespace std;

class ReversePairs {
public:
	int  reversePairs(vector<int>& arr,int size) {
		vector<int> temp(size);
		return mergeSort(arr, 0, size - 1, temp);
	}
	int mergeSort(vector<int>& arr, int left, int right, vector<int>& temp) {
		if (arr[left] <= arr[right]) return 0;

		int mid = left + (right - left) / 2;

		int res = mergeSort(arr, left, mid, temp) +
			mergeSort(arr, mid + 1, right, temp) +
			merge(arr, left, mid, right, temp);

		return res;
	}
	int merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp) {
		int i = left;
		int j = mid + 1;
		int index = 0;
		int res = 0;

		while (i <= mid && j <= right) {
			if(arr[i] <= arr[j]) {
				temp[index++] = arr[i++];
			}
			else {
				res += mid - i + 1;
				temp[index++] = arr[j++];
			}
		}
		while (i <= mid) {
			temp[index++] = arr[i++];
		}
		while (j <= right) {
			temp[index++] = arr[j++];
		}
		for(int k = 0; k < index; k++) {
			arr[left + k] = temp[k];
		}
		return res;
	}
};