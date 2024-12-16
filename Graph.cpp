
#include "Graph.h"
using namespace std;


Graph::Graph(string path)
{
	vector<vector<int>> adjMatrixFile = readFile(path);
	adjMatrix = adjMatrixFile;
	vertices = adjMatrixFile.size();
	
	bool isFirst = 1;
	int vert = 0;
	for (vector<int> adjList: adjMatrixFile) {
		if (isFirst) {
			isFirst = 0;
			continue;
		}
		//vector<int> edge;
		for (int i = vert+1; i < vertices-1; i++) {
			//cout << i;
			vector<int> edge;
			if (adjList[i]) {
				edge.push_back(vert);
				edge.push_back(i);
				edge.push_back(adjList[i]);
			}
			if (!edge.empty()) edgeList.push_back(edge);
		}
		//cout << '\n';
		//edgeList.push_back(edge);
		vert++;
	}
	
}

void Graph::showAdjMatrix()
{
	
	cout << "Матрица смежности:" << endl;
	int letter = -1;
	for (vector<int> i : adjMatrix) {
		if (letter == -1) {
			letter++;
			continue;
		}
		cout << letters[letter] << ": ";
		for (int j : i) {
			//if (!j) 
				cout << j << " ";
		}
		cout << '\n';
		letter++;
	}
	
}

void Graph::showEdgeList()
{
	cout << "Список ребер:" << endl;
	for (vector<int> edge : edgeList) {
		//cout << edge[0] << "-" << edge[1] << ": " << edge[2] << endl;
		for (int i : edge) cout << i << ' ';
		cout << endl;
	}
}
