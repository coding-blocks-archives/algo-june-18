#include<iostream>
#include<map>
using namespace std;

class node{
	char data;
	map<char,node*> m;
	bool isTerminal;
public:
	node(char d){
		data = d;
		isTerminal = false;
	}
	friend class Trie;
};

class Trie{
	node*root;
public:
	Trie(){
		root = new node('\0');
	}
	void addWord(char *word){

		node*temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->m.count(ch)==0){
				node* n = new node(ch);
				temp->m[ch] = n;
				temp = n;
			}
			else{
				temp  = temp->m[ch];
			}
		}
		temp->isTerminal = true;
	}
	bool search(char *word){
		node*temp = root;
		
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->m.count(ch)==0){
				return false;
			}
			else{
				temp  = temp->m[ch];
			}
		}
		return temp->isTerminal;
	}
};

int main(){
	Trie t;
	char words[100][10] = {"Apple","Ape","Mango","Men","No","News","Not"};
	for(int i=0;i<8;i++){
		t.addWord(words[i]);
	}
	char w[10];
	while(1){
		cin>>w;
		if(t.search(w)){
			cout<<w<<" found";
		}
		else{
			cout<<"Not found";
		}
	}


	return 0;
}