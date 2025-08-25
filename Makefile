CXX := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -O2 -Wpedantic

rev_linked_list2: Node.cpp LinkedList.cpp newMain.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f rev_linked_list2