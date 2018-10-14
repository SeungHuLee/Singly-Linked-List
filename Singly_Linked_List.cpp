#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
	T element;
	Node *next_node;

public:
	Node(T = 0, Node * = 0);
	T retrieve() const;
	Node *next() const;
};

template <typename T>
Node<T>::Node(T e, Node * n) : element(e), next_node(n) {}

template <typename T>
T Node<T>::retrieve() const {
	return element;
}

template <typename T>
Node<T> *Node<T>::next() const {
	return next_node;
}

template <typename T>
class List {
private:
	Node<T> *list_head;
public:
	List() : list_head(0) {}
	bool empty() const;
	T front() const;
	void push_front(T element);
	void pop_front();
};

template <typename T>
bool List<T>::empty() const {
	return (list_head == 0);
}

template <typename T>
T List<T>::front() const {
	if (empty()) {
		return -1;
	}
	return list_head->retrieve();
}

template <typename T>
void List<T>::push_front(T element) {
	list_head = new Node<T>(element, list_head);
}

template<typename T>
void List<T>::pop_front() {
	if (empty()) {
		cout << -1 << endl;
		return;
	}
	T pop = front();
	Node<T> *ptr = list_head;
	list_head = list_head->next();
	delete ptr;
	cout << pop << endl;
}

int main() {
	List<int> list;
	list.push_front(9);
	cout << list.front() << endl;
	list.pop_front();
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.pop_front();
	list.pop_front();
	list.pop_front();
	cout << boolalpha;
	cout << list.empty() << endl;

}

