#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListInterface.h"
#include "Node.h"

template <typename T>
class LinkedList: public LinkedListInterface<T> 
{
    private:
	Node<T>* head = nullptr;
	Node<T>* traverse;
	Node<T>* connection;
	Node<T>* temp;
	Node<T>* previous;
	Node<T>* next;

	int listCount = 0;
        
    public:
    ~LinkedList();
	LinkedList();
	LinkedList(const LinkedList<T> &oldList);

    void insert(int index, T entry);

    void removeByIndex(int index);

    void removeByValue(T value);

	void printList();

    T getEntry(int index) const;

    int length() const;

	bool isEmpty() const;

	bool find(T value) const;

	void appendList(LinkedList<T> toAppend);

	void reverse();
	
    void clear();

    void setEntry(int index, T entry);

};
#include "LinkedList.cpp"
#endif