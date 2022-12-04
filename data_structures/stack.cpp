#include <iostream>

using namespace std;

#define MAX 10

class Stack {
	int top;

	public:
	int stack[MAX];

	Stack() { top = -1; }
	bool push(int x);
	int pop();
	bool isEmpty();
};

bool Stack::push(int x) {
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	} else {
		stack[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

int Stack::pop() {
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	} else {
		int x = stack[top--];
		return x;
	}
}

bool Stack::isEmpty() {
	return (top < 0);
}

int main() {
	Stack st;
}
