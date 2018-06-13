#include<iostream>
using namespace std;

int power(int a,int b){
	//Base Case
	if(b==0){
		return 1;
	}
	//Rec Case
	int commonTerm = power(a,b/2);
	commonTerm *= commonTerm;

	if(b&1){
		return a*commonTerm;
	}
	return commonTerm;
}

//Space Optimised O(1) , Complexity Time O(Log2(b))
int powerIterative(int a,int b){
	int res = 1;

	while(b){
		if(b&1){
			res = res*a;
		}
		b = b>>1;
		a = (a*a);
	}

}

int main(){

	int a,b;
	cin>>a>>b;

	cout<<power(a,b)<<endl;

	return 0;
}