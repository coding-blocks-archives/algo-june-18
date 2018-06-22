#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*next;
	
	node(int d){
		data = d;
		next = NULL;
	}
	~node(){
		if(next!=NULL){
			delete next;
		}
		cout<<"Deleting node "<<data<<endl;
	}
};

void insertAtHead(node*&head,int data){
	node* n = new node(data);
	n->next = head;
	head = n;
}
void insertInMiddle(node *&head,int data,int p){
	if(p==0){
		insertAtHead(head,data);
		return;
	}

	node*temp = head;
	int jumps = 1;
	while(jumps<=p-1){
		temp = temp->next;
		jumps++;
	}
	//Now insert the node
	node*n = new node(data);
	//Save the next node
	n->next = temp->next;
	//Updtae the  next of temp node
	temp->next = n;
	return;

}
void deleteAtHead(node *&head){

	node*temp = head;
	head = head->next;
	temp->next = NULL;
	delete temp;

}

void print(node*head){
	while(head!=NULL){
		cout<<head->data<<" =>";
		head = head->next;
	}
	cout<<"NULL";
}

//Search (HW) ->Recursive || Iterative 
bool isPresent(node*head,int key){
	if(head==NULL){
		return false;
	}
	//Rec Case
	if(head->data==key){
		return true;
	}
	return isPresent(head->next,key);
}
//Reverse a Linked List - Iterative Approach
void reverse(node *&head){
	node*prev=NULL;
	node*current= head;

	while(current!=NULL){
		node*NEXT = current->next;
		current->next = prev;
		prev = current;
		current = NEXT; 
	}
	head = prev;
	return;
}
//Recursively Reverse a Linked List 
node* reverseRec(node *head){
	//Base Case
	if(head->next==NULL){
		return head;
	}
	//Rec Case
	node* chotaHead = reverseRec(head->next);
	head->next->next = head;
	head->next = NULL;
	return chotaHead;
}
void buildLinkedList(node *&head){
	int d;
	cin>>d;
	while(d!=-1){
		insertAtHead(head,d);
		cin>>d;
	}
	return;
}

node*midPoint(node*head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	node* slow = head;
	node*fast = head->next;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;

}

//Kth Node from the last
node* merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	//Rec Case
	node*c;
	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;

} 

node* mergeSort(node*l){
	//merge sort
	if(l==NULL||l->next==NULL){
		return l;
	}
	//Rec Case
	node*mid = midPoint(l);
	node*a = l;
	node*b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);
	return merge(a,b);

}

int main(){

	node*head = NULL;
	buildLinkedList(head);
	print(head);
	//deleteAtHead(head);
	//head = reverseRec(head);
	head  = mergeSort(head);
	print(head);

	/*
	while(1){
		int d,p;
		cin>>d>>p;
		insertInMiddle(head,d,p);
		print(head);
	}
	*/

	return 0;
}