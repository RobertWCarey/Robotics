#include "astar_path_planner/open_set.h"

#include <ros/ros.h>

namespace astar_path_planner
{
void OpenSet::push(const Node &n)
{
  nodes_.push_back(n);
}

Node OpenSet::pop(double heuristic_cost_weight)
{
  int index = 0;

  // Find the best node in "nodes_"
  // Save the index into "index" and it will be removed from "nodes_" and returned
  // You need to compare combined costs: the cost of the node + (heuristic cost * weight)
  // Use "heuristic_cost_weight" to calculate the combined cost so it can be modified later

  // YOUR CODE HERE

  int counter = 0;                                     // Used to store current index in foreach loop
  double minCost = std::numeric_limits<double>::max(); // Store current min cost

  for (Node node : nodes_)
  {
    double cost = node.cost + (node.heuristic_cost * heuristic_cost_weight);
    if (cost < minCost)
    {
      // Update index with current position in foreach loop
      index = counter;
      minCost = cost;
    }

    counter++;
  }

  // YOU DON'T NEED TO MODIFY ANYTHING AFTER THIS LINE

  // Copy the node
  Node n = nodes_[index];

  // Overwrite the node with the node at the end of the vector
  nodes_[index] = nodes_.back();

  // Delete the node at the end of the vector
  nodes_.pop_back();

  // Return the copy
  return n;
}

bool OpenSet::contains(int id)
{
  // Returns true if the node is in nodes_
  for (const auto &n : nodes_)
  {
    if (n.id == id)
    {
      return true;
    }
  }

  return false;
}

void OpenSet::update(const Node &n)
{
  // Find node "n" in "nodes_"
  // If the cost of node "n" is less than the cost of the node already in the open set, replace it

  // YOUR CODE HERE

  // Loop through nodes
  for (Node &node : nodes_)
  {
    // Find matching node
    if (node.id == n.id)
    {
      // if the new node has lower cost replace exsiting node
      if (n.cost < node.cost)
        node = n;
    }
  }
}

bool OpenSet::empty()
{
  return nodes_.empty();
}

const std::vector<Node> &OpenSet::getNodes()
{
  return nodes_;
}

std::ostream &operator<<(std::ostream &os, const OpenSet &open_set)
{
  os << "\n\nOpen set:" << std::endl;

  for (const auto &n : open_set.nodes_)
  {
    os << n;
  }

  return os;
}

} // namespace astar_path_planner