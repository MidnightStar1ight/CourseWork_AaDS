#include "dsu.h"

DisjointSet::DisjointSet(int size)
{
    parent.resize(size, -1);
    rank.resize(size, 0);
    for (int i = 0; i < size; ++i) {
        parent[i] = i;
    }
}

int DisjointSet::find(int element)
{
    if (parent[element] != element) {
        parent[element] = find(parent[element]);
    }
    return parent[element];
}

void DisjointSet::unionSets(int set1, int set2)
{
    int root1 = find(set1);
    int root2 = find(set2);

    if (root1 != root2) {
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
        //std::cout << "���������� ����� " << letters[root1] << " � " << letters[root2] << std::endl;
    }
}

bool DisjointSet::connected(int set1, int set2)
{
    return find(set1) == find(set2);
}
