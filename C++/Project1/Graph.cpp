#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node;
struct Edge;

struct Node {
	int value;
	int in;
	int out;
	std::vector<shared_ptr<Node>> nodes;
	std::vector<shared_ptr<Edge>> edges;
	Node(int val) : value(val), in(0), out(0) {}
};

struct Edge {
	shared_ptr<Node> from;
	shared_ptr<Node> to;
	int weight;
	Edge(shared_ptr<Node> f, shared_ptr<Node> t, int w) : from(f), to(t), weight(w) {}
};

struct Graph {
	std::unordered_map<int, shared_ptr<Node>> nodes;
	std::unordered_set<shared_ptr<Edge>> edges;
};


class GraphAlgorithm {
public:

};