#include<assert.h>
#include"MyVector.h"
using namespace std;


template<typename T>
MyVector<T>::MyVector() : _count(0),_capacity(DEFAULTSIZE) {
	pdata = new T[DEFAULTSIZE];
}

template<typename T>
MyVector<T>::MyVector(int size, T num) : _count(size){
	if (_count == 0) {
		_capacity = DEFAULTSIZE;
	}
	else {
		_capacity = size * EXTENDSIZE;
	}

	pdata = new T[_capacity];
	
	for (int i = 0; i < size; i++) {
		*(pdata + i) = num;
	}
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& origin) {
	_count = origin._count;
	_capacity = origin._capacity;
	pdata = new T[_capacity];
	for (int i = 0; i < _count; i++) {
		*(pdata + i) = *(origin.pdata + i);
	}
}

template<typename T>
MyVector<T>::~MyVector()
{
	delete[] pdata;
}

template<typename T>
void MyVector<T>::print() {
	cout << "_count : " << this->_count << endl;
	for (int i = 0; i < this->_count; i++) {
		cout << i << " : " << *(this->pdata+i) << endl;
	}
}

template<typename T>
void MyVector<T>::assign(const int size, T num) {

	if (this->_capacity <= size) {
		this->reassign(size * EXTENDSIZE);
	}
	
	this->_count = size;
	for (int i = 0; i < this->_count; i++) {
		*(this->pdata + i) = num;
	}
}

template<typename T>
T MyVector<T>::at(const int index) {
	assert(0 <= index && index < this->_count);
	return *(this->pdata + index);
}

template<typename T>
T MyVector<T>::operator[](const int index) {
	return *(this->pdata + index);
}

template<typename T>
void MyVector<T> ::clear() {
	this->_count = 0;
}

template<typename T>
void MyVector<T>::push_back(T data) {
	if (this->_count >= this->_capacity) {
		this->reassign(this->_count * EXTENDSIZE);
	}
	//*(this->pdata + this->_count) = data;
	this->pdata[this->_count] = data;
	this->_count++;

}

template<typename T>
T MyVector<T>::pop_back() {
	this->_count--;
	return *(this->pdata + this->_count);
}

template<typename T>
void MyVector<T>::resize(const int size, const T data) {
	if (size >= this->_capacity) {
		this->reassign(size * EXTENDSIZE);
	}
	if (this->_count >= size) {
		this->_count = size;
	}
	else {
		for (int i = this->_count; i < size;i++)
			*(this->pdata + i) = data;
		this->_count = size;
	}
}

template<typename T>
void MyVector<T>::insert(const int index, const T data) {
	if (this->_capacity <= this->_count) {
		this->reassign(this->_count * EXTENDSIZE);
	}
	for (int i = index; i < this->_count; i++) {
		*(this->pdata + i+ 1) = *(this->pdata + i);
	}
	*(this->pdata + index) = data;
	this->_count++;
}

template<typename T>
void MyVector<T>::insert(const int index, const int size, const T data) {
	if (this->_capacity <= this->_count + size) {
		this->reassign((this->_count + size) * EXTENDSIZE);
	}
	for (int i = index; i < this->_count + size - 1; i++) {
		*(this->pdata + i + size) = *(this->pdata + i);
	}
	for (int count = 0; count < size; count++) {
		*(this->pdata + index + count) = data;
	}
	this->_count += size;
}

template<typename T>
bool MyVector<T>::empty() {
	if (this->_capacity) {
		return true;
	}
	else {
		return false;
	}
}


template<typename T>
void MyVector<T>::reassign(const int size) {
	T* pdel = this->pdata;
	int pdelsize = this->_capacity;
	this->_capacity = size;
	this->pdata = new T[this->_capacity];
	for (int i = 0; i < pdelsize; i++) {
		*(this->pdata + i) = *(pdel + i);
	}
	delete[] pdel;
}