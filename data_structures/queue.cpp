#include <iostream>
using namespace std;

#define SIZE 10

class Queue {
	int* arr;
	int capacity;
	int front;
	int rear;
	int count;

	public:
	Queue(int size = SIZE);
	~Queue();

	int dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
};

Queue::Queue(int size) {
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

Queue::~Queue() {
	delete[] arr;
}

int Queue::dequeue() {
	if (isEmpty()) {
		cout << "Queue underflow";
		return 0;
	}

	int x = arr[front];
	cout << "Removing " << x << endl;
	front = (front + 1) % capacity;
	count--;

	return x;
}

void Queue::enqueue(int item) {
	if (isFull()) {
		cout << "Queue overflow";
		return 0;
	}

	cout << "Inserting " << item << endl;

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

int Queue::peek() {
	if (isEmpty()) {
		cout << "Queue underflow";
		return 0;
	}
	return arr[front];
}

int Queue::size() {
	return count;
}

bool Queue::isEmpty() {
	return (size() == 0);
}

int main() {
	Queue queue(5);
}
