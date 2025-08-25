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

    // Print list
    std::cout << "Values:\n";
    std::cout << list->ToString();

    list->Usurp(420);
    std::cout << "Values:\n" << list->ToString() << "\n";

    list->Reverse();
    std::cout << "Values:\n" << list->ToString() << "\n";

    return 0;
}