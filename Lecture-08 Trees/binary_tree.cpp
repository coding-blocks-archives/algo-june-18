#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;
	node(int d):data(d),left(NULL),right(NULL){}
};

node*buildTree(){
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}
	node*n = new node(d);
	n->left = buildTree();
	n->right = buildTree();
	return n;
}

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
//Level Order Build - Input 
node* buildLevelOrder(){

	cout<<"Enter root data";
	int d;
	cin>>d;
	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node*n  = q.front();
		q.pop();
		cout<<"Enter children of "<<n->data<<" ";
		int c1,c2;
		cin>>c1>>c2;
		if(c1!=-1){
			n->left = new node(c1);
			q.push(n->left);
		}
		if(c2!=-1){
			n->right = new node(c2);
			q.push(n->right);
		}

	}

	return root;
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
int replaceSum(node*root){
	//Base Case
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}

	int temp = root->data;
	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);
	root->data = leftSum + rightSum;
	return temp + root->data;
}

void mirror(node *root){
	if(root==NULL){
		return;
	}
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}

//You have to check if a tree is height balanced
class Pair{
public:
	bool balance;
	int height;
};

Pair isHeightBalanced(node*root){
	Pair p;
	if(root==NULL){
		p.balance = true;
		p.height = 0;
		return p;
	}
	//Rec Case
	Pair left = isHeightBalanced(root->left);
	Pair right = isHeightBalanced(root->right);

	if(left.balance && right.balance && abs(left.height-right.height)<=1)
		p.balance = true;
	else
		p.balance = false;
	p.height = max(left.height,right.height) +1;
	return p;
}


int main(){
	node*root = buildLevelOrder();//buildTree();
	/*
	printTree(root);
	cout<<endl;
	printTreeIn(root);
	cout<<endl;
	printTreePost(root);*/
	//cout<<height(root);
	//printAtLevelK(root,3);
	//printAllLevels(root);
	levelOrder(root);
	return 0;
}