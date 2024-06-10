#include<iostream>
#include<vector>

using namespace std;

class Node {
    private:
        int val;
        Node* next;

    public:
        Node(int v){ 
            this->val = v;
        }

        void setVal(int v) {
            this->val = v;
        }

        void setNext(Node* n) {
            this->next = n;
        }

        int getVal() {
            return val;
        }
        Node* getNext() {
            return next;
        }
};

class CirQueue {
    private:
        Node* head;
        Node* tail;
        Node* prevTail;
        int size = 0;

    public:
        void add(int);
        void del();
        int getSize() {return size;}
        void display();

};

void CirQueue::add(int el) {
    Node* newNode = new Node(el);

    if(getSize() == 0) {
        head = newNode;
        prevTail = head;
        tail = head;
        size++;
        return;
    }

    Node* cur = head;
    for(int i = 1; i < getSize(); i++) {
        cur = cur->getNext();
    }

    prevTail = cur;
    tail = newNode;
    prevTail->setNext(tail);
    tail->setNext(head);
    size++;
}

void CirQueue::del() {
    if(getSize() == 0) {
        cout << "Queue is empty!";
        return;
    }

    Node* temp = head;
    head = temp->getNext();
    delete temp;

    size--;

}

void CirQueue::display() {
    Node* cur = head;
    for(int i = 1; i <= getSize(); i++) {
        cout << cur->getVal() << " ";
        cur = cur->getNext();
    }
}   

int main() {
    CirQueue q;

    q.add(5);
    q.add(9);
    q.add(1);
    q.add(8);

    q.del();
    q.del();
    q.del();
    q.del();
    q.del();

    cout << endl << q.getSize();


    q.display();
    return 0;
}