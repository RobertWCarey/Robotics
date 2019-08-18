#include "astar_path_planner/closed_set.h"
#include <ros/ros.h>

#include <algorithm>

namespace astar_path_planner
{
size_t ClosedSet::size()
{
  return nodes_.size();
}

Node ClosedSet::getNode(int id){
  for(const Node& n : nodes_)
  {
    if (n.id == id)
      return n;
  }
}

void ClosedSet::push(const Node& n)
{
  nodes_.push_back(n);
}

bool ClosedSet::contains(int id)
{
  // Return true if the node is in nodes_
  for (const auto& n : nodes_)
  {
    if (n.id == id)
    {
      return true;
    }
  }

  return false;
}

void waitForKey()
{
  ROS_INFO("Paused, press enter to continue...");
  std::cin.get();
}

std::vector<int> ClosedSet::getPath(int start_id, int goal_id)
{
  // Return a path of IDs from the goal to the start
  // Find the goal node in "nodes_", then find its parent
  // Keep finding parents until you get to the start node
  // You should also reverse the path before returning it

  std::vector<int> path{};

  // YOUR CODE HERE
  bool startNodeFound = false;
  Node curr_node = nodes_.back();

  // ROS_INFO_STREAM("\n\nCurrent Node: " << curr_node);
  // ROS_INFO("\n\nGoal ID: %d", goal_id);
  // ROS_INFO("\n\nStart ID: %d", start_id);
  // waitForKey();
  // for(Node n : nodes_)
  // {
  //   ROS_INFO_STREAM("\n\nnodes_: " << n);
  // }
  // waitForKey();
  while (!startNodeFound)
  {
    path.push_back(curr_node.id);
    // waitForKey();
    // ROS_INFO("\n\nNext Node ID: %d", curr_node.id);
    // ROS_INFO("\n\nParent Node ID: %d", curr_node.parent_id);
    
    if (curr_node.id == start_id)
    {
      startNodeFound = true;
      ROS_INFO("Paused, press enter to continue...");
      std::cin.get();
    }
    curr_node = getNode(curr_node.parent_id);
  }
  
  // std::reverse(path.begin(), path.end());

  return path;
}

const std::vector<Node>& ClosedSet::getNodes()
{
  return nodes_;
}

std::ostream& operator<<(std::ostream& os, const ClosedSet& closed_set)
{
  os << "\n\nClosed set:" << std::endl;

  for (const auto& n : closed_set.nodes_)
  {
    os << n;
  }

  return os;
}

}  // namespace astar_path_planner
