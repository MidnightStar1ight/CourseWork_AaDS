#include "Graph.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    
	string path = "input.txt";
	Graph graph(path);
	graph.showAdj();
    
    /*
    int numVertices = 6;
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 4},
        {2, 4, 2},
        {3, 4, 5},
        {3, 5, 2},
        {4, 5, 6}
    };

    findMinSpanningTree(edges, numVertices);
    */
}