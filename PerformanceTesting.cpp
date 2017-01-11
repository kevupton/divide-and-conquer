// PerformanceTesting.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <iostream>
#include "MergeSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include <ctime>

using namespace std;

int *randArray(int, int);
template<typename Func>
double testFunction(Func);
int *clone(int*, int);

int main()
{
	int size = 100000;
	int max = 1000000;
	
	int *arr = randArray(size, max);
	int *tempArr;

	double time_taken;

	// quick sort test
	tempArr = clone(arr, size);
	time_taken = testFunction([&]() {
		quickSort(tempArr, size);
	});
	delete tempArr;
	cout << "QuickSort: " << time_taken << " sec\n";

	tempArr = clone(arr, size);
	time_taken = testFunction([&]() {
		insertionSort(tempArr, size);
	});
	delete tempArr;
	cout << "InsertionSort: " << time_taken << " sec\n";

	tempArr = clone(arr, size);
	time_taken = testFunction([&]() {
		selectionSort(tempArr, size);
	});
	delete tempArr;
	cout << "SelectionSort: " << time_taken << " sec\n";

	tempArr = clone(arr, size);
	time_taken = testFunction([&]() {
		mergeSort(tempArr, 0, size);
	});
	delete tempArr;
	cout << "MergeSort: " << time_taken << " sec\n";

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

int *clone(int *toClone, int length) {
	int *newArray = new int[length];

	for (int i = 0; i < length; i++) {
		newArray[i] = toClone[i];
	}

	return newArray;
}

template<typename Func>
double testFunction(Func func)
{
	clock_t start_time = clock();
	func();
	return (clock() - start_time) * 1.0 / CLOCKS_PER_SEC;
}