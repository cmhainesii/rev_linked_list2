#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <string>
#include <cstdint>

class LinkedList
{
  public:
    LinkedList(void);
    ~LinkedList(void);
    void Clear(void);
    void Add(uint32_t value);
    bool Delete(uint32_t value);
    void Usurp(uint32_t value);
    void Decapitate(void);
    void DetachTail(void);
    void Reverse(void);
    std::string ToString();
    std::unique_ptr<Node> head;
};

#endif