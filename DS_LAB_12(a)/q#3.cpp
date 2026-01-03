#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    list<int> *l;                    // adjacency list
    vector<vector<int>> adjMatrix;   // adjacency matrix

public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];

        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void printGraph() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int neighbour : l[i]) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void BFS() {
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(0);
        visited[0] = true;

        cout << "BFS: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << u << " ";
            for (int v : l[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void DFS_helper(int u, vector<bool> &visited) {
        cout << u << " ";
        visited[u] = true;

        for (int v : l[u]) {
            if (!visited[v]) {
                DFS_helper(v, visited);
            }
        }
    }

    void DFS() {
        vector<bool> visited(V, false);
        cout << "DFS: ";
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS_helper(i, visited);
            }
        }
        cout << endl;
    }
};


int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();      // adjacency list
    g.printAdjMatrix();  // adjacency matrix

    g.DFS(); // DFS
    g.BFS(); // BFS

    return 0;
}
