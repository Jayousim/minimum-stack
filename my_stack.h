
#ifndef UNTITLED1_MY_STACK_H
#define UNTITLED1_MY_STACK_H
#include <vector>
#include <cstdlib>
#include <stdexcept>
template<typename T>
class Stack{
public:
    Stack();
    void pop();
    T& top();
    const T& top()const;
    void push(const T& val);
    size_t size()const;

private:
    std::vector<T> data;

};

template<typename T>
Stack<T>::Stack() {

}

template<typename T>
void Stack<T>::pop() {
    if(data.size() > 0)
        data.pop_back();
    else
        throw std::exception();
}

template<typename T>
const T &Stack<T>::top()const {
    if(data.size() > 0){
        return data.back();
    }
    throw std::exception();
}

template<typename T>
T &Stack<T>::top(){
    return data.back();
}

template<typename T>
void Stack<T>::push(const T &val) {
    data.push_back(val);
}

template<typename T>
size_t Stack<T>::size() const{
    return data.size();
}

#endif //UNTITLED1_MY_STACK_H
