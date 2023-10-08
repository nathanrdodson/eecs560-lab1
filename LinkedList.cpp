#include <iostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
LinkedList<T>::LinkedList()
{
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &oldList)
{
	for(int i = 1; i <= oldList.length(); i++)
	{
		insert(i,oldList.getEntry(i));
	}
}

template <typename T>
void LinkedList<T>::printList()
{
	for(int i = 1; i <= length(); i++)
		std::cout << getEntry(i)
				  << ' ';
	std::cout << '\n';
}

template <typename T>
void LinkedList<T>::insert(int index, T entry)
{
    Node<T>* newNode = new Node<T>(entry);
    traverse = head;
    if(index > listCount + 1 || index <= 0)
    {
        throw std::runtime_error("ERROR: Invalid insert, out of bounds\n");
    }    
    if(head == nullptr)
    {
        head = newNode;
        head->setNext(nullptr);
        listCount++;

    } else if(index == 1) {
                
        newNode->setNext(head);
        head = newNode;
        listCount++;

    } else {
        for(int i = 1; i <= index; i++)
        {  
            if(i == index-1)
            {
                newNode->setNext(traverse->getNext());
                traverse->setNext(newNode);
                listCount++;
                break;                
            } else {
                traverse = traverse->getNext();
            }            
        }
    }
}

template <typename T>
void LinkedList<T>::removeByIndex(int index)
{
    traverse = head;
    temp = nullptr;

    if(index > listCount + 1 || index <= 0)
    {
        throw std::runtime_error("ERROR: Invalid remove, out of bounds\n");
    }    
    if(head == nullptr)
    {
        throw std::runtime_error("ERROR: Cannot remove null\n");
    } else {
        for(int i = 1; i <= listCount; i++)
        {  
            if(i == index - 1)
            {                
                temp = traverse->getNext()->getNext();                
                delete traverse->getNext();
                traverse->setNext(temp);
                listCount--;
                break;                
            } else {
                traverse = traverse->getNext();
            }            
        }
    }
}

template <typename T>
void LinkedList<T>::removeByValue(T value)
{
    traverse = head;
    temp = nullptr;

    if(head == nullptr)
    {
        throw std::runtime_error("ERROR: Cannot remove null\n");
    } else if (head->getEntry() == value) {
		temp = head;
		head = traverse->getNext();
		delete temp;
		listCount--;
	} else {
        for(int i = 1; i <= listCount; i++)
        {  
            if(traverse->getNext()->getEntry() == value)
            {                
                temp = traverse->getNext()->getNext();                
                delete traverse->getNext();
                traverse->setNext(temp);
                listCount--;
                break;                
            } else {
                traverse = traverse->getNext();
            }            
        }
    }
}

template <typename T>
T LinkedList<T>::getEntry(int index) const
{
    Node<T>* traverse2 = head;
    if(index > listCount || index <= 0)
    {
        throw std::runtime_error("ERROR: Invalid getEntry, out of bounds\n");
    }    
    for(int i = 1; i <= index; i++)
    {  
        if(i == index)
        {
            break;
        } else {
            traverse2 = traverse2->getNext();
        }            
    }
    return traverse2->getEntry();
}

template <typename T>
int LinkedList<T>::length() const
{
    if(head == nullptr)
    {
        return 0;
    } else {
        return listCount;
    }
}

template <typename T>
void LinkedList<T>::reverse()
{
	traverse = head;
	previous = nullptr;
	next = nullptr;

	while(traverse != nullptr)
	{
		next = traverse->getNext();
		traverse->setNext(previous);
		previous = traverse;
		traverse = next;
	}
	head = previous;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return length() == 0 ? true : false;
}

template <typename T>
bool LinkedList<T>::find(T value) const
{
    Node<T>* traverse = head;              
	for(int i = 1; i < listCount; i++)
	{
		if(traverse->getEntry() == value)
		{
			return true;
		} else {
			traverse = traverse->getNext();
		}
	}
	return false;
}

template <typename T>
void LinkedList<T>::clear()
{
    for(int i = 1; i <= listCount; i++)
    {
        temp = head;
        head = head->getNext();
        delete temp;
    }
    listCount = 0;
}

template <typename T>
void LinkedList<T>::setEntry(int index, T entry)
{
    Node<T>* traverse2 = head;
    if(index > listCount || index <= 0)
    {
        throw std::runtime_error("ERROR: Invalid setEntry, out of bounds\n");
    }    
    for(int i = 1; i <= index; i++)
    {  
        if(i == index)
        {
            traverse2->setEntry(entry);
        } else {
            traverse2 = traverse2->getNext();
        }            
    }
}

template <typename T>
void LinkedList<T>::appendList(LinkedList<T> toAppend)
{
	for(int i = 1; i <= toAppend.length(); i++)
		insert(i,toAppend.getEntry(i));
	
}



