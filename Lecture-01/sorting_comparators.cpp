#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool myCompare(string a,string b){
	if(a.length()==b.length()){
		return a>b;
	}
	return a.length()>b.length();
}

int main(){

	string s[100]= {"apple","mango","guava","banana"};
	sort(s,s+4,myCompare);

	for(int i=0;i<4;i++){
		cout<<s[i]<<endl;
	}

	return 0;
}