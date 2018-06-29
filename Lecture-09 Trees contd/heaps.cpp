#include<iostream>
#include<vector>
using namespace std;


class Heap{
		vector<int> v;
		bool minType;
		
		bool cmp(int a,int b){
			if(minType){
				return a>b;
			}
			return a<b;
		}
		void heapify(int index){

				int left = 2*index;
				int right = left+1;

				int minIndex = index;
				if(left<v.size() and cmp(v[index],v[left])){
					minIndex = left;
				}
				if(right<v.size() and cmp(v[minIndex],v[right])){
					minIndex = right;
				}

				if(minIndex!=index){
						swap(v[index],v[minIndex]);
						heapify(minIndex);
				}
				return;
		}
	
	public:
		Heap(bool mH=true){
				minType = mH;
				v.reserve(100);
				v.push_back(-1);
		}
		void push(int data){

			v.push_back(data);
			int index = v.size() - 1;
			int parent = index/2;
			while(index>1 && cmp(v[parent],v[index])){
				swap(v[parent],v[index]);
				index = parent;
				parent = parent/2;
			}
		}
		int top(){
			return v[1];
		}
		void pop(){
			//Removes the top element
			int last = v.size()-1;
			swap(v[1],v[last]);
			v.pop_back();
			heapify(1);
		}
		bool isEmpty(){
			return v.size()==1;
		}

};


int main(){

	int arr[] = {7,8,9,1,2,5,4};
	int n = sizeof(arr)/sizeof(int);

	Heap h;
	for(int i=0;i<n;i++){
		h.push(arr[i]);
	}

	while(not h.isEmpty()){
		cout<<h.top()<<endl;
		
		h.pop();
	}

	return 0;
}