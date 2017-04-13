
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main(int argc,char** argv) {

  int vectorSize;

  vector< vector<int> > myVectors;

  int userInput;

  // Input size
  cin >> vectorSize;

  // Input Data

  for (int i = 0; i < vectorSize; i++) {

	  vector<int> temp;

	  myVectors.push_back(temp);

	  for (int j = 0; j < 10; j++) {

		  cin >> userInput;

		  myVectors[i].push_back(userInput);

	  }

  }

  // Insertion Sort

  for (int i = 9; i >= 0; i--) {

	  for (int j = 1; j < vectorSize; j++) {

		  vector<int> key = myVectors[j];
		  int k = j - 1;

		  while (k >= 0 && myVectors[k][i] > key[i]) {

			  myVectors[k + 1] = myVectors[k];
			  k = k - 1;

		  }

		  myVectors[k + 1] = key;

	  }

  }
    
  // Output Data

  for (int i = 0; i < vectorSize; i++) {

	  for (int j = 0; j < 10; j++) {

		  cout << myVectors[i][j] << ";";

	  }

	  cout << endl;

  }

}
