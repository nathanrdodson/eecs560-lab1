#ifndef LINKEDLISTINTERFACE_H
#define LINKEDLISTINTERFACE_H

#include "LinkedList.h"

// adapted from my own EECS268 lab 5 "browser history" implementation of a linked list.

template <typename T>
class LinkedListInterface
{
    public:
	virtual ~LinkedListInterface() {}

	virtual void insert(int index, T entry) = 0;

	virtual void removeByIndex(int index) = 0;

	virtual void removeByValue(T value) = 0;
	
	virtual T getEntry(int index) const = 0;

	virtual int length() const = 0;

	virtual bool isEmpty() const = 0;

	virtual bool find(T value) const = 0;

	virtual void clear() = 0;

	virtual void reverse() = 0;

	virtual void setEntry(int index, T entry) = 0;

};
#endif