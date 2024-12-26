#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <climits> // Include this header for INT_MAX
using namespace std;

class Graph {
    int V; // Number of locations (nodes)
    vector<vector<pair<int, int>>> adj; // Adjacency list using vector of vectors

public:
    Graph(int V) : V(V), adj(V) {} // Initialize adjacency list

    void addEdge(int u, int v, int cost) {
        adj[u].push_back({v, cost}); // Add edge from u to v
        adj[v].push_back({u, cost}); // Undirected graph
    }

    vector<int> dijkstra(int src) {
        vector<int> dist(V, INT_MAX); // Initialize distances to infinity
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0; // Source distance is 0
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main() {
    int n = 6; // Number of locations (nodes)
    Graph city(n);

    // Add edges representing distances between locations
    city.addEdge(0, 1, 5);
    city.addEdge(0, 2, 10);
    city.addEdge(1, 2, 2);
    city.addEdge(1, 3, 3);
    city.addEdge(2, 4, 4);
    city.addEdge(3, 5, 6);
    city.addEdge(4, 5, 1);

    int passengerLocation = 1; // Passenger's current location
    int destination = 5;      // Passenger's desired destination

    // Find the shortest path from passenger's location to all other locations
    vector<int> distances = city.dijkstra(passengerLocation);

    // Output the shortest path to the destination
    cout << "Shortest path distance to destination: " << distances[destination] << endl;

    return 0;
}
