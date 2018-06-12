#include<iostream>
#include<cstring>
using namespace std;


int main(){

	//char a[1000] = "Hi- this. is.an.Algo++ class.";
	char a[10000];
	cin.getline(a,10000);

	char*ptr = strtok(a," -.");

	while(ptr!=NULL){
		cout<<ptr<<endl;
		ptr = strtok(NULL," -.");

	}
	
	return 0;
}