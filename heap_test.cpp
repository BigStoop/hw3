#include "heap.h"
#include <iostream>

struct maxcomp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {

	Heap<int, maxcomp> max_heap(3);

	max_heap.push(18);
	max_heap.push(8);
	max_heap.push(30);
	max_heap.push(2);

	std::cout << "Top: " << max_heap.top() << std::endl;

	max_heap.pop();
	std::cout << "New top: " << max_heap.top() << std::endl;

	return 0;
}