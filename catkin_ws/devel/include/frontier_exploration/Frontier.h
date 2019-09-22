// Generated by gencpp from file frontier_exploration/Frontier.msg
// DO NOT EDIT!


#ifndef FRONTIER_EXPLORATION_MESSAGE_FRONTIER_H
#define FRONTIER_EXPLORATION_MESSAGE_FRONTIER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Point.h>

namespace frontier_exploration
{
template <class ContainerAllocator>
struct Frontier_
{
  typedef Frontier_<ContainerAllocator> Type;

  Frontier_()
    : size(0)
    , min_distance(0.0)
    , travel_point()  {
    }
  Frontier_(const ContainerAllocator& _alloc)
    : size(0)
    , min_distance(0.0)
    , travel_point(_alloc)  {
  (void)_alloc;
    }



   typedef uint32_t _size_type;
  _size_type size;

   typedef double _min_distance_type;
  _min_distance_type min_distance;

   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _travel_point_type;
  _travel_point_type travel_point;





  typedef boost::shared_ptr< ::frontier_exploration::Frontier_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::frontier_exploration::Frontier_<ContainerAllocator> const> ConstPtr;

}; // struct Frontier_

typedef ::frontier_exploration::Frontier_<std::allocator<void> > Frontier;

typedef boost::shared_ptr< ::frontier_exploration::Frontier > FrontierPtr;
typedef boost::shared_ptr< ::frontier_exploration::Frontier const> FrontierConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::frontier_exploration::Frontier_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::frontier_exploration::Frontier_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace frontier_exploration

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'frontier_exploration': ['/home/rob/Documents/Robotics/catkin_ws/src/frontier_exploration/frontier_exploration/msg', '/home/rob/Documents/Robotics/catkin_ws/devel/share/frontier_exploration/msg'], 'actionlib_msgs': ['/opt/ros/melodic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'visualization_msgs': ['/opt/ros/melodic/share/visualization_msgs/cmake/../msg'], 'move_base_msgs': ['/opt/ros/melodic/share/move_base_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::frontier_exploration::Frontier_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::frontier_exploration::Frontier_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::frontier_exploration::Frontier_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::frontier_exploration::Frontier_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::frontier_exploration::Frontier_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::frontier_exploration::Frontier_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::frontier_exploration::Frontier_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8e57df42619e81a60a4a5920d716e4b4";
  }

  static const char* value(const ::frontier_exploration::Frontier_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8e57df42619e81a6ULL;
  static const uint64_t static_value2 = 0x0a4a5920d716e4b4ULL;
};

template<class ContainerAllocator>
struct DataType< ::frontier_exploration::Frontier_<ContainerAllocator> >
{
  static const char* value()
  {
    return "frontier_exploration/Frontier";
  }

  static const char* value(const ::frontier_exploration::Frontier_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::frontier_exploration::Frontier_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 size\n"
"float64 min_distance\n"
"geometry_msgs/Point travel_point\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::frontier_exploration::Frontier_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::frontier_exploration::Frontier_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.size);
      stream.next(m.min_distance);
      stream.next(m.travel_point);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Frontier_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::frontier_exploration::Frontier_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::frontier_exploration::Frontier_<ContainerAllocator>& v)
  {
    s << indent << "size: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.size);
    s << indent << "min_distance: ";
    Printer<double>::stream(s, indent + "  ", v.min_distance);
    s << indent << "travel_point: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.travel_point);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FRONTIER_EXPLORATION_MESSAGE_FRONTIER_H
