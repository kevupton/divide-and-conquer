// InsertionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int *insertionSort(int *unsortedArray, int length);

int main()
{
    return 0;
}

int *insertionSort(int *unsortedArray, int length) {
	int *sortedArray = new int[length];

	for (int i = 0; i < length; i++) {
		int position = i;
		int positionValue = unsortedArray[i];

		while (position > 0 && sortedArray[position - 1] > positionValue) {
			sortedArray[position] = sortedArray[position - 1];
			position--;
		}

		sortedArray[position] = positionValue;
	}

	return sortedArray;
}