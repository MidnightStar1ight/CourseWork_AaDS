#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

/*
struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge edge1, Edge edge2) {
    return edge1.weight < edge2.weight;
}

void findMinSpanningTree(vector<Edge>& edges, int numVertices) {
    // ���������� ����� �� ����
    sort(edges.begin(), edges.end(), compareEdges);

    // �������� ������� ��� �������� ��������� ������
    vector<int> parent(numVertices, -1);

    // �������� ������� ��������� ������
    vector<Edge> minSpanningTree;
    int numEdgesAdded = 0;

    for (Edge edge : edges) {
        // ����� ��������� ������, ����������� ������ ������
        int srcParent = -1;
        int destParent = -1;

        int src = edge.src;
        int dest = edge.dest;

        while (parent[src] != -1) {
            src = parent[src];
        }
        while (parent[dest] != -1) {
            dest = parent[dest];
        }

        srcParent = src;
        destParent = dest;

        // �������� ������� �����
        if (srcParent != destParent) {
            minSpanningTree.push_back(edge);
            numEdgesAdded++;

            // ����������� ������ � ���� ������
            parent[destParent] = srcParent;
        }

        // ����������� ��������� ����� ���������� ���� ������ � �������� ������
        if (numEdgesAdded == numVertices - 1) {
            break;
        }
    }

    // ����� ������������ ��������� ������
    cout << "����������� �������� ������:" << endl;
    for (Edge edge : minSpanningTree) {
        cout << edge.src << " -- " << edge.dest << "  ���: " << edge.weight << endl;
    }
}
*/

/*
class DisjointSet {
public:
    // �����������
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i; // ������ ������� �������� ����� ���������
        }
    }

    // ������� ������ � ����������� ����
    int find(int element) {
        if (parent[element] != element) {
            parent[element] = find(parent[element]); // ���������� ������� ������
        }
        return parent[element];
    }

    // ������� ����������� ���� ��������
    void unionSets(int set1, int set2) {
        int root1 = find(set1);
        int root2 = find(set2);

        if (root1 != root2) {
            // ���������� �� �����
            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            }
            else if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            }
            else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }

    // �������� �������������� � ������ ���������
    bool connected(int set1, int set2) {
        return find(set1) == find(set2);
    }

private:
    vector<int> parent; // ������ ���������
    vector<int> rank;   // ������ ������
};
*/


class Graph
{
private:
	int vertices; // �������
    vector<string> letters {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
        "AA", "AB", "AC", "AD", "AE", "AF", "AG", "AH", "AI", "AJ", "AK", "AL", "AM", "AN", "AO", "AP", "AQ", "AR", "AS", "AT", "AU", "AV", "AW", "AX"
    };
    vector<vector<int>> adjMatrix; // ������� ���������
    vector<vector<int>> incMatrix; // ������� ������������� (�� �������!)
    vector<vector<int>> edgeList; // ������ �����
	vector<string> vertNames;
    vector<int> parseString(string input) {
        vector<int> numbers;
        istringstream stream(input);
        int number;

        // ������ ����� �� ������
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
};
