#include <iostream>
#include <vector>
using namespace std;

class SmallProblem {
public:
	int smallsum(vector<int>& arr, int size) {
				vector<int> temp(size);
		return merageSort(arr, 0, size - 1, temp);
	}
	int merageSort(vector<int>& arr, int left, int right, vector<int>& temp) {
		if (left >= right) return 0;

		int mid = left + (right - left) / 2;

		int smallsum = merageSort(arr, left, mid, temp) +
		merageSort(arr, mid + 1, right, temp) +
		merage(arr, left, mid, right, temp);

		return smallsum;
	}
	int merage(vector<int>& arr, int left, int mid, int right, vector<int>& temp) {
		int i = left;
		int j = mid + 1;
		int index = 0;
		int smallsum = 0;
		
		while (i <= mid && j <= right) {
			if (arr[i] < arr[j]) {
				smallsum += arr[i] * (right - j + 1);
				temp[index++] = arr[i++];
			}
			else {
				temp[index++] = arr[j++];
			}
		}
		while(i <= mid) {
			temp[index++] = arr[i++];
		}
		while(j <= right) {
			temp[index++] = arr[j++];
		}
		for (int k = 0; k < index; k++) {
			arr[left + k] = temp[k];
		}
		return smallsum;
	}
};