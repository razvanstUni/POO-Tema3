//
// Created by Razvan Statescu on 09/03/2018.
//

#ifndef PROIECT_POO_1_LIST_H
#define PROIECT_POO_1_LIST_H

/*
 * Definition of list node
 */

template <typename T>
struct List {
    T value;
    int priority;
    List<T> *next;

    List(T, int);
};

template <typename T>
List<T>::List(T value, int priority) {
    this->value = value;
    this->priority = priority;
    this->next = 0;
}

#endif //PROIECT_POO_1_LIST_H



