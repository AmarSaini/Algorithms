#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

static int timer = 0;

struct Vertex; // A temp reference to the Vertex structure for the Weight structure

struct Weight {

	Vertex * v;
	int weight;

};

struct Vertex {

	int num; // Vertex Number
	int key; // Weight Holder
	Vertex* pi; // Predecessor

	vector <Weight *> adj;

};

int main() {

	int vertexCount;

	cin >> vertexCount;

	int edgeCount;

	cin >> edgeCount;

	vector <Vertex* > myGraph;

	for (int i = 0; i < vertexCount; i++) {

		Vertex* temp = new Vertex();

		temp->num = i;

		myGraph.push_back(temp);

	}

	for (int i = 0; i < edgeCount; i++) {

		int vertex1;
		int vertex2;
		int weight;

		cin >> vertex1;
		cin >> vertex2;
		cin >> weight;

		Weight* temp1 = new Weight();

		temp1->v = myGraph[vertex2];
		temp1->weight = weight;

		myGraph[vertex1]->adj.insert(myGraph[vertex1]->adj.begin(), temp1);

		Weight* temp2 = new Weight();

		temp2->v = myGraph[vertex1];
		temp2->weight = weight;

		myGraph[vertex2]->adj.insert(myGraph[vertex2]->adj.begin(), temp2);

	}

	/* for (int i = 0; i < vertexCount; i++) {

		cout << "Vertex: " << myGraph[i]->num << " has adj: " << endl;

		for (int j = 0; j < myGraph[i]->adj.size(); j++) {

			cout << myGraph[i]->adj[j]->v->num  << " with weight " << myGraph[i]->adj[j]->weight << endl;

		}

		cout << endl;


	} */


	// MST-Prim

	for (int i = 0; i < vertexCount; i++) {

		myGraph[i]->key = 100000000;
		myGraph[i]->pi = NULL;

	}

	myGraph[0]->key = 0;

	vector <Vertex* > queue;

	queue = myGraph;

	while (queue.size() != 0) {

		int index = 0;
		int min = queue[0]->key;

		for (int i = 0; i < queue.size(); i++) {

			if (queue[i]->key < min) {

				index = i;
				min = queue[i]->key;

			}

		}

		Vertex* u = queue[index];
		queue.erase(queue.begin() + index);

		for (int i = 0; i < u->adj.size(); i++) {

			Vertex* v = u->adj[i]->v;
			int weight = u->adj[i]->weight;
			bool contains = false;


			for (int j = 0; j < queue.size(); j++) {

				if (queue[j] == v) {

					contains = true;

				}

			}

			if (contains && weight < v->key) {

				v->pi = u;
				v->key = weight;

			}

		}

	}

	for (int i = 1; i < vertexCount; i++) {

		cout << myGraph[i]->pi->num << endl;

	}

}