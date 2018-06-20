#include<iostream>
using namespace std;

int dp[100][100] = {0};

int f(int i,int j,int *p,int y){
	//Base Case
	if(i>j){
		return 0;
	}
	if(dp[i][j]!=0){
		return dp[i][j];
	}
	//Rec Case
	int op1 = f(i+1,j,p,y+1) + y*p[i];
	int op2 = f(i,j-1,p,y+1) + y*p[j];
	return dp[i][j] = max(op1,op2);
}

int main(){

	int prices[] = {2,3,5,1,4};
	int n = 5;
	cout<<f(0,n-1,prices,1)<<endl;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}