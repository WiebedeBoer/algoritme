// algoritme3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//For this exercise you are to choose a puzzle and program a solver for it in C++.

//Study the 8 - puzzle files(8puzzle.h, 8puzzle.cpp) and peg game files(peggame.h, peggame.cpp) and 
//add your implementation of the breadth - first search algorithm that you created in the previous exercise.

//Pay attention to how the state of a board represents a vertex and how every move represents an edge.
//Test the program and see if it can solve the 8 - puzzle and peg game.

//Choose a puzzle and think up a representation for itsstate and jumps(moves).
//Use the files for the 8 - puzzle or peggame as a starting point 
//and change the methods and functions(e.g.Graph::cbegin, doMove, operator>>, etc) 
//so that it solves the chosen puzzle instead.

//For some puzzles breadth - first search alone won’t suffice 
//and you will need to implement a more appropriate search strategy such as beam search or A * .

#include "pch.h"
#include <queue>

typename std::vector<Vertex>::const_iterator Graph::cbegin(Vertex v) const
{
	adjacents.clear();

	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (v[r][c] == 0) {
				if (c < 2) adjacents.push_back(doMove(v, Move::l));
				if (c > 0) adjacents.push_back(doMove(v, Move::r));
				if (r < 2) adjacents.push_back(doMove(v, Move::u));
				if (r > 0) adjacents.push_back(doMove(v, Move::d));
			}
		}
	}
	return adjacents.cbegin();
}

typename std::vector<Vertex>::const_iterator Graph::cend() const
{
	return adjacents.cend();
}

Vertex doMove(const Vertex &v, const Move &m)
{
	bool done = false;
	Vertex n = v;

	for (int r = 0; r < 3 && !done; r++) {
		for (int c = 0; c < 3 && !done; c++) {
			if (v[r][c] == 0) {
				switch (m) {
				case Move::l: std::swap(n[r][c], n[r][c + 1]); done = true; break;
				case Move::r: std::swap(n[r][c], n[r][c - 1]); done = true; break;
				case Move::u: std::swap(n[r + 1][c], n[r][c]); done = true; break;
				case Move::d: std::swap(n[r - 1][c], n[r][c]); done = true; break;
				}
			}
		}
	}
	return n;
}

std::ostream &operator<<(std::ostream &os, const Vertex &state)
{
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (state[r][c] != 0) {
				os << state[r][c];
			}
			else {
				os << " ";
			}
		}
		os << std::endl;
	}
	return os;
}

Path dfs(const Graph &graph, const Vertex &start, std::function<bool(const Vertex &vertex)> goalTest)
{
	std::stack<Path> queue;
	std::set<Vertex> visited;
	Path path;

	queue.push(path);
	while (!queue.empty()) {
		path = queue.top();
		queue.pop();

		Vertex last;
		if (path.size() == 0) {
			last = start;
		}
		else {
			last = path.back();
		}
		if (goalTest(last))
			return path; // path is a vector of Vertices

		if (visited.find(last) == visited.end()) {
			visited.insert(last);
			for (auto it = graph.cbegin(last); it != graph.cend(); it++) { // extend path with new Vertex
				Path n = path;
				n.push_back(*it);
				queue.push(n);
			}
		}
	}
	return Path();
}

Path bfs(const Graph &graph, const Vertex &start, std::function<bool(const Vertex &vertex)> goalTest)
{
	// Here goes the solution to exercise #2
	std::queue<Path> queue;
	std::set<Vertex> visited;
	Path path;

	queue.push(path);
	while (!queue.empty()) {
		path = queue.front();
		queue.pop();

		Vertex last;
		if (path.size() == 0) {
			last = start;
		}
		else {
			last = path.back();
		}
		if (goalTest(last))
			return path; // path is a vector of Vertices

		for (auto it = graph.cbegin(last); it != graph.cend(); it++) { // extend path with new Vertex
			if (visited.find(*it) == visited.end()) {
				Path n = path;
				n.push_back(*it);
				queue.push(n);
			}
		}
	}
	return Path(); // return empty path
}

int main()
{
	Graph graph;

	Vertex start = { {
		{{1,2,3}},
		{{7,0,4}},
		{{8,6,5}}
	} };

	Vertex goal = { {
		{{1,2,3}},
		{{4,5,6}},
		{{7,8,0}}
	} };

	Path path = bfs(graph, start, [&](Vertex v) { return (v == goal); });

	std::cout << start << std::endl;
	for (auto it = path.cbegin(); it != path.cend(); it++)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
