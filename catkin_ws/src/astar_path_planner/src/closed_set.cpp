#include "astar_path_planner/closed_set.h"

#include <algorithm>

namespace astar_path_planner
{
size_t ClosedSet::size()
{
  return nodes_.size();
}

Node ClosedSet::getNode(int id)
{
  for (const Node &n : nodes_)
  {
    if (n.id == id)
      return n;
  }

  // if no match node can be found return last node
  return nodes_.back();
}

void ClosedSet::push(const Node &n)
{
  nodes_.push_back(n);
}

bool ClosedSet::contains(int id)
{
  // Return true if the node is in nodes_
  for (const auto &n : nodes_)
  {
    if (n.id == id)
    {
      return true;
    }
  }

  return false;
}

std::vector<int> ClosedSet::getPath(int start_id, int goal_id)
{
  // Return a path of IDs from the goal to the start
  // Find the goal node in "nodes_", then find its parent
  // Keep finding parents until you get to the start node
  // You should also reverse the path before returning it

  std::vector<int> path{};

  // YOUR CODE HERE

  bool startNodeFound = false; // bool to indicat if start node has been found

  // Get the last node off the end of the closed set
  // This should be the goal node
  Node curr_node = nodes_.back();

  while (!startNodeFound)
  {
    // Update the path list
    path.push_back(curr_node.id);

    // If the node just added to the path is the start ndoe, exit
    if (curr_node.id == start_id)
    {
      startNodeFound = true;
    }

    // Update curr_node with the parent node of the previous curr_node
    curr_node = getNode(curr_node.parent_id);
  }

  // Reverse path
  std::reverse(path.begin(), path.end());

  return path;
}

const std::vector<Node> &ClosedSet::getNodes()
{
  return nodes_;
}

std::ostream &operator<<(std::ostream &os, const ClosedSet &closed_set)
{
  os << "\n\nClosed set:" << std::endl;

  for (const auto &n : closed_set.nodes_)
  {
    os << n;
  }

  return os;
}

} // namespace astar_path_planner
