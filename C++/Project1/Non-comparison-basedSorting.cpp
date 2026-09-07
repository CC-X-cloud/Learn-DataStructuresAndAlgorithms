#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NonComparisonBaseSorting {
public:

	void CountingSort(vector<int>& arr) {
		int max = *max_element(arr.begin(), arr.end());
		int min = *min_element(arr.begin(), arr.end());

		int n = arr.size();

		vector<int> count(max - min + 1);

		for (int i = 0; i < n; i++) {
			//统计每个元素出现的次数
			count[arr[i] - min]++;
		}
		int index = 0;
		for (int i = 0; i < count.size(); i++) {
			while(count[i]-- > 0) {
				arr[index++] = i + min;
			}
		}
	}
	void CountingSortStable(vector<int>& arr) {
		int max = *max_element(arr.begin(), arr.end());
		int min = *min_element(arr.begin(), arr.end());

		int n = arr.size();
		vector<int> count(max - min + 1);
		vector<int> output(n);

		for (int i = 0; i < n; i++) {
			count[arr[i] - min]++;
		}
		//维持稳定性，前缀和，记录每个元素在排序后的位置
		for(int i = 1; i < count.size(); i++) {
			count[i] += count[i - 1];
		}

		for(int i = n - 1; i>= 0; i--) {
			output[count[arr[i] - min] - 1] = arr[i];
			count[arr[i] - min]--;
		}
		for(int i = 0; i < n; i++) {
			arr[i] = output[i];
		}
	}
	void radixSort(vector<int>& arr) {
		int max = *max_element(arr.begin(), arr.end());

		for(int i= 1; max / i > 0; i *= 10) {
			countingSortByDigit(arr, i);
		}
	}
	void countingSortByDigit(vector<int>& arr, int exp) {
		int n = arr.size();
		vector<int> count(10);
		vector<int> output(n);

		for (int i = 0; i < n; i++) {
			count[arr[i] / exp % 10]++;
		}
		for(int i =1;i< 10; i++) {
			count[i] += count[i - 1];
		}

		for (int i = n - 1; i >= 0; i--) {
			output[count[arr[i] / exp % 10] - 1] = arr[i];
			count[arr[i] / exp % 10]--;
		}
		for(int i = 0; i < n; i++) {
			arr[i] = output[i];
		}
	}
};