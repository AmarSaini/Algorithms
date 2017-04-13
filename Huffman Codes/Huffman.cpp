#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
	Node *left = NULL;   // Pointer to the left node
	Node *right = NULL;  // Pointer to the right node
	Node *parent = NULL; // Pointer to the parent node
	int freq;
	char letter = 'z';
	char val;
};

static Node* found;

void preorder(Node* root, char letter) {

	if (root != NULL) {

		if (root->letter == letter) {

			found = root;

		}

		preorder(root->left, letter);
		preorder(root->right, letter);

	}

}

int main() {

	vector<Node*> C;
	int num;
	char letter = 'A';

	for (int i = 0; i < 6; i++) {

		Node* temp = new Node();

		cin >> num;

		temp->freq = num;
		temp->letter = letter;

		C.push_back(temp);

		letter++;

	}

	// Huffman

	int n = C.size();

	vector<Node*> Q = C;

	for (int j = 0; j < n - 1; j++) {

		Node* z = new Node();
		Node* x = new Node();
		Node* y = new Node();

		int min1 = 10000000;
		int index1;

		for (int i = 0; i < Q.size(); i++) {

			if (Q[i]->freq < min1) {

				x = Q[i];
				min1 = x->freq;
				index1 = i;

			}

		}

		Q.erase(Q.begin() + index1);

		int min2 = 10000000;
		int index2;

		for (int i = 0; i < Q.size(); i++) {

			if (Q[i]->freq < min2) {

				y = Q[i];
				min2 = y->freq;
				index2 = i;

			}

		}

		Q.erase(Q.begin() + index2);

		x->val = '0';
		y->val = '1';

		x->parent = z;
		y->parent = z;

		z->left = x;
		z->right = y;

		z->freq = x->freq + y->freq;

		Q.push_back(z);
	
		
	
	}

	for (letter = 'A'; letter <= 'F'; letter++) {

		Node* root = Q[0];

		string code = "";

		preorder(root, letter);

		cout << found->letter << ":";

		while (found != Q[0]) {

			code += found->val;

			found = found->parent;

		}

		for (int i = code.length() - 1; i >= 0; i--) {

			cout << code.at(i);

		}

		cout << endl;



	}

}