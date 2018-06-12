#include<iostream>
#include<cstring>
using namespace std;

int main(){

	string s("hello");
	string s2 = "world";
	cout<<s + s2<<endl;



	string suser;
	//cin>>suser;
	getline(cin,suser);
	cout<<suser<<endl;



	return 0;
}