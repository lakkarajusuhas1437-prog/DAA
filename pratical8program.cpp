#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

class GraphTraversal {
private:
    int vertices;
    vector<vector<int>> graph;

public:
    GraphTraversal(int n) {
        vertices = n;
        graph.resize(n);
    }

    void insertEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);   // Undirected graph
    }

    void performDFS(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << current << " ";

        for (int next : graph[current]) {
            if (!visited[next]) {
                performDFS(next, visited);
            }
        }
    }

    void DFS(int source) {
        vector<bool> visited(vertices, false);
        performDFS(source, visited);
    }

    void BFS(int source) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[source] = true;
        q.push(source);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int next : graph[current]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    GraphTraversal g(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges:\n";

    for (int i = 0; i < edges; i++) {
        int x, y;
        cin >> x >> y;
        g.insertEdge(x, y);
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    // Measure DFS execution time
    auto dfsStart = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    g.DFS(source);

    auto dfsEnd = high_resolution_clock::now();

    auto dfsDuration =
        duration_cast<nanoseconds>(dfsEnd - dfsStart);

    // Measure BFS execution time
    auto bfsStart = high_resolution_clock::now();

    cout << "\nBFS Traversal: ";
    g.BFS(source);

    auto bfsEnd = high_resolution_clock::now();

    auto bfsDuration =
        duration_cast<nanoseconds>(bfsEnd - bfsStart);

    cout << "\n\nExecution Time:";
    cout << "\nDFS Time = " << dfsDuration.count() << " ns";
    cout << "\nBFS Time = " << bfsDuration.count() << " ns";

    return 0;
}
