// SelectionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    return 0;
}

int *selectionSort(int *unsortedArray, int length) {
	int *sortedArray = new int[length];

	for (int i = 0; i < length - 1; i++) {
		int minPosition = i;
		int minValue = unsortedArray[i];
		
		for (int j = i + 1; j < length; j++) {
			int curValue = unsortedArray[j];
			if (curValue < minValue) {
				minPosition = j;
				minValue = curValue;
			}
		}

		if (minPosition !=  i) {
			unsortedArray[minPosition] = unsortedArray[i];
		}

		sortedArray[i] = minValue;
	}

	return sortedArray;
}

