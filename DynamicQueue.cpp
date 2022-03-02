#include "DynamicQueue.h"
#include <iostream>
#include <stdlib.h>


//-------------------------------------------------------------------------------
// constructors
DynamicQueue::DynamicQueue() {
    front = nullptr;
    rear = nullptr;
}

//---------------------------------------------------------------
// methods (inserts and deletes)

// check if queue is empty
bool DynamicQueue::empty() {
    return (front == nullptr);
}

// insert at the rear of the queue
void DynamicQueue::insert(char x) {
    DynamicNode* p = new DynamicNode;
    p->info =x;
    p->next = nullptr;
    if (empty()) {
        front = p;
    }
    else {
        rear->next = p;
    }
    rear = p;


}

// remove from the front of the queue
char DynamicQueue::remove() {
    if (empty()) {
        std::cout << "queue underflow";
        exit(1);
    }

    DynamicNode* p = front;
    int temp = p->info;
    front = p->next;
    delete p;
    if (front == nullptr)
        rear = nullptr;

    return temp;
}


// check if key is present is Queue
bool DynamicQueue::keyInQueue(char x) {
    DynamicNode * p = front;
    for (p; p!= nullptr; p = p->next){
        if (p->info == x){
            return true;
        }
    }
    return false;
}


// print queue
void DynamicQueue::print() {
    if (empty()) {
        std::cout << "Empty " << std::endl;
    }
    else {

        DynamicNode *p = front;
        while (p != nullptr) {
            std::cout << p->info;
            if (p->next != nullptr) {
                std::cout << "->";
            }
            else {
                std::cout << "\n";
            }
            p = p->next;
        }
    }
}

// check if queue is full
bool DynamicQueue::full() {
    int count = 0;
    DynamicNode * p = front;
    for (p; p->next != nullptr; p = p->next) {
        count +=1;
    }

    if (count == QUEUESIZE -1) {
        return true;
    }
    else {
        return false;
    }

}

// used to remove elements already present in the queue
void DynamicQueue::findAndRemove(char x) {
    DynamicNode* p = front; // p is the first node
    DynamicNode* q = nullptr; // q will be the one behind p, null for now
    while (p != nullptr) { // traverse the list
        if (p->info == x) { // you found it
            p = p->next;
            if (q == nullptr) {
                remove(); // remove first node of the list
            }
            else {
                deleteAfter(q); // q is before p, p has info=x
            }
        }
        else {
            // advance to next node of list
            q = p;
            p = p->next;
        }
    } // end while
} // end findAndRemove


// deletes node after p
char DynamicQueue::deleteAfter(DynamicNode *p) {
    if(p == nullptr || p->next == nullptr)  {
        std::cout << "void deletion" << std::endl;
        exit(1);
    }

    DynamicNode* q = p->next; // q is a temp to the next of p
    int temp = q->info;       // info to be returned
    p->next = q->next;        // update the next

    //if p->next is null make rear p
    if(p->next == nullptr){
        rear = p;
    }

    delete q;                 // delete actual node in memory
    return temp;    // return info of deleted node

}

// method used to check queues and insert keys
void DynamicQueue::checkQueueAndInsert(char x) {

    //if queue is empty, insert in rear
    if(empty()){
        insert(x);
        std::cout << "Inserting " << x << " in rear. ";
        return;
    }

    // if key already in queue
    if(keyInQueue(x)){
        // if key already in rear, return
        DynamicNode * p = rear;
        if (p->info == x) {
            std::cout << x << " is already rear. ";
            return;
        }
        // else remove x from previous position and insert at rear
        else {
            findAndRemove(x); // remove that x
            insert(x);  // insert in rear
            std::cout << "Moving " << x << " to rear. ";
        }
    }
    //if keys not in queue
    else{
        //if queue not full
        if(!full()){
            insert(x);  // if not full insert at rear;
            std::cout << "Inserting " << x << " in rear. ";
        }
        // if full
        else{
            remove();   //if full remove front
            insert(x);  // insert in the rear
            std::cout << "Q is full, removing front. Inserting " << x << " in rear. ";
        }
    }

}