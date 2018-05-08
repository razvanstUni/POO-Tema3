//
// Created by Razvan Statescu on 08/03/2018.
//

#ifndef PROIECT_POO_1_PQUEUE_H
#define PROIECT_POO_1_PQUEUE_H

#endif //PROIECT_POO_1_PQUEUE_H
#include "List.cpp"

/*
 * Definition of the list class
 */

template <typename T>
class PQueue {
    List<T> *list;
    List<T> *last;
    int elements;

    void freeList();

    public:
        PQueue();
        PQueue(PQueue&);
        ~PQueue();
        bool empty();
        void insert(T, int);
        T front();
        List<T>* pop();
        int size();
        int maxPriority();
        PQueue& operator+(const PQueue&);
        PQueue& operator++(int);
        PQueue& operator--(int);
        PQueue& operator=(const PQueue&);
};






