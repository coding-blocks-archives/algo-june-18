#include<cstring>
using namespace std;

template<typename T>
class node{
public:
	string key;
	T value;
	node<T>* next;

	node(string key,T value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
	~node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class Hashtable{
	node<T>**table;
	int tableSize;
	int currentSize;

	int hashFn(string key){
		int L = key.length();
		int p = 1;
		int ans = 0;

		for(int i=0;i<L;i++){
			ans = (ans + key[L-i-1]*p)%tableSize;
			p = (p*37)%tableSize;
		}
		return ans;
	}
	void rehash(){
		node<T>**oldTable = table;
		int oldTableSize = tableSize;
		
		table = new node<T>*[2*tableSize];
		tableSize *= 2;
		currentSize = 0;
		for(int i=0;i<tableSize;i++){
			table[i] = NULL;
		}
		//Iterate over over table and insert entries into new table
		for(int i=0;i<oldTableSize;i++){
			node<T>*temp = oldTable[i];

			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			if(oldTable[i]!=NULL){
				delete oldTable[i];
			}
		}
		delete [] oldTable;
	}

public:
	Hashtable(int defaultSize=7){
		tableSize = defaultSize;
		table = new node<T>*[tableSize];
		currentSize = 0;

		for(int i=0;i<tableSize;i++){
			table[i] = NULL;
		}
	}
	void insert(string key,T value){
		int index = hashFn(key);
		node<T> *n = new node<T>(key,value);

		//Insert at the head of ith Linked List
		n->next = table[index];
		table[index] = n;
		currentSize++;	

		float load_factor = currentSize/(1.0*tableSize);	
		if(load_factor>0.7){
			rehash();
		}

	}
	T* search(string key){
		int index = hashFn(key);

		node<T>*temp = table[index];
		while(temp!=NULL){
			if(temp->key==key){
				return &(temp->value);
			}
			temp = temp->next;
		}

		return NULL;
	}
	void print(){

		for(int i=0;i<tableSize;i++){
			node<T>* temp = table[i];
			cout<<"Bucket "<<i<<"=>";
			while(temp!=NULL){
				cout<<temp->key<<"->";
				temp = temp->next;
			}
			cout<<endl;
		}
		return;
	}
	void erase(string key){
		//Classwork... 5 mins


	}
	T& operator[](string key){
		T* temp = search(key);
		if(temp==NULL){
			T garbage;
			insert(key,garbage);
			temp = search(key);
			return *temp;
		}
		else{
			return (*temp);
		}
	}

};

