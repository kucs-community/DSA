//Polynomial Addition using linked lists
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

/*---manaul comparator function used to sort a 1
vector of pairs by second element of each pair----*/
bool com(const pair<int,int> a, const pair<int,int> b ){
            return a.second > b.second;
}

/**
 class to receive the input from console and format the input 
    to match the structue of a polynomial.
*/
class Interface {
    private:
        vector<pair<int,int>> poly1, poly2;
    public:
        void getInput();
        void sortInput(){sort(poly1.begin(), poly1.end(),com); sort(poly2.begin(), poly2.end(),com);};
        vector<pair<int,int>> getFirstPoly(){return poly1;};
        vector<pair<int,int>> getSecondPoly(){return poly2;};
};

// getting input from the user
void Interface::getInput(){

    int size = 0;

    cout<<"Enter the size of the first polynomial: ";
    cin>>size;

    poly1.resize(size);

    cout<<"Enter the coefficeints of the first polynomial: \n";
    for(int i =0; i < size; ++i)
        cin>>poly1[i].first;

    cout<<"Enter the exponents of the first polynomial: \n";
    for(int i =0; i < size; ++i)
        cin>>poly1[i].second;

    cout<<"Enter the size of the second polynomial: ";
    cin>>size;

    poly2.resize(size);

    cout<<"Enter the coefficeints of the second polynomial: \n";
    for(int i =0; i < size; ++i)
        cin>>poly2[i].first;

    cout<<"Enter the exponents of the second polynomial: \n";
    for(int i =0; i < size; ++i)
        cin>>poly2[i].second;
}

// class tp represent the polynomial term
class Node {
    private: 
        int coef;
        int exp;

    public:
        Node(int c,int e){coef=c; exp=e;};

        void setCoef(int c) {this->coef = c;} 

        void setexp(int e) {this->exp = e;}

        int getCoef() {return coef;}

        int getExp() {return exp;}
};

/* class to implement the addition of polynomials 
   using linked list
*/

class AdditionOfPoly {
    private:
        list<Node> polyList;

    public: 
        void addPoly(vector<pair<int,int>>,vector<pair<int,int>>);
        void print();
        
        list<Node> getPoly(){return polyList;};
};

/* This class takes two vectors of pairs as input
    and stores their sum in the linked list
*/
void AdditionOfPoly::addPoly(vector<pair<int,int>> poly1, vector<pair<int,int>> poly2) {
    
    int i = 0, j = 0;
    while(i < poly1.size() || j < poly2.size()){

        if(poly1[i].second > poly2[j].second){
            polyList.push_back(Node(poly1[i].first, poly1[i].second));
            i++;
        }
        else if(poly1[i].second < poly2[j].second){
            polyList.push_back(Node(poly2[j].first,poly2[j].second));
            j++;
        }
        else{
            polyList.push_back(Node(poly1[i].first+poly2[j].first,poly1[i].second));
            ++i;
            ++j;
        }

        if(i == poly1.size()){

            for(; j < poly2.size(); ++j){
                polyList.push_back(Node(poly2[j].first, poly2[j].second));
            }
        }
        
        if(j == poly2.size()){
            for(; i < poly1.size(); ++i){
                polyList.push_back(Node(poly1[i].first, poly1[i].second));
            }
        }
    }
}

// printing the linked list
void AdditionOfPoly::print(){

    for(auto x : polyList){
        cout<<x.getCoef()<<"X^"<<x.getExp()<<" + ";
    }
}

int main() {   

    Interface inter;
    
    inter.getInput();
    inter.sortInput();

    AdditionOfPoly add;

    add.addPoly(inter.getFirstPoly(), inter.getSecondPoly());

    add.print();

    return 0;
}
