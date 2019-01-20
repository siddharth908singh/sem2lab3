//implement double link list using c ++
//including library
#include<iostream>
using namespace std;

//making the class node
class Node 
{
	public:
	Node *next;
	Node *prev;
	int data;
	Node()
	{
		next=NULL;
		prev=NULL;
	}
};

//making the constructor
class dll
{
//making pointers to the head and tail

	Node *head;
	Node *tail;
	public:
	dll()
	{
		head=NULL;
		tail=NULL;
	}
//including the required functios

	void insert(int value);

	void insertat(int pos,int value);

	void del();

	void delat(int pos);

	int count();

	void display();
};

//for instering the at the end
void dll::insert(int value)
{
	Node *ptr=new Node;
	ptr->data=value;
	if (head==NULL){
		head=ptr;
	}
	else{
		ptr->prev=tail;
	 	tail->next=ptr;
	}

	tail=ptr;
}

//for inserting at required positions

void dll::insertat(int pos,int value){
	
	if( pos>this->count() )
		cout<<"this number of elements is not in the linklist"<<endl;
	else{
		Node *temp=new Node;
		temp->data=value;
		if (pos==1){
			head->prev=temp;
			temp->next=head;
			temp->prev=NULL;
			head=temp;
		}
		else{	
			int i=1;
			Node* ptr=head;
			
			while(i<pos-1){
				ptr=ptr->next;i++;
			}
			temp->prev=ptr;
			temp->next=ptr->next;
			ptr->next=temp;
			
			if(temp->next!=NULL)
				temp->next->prev=temp;
		}
	}
}

//for deleting the elements of linl list from the end

void dll::del(){
	Node* ptr=head;
	while(ptr->next!=tail){
		ptr=ptr->next;
	}
	
	tail=ptr;
	ptr=ptr->next;
	tail->next=NULL;
	ptr->prev=NULL;
	
	delete ptr;
}

//for deleting at the reqiired positions

void dll::delat(int pos){
	if( pos>this->count() )
		cout<<"this number of elements is not present inn this linklis"<<endl;
	else{
		Node* ptr=head;int i=1;
		while(i<pos){
			ptr=ptr->next;i++;
		}
		
		if (ptr!=head){
			ptr->prev->next=ptr->next;
		}
		
		if (ptr!=tail){
			ptr->next->prev=ptr->prev;
		}
		
		ptr->next=NULL;
		ptr->prev=NULL;
		delete ptr;
	}
}

//for counting the number of elements of the link lidt

int dll::count(){
	Node *ptr=head;int i=0;
	while(ptr!=NULL){
		i+=1;
		ptr=ptr->next;
	}
return i;
}
//for displaying the linklist

void dll::display(){
	Node *ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<"->";
		ptr=ptr->next;
	}
	cout<<"NULL"<<endl;
}

//mentioning the main function

int main(){
	dll dl;
	
	dl.insert(1);
	
	dl.insert(2);

	dl.insert(3);

	dl.insert(4);

	dl.insert(5);

	dl.insert(6);

	dl.insert(7);

	dl.display();

	dl.insertat(3,8);

	dl.display();

	dl.insertat(8,9);

	dl.del();

	dl.display();

	dl.delat(5);

	dl.display();	

return 0;
}
