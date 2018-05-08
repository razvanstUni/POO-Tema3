//
// Created by Razvan Statescu on 11/03/2018.
//

/*
 * Implementation of the List class
 */

#include <iostream>
#include "PQueue.h";
using namespace std;

//Class constructor without params
template <typename T>
PQueue<T>::PQueue() {
    this->elements = 0;
}

//Copy constructor
template <typename T>
PQueue<T>::PQueue(PQueue<T>& list) {
    this->elements = 0;
    List<T> *q = list.list;
    while(q) {
        this->insert(q->value, q->priority);
        q = q->next;
    }
}

//Class destructor, where the memory gets freed
template <typename T>
PQueue<T>::~PQueue() {
    List<T> *list1 = this->list;
    List<T> *list2 = this->list;
    while(list2) {
        list1 = list1->next;
        delete list2;
        list2 = list1;
    }
}

//Override of the "+" operator
template <typename T>
PQueue<T>& PQueue<T>::operator+(const PQueue &l) {
    List<T> *list = l.list;
    PQueue<T> *newList = new PQueue<T>;
    while(list) {
        newList->insert(list->value, list->priority); newList->elements++;
        list = list->next;
    }
    list = this->list;
    while(list) {
        newList->insert(list->value, list->priority); newList->elements++;
        list = list->next;
    }
    return *newList;
}

//Override of the "=" operator
template <typename T>
PQueue<T>& PQueue<T>::operator=(const PQueue<T> &l) {
    List<T> *list = l.list;
    PQueue<T> *newList = new PQueue<T>;
    while(list) {
        newList->insert(list->value, list->priority);
        list = list->next;
    }
    this->list = newList->list;
    this->elements = l.elements;
    return *newList;
}

//Override of the "++" operator
template <typename T>
PQueue<T>& PQueue<T>::operator++(int) {
    List<T> *list = this->list;
    while(list) {
        list->priority++;
        list = list->next;
    }
    return *this;
}

//Override of the "--" operator
template <typename T>
PQueue<T>& PQueue<T>::operator--(int) {
    List<T> *list = this->list;
    list->priority--;
    while(list->next) {
        if(list->next->priority > list->priority)
            list->next->priority--;
        list = list->next;
    }
    this->freeList();
    return *this;
}

//Rmeove elements with negative priority from the list
template <typename T>
void PQueue<T>::freeList() {
    List<T> *q = list;
    while(q->priority < 0) q = this->pop();
    while(q->next) {
        if(q->next->priority < 0)
            q->next = q->next->next;
        q = q->next;
    }
}

//Get the number of elements in the list
template <typename T>
int PQueue<T>::size() {
    return this->elements;
}

//Check if the list is empty
template <typename T>
bool PQueue<T>::empty() {
    if(elements <= 0 || this->list == NULL) return true;
    return false;
}

//Insert an element into the list
template <typename T>
void PQueue<T>::insert(T x, int priority) {
    if(this->empty()) { //If the list is empty
        this->list = new List<T>(x, priority);
        last = list;
    } else {
        List<T> *newList;
        List<T> *q = list;
        newList = new List<T>(x, priority);
        if(priority <= this->list->priority) { //If the element is added at the beginning
            newList->next = list;
            list = newList;
        } else if( priority >= last->priority ) { //If the element is added at the end
            last->next = newList;
            last = newList;
        } else { //If the element is added in the middle
            while(q->next) {
                if( q->next->priority > priority ) {
                    newList->next = q->next;
                    q->next = newList;
                    break;
                }
                q = q->next;
            }
        }
    }

    this->elements++;
}

//Remove an element from the list
template <typename T>
List<T>* PQueue<T>::pop() {
    List<T> *q = this->list;
    this->list = this->list->next;
    delete q;
    return this->list;
}

template <typename T>
T PQueue<T>::front() {
    return this->list->value;
}

//Get the value of the highest priority
template <typename T>
int PQueue<T>::maxPriority() {
    List<T> *list = this->list;
    int max = list->priority; list = list->next;
    while(list) {
        if(max < list->priority) max = list->priority;
        list = list->next;
    }
    return max;
}