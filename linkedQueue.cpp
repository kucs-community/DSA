//Queue using linked list

#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Queue{
    private:
        list<int> q;
    public:
        void enQueue(int);
        void deQueue();
        bool empty(){return q.size() == 0;};
        void display();
};

void Queue::enQueue(int data){
    
    q.push_back(data);
}

void Queue::deQueue(){

    q.pop_front();    
}

void Queue::display(){

    for(auto it : q){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    Queue q;

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