#include "graph.h"

Graph::Graph(int v)
{
    vertices = v;
    adjList.resize(v);
}

void Graph::addEdge(int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::display()
{
    for (int i = 0; i < vertices; ++i)
    {
        std::cout << "Vertex " << i << ": ";
        for (int neighbor : adjList[i])
        {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::shortest_distance(int vertex)
{
    if (vertex >= vertices)
    {
        std::cout << "Sorry, " << vertex << " is out of the vertices range";
        return;
    }

    std::vector<bool> visited(vertices, false);
    std::vector<int> distance(vertices, -1);
    std::queue<int> q;

    q.push(vertex);
    visited[vertex] = true;
    distance[vertex] = 0;

    while (!q.empty())
    {
        int pop_vertex = q.front();
        visited[pop_vertex] = true;
        q.pop();
        for (auto conneted : adjList[pop_vertex])
        {
            if (!visited[conneted])
                q.push(conneted);
            if (distance[conneted] == -1)
            {
                distance[conneted] = distance[pop_vertex] + 1;
            }
            else
            {
                distance[conneted] = std::min(distance[conneted], distance[pop_vertex] + 1);
            }
        }
    }
    int i = 0;
    std::cout << "From " << vertex << " distance of every vertex is: " << std::endl;
    for (auto x : distance)
    {
        std::cout << i << " : " << x << std::endl;
        i++;
    }
}

void Graph::dfs_util(int v, std::vector<bool> &visited)
{
    visited[v] = true;
    std::cout << v << " ";

    for (int neighbor : adjList[v])
    {
        if (!visited[neighbor])
        {
            dfs_util(neighbor, visited);
        }
    }
}

void Graph::dfs(int startVertex)
{
    std::vector<bool> visited(vertices, false);
    dfs_util(startVertex, visited);
    std::cout << "\n";
}

void Graph::topological_sort_util(int v, std::vector<bool> &visited, std::stack<int> &stacks)
{
    visited[v] = true;

    for (auto vertex : adjList[v])
    {
        if (!visited[vertex])
            topological_sort_util(vertex, visited, stacks);
    }

    stacks.push(v);
}
void Graph::topological_sort()
{
    std::stack<int> topstack;
    std::vector<bool> visited(vertices, false);

    for (auto vertex : visited)
    {
        if (!vertex)
        {
            topological_sort_util(vertex, visited, topstack);
        }
    }

    while (!topstack.empty())
    {
        std::cout << topstack.top() << " ";
        topstack.pop();
    }
    std::cout << "\n";
}
