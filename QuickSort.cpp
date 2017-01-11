// QuickSort.cpp : Defines the entry point for the console application.
//

#include "QuickSort.h"

using namespace std;

void quickSort(int *unsortedArray, int left, int right);
int partition(int *unsortedArray, int left, int right, int pivot);
void swap(int *unsortedArray, int left, int right);

void quickSort(int *unsortedArray, int length) {
	return quickSort(unsortedArray, 0, length - 1);
}

void quickSort(int *unsortedArray, int left, int right) {
	if (right - left <= 0) {
		return;
	}

	int position = partition(unsortedArray, left, right, unsortedArray[right]);
	quickSort(unsortedArray, left, position - 1);
	quickSort(unsortedArray, position + 1, right);
}

int partition(int *unsortedArray, int left, int right, int pivot) {
	int leftPointer = left - 1;
	int rightPointer = right;

	while (true) {
		while (unsortedArray[++leftPointer] < pivot) {}
		while (unsortedArray[--rightPointer] > pivot) {}
		if (leftPointer >= rightPointer) break;
		else swap(unsortedArray, leftPointer, rightPointer);
	}

	swap(unsortedArray, leftPointer, right);
	return leftPointer;
}

void swap(int *unsortedArray, int a, int b) {
	int temp = unsortedArray[b];
	unsortedArray[b] = unsortedArray[a];
	unsortedArray[a] = temp;
}