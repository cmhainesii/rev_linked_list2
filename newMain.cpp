#include "LinkedList.h"

#include <iostream>
#include <memory>
#include <format>
#include <random>

int main()
{
    std::unique_ptr<LinkedList> list = std::make_unique<LinkedList>();

    // Set up RNG
    std::random_device rd; // Seed
    std::mt19937 gen(rd()); // Mersenne Twister Engine
    std::uniform_int_distribution<uint32_t> dist(0, 1000000);

    const size_t listSize = 100000;
    for(size_t i = 0; i < listSize; ++i)
    {
        list->Add(dist(gen));
    }

    list->Sort();
    //std::cout << std::format("List:\n{}", list->ToString());

    return 0;
}