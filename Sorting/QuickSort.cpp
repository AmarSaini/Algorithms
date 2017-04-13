
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

int Partition(int* A, int p, int r) {

	int x = A[r];
	int i = p - 1;

	for (int j = p; j <= r - 1; j++) {

		if (A[j] <= x) {

			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;

		}

	}

	int temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;

	return i + 1;

}

int RandomizedPartition(int* A, int p, int r) {

	srand(time(NULL));

	int i = (rand() % (r - p)) + p;

	int temp = A[r];
	A[r] = A[i];
	A[i] = temp;

	return Partition(A, p, r);


}

void QuickSort(int* A, int p, int r) {

	if (p < r) {

		int q = RandomizedPartition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);


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
	QuickSort(Sequence, 0, arraySize-1);

	// Output the result
	for (int i = 0; i<arraySize; i++)
		cout << Sequence[i] << endl;

	// Free allocated space
	delete[] Sequence;
}
