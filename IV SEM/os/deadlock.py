# program to detect deadlock using RAG when one instance of each resource type is given
class Graph:
  def __init__(self, vertices):
    self.graph = {v: [] for v in vertices}
    self.visited = {v: False for v in vertices}
    self.recStack = {v: False for v in vertices}

  def add_edge(self, u, v):
    self.graph[u].append(v)


  def is_cyclic_util(self, v):
    self.visited[v] = True
    self.recStack[v] = True

    for neighbor in self.graph[v]:
      if not self.visited[neighbor]:
        if self.is_cyclic_util(neighbor):
          return True
      elif self.recStack[neighbor]:
        return True

    self.recStack[v] = False
    return False

  def is_cyclic(self):
    for node in self.graph:
      if not self.visited[node]:
        if self.is_cyclic_util(node):
          return True
    return False

# Example usage
vertices = ['P1', 'P2', 'R1', 'R2']
g = Graph(vertices)
g.add_edge('P1', 'R1')
g.add_edge('R1', 'P2')
g.add_edge('P2', 'R2')
g.add_edge('R2', 'P1')

if g.is_cyclic():
  print("Deadlock detected")
else:
  print("No deadlock detected")
