#include"LinkedList.h"
using namespace std;

template<typename T>
LinkNode<T>::LinkNode() {
	this->previous = nullptr;
	this->next = nullptr;
}

template<typename T>
LinkNode<T>::LinkNode(T data) {
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}
template<typename T>
LinkNode<T>::LinkNode(LinkNode& origin) {
	this->data = origin.data;
	this->previous = origin.previous;
	this->next = origin.next;
}

template<typename T>
LinkedList<T>::LinkedList() {
	this->count = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(const int size) {
	LinkNode<T>* nodest = new LinkNode<T>();
	this->head = nodest;
	this->tail = nodest;

	for (int i = 1; i < size; i++) {
		LinkNode<T>* node = new LinkNode<T>();
		this->head->previous = node;
		node->next = this->head;
		this->head = node;
	}
	this->count = size;
}

template<typename T>
LinkedList<T>::LinkedList(const int size, T data) {
	LinkNode<T>* nodest = new LinkNode<T>(data);
	this->head = nodest;
	this->tail = nodest;
	for (int i = 1; i < size; i++) {
		this->push_front(data);
	}
	this->count = size;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList* origin) {
	LinkNode<T>* node = new LinkNode<T>(origin->tail);
	this->head = node;
	this->tail = node;
	for (; node->previous != nullptr;) {
		node = node->previous;
		this->push_front(node->previous->data);
	}
	this->count = origin->count;

}

template<typename T>
void LinkedList<T>::print() {
	cout << "Size : " << this->count << endl;
	for (LinkNode<T>* node = this->head; node != nullptr; node = node->next) {
		cout << node->data << endl;
	}
	cout << endl;
}

template<typename T>
void LinkedList<T>::assign(const int size, T data) {
	if (this->count > 0) {
		this->clear();
	}
	LinkNode<T>* node = new LinkNode<T>(data);
	this->head = node;
	this->tail = node;
	for (int i = 1; i < size; i++) {
		this->push_front(data);
	}
	this->count = size;
}

template<typename T>
void LinkedList<T>::push_back(T data) {
	LinkNode<T>* node = new LinkNode<T>(data);
	if (this->tail == nullptr) {
		this->head = node;
		this->tail = node;
		this->count++;
		return;
	}
	this->tail->next = node;
	node->previous = this->tail;
	this->tail = node;
	this->count++;
}

template<typename T>
void LinkedList<T>::push_front(T data) {
	LinkNode<T>* node = new LinkNode<T>(data);
	if (this->tail == nullptr) {
		this->head = node;
		this->tail = node;
		this->count++;
		return;
	}
	this->head->previous = node;
	node->next = this->head;
	this->head = node;
	this->count++;
}

template<typename T>
T LinkedList<T>::pop_back() {
	LinkNode<T>* preturn = this->tail;
	int datareturn = preturn->data;

	this->tail = this->tail->previous;
	this->tail->next = nullptr;

	delete preturn;

	return datareturn;
}

template<typename T>
T LinkedList<T>::pop_front() {
	LinkNode<T>* preturn = this->head;
	int datareturn = preturn->data;

	this->head = this->head->next;
	this->head->previous = nullptr;

	delete preturn;
	
	return datareturn;
}

template<typename T>
LinkNode<T>* LinkedList<T>::insert(LinkNode<T>* pinsert, T data) {
	LinkNode<T>* node = new LinkNode<T>(data);
	node->next = pinsert->next;
	pinsert->next = node;
	node->previous = pinsert;
	node->next->previous = node;
	return node;
}

template<typename T>
LinkNode<T>* LinkedList<T>::erase(LinkNode<T>* premove) {
	if (premove == nullptr) {
		return nullptr;
	}
	LinkNode<T>* returnp = premove->next;
	premove->previous->next = premove->next;
	premove->next->previous = premove->previous;
	delete premove;
	this->count--;
	return returnp;
}

template<typename T>
void LinkedList<T>::clear() {
	LinkNode<T>* pdel = nullptr;
	for (LinkNode<T>* node = this->head; node != nullptr;) {
		pdel = node;
		node = node->next;
		delete pdel;
	}
	this->count = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

template<typename T>
LinkNode<T>* LinkedList<T>::search(T data) {
	for (LinkNode<T>* node = this->head; node != nullptr; node = node->next) {
		if (node->data == data) {
			return node;
		}
	}
	return nullptr;
}

template<typename T>
void LinkedList<T>::remove(T data) {
	while (this->erase(this->search(data)) != nullptr) {

	}
	
}

template<typename T>
void LinkedList<T>::reverse() {
	LinkNode<T>* node;
	LinkNode<T>* nextnode;
	node = this->tail;
	this->head = node;
	while (true) {
		nextnode = node->previous;
		node->previous = node->next;
		node->next = nextnode;
		node = nextnode;
		if (nextnode == nullptr) {
			break;
		}
	}
	this->tail = node;
}

template<typename T>
void LinkedList<T>::unique() {
	LinkNode<T>* node = nullptr;
	LinkNode<T>* delnode = nullptr;
	for (node = this->head; node->next != nullptr;) {
		if (node->data == node->next->data) {
			delnode = node;
			node = this->erase(node);
		}
		else {
			node = node->next;
		}

	}
}

