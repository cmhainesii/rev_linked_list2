CXX := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -O2 -Wpedantic

run_tests: ../LinkedList.cpp ../Node.cpp test.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f run_tests

