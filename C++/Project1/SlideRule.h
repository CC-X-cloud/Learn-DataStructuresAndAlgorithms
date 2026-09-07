#pragma once
#include <cstdlib>
class SlideRule
{
public:
	int* generate_random_array(int maxsize,int maxvalue) {
		int size = rand() % maxsize;
		int* arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % maxvalue;  
			// Generate random numbers between 0 and maxvalue
		}
		return arr;
	}
};

