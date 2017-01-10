// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int *randArray	(int, int);
int *merge		(int*, int, int*, int);
int *mergeSort	(int*, int, int);

int main()
{
	int size = 100;
	int max = 100;

	int *arr = mergeSort(randArray(size, max), 0, size);

	for (int i = 0; i < size; i++) {
		cout << i << ": " << arr[i] << "\n";
	}

	cin.get();
	delete arr;

    return 0;
}


int* randArray(int total, int modulous) {
	int *intArray = new int[total];

	for (int i = 0; i < total; i++) {
		int random = rand() % modulous;

		intArray[i] = random;
	}

	return intArray;
}

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