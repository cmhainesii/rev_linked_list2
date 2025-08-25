#include "LinkedList.h"

#include <iostream>
#include <memory>
#include <format>

int main()
{
    std::unique_ptr<LinkedList> list = std::make_unique<LinkedList>();

    // Add some nodes to the list
    list->Add(100);
    list->Add(200);
    list->Add(500);
    list->Add(800);

    // Print list
    std::cout << "Values:\n";
    std::cout << list->ToString();

    list->DetachTail();
    list->DetachTail();

    std::cout << "Values:\n" << list->ToString() << "\n";

    

    return 0;
}