//Circular queue using array

#include<iostream>
#include<vector>

using namespace std;

class Queue{
    private:
        vector<int> q;
        int rear,front;
        int size;
    public:
        Queue(int s){size = s; q.resize(size);rear = front = -1;};
        void enQueue(int);
        void deQueue();
        bool empty(){return rear == -1 && front == -1;};
        bool full(){return rear == -1 && front == size-1;};
        void display();
};

void Queue::enQueue(int data){
    if(full()){
        cout<<"Queue is full!!!!"<<endl;
        return;
    }
    
    if(empty()) front++;

    q[++rear] = data;
}

void Queue::deQueue(){
    if(empty()){
        cout<<"Queue is empty!!!!"<<endl;
        return;
    }
    else if(front == rear){
        front = rear = -1;
        return;
    }

    ++front;    
}

void Queue::display(){

    if(empty()) return;
    
    int t = front;

    while(t != rear){
        cout<<q[t]<<" ";
        ++t;
    }
    cout<<q[t];
    cout<<endl;
}

int main(){
    Queue q(5);

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    q.display();


    q.deQueue();
    q.deQueue();
    q.deQueue();

    q.display();
    
   
    return 0;
}