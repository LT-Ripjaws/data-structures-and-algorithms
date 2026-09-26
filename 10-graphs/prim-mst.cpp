// Prim's algorithm for a minimum spanning tree (MST).
// Grow the tree from vertex 0. At each step, add the cheapest edge that
// connects a vertex in the tree to a vertex outside it.
// O(V^2) with an adjacency matrix. A weight of 0 means "no edge".
#include <iostream>
using namespace std;

const int MAX = 100;
const int INF = 1e9;

int findMinKeyVertex(const int key[], const bool inMST[], int vertices)
{
    int minKey = INF;
    int minIndex = -1;
    for (int v = 0; v < vertices; ++v)
    {
        if (!inMST[v] && key[v] < minKey)
        {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(const int graph[MAX][MAX], int vertices)
{
    int parent[MAX]; // parent[v] is the tree vertex v connects to
    int key[MAX];    // cheapest known edge weight into v
    bool inMST[MAX];

    for (int v = 0; v < vertices; ++v)
    {
        key[v] = INF;
        inMST[v] = false;
        parent[v] = -1;
    }
    key[0] = 0;

    for (int count = 0; count < vertices; ++count)
    {
        int u = findMinKeyVertex(key, inMST, vertices);
        if (u == -1)
            break; // remaining vertices are unreachable
        inMST[u] = true;

        for (int v = 0; v < vertices; ++v)
        {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;
    cout << "Edge    Weight" << endl;
    for (int v = 1; v < vertices; ++v)
    {
        if (parent[v] == -1)
            continue;
        cout << parent[v] << " - " << v << "    " << graph[v][parent[v]] << endl;
        total += graph[v][parent[v]];
    }
    cout << "Total weight: " << total << endl;
}

int main()
{
    int vertices = 5;
    int graph[MAX][MAX] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    primMST(graph, vertices);
    return 0;
}
