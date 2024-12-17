#pragma once
#include "dsu.h"

using namespace std;


class Graph
{
private:
    struct Edge {
        int left, right, weight = 0;
    };
    static int first(Edge edge1, Edge edge2);
    static bool compareEdges(Edge edge1, Edge edge2);
	int vertices;
    vector<string> letters {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
        "AA", "AB", "AC", "AD", "AE", "AF", "AG", "AH", "AI", "AJ", "AK", "AL", "AM", "AN", "AO", "AP", "AQ", "AR", "AS", "AT", "AU", "AV", "AW", "AX"
    };
    vector<list<int>> adjList; // Список смежности
    vector<vector<int>> adjMatrix; // Матрица смежности
    vector<vector<int>> incMatrix; // Матрица инцидентности (не сделано!)
    vector<Edge> edgeList; // Список ребер
	vector<string> vertNames;
    vector<int> parseString(string input) {
        vector<int> numbers;
        istringstream stream(input);
        int number;

        // Читаем числа из строки
        while (stream >> number) {
            numbers.push_back(number);
        }

        return numbers;
    }
    vector<vector<int>> readFile(string path) {
        ifstream File(path);
        vector<vector<int>> adjMatrix;
        if (File.is_open()) {
            while (!File.eof()) {
                string line;
                getline(File, line);
                vector<int> numbers = parseString(line);
                adjMatrix.push_back(numbers);
                //cout << line << endl;
            }
            File.close();
        }
        else {
            cout << "Error: the file has not been opened!" << endl;
        }
        return adjMatrix;
    }

public:
	Graph(string path);
    void showAdjMatrix();
    void showEdgeList();
    void showAdjList();
    void showIncMatrix();
    void findMinSpanningTree();
    void DFS();
    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        vector<int>::iterator it;
        for (it = adjMatrix[v].begin(); it != adjMatrix[v].end(); ++it) {
            if (!visited[*it]) {
                DFS(*it, visited);
            }
        }
    }
};