#include "queue.h"
#include <iostream>
using namespace std;

// Constructor implementation
ListQueue::ListQueue()
{
    // TODO: Initialize front_node and rear_node
    front_node = nullptr;
    rear_node = nullptr;
    // TODO: Initialize current_size to 0
    current_size = 0;

}

// Destructor implementation
ListQueue::~ListQueue()
{
    // TODO: Deallocate all nodes in the linked list

    clear();
    // TODO: Consider using the clear() method

}

// Enqueue implementation (add an item at the rear of the queue)
void ListQueue::enqueue(int item)
{
    // TODO: Create a new node with the given item
    Node* new_node = new Node(item);

    // TODO: Link the new node to the rear
    if (rear_node != nullptr) {
        rear_node->next = new_node;
    } else {
        front_node = new_node; // If the queue was empty, front also points to the new node
    }

    // TODO: Update the rear_node
    rear_node = new_node;
    // TODO: Increment the current size
    current_size++;
}

// Dequeue implementation (remove an item from the front of the queue)
int ListQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    if (empty()) {
        cout << "Error: Queue is empty. Cannot dequeue." << endl;
        return -1; 
    }
    // TODO: Store the data from the front node
    int front_data = front_node->data;
    Node* temp = front_node;
    // TODO: Update the front pointer to the next node
    front_node = front_node->next;
    

    // TODO: Update the rear pointer if the queue becomes empty
    if (front_node == nullptr) {
        rear_node = nullptr;
    }
    // TODO: Delete the old front node
    delete temp;

    // TODO: Decrement current_size
    current_size--;
    // TODO: Return the stored data
    return front_data;
}

// Clear implementation (delete all elements)
void ListQueue::clear()
{
    // TODO: Traverse the linked list and delete each node
    Node* current = front_node;
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
    // TODO: Reset front and rear pointer
    front_node = nullptr;
    rear_node = nullptr;
    // TODO: Reset current_size to 0
    current_size = 0;
}

// Size implementation (return the current number of elements)
int ListQueue::size() const
{
    // TODO: Return the current size (current_size)
    return current_size;
}

// Front implementation (get the element at the front of the queue)
int ListQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if (empty()) {
        cout << "Error: Queue is empty. Cannot access front." << endl;
        return -1; 
    }
    // TODO: Return the data from the front node without removing it
    return front_node->data;
     
}

// Back implementation (get the element at the back of the queue)
int ListQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    if (empty()) {
        cout << "Error: Queue is empty. Cannot access back." << endl;
        return -1; 
    }
    // TODO: Return the data from the back node without removing it
    return rear_node->data;
}

// Empty implementation (check if the queue is empty)
bool ListQueue::empty() const
{
    // TODO: Return whether front is nullptr
    return front_node == nullptr;
}

// Print implementation (print elements from front to rear)
string ListQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    string str = "<";;
    Node* current = front_node;
    int count = 0;
    while (current != nullptr) {
        str += to_string(current->data);
        count++;
        if (count < current_size) {
            str += ", ";
        }
        current = current->next;
    }
    str += "|>";
    return str;
    // TODO: Traverse the linked list from front

}
