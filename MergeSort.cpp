// MergeSort.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"

using namespace std;

int* mergeSort(int *unsortedArray, int from, int length) {

	if (length == 1) {
		return new int[1] {
			unsortedArray[from]
		};
	}

	int halfWay = length / 2;
	
	int rightArraySize = length - halfWay;

	int *leftArray = mergeSort(unsortedArray, from, halfWay);
	int *rightArray = mergeSort(unsortedArray, from + halfWay, rightArraySize);
	
	return merge(leftArray, halfWay, rightArray, rightArraySize);
}

int *merge(int *arrayA, int sizeA, int *arrayB, int sizeB) {

	int posA = 0;
	int posB = 0;
	int sortedPos = 0;

	int *sortedArray = new int[sizeA + sizeB];

	while (posA < sizeA && posB < sizeB) {
		if (arrayA[posA] < arrayB[posB]) {
			sortedArray[sortedPos] = arrayA[posA];
			posA++;
		}
		else {
			sortedArray[sortedPos] = arrayB[posB];
			posB++;
		}
		sortedPos++;
	}

	while (posA < sizeA) {
		sortedArray[sortedPos] = arrayA[posA];
		posA++;
		sortedPos++;
	}

	while (posB < sizeB) {
		sortedArray[sortedPos] = arrayB[posB];
		posB++;
		sortedPos++;
	}

	delete arrayB, arrayA;

	return sortedArray;
}