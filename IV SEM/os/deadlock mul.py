class Graph:
  def __init__(self, vertices, instances):
    self.graph = {v: [] for v in vertices}
    self.visited = {v: False for v in vertices}
    self.recStack = {v: False for v in vertices}
    self.instances = instances
    self.allocation = {v: 0 for v in vertices if v.startswith('R')}

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

  def request_resource(self, process, resource):
    if self.allocation[resource] < self.instances[resource]:
      self.allocation[resource] += 1
      self.add_edge(process, resource)
      return True
    return False

  def release_resource(self, process, resource):
    if self.allocation[resource] > 0:
      self.allocation[resource] -= 1
      self.graph[process].remove(resource)
      return True
    return False

# Example usage
vertices = ['P1', 'P2', 'R1', 'R2']
instances = {'R1': 2, 'R2': 1}
g = Graph(vertices, instances)
g.request_resource('P1', 'R1')
g.request_resource('P2', 'R1')
g.request_resource('P2', 'R2')
g.add_edge('R2', 'P1')

if g.is_cyclic():
  print("Deadlock detected")
else:
  print("No deadlock detected")
