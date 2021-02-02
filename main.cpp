#include <iostream>

#include "min_stack.h"
#include <assert.h>
void test1(){
    MinStack<int> s1;
    s1.push(2);
    /* stack = 1, */
    assert(s1.getMin()  == 2);
    s1.push(1);
    assert(s1.getMin()  == 1);

    s1.push(0);
    assert(s1.getMin()  == 0);
    s1.push(1);
    s1.push(-1);
    assert(s1.getMin()  == -1);
    s1.pop();
    s1.pop();
    assert(s1.getMin()  == 0);
    s1.pop();
    assert(s1.getMin()  == 1);
    s1.pop();
    assert(s1.getMin()  == 2);
}


void test2(){
    MinStack<int> s1;
    s1.push(1);
    assert(s1.getMin()  == 1);
    s1.push(1);

    s1.push(0);

    assert(s1.getMin()  == 0);

    s1.push(-1);
    assert(s1.getMin()  == -1);
    s1.pop();
    assert(s1.getMin()  == 0);
    s1.pop();
    assert(s1.getMin()  == 1);
    s1.pop();
    assert(s1.getMin()  == 1);
}
void test_empty_pop(){
    MinStack<int> s1;
    s1.push(1);
    s1.pop();
    try{
        s1.pop();
    }
    catch (std::exception& e) {

    }
}
int main() {
    test1();
    test_empty_pop();
    test2();
    return 0;
}
