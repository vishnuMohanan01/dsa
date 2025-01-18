/*
 *  Given a directed graph design an algorithm to find out whether there is a route between two nodes 
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

enum State { UNVISITED, VISITED };

class Node {
  public:
    int number;
    State state;
    vector<Node*> connections;
  
    Node(int n) :  number(n) {}

    void add_connection(Node* node) {
      connections.push_back(node);
    }
};

class Graph {
  public:
    unordered_map<int, Node*> nodes;

    void add_node(int number) {
      nodes[number] = new Node(number);
    }

    void add_edge(int from, int to) {
      if (nodes.find(from) != nodes.end() && nodes.find(to) != nodes.end()) {
        nodes[from]->add_connection(nodes[to]);
      }
    }

    bool search_path(int num_1, int num_2) {
      if (nodes.find(num_1) == nodes.end() || nodes.find(num_2) == nodes.end()) {
        return false; // or raise error
      }
  
      if (num_1 == num_2) return true;
      
      Node* start = nodes[num_1];
      Node* end = nodes[num_2];
      queue<Node*> q;
      
      for (auto& pair : nodes) {
        pair.second->state = UNVISITED;
      }

      q.push(start);

      Node* u;

      while(!q.empty()) {
        u = q.front();
        q.pop();
        
        if (u == NULL) continue;

        for (Node* v : u->connections) {
          if (v->state == VISITED) continue;

          if (v == end) return true;
          else {
            q.push(v);
          }
        }
        
        u->state = VISITED;
      }

      return false;
    }
    
    ~Graph() {
      for (auto& pair : nodes) {
        delete pair.second;
      }
    }
};

int main() {
  Graph graph;

  for (int i = 1; i <= 6; i++) {
    graph.add_node(i);
  }

  graph.add_edge(1, 2);
  graph.add_edge(1, 6);
  graph.add_edge(2, 3);
  graph.add_edge(2, 6);
  graph.add_edge(3, 4);
  graph.add_edge(4, 1);
  graph.add_edge(5, 3);
  
  int num_1, num_2;

  cout << "Enter nodes to search path between (1-6):";
  cin >> num_1 >> num_2;

  cout << graph.search_path(num_1, num_2);
}

