#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

static int heapSize;

void maxHeapify(int* A, int i) {

	int l = 2 * i;
	int r = (2 * i) + 1;
	int largest;

	if (l < heapSize && A[l] > A[i]) {

		largest = l;

	}

	else {

		largest = i;

	}

	if (r < heapSize && A[r] > A[largest]) {

		largest = r;

	}

	if (largest != i) {

		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;

		maxHeapify(A, largest);
	}

}

void buildMaxHeap(int* A, int arraySize) {

	heapSize = arraySize;

	for (int i = arraySize / 2; i >= 0; i--) {

		maxHeapify(A, i);

	}

}

void HeapSort(int* A, int arraySize) {

	buildMaxHeap(A, arraySize);

	for (int i = arraySize - 1; i >= 1; i--) {

		int temp = A[0];
		A[0] = A[i];
		A[i] = temp;

		heapSize--;

		maxHeapify(A, 0);

	}

}

int main(int argc, char** argv) {

	int* Sequence;
	int arraySize;

	// Get the size of the sequence
	cin >> arraySize;

	// Allocate enough memory to store "arraySize" integers
	Sequence = new int[arraySize];

	// Read in the sequence
	for (int i = 0; i<arraySize; i++)
		cin >> Sequence[i];

	// Run your algorithms to manipulate the elements in Sequence
	HeapSort(Sequence, arraySize);

	// Output the result
	for (int i = 0; i<arraySize; i++)
		cout << Sequence[i] << endl;

	// Free allocated space
	delete[] Sequence;
}
