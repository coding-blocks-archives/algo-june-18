#include<iostream>
#include<set>
#include<cstring>
using namespace std;

set<string> s;

void findSubsets(char *in,char *out,int i,int j){
	//Base Case
	if(in[i]=='\0'){
		out[j] = '\0';
		//cout<<out<<endl;
		string temp(out);
		s.insert(temp);

		return;
	}
	//Rec Case
	//1. Include
	out[j] = in[i];
	findSubsets(in,out,i+1,j+1);
	//2.Exclude
	findSubsets(in,out,i+1,j);
}

int main(){

	char in[100];
	cin>>in;
	char out[100];
	findSubsets(in,out,0,0);

	for(auto it=s.begin();it!=s.end();it++){
		cout<<(*it)<<endl;
	}



	return 0;
}