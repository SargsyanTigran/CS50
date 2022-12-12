#include<iostream>

using namespace std;

struct Node{
	int data;
	Node *next;
};

class Queue{
	    public:
		Node *front,*rear;
	Queue(){front=rear=NULL;}

	void insert(int n);
	void delete_item();
	void display();
	~Queue();
};

void Queue::insert(int n){
	Node *temp=new Node;
	if(temp==NULL){
		cout<<"Overflow"<<endl;
		return;
	}
	temp->data=n;
	temp->next=NULL;

	//for first node
	if(front==NULL){
		front=rear=temp;
	}
	else{
		rear->next=temp;
		rear=temp;
	}
	cout<<n<<" has been inserted successfully."<<endl;
}

void Queue::display(){
	if(front==NULL){
		cout<<"Underflow."<<endl;
		return;
	}
	Node *temp=front;
	//will check until NULL is not found
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void Queue :: delete_item()
{
	if (front==NULL){
		cout<<"underflow"<<endl;
		return;
	}

	cout<<front->data<<" is being deleted "<<endl;
	if(front==rear)
		front=rear=NULL;
	else
		front=front->next;
}

Queue ::~Queue()
{
	while(front!=NULL)
	{
		Node *temp=front;
		front=front->next;
		delete temp;
	}
	rear=NULL;
}


int main(){
	Queue Q;
	return 0;
}

