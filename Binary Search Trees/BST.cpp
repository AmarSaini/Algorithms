#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct Node {
	int val;   // Value of the node
	Node *left;   // Pointer to the left node
	Node *right;  // Pointer to the right node
	Node *parent; // Pointer to the parent node
};

struct Tree {

	Node* root;

};

void preorder(Node* root) {

	if (root != NULL) {

		cout << root->val << endl;

		preorder(root->left);
		preorder(root->right);

	}

}

void postorder(Node* root) {

	if (root != NULL) {

		postorder(root->left);
		postorder(root->right);

		cout << root->val << endl;

	}

}

void inorder(Node* root) {

	if (root != NULL) {

		inorder(root->left);

		cout << root->val << endl;

		inorder(root->right);

	}

}

void transplant(Tree* T, Node* u, Node* v) {

	if (u->parent == NULL) {

		T->root = v;

	}

	else if (u == u->parent->left) {

		u->parent->left = v;

	}

	else {

		u->parent->right = v;

	}

	if (v != NULL) {

		v->parent = u->parent;

	}

}

void deleteNode(Tree* T, Node* z) {

	if (z->left == NULL) {

		transplant(T, z, z->right);

	}

	else if (z->right == NULL) {

		transplant(T, z, z->left);

	}

	else {

		Node* y = z->right;

		while (y->left != NULL) {

			y = y->left;

		}

		if (y->parent != z) {

			transplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;

		}

		transplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;

	}

}

int main() {

	string input;

	cin >> input;

	Tree* myTree = new Tree();

	myTree->root = NULL;


	while (input.at(0) != 'e') {

		int key;

		if (input.at(0) == 'i') {

			string text = input.substr(1, input.length() - 1);

			istringstream(text) >> key;

			if (myTree->root == NULL) {

				myTree->root = new Node();
				myTree->root->val = key;
				myTree->root->left = NULL;
				myTree->root->right = NULL;
				myTree->root->parent = NULL;

			}

			else {

				Node* subRoot = myTree->root;

				while (true && subRoot != NULL) {

					if (key <= subRoot->val) {

						if (subRoot->left == NULL) {

							subRoot->left = new Node();
							subRoot->left->parent = subRoot;
							subRoot = subRoot->left;

							subRoot->val = key;
							subRoot->left = NULL;
							subRoot->right = NULL;

							break;

						}

						else {

							subRoot = subRoot->left;

						}

					}

					else if (key > subRoot->val) {

						if (subRoot->right == NULL) {

							subRoot->right = new Node();
							subRoot->right->parent = subRoot;
							subRoot = subRoot->right;

							subRoot->val = key;
							subRoot->left = NULL;
							subRoot->right = NULL;

							break;

						}

						else {

							subRoot = subRoot->right;

						}

					}

				}

			}
			

		}

		else if (input.at(0) == 'd') {

			string text = input.substr(1, input.length() - 1);

			istringstream(text) >> key;

			Node* subRoot = myTree->root;

			while (true && subRoot != NULL) {

				if (key == subRoot->val) {

					deleteNode(myTree, subRoot);

					break;

				}

				if (key < subRoot->val) {

					subRoot = subRoot->left;

				}

				else if (key > subRoot->val) {

					subRoot = subRoot->right;

				}

			}

		}

		else if (input == "opre") {

			preorder(myTree->root);

		}

		else if (input == "opost") {

			postorder(myTree->root);

		}

		else if (input == "oin") {

			inorder(myTree->root);

		}

		cin >> input;

	}

}