
#include "Graph.h"
using namespace std;


bool Graph::compareEdges(Edge edge1, Edge edge2)
{
	return edge1.weight < edge2.weight;
}

void Graph::createDSU()
{
	
}

void Graph::findMinSpanningTree()
{
	/*
	vector<Edge> edges = edgeList;
	int numVertices = vertices;

	// ���������� ����� �� ����
	std::sort(edges.begin(), edges.end(), compareEdges);

	// �������� ������� ��� �������� ��������� ������
	vector<int> parent(numVertices, -1);

	// �������� ������� ��������� ������
	vector<Edge> minSpanningTree;
	int numEdgesAdded = 0;

	for (Edge edge : edges) {
		// ����� ��������� ������, ����������� ������ ������
		int leftParent = -1;
		int rightParent = -1;

		int left = edge.left;
		int right = edge.right;

		while (parent[left] != -1) {
			left = parent[left];
		}
		while (parent[right] != -1) {
			right = parent[right];
		}

		leftParent = left;
		rightParent = right;

		// �������� ������� �����
		if (leftParent != rightParent) {
			minSpanningTree.push_back(edge);
			numEdgesAdded++;

			// ����������� ������ � ���� ������
			parent[rightParent] = leftParent;
		}

		// ����������� ��������� ����� ���������� ���� ������ � �������� ������
		if (numEdgesAdded == numVertices - 1) {
			break;
		}
	}
	edgeList = minSpanningTree;
	// ����� ������������ ��������� ������
	cout << "����������� �������� ������:" << endl;
	int sum = 0;
	for (Edge edge : minSpanningTree) {
		cout << letters[edge.left] << " -- " << letters[edge.right] << "  ���: " << edge.weight << endl;
		sum += edge.weight;
	}
	cout << "��������� ���: " << sum << endl;
	
	vector<vector<int>> NewAdjMatrix(vertices, vector<int>(vertices-1, 0));
	adjMatrix = NewAdjMatrix;

	for (Edge edge : minSpanningTree) {
		adjMatrix[edge.left+1][edge.right] = edge.weight; // ������������� ��� �����
		adjMatrix[edge.right+1][edge.left] = edge.weight; // ��� ������������������ �����
	}

	adjList.clear();
	int vert = 0;
	bool isFirst = 1;
	for (vector<int> l : adjMatrix) {
		if (isFirst) {
			isFirst = 0;
			continue;
		}
		list<int> adjList;
		adjList.push_back(vert);
		int dest = 0;
		for (int i : l) {
			if (i) adjList.push_back(dest);
			dest++;
		}
		this->adjList.push_back(adjList);
		vert++;
	}
	cout << "������� ��������� ���������. ������ ����� ��������. ������ ��������� ���������." << endl;
	//showAdjMatrix();
	*/
	vector<Edge> edges = edgeList;
	int numVertices = vertices;

	std::sort(edges.begin(), edges.end(), compareEdges);

	DisjointSet dsu(vertices);
	vector<Edge> minSpanningTree;
	int numEdgesAdded = 0;

	for (Edge edge : edges) {
		if (!dsu.connected(edge.left, edge.right)) {
			dsu.unionSets(edge.left, edge.right);
			minSpanningTree.push_back(edge);
			edgeList = minSpanningTree;
		}
		//else break;
	}
	edgeList = minSpanningTree;
	// ����� ������������ ��������� ������
	cout << "����������� �������� ������:" << endl;
	int sum = 0;
	for (Edge edge : minSpanningTree) {
		cout << letters[edge.left] << " -- " << letters[edge.right] << "  ���: " << edge.weight << endl;
		sum += edge.weight;
	}
	cout << "��������� ���: " << sum << endl;

	vector<vector<int>> NewAdjMatrix(vertices, vector<int>(vertices - 1, 0));
	adjMatrix = NewAdjMatrix;

	for (Edge edge : minSpanningTree) {
		adjMatrix[edge.left + 1][edge.right] = edge.weight; // ������������� ��� �����
		adjMatrix[edge.right + 1][edge.left] = edge.weight; // ��� ������������������ �����
	}

	adjList.clear();
	int vert = 0;
	bool isFirst = 1;
	for (vector<int> l : adjMatrix) {
		if (isFirst) {
			isFirst = 0;
			continue;
		}
		list<int> adjList;
		adjList.push_back(vert);
		int dest = 0;
		for (int i : l) {
			if (i) adjList.push_back(dest);
			dest++;
		}
		this->adjList.push_back(adjList);
		vert++;
	}
	cout << "������ ���������" << endl;
}

void Graph::showIncMatrix()
{
	cout << "������� �������������:" << endl;
	int letter = 0;
	for (vector<int> i : incMatrix) {
		//if (letter == -1) {
		//	letter++;
		//	continue;
		//}
		cout << letters[letter] << ": ";
		for (int j : i) {
			//if (!j) 
			cout << j << " ";
		}
		cout << '\n';
		letter++;
	}
}

void Graph::DFS()
{
	vector<bool> visited(vertices, false);
	DFS(vertices, visited);
}

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
			Edge edge;
			if (adjList[i]) {
				edge.left = vert;
				edge.right = i;
				edge.weight = adjList[i];
			}
			if (edge.weight) edgeList.push_back(edge);
		}
		//cout << '\n';
		//edgeList.push_back(edge);
		vert++;
	}
	vert = 0;
	isFirst = 1;
	for (vector<int> l : adjMatrix) {
		if (isFirst) {
			isFirst = 0;
			continue;
		}
		list<int> adjList;
		adjList.push_back(vert);
		int dest = 0;
		for (int i : l) {
			if (i) adjList.push_back(dest);
			dest++;
		}
		this->adjList.push_back(adjList);
		vert++;
	}

	// ������������� ������� ������������� ������
	vector<vector<int>> incMatrix(vertices-1, vector<int>(edgeList.size()-1, 0));

	// ���������� ������� �������������
	for (size_t i = 0; i < edgeList.size()-1; ++i) {
		const Edge& edge = edgeList[i];
		incMatrix[edge.left][i] = 1; // ������� left ���������� ����� i
		incMatrix[edge.right][i] = 1; // ������� right ���������� ����� i
	}
	this->incMatrix = incMatrix;
}

void Graph::showAdjMatrix()
{
	
	cout << "������� ���������:" << endl;
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

int Graph::first(Edge edge1, Edge edge2) {
	return edge1.left < edge2.left;
}

void Graph::showEdgeList()
{
	cout << "������ �����:" << endl;
	vector<Edge> newEdgeList = edgeList;
	sort(newEdgeList.begin(), newEdgeList.end(), first);
	for (Edge edge : newEdgeList) {
		cout << letters[edge.left] << "-" << letters[edge.right] << ": " << edge.weight << endl;
	}
}

void Graph::showAdjList()
{
	cout << "������ ���������:" << endl;
	for (list<int> list : adjList) {
		bool isFirst = 1;
		for (int i : list) {
			if (isFirst) {
				cout << letters[i];
				isFirst = 0;
			}
			else cout << "->" << letters[i];
		}
		cout << endl;
	}
}
