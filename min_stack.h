//
// Created by Jayou on 10/01/2021.
//

#ifndef UNTITLED1_MIN_STACK_H
#define UNTITLED1_MIN_STACK_H

#include "my_stack.h"
#include <cstdlib>

template<typename T>
class MinStack{
public:
    MinStack();
    void pop();
    T& top()const;
    void push(const T& val);
    size_t size()const;
    T getMin()const;

private:
    Stack<T> data;
    Stack<T> mins;
    Stack<int> mins_count;
};

template<typename T>
MinStack<T>::MinStack() {

}

template<typename T>
void MinStack<T>::pop() {
    if (data.top() == mins.top()){
        if (mins_count.top() > 1 )
            --mins_count.top();
        else{
            mins.pop();
            mins_count.pop();
        }
    }
    data.pop();

}

template<typename T>
T &MinStack<T>::top() const {
    return data.top();
}

template<typename T>
void MinStack<T>::push(const T &val) {
    data.push(val);
    if (mins.size() == 0 || val < mins.top()){
        mins.push(val);
        mins_count.push(1);
    }
    else if(val == mins.top())
        ++mins_count.top();

}

template<typename T>
size_t MinStack<T>::size()const {
    return data.size();
}

template<typename T>
T MinStack<T>::getMin()const {
    if (mins.size())
        return mins.top();
    return 0;
}

#endif //UNTITLED1_MIN_STACK_H
