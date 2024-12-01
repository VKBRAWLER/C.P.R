// WAP for Deadlock Detection
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph {
  unordered_map<string, vector<string>> graph;
public:
  Graph(const vector<string>& vertices) {
    for (const auto& v : vertices) {
      graph[v] = {};
    }
  }

  void addEdge(const string& u, const string& v) {
    graph[u].push_back(v);
  }

  bool isCyclicUtil(const string& v, unordered_map<string, bool>& visited, unordered_map<string, bool>& recStack) {
    visited[v] = recStack[v] = true;
    for (const auto& neighbor : graph[v]) {
      if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack)) return true;
      if (recStack[neighbor]) return true;
    }
    recStack[v] = false;
    return false;
  }

  bool isCyclic() {
    unordered_map<string, bool> visited, recStack;
    for (const auto& node : graph) {
      if (!visited[node.first] && isCyclicUtil(node.first, visited, recStack)) return true;
    }
    return false;
  }
};

int main() {
  Graph g({"P1", "P2", "R1", "R2"});
  g.addEdge("P1", "R1");
  g.addEdge("R1", "P2");
  g.addEdge("P2", "R2");
  g.addEdge("R2", "P1");

  cout << (g.isCyclic() ? "Deadlock detected" : "No deadlock detected") << endl;
  return 0;
}
