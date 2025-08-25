#include "../LinkedList.h"
#include <cassert>
#include <string>
#include <iostream>
#include <memory>
#include <cstdint>


void TestAddNode(LinkedList *list);
void TestDeleteNode(LinkedList *list);


int main()
{
    std::unique_ptr<LinkedList> list = std::make_unique<LinkedList>();

    TestAddNode(list.get());
    list->Clear();
    TestDeleteNode(list.get());

    std::cout << "All test completed successfully\n";

    return 0;


}




void TestAddNode(LinkedList *list)
{

    constexpr uint32_t NEW_VALUE = 44;
    // Assert that the value to be inserted is does not exist on on the list
    assert(!list->Contains(NEW_VALUE));

    // Add value to the list and assert that we can find it using LinkedList.Contains()
    list->Add(NEW_VALUE);
    assert(list->Contains(NEW_VALUE));

    
}

void TestDeleteNode(LinkedList *list)
{
    constexpr uint32_t VALUE = 44;
    assert(!list->Contains(VALUE));
    list->Add(VALUE);
    assert(list->Contains(VALUE));

    // Asserted that the list has one item that we added. 
    // Delete list item and assert that the list no longer contains the value
    list->Delete(44);
    assert(!list->Contains(VALUE));
}

