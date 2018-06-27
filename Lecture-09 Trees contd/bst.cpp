#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;
	node(int d):data(d),left(NULL),right(NULL){}
};



void printTree(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printTree(root->left);
	printTree(root->right);
}
void printTreeIn(node*root){
	if(root==NULL){
		return;
	}
	printTreeIn(root->left);
	cout<<root->data<<" ";
	printTreeIn(root->right);
}
void printTreePost(node*root){
	if(root==NULL){
		return;
	}
	printTreePost(root->left);
	printTreePost(root->right);
	cout<<root->data<<" ";	
}

void printAtLevelK(node*root,int k){
	if(root==NULL||k<1){
		return;
	}
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
}
int height(node*root){
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	return max(h1,h2)+1;
}
void printAllLevels(node*root){
	int maxLevel = height(root);
	
	for(int k=1;k<=maxLevel;k++){
		printAtLevelK(root,k);
		cout<<endl;
	}
	return;
}

//Breadth First Traversal | level order iterative
void levelOrder(node *root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* n = q.front();
		if(n==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<n->data<<" ";

			if(n->left){
				q.push(n->left);
			}
			if(n->right){
				q.push(n->right);
			}
		}

	}
}


node* insert(node*root,int data){
	if(root==NULL){
		root = new node(data);
		return root;
	}
	else if(data<root->data){
		root->left  = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

node* build(){
	int d;
	cin>>d;
	node*root = NULL;

	while(d!=-1){
		root = insert(root,d);
		cin>>d;
	}
	return root;
}
node* search(node*root,int key){
//HW
}

//Deletion in BST
node* deleteNode(node*root,int key){
	if(root==NULL){
		return NULL;
	}

	if(root->data==key){
		if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
		}
		else if(root->left==NULL && root->right!=NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}
		else if(root->left!=NULL && root->right==NULL){
			node*temp = root->left;
			delete root;
			return temp;
		}
		else{
			//2 children
			//Right min node
			node*temp = root->right;
			while(temp->left!=NULL){
				temp  = temp->left;
			}
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
			return root;
		}


	}
	else if(root->data>key){
		root->left = deleteNode(root->left,key);

	}
	else{
		root->right = deleteNode(root->right,key);
	}
	return root;
}

bool isBST(node*root,int minV,int maxV){
	if(root==NULL){
		return true;
	}
	if(root->data>=minV && root->data<=maxV && isBST(root->left,minV,root->data) && isBST(root->right,root->data,maxV)){
		return true;
	}
	return false;
}

node* arrayToBST(int *a,int s,int e){
	if(s>e){
		return NULL;
	}
	int mid = (s+e)/2;
	node*root = new node(a[mid]);
	root->left = arrayToBST(a,s,mid-1);
	root->right = arrayToBST(a,mid+1,e);
	return root;
}

//BST To Sorted Linked List
class LinkedList{
public:
	node*head;
	node*tail;
	LinkedList():head(NULL),tail(NULL){}
};
LinkedList bstToLL(node*root){
	LinkedList l;
	if(root==NULL){
		return l;
	}

	if(root->left==NULL && root->right==NULL){
		l.head = l.tail = root;
		return l;
	}
	else if(root->left!=NULL &&root->right==NULL){
		LinkedList left = bstToLL(root->left);
		left.tail->right = root;
		l.head = left.head;
		l.tail = root;
		return l;
	}
	else if(root->right!=NULL && root->left==NULL){
		LinkedList right = bstToLL(root->right);
		root->right = right.head;
		l.head = root;
		l.tail = right.tail;
		return l;
	}
	else{
		LinkedList left,right;
		left = bstToLL(root->left);
		right = bstToLL(root->right);
		left.tail->right = root;
		root->right = right.head;
		l.head = left.head;
		l.tail = right.tail;
		return l;
	}
}


int main(){
	node*root = build();//buildTree();
	
	levelOrder(root);
	/*
	cout<<endl;
	printTreeIn(root);
	deleteNode(root,2);
	levelOrder(root);
	cout<<endl;

	deleteNode(root,10);
	levelOrder(root);
	cout<<endl;

	deleteNode(root,8);
	levelOrder(root);
	cout<<endl;
	
	*/
	LinkedList l = bstToLL(root);
	node*temp  = l.head;
	while(temp!=NULL){
		cout<<temp->data<<"-->";
		temp = temp->right;
	}
	cout<<endl;



	
	return 0;
}