#include<iostream>
using namespace std;

//Space Time Complexity 
//Optimise uisng dp (later..)
int tiles(int n){
	if(n>=0&&n<=3){
		return 1;
	}
	return tiles(n-1) + tiles(n-4);
}

int main(){

	int n;
	cin>>n;
	cout<<tiles(n)<<endl;

	return 0;
}