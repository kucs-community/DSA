//doubly linked list

#include<bits/stdc++.h>

using namespace std;

class node{
	private:
		int data;
		node* next = NULL;
		node* prev = NULL;
	public:
		void set_data(int v){data=v;}
		void set_next(node* n){next=n;}
		void set_prev(node* n){prev=n;}
		
		int get_data(){return data;}
		node* get_next(){return next;}
		node* get_prev(){return prev;}
};

class List{
	private:
		node* head = NULL;
		node* tail = NULL;
		int len = 0;
	public:
		node* get_head(){return head;}
		int get_len(){return len;}
		node* get_tail() {
			return tail;
		}
		
		void insert_at_beg(int);
		void insert_at_end(int);
		void insert_at_pos(int,int);
		
		void del_at_beg();
		void del_at_end();
		void del_at_pos(int);
		
		void print_list();
};

void List::insert_at_beg(int data){
	
	node* newNode = new node;
	newNode->set_data(data);
	
	newNode->set_next(head);
	
	if(!head)
		tail = newNode;

	if(head)
		head->set_prev(newNode);
		
	head = newNode;
	len++;
}
	
void List::insert_at_end(int data){
	
	node* newNode = new node;
	newNode->set_data(data);
	
	if(head == NULL){
		tail = head = newNode;
		return;
		}

	tail->set_next(newNode);
	newNode->set_prev(tail);
	tail = newNode;
	
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
		
	node* s = head;
	
	node* newNode = new node;
	newNode->set_data(data);
	
	//seek s to pos-1
	for(int i = 1; i < pos-1; ++i){	
		s = s->get_next();
	}
	

	s->get_next()->set_prev(newNode); //
	newNode->set_next(s->get_next());
	s->set_next(newNode);
	newNode->set_prev(s);
	
	len++;	
}

void List::del_at_beg() {

	node *temp = head;
	if(len == 0) {
		cout << "The list is already empty"<< endl;
		return;
	}
	else if(len == 1)
	{
        head=NULL;
		tail=NULL;
	}
	
	head = head->get_next();
	head->set_prev(NULL);

	delete temp;

	len--; //Decrement the length of linked list by 1
}

void List::del_at_end() {
	if(len == 0){
		cout<<"List is already empty!!!"<<endl;
		return;
	}

	node* temp = tail;

	if(len == 1){
		tail = head = NULL;
	}
	else{
		tail = tail->get_prev();
		tail->set_next(NULL);
	}

	delete temp;
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
	temp->set_next(p->get_next()); //node is pos-1 is set to node at pos+1
	p->get_next()->set_prev(temp); //node at pos+1 is set to node at pos-1

	delete p;
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
	
	List dll;
	
	do{
		cout<<"List: ";
		dll.print_list();
		cout<<"\nSize: "<<dll.get_len()<<endl;

		cout<<"Operations: \n";
		cout<<"\t1: Insert at begining\n";
		cout<<"\t2: Insert at end\n";
		cout<<"\t3: Insert at at given position\n";
		cout<<"\t4: Delete at beginning\n";
		cout<<"\t5: Delete at end\n";
		cout<<"\t6: Delete at pos\n";
		cout<<"\t7: Exit\n";
		cout<<"\nEnter your choice: ";
		
		int ch;
		cin>>ch;

		switch(ch){
			case 1:
				dll.insert_at_beg(getInput());
				break;
			case 2:
				dll.insert_at_end(getInput());
				break;
			case 3:
				dll.insert_at_pos(getInput(),getPosition());
				break;

			case 4:
				dll.del_at_beg();
				break;

			case 5:
				dll.del_at_end();
				break;
				
			case 6:
				dll.del_at_pos(getPosition());
				break;

			case 7:
				exit(0);
		}

		getchar();
		getchar();

		system("cls");
		
	}while(true);
	
	return 0;
}
