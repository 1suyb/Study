#pragma once

template<typename T>
class  LinkNode
{
public:
	LinkNode();
	LinkNode(T data);
	LinkNode(LinkNode&);
	~LinkNode() {  };
	T data;
	LinkNode* next;
	LinkNode* previous;

};


template<typename T>
class  LinkedList
{
private:
	int count;
	LinkNode<T>* head;
	LinkNode<T>* tail;

public:
	LinkedList();
	LinkedList(const int size);
	LinkedList(const int size, T data);
	LinkedList(const LinkedList*);
	~LinkedList() { delete head; delete tail; };

	void print();

	void assign(const int size, T data);
	T front() { return this->head->data; }
	T back() { return this->tail->data; };
	void push_back(T data);
	void push_front(T data);
	T pop_back();
	T pop_front();
	LinkNode<T>* insert(LinkNode<T>* pinsert, T data);
	LinkNode<T>* erase(LinkNode<T>* premove);

	LinkNode<T>* search(T data);
	void clear();

	int size() { return count; }
	void remove(T removedata);
	void reverse();
	void unique();

private : 
	

};

