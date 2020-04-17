//
// Created by Hrayr on 4/8/2020.
//

#include "Connections.h"
#include "Helper.h"
#include <iostream>
using namespace std;

size_t *Connections::getPointer(size_t index) {
    return this->_connections[index];
}

size_t *Connections::getPointer(char *pointer) {
    size_t p_index = this->getPointerIndex(pointer);
    if (p_index == -1)
        return nullptr;
    return this->getPointer(p_index);
}

size_t Connections::getPointerIndex(char *pointer) {
//    char tmp, tmp_2;
    size_t pos = 0;
    size_t index = 0;
    if (this->count() == 0) {
        return -1;
    }
    while (pointer[pos] != '\0' && this->_pointers[index][pos] != '\0') {
        if (pointer[pos] != this->_pointers[index][pos]) {
            pos = 0;
            index++;
            if (index >= this->count()) {
                return -1;
            }
            continue;
        }
        pos++;
    }

    /*while ((memcpy(&tmp, pointer + pos, sizeof(char)) && memcpy(&tmp_2, (&this->_pointers[index]) + pos)) && tmp != '\0' && tmp_2 != '\0' && tmp != tmp_2) {
        if ((tmp != '\0' && tmp_2 == '\0' )|| (tmp == '\0' && tmp_2 != '\0')) {
            pos = 0;
            index++;
        }
        if (index > this->count()) {
            return -1;
        }
    }*/

    return index;
}

size_t Connections::createPointer(char *pointer) {
    // add it if does not exists
    size_t pointer_index = this->_count;
    // Allocate memory for title
    size_t pointer_size = Helper::sizeOfString(pointer);
    this->_pointers[pointer_index] = (char *) malloc(sizeof(char) * pointer_size);
    // and copy value of title to the allocated memory
    memcpy(this->_pointers[pointer_index], pointer, pointer_size * sizeof(char) + 1);
    this->_count++; // increment self count
    // Initialize element in _connections variable to be able store connections
    this->_connections[pointer_index] = new size_t[1];
    this->_connections[pointer_index][0] = 0;
    return pointer_index;
}

// First item is the count of all items in points list
bool Connections::add(char *title, char **points) {
    size_t pointer_index;
    // Check if pointer already in list
    if ((pointer_index = this->getPointerIndex(title)) == -1) {
        pointer_index = this->createPointer(title);
    }
    return this->add(pointer_index, points);
}

bool Connections::add(size_t index, char **points) {
    // First item is the count of all items in points list
    size_t count = static_cast<size_t*>(static_cast<void*>(points[0]))[0];

    // Lets walk over the items and add them one by one
    // Also add new items to the global pointers list
    for (size_t i = 1; i <= count; i++) {
        this->add(index, points[i]);
    }
    return true;
}

bool Connections::add(char *title, char *point) {
    int index1, index2;
    // Checks if element does not exists in the list
    if ((index1 = this->getPointerIndex(title)) == -1) {
        // Create the element
        index1 = this->createPointer(title);
    }
    // Checks if element does not exists in the list
    if ((index2 = this->getPointerIndex(point)) == -1) {
        // Create the element
        index2 = this->createPointer(point);
    }
    return this->add(index1, index2);
}

bool Connections::add(size_t index, char *point) {
    int index2; // position of element with title *point
    // Checks if element does not exists in the list
    if ((index2 = this->getPointerIndex(point)) == -1) {
        // Create the element
        index2 = this->createPointer(point);
    }
    return this->add(index, index2);
}

bool Connections::add(size_t index1, size_t index2) {
    this->_connections[index1][
            ++this->_connections[index1][0] // this is count of elements. Increment it and use it only after that so it will be the position of current element
            ] = index2;
    return true;
}

char *Connections::getTitle(size_t index) {
    if (index >= this->_count) {
        return nullptr;
    }
    return this->_pointers[index];
}


bool Connections::show() {
    for (size_t index=0; index < 1; ++index) {
        cout << this->_pointers[index] << " (" << this->_connections[index][0] << ") has connection with ";
        for (size_t j = 1; j < this->_connections[index][0]; ++j) {
            cout << this->_pointers[this->_connections[index][0]] << ", ";
        }
        cout << endl;
    }
    return true;
}

Connections::Connections() {
    this->_count = 0;
    this->_pointers = (char **) malloc(sizeof(char));
    this->_connections = (size_t **) malloc(sizeof(size_t));
}