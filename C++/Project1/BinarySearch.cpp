#include "BinarySearch.h"
using namespace std;

int BinarySearch::binarysearch(int arr[], int size, int target) {
	//用于有序数组的二分查找
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int BinarySearch::boundarysearch(int arr[], int size, int target) {
	//用于有序数组的边界查找
	int left = 0;
	int right = size - 1;
	int result = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target) {
			result = mid;
			right = mid - 1;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
}

int BinarySearch::localminsearch(int arr[], int size) {
	//用于无序数组的局部最小值查找
	if (arr[0] < arr[1]) return arr[0];
	if (arr[size - 1] < arr[size - 2]) return arr[size - 1];
	int left = 0;
	int right = size - 1;
	while (left <= right) {
		int mid = left + (right + left) / 2;
		if (arr[mid] > arr[mid - 1])
			right = mid - 1;
		else if(arr[mid] > arr[mid + 1])
			left = mid + 1;
		else
			return arr[mid];
	}
	return -1;
}

