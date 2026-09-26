// Kruskal's algorithm for a minimum spanning tree.
// Sort all edges by weight, then add each edge unless it would form a cycle.
// A disjoint-set (union-find) structure tracks which vertices are already
// connected. O(E log E) for the sort; union-find is nearly O(1) per call.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int u, v, weight;
};

bool compareByWeight(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

class DisjointSet
{
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Path compression: point every visited node straight at the root.
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank: attach the shorter tree under the taller one.
    bool unite(int a, int b)
    {
        int rootA = find(a), rootB = find(b);
        if (rootA == rootB)
            return false; // already connected, the edge would form a cycle
        if (rank[rootA] < rank[rootB])
            swap(rootA, rootB);
        parent[rootB] = rootA;
        if (rank[rootA] == rank[rootB])
            rank[rootA]++;
        return true;
    }
};

int main()
{
    int vertices = 5;
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8},
        {1, 4, 5}, {2, 4, 7}, {3, 4, 9},
    };

    sort(edges.begin(), edges.end(), compareByWeight);

    DisjointSet ds(vertices);
    int total = 0;
    cout << "Edge    Weight" << endl;
    for (const Edge &e : edges)
    {
        if (ds.unite(e.u, e.v))
        {
            cout << e.u << " - " << e.v << "    " << e.weight << endl;
            total += e.weight;
        }
    }
    cout << "Total weight: " << total << endl;

    return 0;
}
