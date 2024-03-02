#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    std::vector<T> myvec;
};

template <typename T>
Stack<T>::Stack() {

}

template <typename T>
Stack<T>::~Stack() {}


template <typename T>
bool Stack<T>::empty() const {
    return myvec.empty();
}

template <typename T>
size_t Stack<T>::size() const {
    return myvec.size();
}

template <typename T>
void Stack<T>::push(const T& item) {
    myvec.push_back(item);
}

template <typename T>
void Stack<T>::pop() {
    if(this->empty()) {
        throw std::underflow_error("Underflow error");
    }
    myvec.pop_back();
}

template <typename T>
const T& Stack<T>::top() const {
    if(this->empty()) {
        throw std::underflow_error("Underflow error");
    }
    return myvec.back();
}

#endif