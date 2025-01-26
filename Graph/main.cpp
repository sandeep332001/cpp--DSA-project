#include <graph.h>

int main()
{
    int numVertices = 5;
    Graph g(numVertices);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();
    g.shortest_distance(2);

    g.dfs(0);
    g.topological_sort();

    return 0;
}
