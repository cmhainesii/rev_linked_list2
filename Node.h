#ifndef NODE_H
#define NODE_H

#include <memory>


class Node
{
  public:
    Node(uint32_t value);
    uint32_t value;
    std::unique_ptr<Node> next;
};

#endif