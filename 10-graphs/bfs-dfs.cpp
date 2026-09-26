// Breadth-first search and depth-first search on an undirected graph stored
// as an adjacency matrix.
// BFS visits vertices level by level using a queue; DFS goes as deep as
// possible first using recursion. Both are O(V^2) with a matrix
// (O(V + E) with an adjacency list).
#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adjMatrix;

    void dfsUtil(int v, vector<bool> &visited) const
    {
        visited[v] = true;
        cout << v << " ";
        for (int neighbor = 0; neighbor < V; ++neighbor)
            if (adjMatrix[v][neighbor] && !visited[neighbor])
                dfsUtil(neighbor, visited);
    }

public:
    Graph(int vertices) : V(vertices), adjMatrix(vertices, vector<int>(vertices, 0)) {}

    void addEdge(int v, int w)
    {
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1;
    }

    void bfs(int start) const
    {
        vector<bool> visited(V, false);
        vector<int> queue(V); // each vertex is enqueued at most once
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        while (front < rear)
        {
            int current = queue[front++];
            cout << current << " ";
            for (int neighbor = 0; neighbor < V; ++neighbor)
            {
                if (adjMatrix[current][neighbor] && !visited[neighbor])
                {
                    visited[neighbor] = true; // mark on enqueue, not on visit
                    queue[rear++] = neighbor;
                }
            }
        }
        cout << endl;
    }

    void dfs(int start) const
    {
        vector<bool> visited(V, false);
        dfsUtil(start, visited);
        cout << endl;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "BFS starting from vertex 0: ";
    g.bfs(0);

    cout << "DFS starting from vertex 0: ";
    g.dfs(0);

    return 0;
}
