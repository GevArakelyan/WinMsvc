#include <atomic>
#include <iostream>

namespace {
	int mains()
	{
		std::atomic<int> a(0);

		int b = a.fetch_add(1);
		int c = a.fetch_add(1);
		std::cout << b << "  " << c;
		return 0;
	}
	struct node { int value; node* next; };
	std::atomic<node*> head;
	void push_front(int x) {
		node* new_n = new node;
		new_n->value = x;
		node* old_h = head;
		do { new_n->next = old_h; } while (!head.compare_exchange_strong(old_h, new_n));
	}
}
