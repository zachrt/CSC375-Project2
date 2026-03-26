#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class Stack {
private:
    int top;
    int capacity;
    T* array;

public:
    Stack(int size = 100) {
        capacity = size;
        top = -1;
        array = new T[capacity];
    }

    ~Stack() {
        delete[] array;
    }

    void push(T item) {
        if (top < capacity - 1) {
            array[++top] = item;
        } else {
            cout << "Stack Overflow!" << endl;
        }
    }

    T pop() {
        if (top >= 0) {
            return array[top--];
        }
        return T();
    }

    T peek() {
        if (top >= 0) {
            return array[top];
        }
        return T();
    }

    bool isEmpty() {
        return top == -1;
    }
};

#endif // STACK_H