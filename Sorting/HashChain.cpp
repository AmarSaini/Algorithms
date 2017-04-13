#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct node {

	int num;
	node* next = NULL;

};

struct LinkedList {

	node* head = new node;

};

int main() {

	int m;

	cin >> m;

	LinkedList myHash[m];

	for (int i = 0; i < m; i++) {


	}

	string input;

	cin >> input;

	while (input.at(0) != 'e') {

		int i;

		int k;

		if (input.at(0) == 'i') {

			string text = input.substr(1, input.length() - 1);

			istringstream(text) >> k;

			i = k % m;

			node* tempNode = new node;

			tempNode->num = k;

			tempNode->next = myHash[i].head;

			myHash[i].head = tempNode;

		}

		if (input.at(0) == 'd') {

			string text = input.substr(1, input.length() - 1);

			istringstream(text) >> k;

			i = k % m;

			LinkedList tempHash = myHash[i];

			bool deleted = false;

			while (tempHash.head->next != NULL) {

				if (tempHash.head->num == k) {

					*tempHash.head = *(tempHash.head->next);

					cout << k << ":DELETED;" << endl;

					deleted = true;

					break;

				}

				tempHash.head = tempHash.head->next;

			}

			if (!deleted) {

				cout << k << ":DELETE_FAILED;" << endl;

			}

		}

		if (input.at(0) == 's') {

			string text = input.substr(1, input.length() - 1);

			istringstream(text) >> k;

			i = k % m;

			LinkedList tempHash = myHash[i];

			bool found = false;

			int j = 0;

			while (tempHash.head->next != NULL) {

				if (tempHash.head->num == k) {

					cout << k << ":FOUND_AT" << i << "," << j << ";" << endl;

					found = true;

					break;

				}

				j++;
				tempHash.head = tempHash.head->next;

			}

			if (!found) {

				cout << k << ":NOT_FOUND;" << endl;

			}

		}

		if (input.at(0) == 'o') {

			for (int i = 0; i < m; i++) {

				LinkedList tempHash = myHash[i];

				cout << i << ":";

				while (tempHash.head->next != NULL) {

					cout << tempHash.head->num << "->";

					tempHash.head = tempHash.head->next;

				}

				cout << ";" << endl;

			}

		}

		cin >> input;

	}

}