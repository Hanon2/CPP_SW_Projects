/*
==========================================
        Doubly Linked List Implementation
==========================================

Module name: doublylinkedlist.h
Author: Mohamed Abdelmoneim
Date: 09/19/2024

Key Features:
--------------

    - **doublylinkedlist**: A class that represents a doubly linked list with various operations.
    - **Node Structure**: Defines the basic node with pointers to previous and next nodes, and an integer data.
    - **Constructor**: Initializes an empty list.
    - **Copy Constructor**: Creates a deep copy of another doubly linked list.
    - **Assignment Operator**: Assigns the contents of another doubly linked list to this one, managing memory correctly.
    - **Destructor**: Cleans up all nodes to prevent memory leaks.
    - **push(int data)**: Adds an element to the end of the list.
    - **pop()**: Removes the last element from the list.
    - **size()**: Returns the number of elements in the list.
    - **print()**: Prints all elements in the list.
    - **at(int idx)**: Returns a reference to the data at the specified index.
    - **insert(int data, int idx)**: Inserts an element at a specified position.
    - **remove(int pos)**: Removes the element at a specified position.
*/
#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
using namespace std;
struct node
{
    int data;
    node * next; 
    node * prev;
};
class doublylinkedlist
{
    public: 
    doublylinkedlist()
    {
        head = nullptr; 
        tail = nullptr; 
    }
    doublylinkedlist(const doublylinkedlist& rhs);
    void operator=(const doublylinkedlist& rhs);
    ~doublylinkedlist();
    void push(int data); 
    void pop();
    int size() const;
    void print();
    int& at (int idx) const; 
    void insert (int data, int pos);
    void remove(int pos); 
    
    private:
    node* head; 
    node*tail;
};
#endif