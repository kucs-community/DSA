#include<iostream>
using namespace std;

const int ARRAY_SIZE = 50;

class Stack {
    private:
        int size = 0;
        int arr[ARRAY_SIZE];

    public:
        void push(int val);
        void pop();
        int peek();
        bool empty();
        bool full();
};

bool Stack::empty() {
    if(size >= ARRAY_SIZE) return true;

    return false;
}

bool Stack::full() {
    if(size <= 0) return true;

    return false;
}

void Stack::push(int val) {
    if(full()) return;

    arr[size] = val;
    size++;
}

void Stack::pop() {
    if(empty()) return;

    arr[size] = NULL;
    size--;
}

int Stack::peek() {
    return arr[size];
}

int main() {

    return 0;
}