// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

#include <array>
#include <vector>
#include <iostream>
#include <functional>
#include <stack>
#include <set>
#include <map>

using Vertex = char;
using Path = std::vector<Vertex>;

class Graph
{
public:
	typename std::vector<Vertex>::const_iterator cbegin(Vertex v) const;
	typename std::vector<Vertex>::const_iterator cend() const;
private:
	mutable Vertex currentVertex;
	typedef std::map<Vertex, std::vector<Vertex>> GraphMap;
	static GraphMap adjacents;
};

Path dfs(const Graph &graph, const Vertex &start, std::function<bool(const Vertex &vertex)> goalTest);
Path bfs(const Graph &graph, const Vertex &start, std::function<bool(const Vertex &vertex)> goalTest);

// TODO: add headers that you want to pre-compile here

#endif //PCH_H
