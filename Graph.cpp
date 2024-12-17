
#include "Graph.h"
using namespace std;


bool Graph::compareEdges(Edge edge1, Edge edge2)
{
	return edge1.weight < edge2.weight;
}

void Graph::findMinSpanningTree()
{
	/*
	vector<Edge> edges = edgeList;
	int numVertices = vertices;

	// Сортировка ребер по весу
	sort(edges.begin(), edges.end(), compareEdges);

	// Создание массива для хранения родителей вершин
	vector<int> parent(numVertices, -1);

	// Создание пустого остовного дерева
	vector<Edge> minSpanningTree;
	int numEdgesAdded = 0;

	for (Edge edge : edges) {
		// Поиск родителей вершин, соединяемых данным ребром
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

		// Проверка наличия цикла
		if (leftParent != rightParent) {
			minSpanningTree.push_back(edge);
			numEdgesAdded++;

			// Объединение вершин в одно дерево
			parent[rightParent] = leftParent;
		}

		// Прекращение алгоритма после добавления всех вершин в остовное дерево
		if (numEdgesAdded == numVertices - 1) {
			break;
		}
	}
	edgeList = minSpanningTree;
	// Вывод минимального остовного дерева
	cout << "Минимальное остовное дерево:" << endl;
	int sum = 0;
	for (Edge edge : minSpanningTree) {
		cout << letters[edge.left] << " -- " << letters[edge.right] << "  вес: " << edge.weight << endl;
		sum += edge.weight;
	}
	cout << "Суммарный вес: " << sum << endl;
	
	vector<vector<int>> NewAdjMatrix(vertices, vector<int>(vertices-1, 0));
	adjMatrix = NewAdjMatrix;

	for (Edge edge : minSpanningTree) {
		adjMatrix[edge.left+1][edge.right] = edge.weight; // Устанавливаем вес ребра
		adjMatrix[edge.right+1][edge.left] = edge.weight; // Для неориентированного графа
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
	cout << "Матрица смежности обновлена. Список ребер обновлен. Списки смежности обновлены." << endl;
	//showAdjMatrix();
	*/
	vector<Edge> edges = edgeList;
	int numVertices = vertices;

	sort(edges.begin(), edges.end(), compareEdges);

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
	// Вывод минимального остовного дерева
	cout << "Минимальное остовное дерево:" << endl;
	int sum = 0;
	for (Edge edge : minSpanningTree) {
		cout << letters[edge.left] << " -- " << letters[edge.right] << "  вес: " << edge.weight << endl;
		sum += edge.weight;
	}
	cout << "Суммарный вес: " << sum << endl;

	vector<vector<int>> NewAdjMatrix(vertices+1, vector<int>(vertices, 0));
	adjMatrix = NewAdjMatrix;
	
	for (Edge edge : minSpanningTree) {
		adjMatrix[edge.left + 1][edge.right] = edge.weight;
		adjMatrix[edge.right + 1][edge.left] = edge.weight;
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

	vector<vector<int>> incMatrix(vertices, vector<int>(edgeList.size(), 0));

	for (size_t i = 0; i < edgeList.size(); ++i) {
		const Edge& edge = edgeList[i];
		incMatrix[edge.left][i] = edge.weight; // Вершина left инцидентна ребру i
		incMatrix[edge.right][i] = edge.weight; // Вершина right инцидентна ребру i
	}
	this->incMatrix = incMatrix;

	cout << "Данные обновлены" << endl;
}

void Graph::showIncMatrix()
{
	cout << "Матрица инцидентности:" << endl;

	int letter = 0;
	cout << "   ";
	for (Edge let : edgeList) {
		cout << letters[let.left] << letters[let.right] << " ";
	}
	cout << endl;

	for (vector<int> i : incMatrix) {

		cout << letters[letter] << ": ";
		for (int j : i) {
			//if (!j) 
			cout << j << "  ";
		}
		cout << '\n';
		letter++;
	}
}

void Graph::DFS()
{
	cout << "Обход в глубину: ";

	vector<bool> visited(vertices, false);
	stack<int> upcomingVertices;
	DFS(0, visited, upcomingVertices);
}

void Graph::BFS()
{
	cout << "Обход в ширину: ";

	BFS(0);
}

void Graph::DFS(int v, vector<bool>& visited, stack<int> upcomingVercites)
{
	int sum = 0;
	for (int i : visited) sum += i;
	if (sum == visited.size()) {
		return;
	}

	visited[v] = true;
	cout << letters[v] << " ";
	for (int i : adjList[v]) {
		if (!visited[i]) upcomingVercites.push(i);
	}
	if (upcomingVercites.empty()) return;
	int newV = upcomingVercites.top();
	upcomingVercites.pop();

	DFS(newV, visited, upcomingVercites);
}

void Graph::BFS(int v)
{
	vector<bool> visited(vertices, false);
	queue<int> q;

	visited[v] = true;
	q.push(v);

	while (!q.empty()) {
		int vert = q.front();
		q.pop();
		cout << letters[vert] << " ";

		for (int i : adjList[vert]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

Graph::Graph(string path)
{
	vector<vector<int>> adjMatrixFile = readFile(path);
	adjMatrix = adjMatrixFile;
	vertices = adjMatrixFile.size()-1;
	
	bool isFirst = 1;
	int vert = 0;
	for (vector<int> adjList: adjMatrixFile) {
		if (isFirst) {
			isFirst = 0;
			continue;
		}
		//vector<int> edge;
		for (int i = vert+1; i < vertices; i++) {
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

	vector<vector<int>> incMatrix(vertices, vector<int>(edgeList.size(), 0));

	for (size_t i = 0; i < edgeList.size(); ++i) {
		const Edge& edge = edgeList[i];
		incMatrix[edge.left][i] = edge.weight; // Вершина left инцидентна ребру i
		incMatrix[edge.right][i] = edge.weight; // Вершина right инцидентна ребру i
	}
	this->incMatrix = incMatrix;
}

void Graph::showAdjMatrix()
{
	
	cout << "Матрица смежности:" << endl;
	int letter = -1;
	for (vector<int> i : adjMatrix) {
		if (letter == -1) {

			cout << "   ";
			for (int let = 0; let < adjMatrix.size()-1; let++) {
				cout << letters[let] << "  ";
			}
			cout << endl;

			letter++;
			continue;
		}
		cout << letters[letter] << ": ";
		for (int j : i) {
			//if (!j) 
				cout << j << "  ";
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
	cout << "Список ребер:" << endl;
	vector<Edge> newEdgeList = edgeList;
	sort(newEdgeList.begin(), newEdgeList.end(), first);
	for (Edge edge : newEdgeList) {
		cout << letters[edge.left] << "-" << letters[edge.right] << ": " << edge.weight << endl;
	}
}

void Graph::showAdjList()
{
	cout << "Списки смежности:" << endl;
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
