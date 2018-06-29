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

//Print at distance k
void printDistanceK(node*n,node*root,int k){
		//HW
}

//Preorder and Inorderṭ
node*buildFromArray(int *in,int*pre,int s,int e){
		
		static int index=0;
		if(s>e){
			return NULL;
		}

		node*root = new node(pre[index]);
		int data = pre[index];
		index += 1;

		//Leaf Node
		if(s==e){
			return root;
		}

		int j;
		for(j=s;j<=e;j++){
			if(in[j]==data){
				break;
			}
		}
		root->left = buildFromArray(in,pre,s,j-1);
		root->right = buildFromArray(in,pre,j+1,e);
		return root;

}


int main(){
	int pre[] = {1,2,3,4,5,6,7,9};
	int in[]  = {4,3,2,5,1,7,9,6};


	int n = sizeof(pre)/sizeof(int);
	node*root = buildFromArray(in,pre,0,n-1);
	levelOrder(root);
	
	return 0;
}