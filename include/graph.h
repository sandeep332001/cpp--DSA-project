#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <queue>
#include <stack>

class Graph
{
    int vertices;
    std::vector<std::vector<int>> adjList;

public:
    Graph(int v);
    void addEdge(int u, int v);
    void display();
    void shortest_distance(int vertex);

    void dfs_util(int v, std::vector<bool> &visited);
    void dfs(int startVertex);

    void topological_sort_util(int v, std::vector<bool> &visited, std::stack<int> &stacks);
    void topological_sort();
};

#endif
