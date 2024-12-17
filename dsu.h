#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;


class DisjointSet {
private:
    vector<string> letters{
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    "AA", "AB", "AC", "AD", "AE", "AF", "AG", "AH", "AI", "AJ", "AK", "AL", "AM", "AN", "AO", "AP", "AQ", "AR", "AS", "AT", "AU", "AV", "AW", "AX"
    };
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int size);
    int find(int element);
    void unionSets(int set1, int set2);
    bool connected(int set1, int set2);
};