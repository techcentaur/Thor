# Python implementation of Krushal's Algo for MST

class Graph(object):
	def __init__(self, vertices):
		super(Graph, self).__init__()
		self.vertices = vertices
		self.graph = []

	def add_edge(self, src, dest, weight):
		self.graph.append([src, dest, weight])

	def find(self, parent, i):
		if parent[i] == i:
			return i
		return self.find(parent, parent[i])

	def union(self, parent, rank, x, y):
		xroot = self.find(parent, x)
		yroot = self.find(parent, y)

		if rank[xroot] < rank[yroot]:
			parent[xroot] = yroot
		elif rank[xroot] > rank[yroot]:
			parent[yroot] = xroot
		else:
			parent[yroot] = xroot
			rank[xroot]+=1


	def kruskal(self):
		resultMST = []
		self.graph = sorted(self.graph, key=lambda item: item[2])
		parent = []; rank = []
		for node in range(self.vertices):
			parent.append(node)
			rank.append(0)

		i = 0
		e = 0
		while e < self.vertices - 1:
			u, v, w = self.graph[i]
			i+=1
			x = self.find(parent, u)
			y = self.find(parent, v)

			if x!=y:
				e+=1
				resultMST.append([u, v, w])
				self.union(parent, rank, x, y)

		print("[*] MST contructed.")
		for u, v, w in resultMST:
			print("Src: {src} -- Dest: {dest} -> Weight: {weight}".format(src=u, dest=v, weight=w))


if __name__=="__main__":
	g = Graph(4)
	g.add_edge(0, 1, 10)
	g.add_edge(0, 2, 6)
	g.add_edge(0, 3, 5)
	g.add_edge(2, 3, 4)

	g.kruskal()