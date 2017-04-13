// This program output the minimum number of operations required to perform the matrix chain multiplication.
#include <iostream>
#include <stdio.h>
#include <vector> // you may use the vector class to represent a matrix, for ex: vector<vector<int>> M;
#include <sys/time.h>
#include <climits>

using namespace std;

void PrintOptimalParens(vector< vector<int> > s, int i, int j) {

	if (i == j) {

		cout << "A" << i-1;

	}

	else {

		cout << "(";
		PrintOptimalParens(s, i, s[i-1][j-1]);
		PrintOptimalParens(s, s[i-1][j-1] + 1, j);
		cout << ")";

	}

}

int main(int argc, char **argv)
{

	// Get number of matrices in the input:
	int n;
	cin >> n;

	// etc

	vector<int> p;
	int num;

	for (int i = 0; i < n + 1; i++) {

		cin >> num;
		p.push_back(num);

	}

	// Matrix-Chain-Order

	vector <vector<int> > m;
	vector <vector<int> > s;
	vector<int> temp;

	// Create m table, n x n

	for (int i = 0; i < n; i++) {

		temp.push_back(0);

	}

	for (int i = 0; i < n; i++) {

		m.push_back(temp);

	}

	// Create s table, n-1 x n

	for (int i = 0; i < n - 1; i++) {

		s.push_back(temp);

	}

	for (int i = 1; i <= n; i++) {

		m[i - 1][i - 1] = 0;

	}

	for (int l = 2; l <= n; l++) {

		for (int i = 1; i <= n - l + 1; i++) {

			int j = i + l - 1;
			m[i - 1][j - 1] = 1000000000;

			for (int k = i; k <= j - 1; k++) {

				int q = m[i - 1][k-1] + m[k][j - 1] + p[i-1] * p[k] * p[j];

				if (q < m[i - 1][j - 1]) {

					m[i - 1][j - 1] = q;
					s[i - 1][j - 1] = k;

				}

			}

		}

	}

	cout << m[0][m.size()-1] << endl;

	PrintOptimalParens(s, 1, n);

	cout << endl;


}

