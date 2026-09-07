#include <iostream>
#include <vector>
using namespace std;

class MergeSort {
	public:
		void merge(vector<int>& arr, int left, int mid, int right, vector<int>& temp) {
			int i = left;
			int j = mid + 1;
			int index = 0;

			while (i <= mid && j <= right) {
				if (arr[i] <= arr[j]) {
					temp[index++] = arr[i++];
				}
				else {
					temp[index++] = arr[j++];
				}
			}
			while (i <= mid) {
				temp[index++] = arr[i++];
			}
			while (j <= right) {
				temp[index++] = arr[j++];
			}

			for (int k = 0; k < index; k++) {
				arr[left + k] = temp[k];
			}
		}
		void mergeSort(vector<int>& arr, int left, int right, vector<int>& temp) {
			//终止条件
			if (left >= right) return;

			//分治
			int mid = left + (right - left) / 2;

			mergeSort(arr, left, mid, temp);
			mergeSort(arr, mid + 1, right, temp);

			merge(arr, left, mid, right, temp);

		}

};