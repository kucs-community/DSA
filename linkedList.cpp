//linked list

#include<bits/stdc++.h>

using namespace std;

class node{
	private:
		int data;
		node* next = NULL;
	public:
		void set_data(int v){data=v;}
		void set_next(node* n){next=n;}
		
		int get_data(){return data;}
		node* get_next(){return next;}
};

class List{
	private:
		node* head = NULL;
		int len = 0;
	public:
		node* get_head(){return head;}
		int get_len(){return len;}
		
		void insert_at_beg(int);
		void insert_at_end(int);
		void insert_at_pos(int,int);
		
		void del_at_beg();
		void del_at_end();
		void del_at_pos(int);
		
		void reverse_list();
		bool search_list(int);
		void print_list();
};

void List::insert_at_beg(int data){
	
	node* newNode = new node;
	newNode->set_data(data);
	
	newNode->set_next(head);

	head = newNode;
	len++;
}
	
void List::insert_at_end(int data){
	
	node* newNode = new node;
	newNode->set_data(data);
	
	if(head == NULL){
		insert_at_beg(data);
		return;	
	}
		
	node* s = head;
	while(s->get_next()){
		s = s->get_next();
	}

	s->set_next(newNode);
	
	len++;
}

void List::insert_at_pos(int data, int pos){
	
	//for values less than 2 the funtion inserts values at position 2
	//to avoid this handle values less than 1 separately
	if(pos < 2){
		insert_at_beg(data);
		return;
	}

	if(pos >= len){
		insert_at_end(data);
		return;
	}
	
	node* newNode = new node;
	newNode->set_data(data);
	
	//take pointer s to the node at pos-1
	node* s = head;
	for(int i = 1; i < pos-1; ++i){	
		s = s->get_next();
	}
	
	newNode->set_next(s->get_next()); //newnode is pointing to pos+1
	s->set_next(newNode); //node at pos-1 is set to newnode
	
	len++;	
}

void List::del_at_beg() {

	if(len == 0) {
		cout << "The list is already empty"<< endl;
		return;
	}
	
	node* temp = head;

	head = head->get_next();
	
	delete temp;

	len--; //Decrement the length of linked list by 1
}

void List::del_at_end() {
	if(len == 0){
		cout<<"List is already empty!!!"<<endl;
		return;
	}

	node* temp = head;

	//seek temp to the n-1th node
	for(int i = 1; i < len-1; ++i){
		temp = temp->get_next();
	}

	delete temp->get_next();
	temp->set_next(NULL);

	len--;
}

void List::del_at_pos(int pos){
	
	if(len == 0){
		cout<<"List is already empty!!!"<<endl;
		return;
	}
	
	if(pos < 2){
		del_at_beg();
		return;
	}

	if(pos >= len){
		del_at_end();
		return;
	}

	node* temp = head;

	for(int i = 1; i < pos-1; ++i){
		temp = temp->get_next();	
	}

	node* p = temp->get_next(); //p is pointing to the node at pos we need to delete
	temp->set_next(p->get_next()); //the node at pos-1 is set to node at pos+1

	delete p; //delete the node at pos
}

void List::reverse_list(){

	node* cur = head;

	node* prev = NULL;      

	while(cur){
		
		head = cur; //if current node is the last node in the list
		node* next = cur->get_next(); //retain the address inside current node
		cur->set_next(prev); //set the current node to previous node in the list
		prev = cur; //the current node will the previous node in the next iteration
		cur = next; //the next next node in the list will the current node in the next iteration
		 
	}
}

bool List::search_list(int key){

	node *cur = head;

	while(cur) {
		if(cur->get_data() == key) {
			return true;
		}
		cur = cur->get_next();
	}

	return false;
}

void List::print_list(){
	
	node* s = head;
	
	while(s){
		cout<<s->get_data()<<" ";
		s = s->get_next();
	}
	cout<<endl;
}


int getInput() {
	int val;
	cout<<"Enter an integer value: ";
	cin>>val;

	return val;
}

int getPosition() {
	int val;
	cout<<"Enter an valid position: ";
	cin>>val;

	return val;
}

int main(){
	
	List LL;
	
	do{
		system("cls");
		cout<<"List: ";
		LL.print_list();
		cout<<"Size: "<<LL.get_len()<<endl;

		cout<<"Operations: \n";
		cout<<"\t1: Insert at begining\n";
		cout<<"\t2: Insert at end\n";
		cout<<"\t3: Insert at at given position\n";
		cout<<"\t4: Delete at beginning\n";
		cout<<"\t5: Delete at end\n";
		cout<<"\t6: Delete at pos\n";
		cout<<"\t7: Reverse List\n";
		cout<<"\t8: Search an element\n";
		cout<<"\t9: Exit\n";
		cout<<"\nEnter your choice: ";
		
		int ch;
		cin>>ch;

		switch(ch){
			case 1:
				LL.insert_at_beg(getInput());
				break;
			case 2:
				LL.insert_at_end(getInput());
				break;
			case 3:
				LL.insert_at_pos(getInput(),getPosition());
				break;

			case 4:
				LL.del_at_beg();
				break;

			case 5:
				LL.del_at_end();
				break;
				
			case 6:
				LL.del_at_pos(getPosition());
				break;

			case 7:
				LL.reverse_list();
				break;

			case 8:
				if(LL.search_list(getInput())) {
					cout << "Element is present.\n";
				} else {
					cout << "Element not present.\n";
				}
				getchar();
				break;

			case 9:
				exit(0);
		}

		getchar();

		system("cls");
		
	}while(true);
	
	return 0;
}
