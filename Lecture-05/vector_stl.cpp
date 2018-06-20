#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Vector is re-sizable array, it uses dynamic memory allocation internally to
grow and shrink it size. Treat it as array, you can insert elements at the end,
you can iterate over the elements, you can remove elements from the last.
Most common functions - 
push_back(d) - pushes d at the end
pop_back() - removes last elements
[i] or at() - accesses the ith element(reading)
clear() - which empties the vector container
reserve(size) - reserves min  'size' no elements itself

Vector expands itself to double when it full, this operation is expensive
in terms of time*/  

bool myComp(int a,int b){
	return a>b;
}

int main(){

	vector<int> v;
	v.reserve(100);

	 for (int i=1; i<=10; i++) 
	 		v.push_back(i);

	 v.pop_back();

	 sort(v.begin(),v.end(),myComp);

	  for(int i=0;i<v.size();i++){
	 	cout<<v[i]<<endl;
	 }

	 cout<<v.size()<<endl;
	 cout<<v.capacity()<<endl;
	 cout<<v.max_size()<<endl;

	 for(auto element:v){
	 	cout<<element<<endl;
	 }


	return 0;
}