
#include "Graph.h"
using namespace std;


Graph::Graph(string path)
{
	vector<list<int>> adjMatrixFile = readFile(path);
	adjMatrix = adjMatrixFile;
	vertices = adjMatrix.size();
}

void Graph::showAdj()
{
	
	int letter = -1;
	for (list<int> i : adjMatrix) {
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
