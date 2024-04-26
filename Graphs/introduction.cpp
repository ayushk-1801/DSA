#include <bits/stdc++.h>
using namespace std;

class graph {
public:
  unordered_map<int, list<int>> adj;

  void addEdge(int u, int v, bool direction) {
    // direction = 0 -> undirected
    // direction = 1 -> directed

    adj[u].push_back(v);

    if (!direction)
      adj[v].push_back(u);
  }

  void printAdjList() {
    for (auto i : adj) {
      cout << i.first << "-> ";
      for (auto j : i.second) {
        cout << j << ", ";
      }
      cout << endl;
    }
  }

  void bfs(int start) {
    unordered_map<int, bool> visited;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
      int node = q.front();
      cout << node << " ";
      q.pop();

      for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }
  }

  void dfsHelper(int node, unordered_map<int, bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (auto neighbor : adj[node]) {
      if (!visited[neighbor]) {
        dfsHelper(neighbor, visited);
      }
    }
  }

  void dfs(int start) {
    unordered_map<int, bool> visited;
    dfsHelper(start, visited);
  }
};

int main() {
  int n;
  cout << "Enter the number of nodes: ";
  cin >> n;

  int m;
  cout << "Enter the number of edges: ";
  cin >> m;

  graph g;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    g.addEdge(u, v, 1);
  }

  g.printAdjList();
  cout << "BFS: ";
  g.bfs(1);
  cout << "\nDFS: ";
  g.dfs(1);
  return 0;
}
