#pragma once

template<typename T>
class MyVector
{
public:
	T* pdata;

private:
	static const int DEFAULTSIZE = 1;
	static const int EXTENDSIZE = 2;
	int _capacity;
	int _count;


public:
	MyVector();
	MyVector(int size);
	MyVector(int size, T num);
	MyVector(const MyVector&);
	~MyVector();

	int Capacity() { return _capacity; }
	int Size() { return _count; }

	void print();

	void assign(const int, T);
	T at(const int);
	T operator[](const int);

	T front() { return *(this->pdata); }
	T back() { return *(this->pdata + this->_count); }

	void clear();
	void push_back(T);
	T pop_back();

	void resize(const int, const T);

	void insert(const int, const T);
	void insert(const int, const int size, const T);

	bool empty();

private:
	void reassign(const int);
};