#include <iostream>
#include <vector>

using namespace std;

class CountingSort {
public:
	void countingSort(vector<int>& arr) {
		//找到数组中的最大值和最小值
		int max = *max_element(arr.begin(), arr.end());
		int min = *min_element(arr.begin(), arr.end());
		//创建统计数组
		vector<int> count(max - min + 1);
		for(int i = 0; i < arr.size(); i++) {
			count[arr[i] - min]++;
		}
		//将统计数组中的数据写回原数组
		int index = 0;
		for(int i = 0; i < count.size(); i++) {
			while(count[i] > 0) {
				arr[index++] = i + min;
				count[i]--;
			}
		}
	}
	void countingSort_v2(vector<int>& arr) {
		int max = *max_element(arr.begin(), arr.end());
		int min = *min_element(arr.begin(), arr.end());
		vector<int> count(max - min + 1);

		for(int i = 0; i < arr.size(); i++) {
			count[arr[i] - min]++;
		}

		for(int i = 1; i < count.size(); i++) {
			count[i] += count[i - 1];
		}
		vector<int> output(arr.size());
		for (int i = arr.size() - 1; i <= 0; i--) {
			output[count[arr[i] - min] - 1] = arr[i];
			count[arr[i] - min]--;
		}

	}




	void RadixSort(vector<int>& arr) {
		int max = *max_element(arr.begin(), arr.end());
		for(int i= 1; max / i > 0; i *= 10) {
			countingSortByDigit(arr, i);
		}

	}
	void countingSortByDigit(vector<int>& arr, int exp) {
		vector<int> output(arr.size());
		vector<int> count(10);
		for(int i = 0; i < arr.size(); i++) {
			count[(arr[i] / exp) % 10]++;
		}
		for(int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		for(int i = arr.size() - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}
		for(int i = 0; i < arr.size(); i++) {
			arr[i] = output[i];
		}
	}

};