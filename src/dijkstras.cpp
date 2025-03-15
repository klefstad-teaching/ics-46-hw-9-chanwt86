#include "dijkstras.h"
#include <queue>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int n = G.numVertices;

    vector<int> distance(n, INF);
    previous.assign(n, -1);
    vector<bool> visited(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        for (const Edge &edge : G.adjacencyList[u]) {
            int v = edge.dst;
            int weight = edge.weight;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){

}

void print_path(const vector<int>& v, int total){

}