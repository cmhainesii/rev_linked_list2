#include "LinkedList.h"
#include <sstream>
#include <algorithm>

LinkedList::LinkedList(void)
{
    head = nullptr;
}

LinkedList::~LinkedList(void)
{
    Clear();
}

void LinkedList::Clear(void)
{
    head = nullptr;
}

void LinkedList::Add(uint32_t value)
{
    std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
    // If list is empty, create node and set it as the head
    if (!head)
    {
        head = std::move(newNode);
        return;
    }

    // Traverse the list and insert node at the end
    Node* currentNode = head.get();
    while(currentNode->next)
    {
        currentNode = currentNode->next.get();
    }
    currentNode->next = std::move(newNode);
}

bool LinkedList::Delete(uint32_t value)
{
    // Traverse the list until the specified value is found
    Node* current = head.get();
    Node* previous = nullptr;
    bool found = false;

    while(current)
    {
        if (current->value == value)
        {
            found = true;
            if(previous)
            {
                previous->next = std::move(current->next);
            }
            else
            {
                head = std::move(current->next);
                break;
            }
        }
        previous = current;
        current = previous->next.get();
    }

    return found;
}

std::string LinkedList::ToString()
{
    if (!head)
    {
        return "<Empty List>";
    }
    std::ostringstream builder;
    // Traverse the list printing values separated by a space one one line
    Node *current = head.get();

    while(current)
    {
        builder << current->value << " ";  
        current = current->next.get();
    }

    return builder.str();
}

void LinkedList::Usurp(uint32_t value)
{
    // Add new node at the beginning of the list
    std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
    newNode->next = std::move(head);
    head = std::move(newNode);
}

void LinkedList::Decapitate()
{
    if (!head)
    {
        return;
    }
    // Remove the head node
    if(head->next)
    {
        head = std::move(head->next);
    }
    else
    {
        head = nullptr;
    }
}

void LinkedList::Reverse(void)
{
    std::unique_ptr<Node> current = std::move(head);
    std::unique_ptr<Node> prev = nullptr;
    while(current)
    {
        std::unique_ptr<Node> next = std::move(current->next);
        current->next = std::move(prev);
        prev = std::move(current);
        current = std::move(next);
    }

    head = std::move(prev);
}

void LinkedList::DetachTail(void)
{


    if (!head)
    {
        return;
    }

    // Traverse the list and remove the last node
    Node* current = head.get();
    Node* prev = nullptr;

    while(current->next.get())
    {
        Node* next = current->next.get();
        prev = current;
        current = next;        
    }

    // current is the tail. Clear prev->next to detach the current tail.
    prev->next = nullptr;
}


bool LinkedList::Contains(uint32_t value)
{
    Node* current = head.get();

    while(current)
    {
        if(current->value == value)
        {
            return true;
        }
        current = current->next.get();
    }

    return false;
}

void LinkedList::Sort(void)
{
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head.get();
        while(current->next)
        {
            if(current->value > current->next->value) {
                std::swap(current->value, current->next->value);
                swapped = true;
            }
            current = current->next.get();
        }
    } while (swapped);
}