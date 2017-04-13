#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

static int timer = 0;

struct Vertex {

	int num; // Vertex Number
	int color; // 0 = White, 1 = Gray, 2 = Black
	Vertex* pi; // Predecessor
	int d; // Start Time
	int f; // Finish Time
	int SCC; // Strongly Connected Component

	vector <Vertex *> adj;

};

void DFSVisit(vector <Vertex* > myGraph, Vertex* u, int SCC, bool storeSCC) {

	timer++;
	u->d = timer;
	u->color = 1;

	if (storeSCC) {

		u->SCC = SCC;

	}

	for (int i = 0; i < u->adj.size(); i++) {

		if (u->adj[i]->color == 0) {

			u->adj[i]->pi = u;
			DFSVisit(myGraph, u->adj[i], SCC, storeSCC);

		}

	}

	u->color = 2;
	timer++;
	u->f = timer;

}

void DFS(vector <Vertex* > myGraph, bool subTree) {

	for (int i = 0; i < myGraph.size(); i++) {

		myGraph[i]->color = 0;
		myGraph[i]->pi = NULL;

	}

	timer = 0;

	for (int i = 0; i < myGraph.size(); i++) {

		if (myGraph[i]->color == 0) {

			if (subTree) {

				DFSVisit(myGraph, myGraph[i], myGraph[i]->num, true);

			}

			else {

				DFSVisit(myGraph, myGraph[i], myGraph[i]->num, false);

			}

		}

	}

}

int main() {

	int vertexCount;

	cin >> vertexCount;

	int edgeCount;

	cin >> edgeCount;

	vector <Vertex* > myGraph;
	vector <Vertex* > myGraphT;

	for (int i = 0; i < vertexCount; i++) {

		Vertex* temp1 = new Vertex();

		temp1->num = i;

		Vertex* temp2 = new Vertex();

		temp2->num = i;

		myGraph.push_back(temp1);
		myGraphT.push_back(temp2);

	}

	for (int i = 0; i < edgeCount; i++) {

		int vertex1;
		int vertex2;

		cin >> vertex1;
		cin >> vertex2;

		myGraph[vertex1]->adj.insert(myGraph[vertex1]->adj.begin(), myGraph[vertex2]);
		myGraphT[vertex2]->adj.insert(myGraphT[vertex2]->adj.begin(), myGraphT[vertex1]);

	}

	DFS(myGraph, false);

	/* for (int i = 0; i < vertexCount; i++) {

		cout << myGraph[i]->num << ": " << myGraph[i]->d << "/" << myGraph[i]->f << endl;

	}*/

	vector <Vertex* > myGraphDesc;

	for (int i = 0; i < vertexCount; i++) {

		int index = 0;
		int max = myGraph[0]->f;

		for (int j = 0; j < myGraph.size(); j++) {

			if (myGraph[j]->f > max) {

				max = myGraph[j]->f;
				index = j;

			}

		}

		myGraphDesc.push_back(myGraphT[index]);
		myGraph[index]->f = -1; // No duplicates

		//cout << myGraphDesc[i]->num << endl;

	}

	DFS(myGraphDesc, true);

	for (int i = 0; i < vertexCount; i++) {

		for (int j = 0; j < vertexCount; j++) {

			if (myGraphDesc[j]->num == i) {

				cout << myGraphDesc[j]->SCC << endl;

			}

		}

	}

}