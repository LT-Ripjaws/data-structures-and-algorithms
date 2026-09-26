// Topological sort of a directed acyclic graph (Kahn's algorithm).
// Repeatedly output a vertex with no remaining incoming edges and remove its
// outgoing edges. If some vertices are never output, the graph has a cycle.
// O(V + E). Typical use: ordering tasks or courses with prerequisites.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool topologicalSort(const vector<vector<int>> &adj, vector<int> &order)
{
    int n = adj.size();
    vector<int> inDegree(n, 0);
    for (int u = 0; u < n; u++)
        for (int v : adj[u])
            inDegree[v]++;

    queue<int> ready;
    for (int v = 0; v < n; v++)
        if (inDegree[v] == 0)
            ready.push(v);

    order.clear();
    while (!ready.empty())
    {
        int u = ready.front();
        ready.pop();
        order.push_back(u);
        for (int v : adj[u])
        {
            inDegree[v]--; // remove the edge u -> v
            if (inDegree[v] == 0)
                ready.push(v);
        }
    }
    return (int)order.size() == n; // false means there is a cycle
}

int main()
{
    // 0: Programming, 1: Data Structures, 2: Discrete Math,
    // 3: Algorithms, 4: Compiler Design, 5: Theory of Computation
    vector<vector<int>> adj = {
        {1},    // Programming -> Data Structures
        {3},    // Data Structures -> Algorithms
        {3, 5}, // Discrete Math -> Algorithms, Theory of Computation
        {4},    // Algorithms -> Compiler Design
        {},
        {4},    // Theory of Computation -> Compiler Design
    };

    vector<int> order;
    if (topologicalSort(adj, order))
    {
        cout << "Course order: ";
        for (int v : order)
            cout << v << " ";
        cout << endl;
    }

    adj[4].push_back(0); // add a cycle: Compiler Design -> Programming
    cout << "With a cycle added: "
         << (topologicalSort(adj, order) ? "sorted" : "no valid order, the graph has a cycle") << endl;

    return 0;
}
