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
	int d; // Upper Bound for Shortest Path Weight
	Vertex* pi; // Predecessor

	vector <Weight *> adj;

};

void Relax(Vertex* u, Vertex* v, int w) {

	if (v->d > u->d + w) {

		v->d = u->d + w;
		v->pi = u;

	}

}

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

	}

	/* for (int i = 0; i < vertexCount; i++) {

		cout << "Vertex: " << myGraph[i]->num << " has adj: " << endl;

		for (int j = 0; j < myGraph[i]->adj.size(); j++) {

			cout << myGraph[i]->adj[j]->v->num  << " with weight " << myGraph[i]->adj[j]->weight << endl;

		}

		cout << endl;


	} */



	// Initialize-Single-Source

	for (int i = 0; i < myGraph.size(); i++) {

		myGraph[i]->d = 1000000000;
		myGraph[i]->pi = NULL;

	}

	myGraph[0]->d = 0;


	// Bellman-Ford

	bool check = true;

	for (int i = 0; i < myGraph.size() - 1; i++) {

		for (int j = 0; j < myGraph.size(); j++) {

			for (int k = 0; k < myGraph[j]->adj.size(); k++) {

				Relax(myGraph[j], myGraph[j]->adj[k]->v, myGraph[j]->adj[k]->weight);

			}

		}

	}


	for (int i = 0; i < myGraph.size(); i++) {

		for (int j = 0; j < myGraph[i]->adj.size(); j++) {

			if (myGraph[i]->adj[j]->v->d > myGraph[i]->d + myGraph[i]->adj[j]->weight) {

				check = false;

			}

		}

	}

	if (check) {

		cout << "TRUE" << endl;

		for (int i = 0; i < myGraph.size(); i++) {

			if (myGraph[i]->d == 1000000000) {

				cout << "INFINITY" << endl;

			}

			else {

				cout << myGraph[i]->d << endl;

			}

		}

	}

	else {

		cout << "FALSE" << endl;

	}


}