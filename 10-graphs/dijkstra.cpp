// Dijkstra's shortest path from one source to every vertex.
// Repeatedly take the unfinished vertex with the smallest known distance and
// relax its outgoing edges. Uses a min-priority queue over an adjacency list:
// O((V + E) log V). Edge weights must be non-negative.
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int INF = 1e9;

// Neighbour = (vertex, edge weight). graph[u] lists u's neighbours.
typedef pair<int, int> Neighbour;
typedef vector<vector<Neighbour>> Graph;

// QueueItem = (distance, vertex). Distance comes first so the queue orders
// by it; greater<QueueItem> makes the smallest distance come out first.
typedef pair<int, int> QueueItem;

void addEdge(Graph &graph, int u, int v, int weight)
{
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight}); // undirected
}

vector<int> dijkstra(const Graph &graph, int source, vector<int> &previous)
{
    int n = graph.size();
    vector<int> dist(n, INF);
    previous.assign(n, -1);

    priority_queue<QueueItem, vector<QueueItem>, greater<QueueItem>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // A vertex can be in the queue more than once. Skip old entries
        // whose distance has since been improved.
        if (d > dist[u])
            continue;

        for (const Neighbour &edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                previous[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void printPath(const vector<int> &previous, int target)
{
    if (previous[target] != -1)
        printPath(previous, previous[target]);
    cout << target << " ";
}

int main()
{
    int n = 7; // vertex 6 has no edges, so it is unreachable
    Graph graph(n);
    addEdge(graph, 0, 1, 7);
    addEdge(graph, 0, 2, 9);
    addEdge(graph, 0, 5, 14);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 1, 3, 15);
    addEdge(graph, 2, 3, 11);
    addEdge(graph, 2, 5, 2);
    addEdge(graph, 3, 4, 6);
    addEdge(graph, 4, 5, 9);

    vector<int> previous;
    vector<int> dist = dijkstra(graph, 0, previous);

    cout << left << setw(8) << "Vertex" << setw(10) << "Distance" << "Path" << endl;
    for (int v = 0; v < n; v++)
    {
        if (dist[v] == INF)
        {
            cout << setw(8) << v << setw(10) << "-" << "unreachable" << endl;
            continue;
        }
        cout << setw(8) << v << setw(10) << dist[v];
        printPath(previous, v);
        cout << endl;
    }

    return 0;
}
