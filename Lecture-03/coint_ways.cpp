#include<iostream>
using namespace std;

int coinways(int n,int coins[],int t){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	int ans = 0;
	for(int i=0;i<t;i++){
		ans += coinways(n-coins[i],coins,t);
	}
	return ans;
}
int minCoinsNeeded(int n,int coins[],int t){
	if(n==0){
		return 0;
	}

	int minCoins = INT_MAX;
	for(int i=0;i<t;i++){
		
		if(n-coins[i]>=0){
			minCoins = min(minCoins,minCoinsNeeded(n-coins[i],coins,t));
		}
	}
	return minCoins+1;
}

int main(){

	int coins[] = {1,7,10};
	int n= 15;
	int t = sizeof(coins)/sizeof(int);
	cout<<minCoinsNeeded(n,coins,t);


	


	return 0;
}