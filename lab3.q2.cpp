//include library
#include<iostream>
using namespace std;

//defining the class node 
class Node {
	public:
//making the pointer next and pointing it to null
	Node *next;
	int data;
	Node(){
		next=NULL;
	}
};

//making the constructor with pointers head and tail and pointing them to null

class cll{
	Node *head;
	Node *tail;
	public:
	cll(){
		head=NULL;
		tail=NULL;
	}

//making the0 desired functions
	void insert(int value);
	void insertat(int pos,int value);
	void del();
	void delat(int pos);
	int count();
	void display();
};

void cll::insert(int value){
	Node *ptr=new Node;
	ptr->data=value;
	if (head==NULL){
		head=ptr;
	}
	else{
		tail->next=ptr;
		ptr->next=head;
	}
	tail=ptr; 	
}

void cll::insertat(int pos,int value){
	
	cout<<"enter the position."<<endl;
	cin>>pos;
	cout<<"enter the value."<<endl;
	cin>>value;
	
	if( pos>(this->count()+1) ){
		cout<<"there is no suvh position"<<endl;
	}
	else{
		Node *ptr=new Node;
		ptr->data=value;
		int i=1;
		Node *current=head;
		while(i<pos-1){
			current=current->next;i++;
		}
		if(pos!=1){
			ptr->next=current->next;
			current->next=ptr;
		}
		else if(pos==1){
			ptr->next=current;
			head=ptr;
		}
	}
}

void cll::del(){
	Node *ptr=head;
	while(ptr->next!=tail){
		ptr=ptr->next;
	}
	tail=ptr;
	ptr=ptr->next;
	ptr->next=NULL;
	delete ptr;
	tail->next=head;
}

void cll::delat(int pos){
	if ( pos>this->count() ){
		cout<<"The linklist does not contain that many elements";
	}
	else{
		Node *ptr=head;
		int i=1;
		while(i<pos-1){
			ptr=ptr->next;i++;
		}
	
		Node *d=ptr->next;
		ptr->next=d->next;
		d->next=NULL;
		delete d;
	}
}

//counting the number of elements of the link list
int cll::count(){
	Node *ptr=head;
	int i=1;
	while (ptr!=tail){
		ptr=ptr->next;i++;
	}
	return i;
}

//displaying the link list
void cll::display(){
	Node *ptr=head;
	while(ptr!=tail){
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<ptr->data<<endl;
	
}

//include the main function
int main(){
	cll cl;

	cl.insert(1);

	cl.insert(2);

	cl.insert(3);

	cl.insert(4);

	cl.insert(5);

	cl.insert(6);

	cl.display();

	cl.insertat(3,9);

	cl.display();

	cl.insertat(5,7);

	cl.del();

	cl.display();

	cl.delat(3);

	cl.display();

	return 0;
}
