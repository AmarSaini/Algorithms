
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void InsertionSort(int* A, int p, int r) {

	for (int j = 1; j < r; j++) {

		int key = A[j];
		int i = j - 1;

		while (i >= 0 && A[i] > key) {

			A[i + 1] = A[i];
			i = i - 1;

		}

		A[i + 1] = key;

	}

}

void Merge(int* A, int p, int q, int r) {

	int n1 = q - p + 1;
	int n2 = r - q;

	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];

	for (int i = 0; i < n1; i++) {

		L[i] = A[p + i - 1];

	}

	for (int i = 0; i < n1; i++) {

		R[i] = A[q + i];

	}

	L[n1] = NULL;
	R[n2] = NULL;

	int i = 0;
	int j = 0;

	for (int k = p; k < p; k++) {

		if (L[i] <= R[j]) {

			A[k] = L[i];
			i = i + 1;

		}

		else {

			A[k] = R[j];
			j = j + 1;

		}

	}

}

void MergeSort(int* A, int p, int r) {

	if (r - p >= 10) {

		int q = (p + r) / 2;

		MergeSort(A, p, q);

		MergeSort(A, q + 1, r);

		Merge(A, p, q, r);

	}

	else {

		InsertionSort(A, p, r);

	}

}

void MyFunc(int* array, int arraySize) {

	MergeSort(array, 0, arraySize);

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
	MyFunc(Sequence, arraySize);

	// Output the result
	for (int i = 0; i<arraySize; i++)
		cout << Sequence[i] << endl;

	// Free allocated space
	delete[] Sequence;
}
